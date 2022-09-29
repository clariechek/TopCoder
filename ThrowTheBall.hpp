#include <iostream>
using namespace std;

class ThrowTheBall 
{
    public:
    int timesThrown(int N, int M, int L) {
        // If M=1, game ends, no pass was made.
        if (M == 1) {
            return 0;
        }

        int res = 0;
        int currentPlayer = 0;
        // Initialise array of numberof times each player held ball
        int p[N];
        // Player 1 received ball once and everyone else has not received ball yet
        p[0] = 1;
        for (int count=1; count<N; count++) {
            p[count] = 0;
        }
        // Initialise array of players on left
        int left[N];
        int value = 1;
        // Player 1 is always on left side of Player N
        left[N-1] = 0;
        for (int j=0; j<N-1; j++) {
            left[j] = value;
            value++;
        }
        // Initialise array of players on right
        int right[N];
        // Player N is always on the right of Player 1
        right[0] = N-1;
        // Reset value
        value = 0;
        for (int k=1; k<N; k++) {
            right[k] = value;
            value++;
        }

        // Game continues as long as ball has not been received M times
        while (p[currentPlayer] < M) {
            int evenOdd = p[currentPlayer]%2;
            // Check number of times each player received ball is even or odd
            if (evenOdd == 0) {
                // If even, go L places to the LEFT
                for (int l=0; l<L; l++) {
                    // update player holding the ball
                    // cout << currentPlayer << endl;
                    currentPlayer = left[currentPlayer];
                }
            } else {
                // If odd, go L places to the RIGHT
                for (int r=0; r<L; r++) {
                    currentPlayer = right[currentPlayer];
                }
            }

            // Update number of times ball received
            p[currentPlayer] += 1;

            // Increment number of times ball passed
            res++;
        }

        return res;
    }
};
