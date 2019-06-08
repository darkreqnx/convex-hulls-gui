//!  Class for Graham Scan
/*!
  Class containing all functions required for the Graham Scan Algorithm
*/

#ifndef GRAHAM_H
#define GRAHAM_H

#include "basic.h"
#include "graph.h"

class Graham
{
public:
    Graham();

    //!  Graham Scan Function
    /*!
      A function that takes no parameters. Completes the Graham Scan and stores iterations into a vector of graphs.
      Returns the count of iterations

      \return integer of the iteration count.
    */
    static int GrahamScan();


    //!  Graham Scan Iteration
    /*!
      A function that takes one integer parameter and sets the global graph object to the same as the index.
      returns integer to show status of success.
      \param x integer that is the index for the current iteration
      \return integer indicating success
    */
    static int Iteration(int x);
};

#endif // GRAHAM_H
