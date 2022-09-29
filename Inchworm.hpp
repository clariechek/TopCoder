#include <iostream>
using namespace std;
 
 
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
    // your code for the problem
    int res = 0;
    // Going from the start of the branch to the end, we increment each iteration by the rest interval
    for (int i=0; i <= branch; i += rest) {
      if (i % leaf == 0) {
        // If the rest location and the leaf interval are common multiples then they coincide so worm eats the leaf.
        res++;
      }
    }
    
    return res;  // return your result
  }
};
    
    