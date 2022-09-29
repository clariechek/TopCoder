#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class CircularLine
{
    public:
    int sum = 0;

    int longestTravel(vector<int> t) {
        int min = 0;
        int maxMin = 0;
        int x,y;
        int total = 0;
        // Get total sum of t
        for (int i=0; i<t.size(); i++) {
            total += t[i];
        }
        // cout << "Total size " << total << endl;

        // Find maximum of the minimums
        for (int i=0; i<t.size()-1; i++) {
            // reset
            x = 0;
            y = 0;
            for (int j=i+1; j<t.size(); j++) {
                sum = 0;
                // Find the 2 distances between station i and j
                x = calcSum(t, i, j);
                y = total - x;
                // Get the minimum distance
                min = (x < y) ? x : y;
                // cout << "i " << i <<  " j " << j << " x " << x << " y " << y << " min " << min << endl;
                // Get the maximum of the minimums
                maxMin = (min > maxMin) ? min : maxMin;
                // cout << "maxMin " << maxMin << endl;
            }
        }
        return maxMin;
    }
    

    int calcSum(vector<int> t, int i, int j) {
        // base case
        if (i+1 == j) {
            sum += t[i];
            // cout << "sum " << sum << endl;
            return sum;
        }

        sum += t[j-1];
        // cout << "sum " << sum << endl;
        calcSum(t, i, j-1);
        return sum;
    }

};