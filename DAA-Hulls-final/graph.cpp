
#include "graph.h"

Graph::Graph(){

};
//! A normal member taking two arguments and adding a normal point to the graph object
/*!
  \param x an integer for x-coordinate
  \param y an integer for y-coordinate
*/
void Graph::addNormalPoint(int x, int y)
{
    Point p = {x,y};

    normalPoints.push_back(p);
}

//! A normal member taking two arguments and adding a bold point to the graph object
/*!
  \param x an integer for x-coordinate
  \param y an integer for y-coordinate
*/
void Graph::addBoldPoint(int x, int y){

    Point p = {x,y};

    boldPoints.push_back(p);
}

//! A normal member taking four arguments and adding a normal line to the graph object
/*!
  \param x1 an integer for x-coordinate
  \param y1 an integer for y-coordinate
  \param x2 an integer for x-coordinate
  \param y2 an integer for y-coordinate
*/
void Graph::addNormalLine(int x1, int y1, int x2, int y2){
    Point p1 = {x1,y1};

    Point p2 = {x2,y2};

    Line l = {p1,p2};
    normalLines.push_back(l);
}

//! A normal member taking four arguments and adding a bold line to the graph object
/*!
  \param x1 an integer for x-coordinate
  \param y1 an integer for y-coordinate
  \param x2 an integer for x-coordinate
  \param y2 an integer for y-coordinate
*/
void Graph::addBoldLine(int x1, int y1, int x2, int y2){
    Point p1 = {x1,y1};

    Point p2 = {x2,y2};

    Line l = {p1,p2};
    boldLines.push_back(l);
}

//! A normal member taking no arguments and returning a vector of all normal points in the graph object.
/*!
  \return vector of Normal Points
*/
std::vector<Point> Graph::getNormalPoints(){
    return normalPoints;
};

//! A normal member taking no arguments and returning a vector of all bold points in the graph object.
/*!
  \return vector of Bold Points
*/
std::vector<Point> Graph::getBoldPoints(){
    return boldPoints;
};


//! A normal member taking no arguments and returning a vector of all normal lines in the graph object.
/*!
  \return vector of Normal Lines
*/
std::vector<Line> Graph::getNormalLines(){
    return normalLines;
};

//! A normal member taking no arguments and returning a vector of all bold lines in the graph object.
/*!
  \return vector of Bold Lines
*/
std::vector<Line> Graph::getBoldLines(){
    return boldLines;
};
