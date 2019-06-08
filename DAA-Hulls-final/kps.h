//!  Class for Kirk Patrick Seidel Algorithm
/*!
  Class containing all functions required for the Kirk Patrick Seidel Algorithm
*/
#ifndef KPS_H
#define KPS_H

#include "basic.h"
#include "graph.h"

class KPS
{
public:
    KPS();

    //!  KPS Function
    /*!
      A function that takes no parameters. Completes the KPS and stores iterations into a vector of graphs.
      Returns the count of iterations

      \return integer of the iteration count.
    */
    static int KPSScan();


    //!  KPS Iteration
    /*!
      A function that takes one integer parameter and sets the global graph object to the same as the index.
      returns integer to show status of success.
      \param x integer that is the index for the current iteration
      \return integer indicating success
    */
    static int Iteration(int x);
};


#endif // KPS_H
