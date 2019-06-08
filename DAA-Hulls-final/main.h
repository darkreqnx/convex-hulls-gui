//! Main Class
/*!
   Class that Contains the main function.
*/

#ifndef MAIN_H
#define MAIN_H

#include "mainwindow.h"
#include <QApplication>
#include "basic.h"
#include "graph.h"

//! const int for the algorithm
static const int GRAHAM = 2;
static const int JARVIS = 1;
static const int KIRK = 3;


//! Function that sets the Current Mode- (i.e which Algorithm is being used)
/*!
  \param integer that uses the above static constants to set the current Algorithm being used
*/
void setMode(int n);


//! Function that gets the current mdoe
/*!
  \return integer that uses the above static constants to get the current Algorithm being used
*/
int getMode();

//! Function that returns reference to the current graph to be displayed.
/*!
  \return reference to a static graph object
*/
Graph& getGraph();


//! set function for the static graph
/*!
  \param reference to a graph object
*/
void setGraph(Graph g);
#endif // MAIN_H
