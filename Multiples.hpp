#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;

class Multiples
{
    public:
    int number(int min, int max, int factor)
    {
        int res = 0;
        string num = "1";
        // If min = max, then check if the single number in the range
        // is divisible by factor. If divisible, return 1, else 0.
        if (min == max) {
            res = (min % factor == 0)? 1 : 0;
            return res;
        }

        // Mathematical pattern for all other cases
        // If both negative,
        if (min < 0 && max < 0) {
                res = (abs(min)/factor) - (abs(max)/factor);
                // Include number itself if it is divisible by factor
                if (abs(max)%factor == 0) {
                    res++;
                }
        } else if (min <= 0 && max >= 0) {
            // If min is negative and max is positive
            res = (max/factor) + (abs(min)/factor) + 1;
        } else {
            // If both is positive
           res = (max/factor) - (min/factor);
           // Include number itself if it is divisible by factor
            if (abs(min)%factor == 0) {
                res++;
            }
        }

        

        return res;
    }
};