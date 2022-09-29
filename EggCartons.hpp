#include <iostream>
#include <limits.h>
using namespace std;

class EggCartons
{
    public:
    int minCartons(int n) {
        // cout << "n " << n << endl;
        // If odd or less than 6, then not possible
        if ((n%2 != 0) || n < 6) {
            return -1;
        }
        int currentMin = numeric_limits<int>::max();
        int total1 = numeric_limits<int>::max();
        int total2 = numeric_limits<int>::max();
        int total3 = numeric_limits<int>::max();
        int c6, c8, rem;
        // Check if n divisble by 8
        if (n%8 == 0) {
            total1 = n/8;
            // cout << "Divisble by 8. TOTAL1 is " << total1 << endl;
        }
        // Check if divisble by 6
        if (n%6 == 0) {
            total2 = n/6;
            // cout << "Divisble by 6. TOTAL2 is " << total2 << endl;
        }

        // Check if there exists a possible combination of 6s and 8s for n
        total3 = findCombination(n, rem, 6, 8, c6, c8);
        // cout << "total3 " << total3 << endl;
        currentMin = updateMin(abs(total1),abs(total2),abs(total3));
        
        return currentMin;
    }

    int findCombination(int n, int rem, int x, int y, int cx, int cy) {
        int result;
        int currentMin = numeric_limits<int>::max();
        cx = (n/x);
        cy = 1;
        // rem = n - (c6 * 6);
        // cout << "Can't by 6. c6 " << cx << " rem " << rem << endl; 

        // // There is a possible combination of x and y to get n
        // if (rem % y == 0) {
        //     cy = rem / y;
        //     cout << "found combination. cy is " << cy << endl;
        // }
        // Keep decrementing number of x until remaining eggs are divisble by y
        for (int i=cx; i>1; i--) {
            cx--;
            rem = n - (x * cx);
            // cout << "cx " << cx << " rem " << rem << endl;
            // There is a possible combination of x and y to get n
            if (rem % y == 0) {
                cy = rem / y;
                result = cx + cy;
                // cout << "found combination. cy is " << cy << endl;
                // cout << "Combination result cx + cy " << cx << " + " << cy << " = " << result << endl; 
                currentMin = updateMin(currentMin, result, numeric_limits<int>::max());
            }
            // There is no combination possible
            if (cx <= 0) {
                result = numeric_limits<int>::max();
                // cout << "No possible combination." << endl;
                return result;
            }
        }
        return result;
    }

    int updateMin(int x, int y, int z) {
        int currentMin;
        // cout << "x " << x << " y " << y << " z " << z << endl;
        if (x < y) {
            if (x < z) {
                currentMin = x;
            } else {
                currentMin = z;
            }
        } else {
            // y < x
            if (y < z) {
                currentMin = y;
            } else {

                currentMin = z;
            }
        }
        if (currentMin == numeric_limits<int>::max() || currentMin > 100) {
            currentMin = -1;
        }
        // cout << "new currentMin " << currentMin << endl;
        return currentMin;
    }
};