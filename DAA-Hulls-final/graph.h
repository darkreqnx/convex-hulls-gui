
//!  Class for Graph
/*!
  Class for the graph object that is used to communicate between GUI and Backend
*/
#ifndef GRAPH_H
#define GRAPH_H

#include "basic.h"

//! Structure For a point. Also has an operator <
/*!
*/
struct Point
{
    int x, y;

    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};
//! Structure For a Line. (Set of Two Points)
/*!
*/
struct Line
{
    Point p1, p2;
};
class Graph
{
public:
    Graph();

    //! A normal member taking two arguments and adding a normal point to the graph object
    /*!
      \param x an integer for x-coordinate
      \param y an integer for y-coordinate
    */
    void addNormalPoint(int x, int y);
    //! A normal member taking two arguments and adding a bold point to the graph object
    /*!
      \param x an integer for x-coordinate
      \param y an integer for y-coordinate
    */
    void addBoldPoint(int x, int y);

    //! A normal member taking four arguments and adding a normal line to the graph object
    /*!
      \param x1 an integer for x-coordinate
      \param y1 an integer for y-coordinate
      \param x2 an integer for x-coordinate
      \param y2 an integer for y-coordinate
    */
    void addNormalLine(int x1, int y1, int x2, int y2);

    //! A normal member taking four arguments and adding a bold line to the graph object
    /*!
      \param x1 an integer for x-coordinate
      \param y1 an integer for y-coordinate
      \param x2 an integer for x-coordinate
      \param y2 an integer for y-coordinate
    */
    void addBoldLine(int x1, int y1, int x2, int y2);

    //! A normal member taking no arguments and returning a vector of all normal points in the graph object.
    /*!
      \return vector of Normal Points
    */
    std::vector<Point> getNormalPoints();

    //! A normal member taking no arguments and returning a vector of all bold points in the graph object.
    /*!
      \return vector of Bold Points
    */
    std::vector<Point> getBoldPoints();

    //! A normal member taking no arguments and returning a vector of all normal lines in the graph object.
    /*!
      \return vector of Normal Lines
    */
    std::vector<Line> getNormalLines();

    //! A normal member taking no arguments and returning a vector of all bold lines in the graph object.
    /*!
      \return vector of Bold Lines
    */
    std::vector<Line> getBoldLines();

    std::string Message;
private:
    //! Vector of Points
    /*!
      Used for Normal Points
    */
    std::vector<Point> normalPoints;

    //! Vector of Points
    /*!
      Used for Bold Points
    */
    std::vector<Point> boldPoints;

    //! Vector of Lines
    /*!
      Used for Normal Lines
    */
    std::vector<Line> normalLines;

    //! Vector of Lines
    /*!
      Used for Bold Lines
    */
    std::vector<Line> boldLines;
};

#endif // GRAPH_H
