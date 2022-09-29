#include <iostream>
using namespace std;

class FibonacciDiv2
{
    public:
    int find(int N) {
        int res = 0;
        int fibLeft = 0;
        int fibRight = 1;
        int nextFib = fibLeft + fibRight;
        // Find fibonacci values before and after N
        while (nextFib < N) {
            nextFib = fibLeft + fibRight;
            fibLeft = fibRight;
            fibRight = nextFib;
        }
        // cout << "Left " << fibLeft << " Right " << fibRight << " next " << nextFib << endl;
        // Calculate the differences between N and the fibonacci values before and after
        int leftDiff = N - fibLeft;
        int rightDiff = fibRight - N;
        // cout << "left diff " << leftDiff << " right diff " << rightDiff << endl;
        // Choose the smallest difference
        if (leftDiff < rightDiff) {
            res = leftDiff;
        } else {
            res = rightDiff;
        }
        return res;
    }
};