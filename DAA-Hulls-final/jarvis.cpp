/*!
 * \file
  Class containing all functions required for the Jarvis Scan
*/
#include "jarvis.h"
#include "main.h"
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


static vector<Graph> gvector;
static Graph gfirst;
static int Count = 0;
static Graph x;

static vector<Point> hull;

/*!
 *
 *\brief A normal member taking three arguments and returning an integer based on orientation of the points. Used as aux in the sorting function.
 *\param a is a Point
 *\param b is a Point
 *\param c is a Point
 *\return integer, value is -1 if points are counter-clockwise, 1 if Clockwise, 0 if linear
*/
int orient(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

Graph currGraph(){



    Graph g = gfirst;

    for (int i=0; i < hull.size()-1;i++) {
        g.addBoldPoint(hull.at(i).x,hull.at(i).y);
        g.addBoldPoint(hull.at(i+1).x,hull.at(i+1).y);
        g.addBoldLine(hull.at(i).x,hull.at(i).y, hull.at(i+1).x,hull.at(i+1).y);
    }

    return g;
}
/*!
 *
 *\brief Main member function that performs the Jarvis' algorithm.
 *\param *points is a reference to an array of points
 *\param N is the length of the array
 *\return A Vector of Points that form the Convex Hull in Cyclic Order.
*/
vector<Point> convexHull(Point points[], int n)
{
    // There must be at least 3 points
//    if (n < 3) return;

    // Initialize Result


    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    x = gfirst;
    x.addBoldPoint(points[l].x,points[l].y);
    x.Message= "LeftMost Point Selected";
    gvector.push_back(x);Count++;

    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hull.push_back(points[p]);

        // Search for a point 'q' such that orientation(p, x,
        // q) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1)%n;
        x =currGraph();
        x.addBoldPoint(points[q].x,points[q].y);
        x.Message= "Current q Selected";
        gvector.push_back(x);Count++;
        for (int i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
            x = currGraph();
            x.addBoldPoint(points[q].x,points[q].y);
            x.addBoldPoint(points[i].x,points[i].y);
            x.Message= "Current i";
            gvector.push_back(x);Count++;
           if (orient(points[p], points[i], points[q]) == 2){
               q = i;
               x = currGraph();
               x.addBoldPoint(points[i].x,points[i].y);
               x.Message= "Current i is new q";
               gvector.push_back(x);Count++;
           }
        }

        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
        x = currGraph();
        x.addBoldPoint(points[q].x,points[q].y);
        x.Message= "Current q is the new p";
        gvector.push_back(x);Count++;

    } while (p != l);  // While we don't come to first point


    return hull;
}

int Jarvis::JarvisHull()
{
    Graph& g= getGraph();

    gfirst = g;
    Graph gfinal = gfirst;
    std::vector<Point> np = gfirst.getNormalPoints();

    vector<Point> hull = convexHull(&np[0], np.size());

    // Print Result
    for (int i = 0; i < hull.size(); i++){
//        cout << "(" << hull[i].x << ", "
//        << hull[i].y << ")\n";

        gfinal.addBoldPoint(hull[i].x,hull[i].y);
    }

    std::vector<Point> bp = gfinal.getBoldPoints();
    int s = bp.size();
    for(int i=0;i<s-1;i++){
        gfinal.addBoldLine(bp[i].x,bp[i].y,bp[i+1].x,bp[i+1].y);
    }
    gfinal.addBoldLine(bp[0].x,bp[0].y,bp[s-1].x,bp[s-1].y);
    gfinal.Message = "End of Jarvis Algorithm!";
    gvector.push_back(gfinal);Count++;
    return Count;
}

int Jarvis::Iteration(int x){
    if(x<Count){
        Graph& g = getGraph();
        g = gvector[x];
        return 1;
    }else{
        return 0;
    }
}
