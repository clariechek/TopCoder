#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

class ChangingString
{
    public:
    int distance(string A, string B, int K) {
        vector<int> distances;
        int diff = 0;
        int total = 0;
        int currentMax = -1;
        int maxPosition = 0;
        // Iterate both strings and store distance between each corresponding letters in 'distances'
        for (int i=0; i<A.length(); i++) {
            diff = abs(A[i] - B[i]);
            distances.push_back(diff);
            // Calculate total distance of original array
            total += diff;
        }

        // Deduct K first maximum distances from total
        for (int k=0; k<K; k++) {
            // Find currentMax
            for (int i=0; i<distances.size(); i++) {
                if (distances[i] > currentMax) {
                    currentMax = distances[i];
                    maxPosition = i;
                }
            }
            if (currentMax == 0) {
                // Increment by 1 if value to be deducted is 0
                total++;
            } else {
                // Otherwise, deduct the maximum value
                total = total - currentMax;
            }
            // mark as deducted
            distances[maxPosition] = -1;
            // reset currentMax
            currentMax = -1;
        }
        // Return minimum distance
        return total;
    }
};