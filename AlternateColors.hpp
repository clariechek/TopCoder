#include <iostream>
#include <string>

using namespace std;

class AlternateColors
{
    public:
    string getColor(long r, long g, long b, long k) {
        // Find minimum colour
        long min = minNum(r,minNum(g,b));
        int val = 0;
        string res = " ";

        // Special case: If k <= min*3 then remainder indicates kth colour
        if (k <= min*3) {
            val = k % 3;
            res = to_string(val);
            if (res[0] == '0') {
                return "BLUE";
            } else if (res[0] == '1') {
                return "RED";
            } else if (res[0] == '2') {
                return "GREEN";
            }
        } // Otherwise, k > min*3 so reduce k by min
        k = k - min*3;
        // Update colours
        r = r-min;
        g = g-min;
        b = b-min;
        
        // Now the min colour is 0 so repeat min for the remaining 2 colours
        if (r==0) {
            // Find minimum colour between green and blue
            min = minNum(g,b);
            // If k <= min*2, then remainder indicates kth colour
            if (k <= min*2) {
                val = k % 2;
                res = to_string(val);
                if (res[0] == '1') {
                    return "GREEN";
                } else {
                    return "BLUE";
                }
            } else {
                // Otherwise, the larger number always ends up as the kth colour
                if (g>=b) {
                    return "GREEN";
                } else {
                    return "BLUE";
                }
            }
        }

        if (b==0) {
            // Find minimum colour between green and blue
            min = minNum(r,g);
            // If k <= min*2, then remainder indicates kth colour
            if (k <= min*2) {
                val = k % 2;
                res = to_string(val);
                if (res[0] == '1') {
                    return "RED";
                } else {
                    return "GREEN";
                }
            } else {
                // Otherwise, the larger number always ends up as the kth colour
                if (r>=g) {
                    return "RED";
                } else {
                    return "GREEN";
                }
            }
        }

        if (g==0) {
            // Find minimum colour between green and blue
            min = minNum(r,b);
            // If k <= min*2, then remainder indicates kth colour
            if (k <= min*2) {
                val = k % 2;
                res = to_string(val);
                if (res[0] == '1') {
                    return "RED";
                } else {
                    return "BLUE";
                }
            } else {
                // Otherwise, the larger number always ends up as the kth colour
                if (r>=b) {
                    return "RED";
                } else {
                    return "BLUE";
                }
            }
        }

        return " ";
    }

    // Function to find minimum colour
    long minNum(long c1, long c2) {
        long min = (c1 <= c2)? c1 : c2;
        return min;
    }
};