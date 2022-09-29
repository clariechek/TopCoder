#include <iostream>
using namespace std;

class ChristmasTree
{
    public:
    int levelSize[10] = {1,3,6,10,15,21,28,36,45,55};
    long decorationWays(int N, int red, int green, int blue) {
        // If not enough baubles then always return 0
        if (red+green+blue < levelSize[N-1]) {
            return 0;
        }
        long res = rec(1, N, red, green, blue);
        return res;
    }

    long numPossiblePermutation(int level, int factor) {
        long r1 = 1;
        for (int i=level; i>0; i--) {
            r1 = r1*i;
        }
        long r2 = 1;
        for (int i=level/factor; i>0; i--) {
            r2 = r2*i;
        }
        long res = 1;
        if (factor == 2) {
            res = r1/r2/r2;
        } else if (factor == 3) {
            res = r1/r2/r2/r2;
        }
        return res;
    }

    long rec(int level,int N, int red, int green, int blue) {
        // cout << "Level: " << level << " red: " << red << " green: " << green << " blue: " << blue << endl;
        // If any colour is less than 0, then not possible so return 0
        if (red < 0 || green < 0 || blue < 0) {
            return 0;
        }
        // Base case: reach end of tree so got 1 possible arrangment
        if (level == N+1) {
            return 1;
        }
        long count = 0;
        // If level is divisble by 2, select 2 colours
        if (level % 2 == 0) {
            // Select red and green
            count += rec(level+1, N, red-level/2, green-level/2, blue)*numPossiblePermutation(level, 2);
            // Select red and blue
            count += rec(level+1, N, red-level/2, green, blue-level/2)*numPossiblePermutation(level, 2);
            // Select green and blue
            count += rec(level+1, N, red, green-level/2, blue-level/2)*numPossiblePermutation(level, 2);
        }
        // If level is divisble by 3, select 3 colours
        if (level % 3 == 0) {
            count += rec(level+1, N, red-level/3, green-level/3, blue-level/3)*numPossiblePermutation(level, 3);
        }
        // Select 1 colour: Red or Green or Blue each time.
        count += rec(level+1, N, red-level, green, blue);
        count += rec(level+1, N, red, green-level, blue);
        count += rec(level+1, N, red, green, blue-level);
        // cout << "Count: " << count << endl;
        return count;
    }
};