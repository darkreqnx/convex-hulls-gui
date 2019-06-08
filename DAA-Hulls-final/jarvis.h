//!  Jarvis Algorithm
/*!
  Class containing all functions required for Jarvis' Algorithm
*/
#ifndef JARVIS_H
#define JARVIS_H

#include "basic.h"

#include "graph.h"

class Jarvis
{
public:
    Jarvis();

    //!  Jarvis Algorithm Function
    /*!
      A function that takes no parameters. Completes the Jarvis Algorithm and stores iterations into a vector of graphs.
      Returns the count of iterations

      \return integer of the iteration count.
    */
    static int JarvisHull();

    //!  Jarvis Iteration
    /*!
      A function that takes one integer parameter and sets the global graph object to the same as the index.
      returns integer to show status of success.
      \param x integer that is the index for the current iteration
      \return integer indicating success
    */
    static int Iteration(int x);
};

#endif // JARVIS_H
