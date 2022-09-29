#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class ElevatorLimit
{
    public:
    vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit) {
        vector<int> minMax;
        int currentMax = 0;
        int cumulativeSum = 0;
        // Find the max possible number of people in the elevator before simulation.
        for (int i=0; i<enter.size(); i++) {
            // Not possible if number of people who entered/exited at any stop is > limit
            if (enter[i] > physicalLimit || exit[i] > physicalLimit) {
                return minMax;
            }
            // Find the maximum cumulative sum throughout the simulation
            cumulativeSum += -exit[i] + enter[i];
            if (cumulativeSum > currentMax) {
                currentMax = cumulativeSum;
            }
        }
        // There must be at least exit[0] people in the elevator before the simulation begins.
        int minSum = exit[0];
        int cumulativeDiff = 0;
        // Find the min possible number of people in the elevator before simulation.
        for (int j=0; j<enter.size()-1; j++) {
            // Find the remaining number of people in the elevator at stop j+1
            cumulativeDiff += enter[j] - exit[j+1];
            // If < 0: More people exited than entered. Otherwise, continue until so.
            if (cumulativeDiff < 0) {
                // The difference is the current minimum number of people that must have been in the elevator before simulation
                minSum += abs(cumulativeDiff);
                // Reset to 0 because now we have enough people before simulation
                cumulativeDiff = 0;
            }
        }
        // Not possible if the min/max number of people exceeds the physical limit
        if (minSum > physicalLimit || (physicalLimit - currentMax) > physicalLimit) {
            return minMax;
        }
        // Not possible if min > max
        if (minSum > (physicalLimit - currentMax)) {
            return minMax;
        }
        // The min number of people before simulation is the minSum
        minMax.push_back(minSum);
        // The maximum number of people before simulation is the limit - max cumulative sum
        minMax.push_back(physicalLimit - currentMax);
        return minMax;
    }
};