/*!
 * \file
  Class containing all functions required for the Graham Scan Algorithm
*/

#include "graham.h"
#include "main.h"
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

static Point pivot;
static vector<Graph> gvector;
static Graph gfirst;
static int Count = 0;
static Graph x;
static stack<Point> hull;

static Graph prevGraph;
//
/*! 
 *
 *\brief A normal member taking three arguments and returning an integer based on orientation of the points. Used in auxilliary for main algorithm
 *\param a is a Point
 *\param b is a Point
 *\param c is a Point
 *\return integer, value is -1 if points are counter-clockwise, 1 if Clockwise, 0 if linear
*/


Graph currGraph(stack<Point> sP){

    stack<Point> hull = sP;

    Point p0= hull.top();
    hull.pop();

    Graph g = gfirst;

    g.addBoldPoint(p0.x, p0.y);

    while (!hull.empty())   {
        Point p = hull.top();
        hull.pop();
        g.addBoldPoint(p.x,p.y);
        g.addBoldLine(p0.x,p0.y,p.x,p.y);
        p0 = p;
    }

    return g;
}
int ccw(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0){
        x = currGraph(hull);
        x.addBoldPoint(a.x,a.y);
        x.addBoldPoint(b.x,b.y);
        x.addBoldPoint(c.x,c.y);
        x.Message= "CounterClockwise";
        gvector.push_back(x);Count++;
        return -1;
    }
    else if (area < 0){

        x = currGraph(hull);
        x.addBoldPoint(a.x,a.y);
        x.addBoldPoint(b.x,b.y);
        x.addBoldPoint(c.x,c.y);
        x.Message= "Clockwise!";
        gvector.push_back(x);Count++;
        return 1;
    }else{

        x = currGraph(hull);
        x.addBoldPoint(a.x,a.y);
        x.addBoldPoint(b.x,b.y);
        x.addBoldPoint(c.x,c.y);
        x.Message= "Linear";
        gvector.push_back(x);Count++;
        return 0;
    }
}
/*!
 *
 *\brief A normal member taking three arguments and returning an integer based on orientation of the points. Used as aux in the sorting function.
 *\param a is a Point
 *\param b is a Point
 *\param c is a Point
 *\return integer, value is -1 if points are counter-clockwise, 1 if Clockwise, 0 if linear
*/
int ccwsort(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0){
        return -1;
    }
    else if (area < 0){

        return 1;
    }else{

        return 0;
    }
}

/*!
 *
 *\brief A normal member taking Two arguments and returning an integer for the square of distance
 *\param a is a Point
 *\param b is a Point
 *\return integer, square of distance between the Points a and b.
*/
int dist(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

/*!
 *
 *\brief A member function used for sorting points according to polar order w.r.t the pivot
 *\param a is a Point
 *\param b is a Point
 *\return integer, square of distance between the Points a and b.
*/
bool POLAR_ORDER(Point a, Point b)  {
    int order = ccwsort(pivot, a, b);
    if (order == 0)
        return dist(pivot, a) < dist(pivot, b);
    return (order == -1);
}

/*!
 *
 *\brief Main member function that performs the Graham Scan algorithm.
 *\param *points is a reference to an array of points
 *\param N is the length of the array
 *\return A Stack of Points that form the Convex Hull in Cyclic Order.
*/


stack<Point> scan(Point *points, int N)    {


    if (N < 3)
        return hull;

    // find the point having the least y coordinate (pivot),
    // ties are broken in favor of lower x coordinate
    int leastY = 0;
    for (int i = 1; i < N; i++)
        if (points[i] < points[leastY])
            leastY = i;
    x = gfirst;
    x.addBoldPoint(points[leastY].x,points[leastY].y);
    cout<<points[leastY].x<<" "<<points[leastY].y<<endl;
    x.Message= "Picking Least Y";
    gvector.push_back(x);Count++;


    // swap the pivot with the first point
    Point temp = points[0];
    points[0] = points[leastY];
    points[leastY] = temp;

    x = gfirst;
    x.addBoldPoint(points[leastY].x,points[leastY].y);
    x.addBoldPoint(points[0].x,points[0].y);
//    cout<<points[leastY].x<<" "<<points[leastY].y<<endl;
    x.Message= "Swapping Pivot Y";
    gvector.push_back(x);Count++;


    // sort the remaining point according to polar order about the pivot
    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);

    x = gfirst;
    x.addBoldPoint(points[0].x,points[0].y);
//    cout<<points[leastY].x<<" "<<points[leastY].y<<endl;
    x.Message= "Sorting remaining Points around new pivot";
    gvector.push_back(x);Count++;

    //Pushing into Hull
    hull.push(points[0]);
    hull.push(points[1]);
    hull.push(points[2]);

    x = gfirst;
    x.addBoldPoint(points[0].x,points[0].y);
    x.addBoldPoint(points[1].x,points[1].y);
    x.addBoldPoint(points[2].x,points[2].y);
    x.addBoldLine(points[0].x,points[0].y,points[1].x,points[1].y);
    x.addBoldLine(points[1].x,points[1].y,points[2].x,points[2].y);

    x.Message= "Push first three Elements into stack";
    gvector.push_back(x);Count++;



    for (int i = 3; i < N; i++) {


        Point top = hull.top();
        hull.pop();

        x = currGraph(hull);
        x.addBoldPoint(top.x,top.y);
        x.addBoldPoint(hull.top().x,hull.top().y);
        x.addBoldPoint(points[i].x,points[i].y);
        char buffer[100];
        sprintf(buffer, "Looping Currently at %d/%d", i, N);
        x.Message = buffer;
//        strcpy(x.Message, buffer);
        gvector.push_back(x);Count++;

        while (ccw(hull.top(), top, points[i]) != -1)   {
            top = hull.top();
            hull.pop();
            x = currGraph(hull);
            x.Message= "Popped From Stack";
            gvector.push_back(x);Count++;
        }

        hull.push(top);
        hull.push(points[i]);
        x = currGraph(hull);
        x.Message= "Two Points pushed into stack";
        gvector.push_back(x);Count++;
    }
    return hull;
}

int Graham::GrahamScan(){
    Graph& g= getGraph();

    gfirst = g;
    Graph gfinal = gfirst;
    std::vector<Point> np = gfirst.getNormalPoints();

    stack<Point> hull = scan(&np[0], np.size());
    while (!hull.empty())   {
        Point p = hull.top();
        hull.pop();
        gfinal.addBoldPoint(p.x,p.y);
    }

    std::vector<Point> bp = gfinal.getBoldPoints();
    int s = bp.size();
    for(int i=0;i<s-1;i++){
        gfinal.addBoldLine(bp[i].x,bp[i].y,bp[i+1].x,bp[i+1].y);
    }
    gfinal.addBoldLine(bp[0].x,bp[0].y,bp[s-1].x,bp[s-1].y);
    gfinal.Message = "End of Graham's Scan!";
    gvector.push_back(gfinal);Count++;
    return Count;
}

int Graham::Iteration(int x){
    if(x<Count){
        Graph& g = getGraph();
        g = gvector[x];
        return 1;
    }else{
        return 0;
    }
}
