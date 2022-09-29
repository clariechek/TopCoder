#include <iostream>
#include <vector>

using namespace std;

class ImportantTasks 
{
    public:
    int maximalCost(vector<int> complexity, vector<int> computers) {
        int res = 0;
        int count = 0;
        res = recursion(complexity, computers, res, count);
        return res;
    }

    // Recursive function
    int recursion(vector<int> complexity, vector<int> computers, int res, int count) {
        // base case: when we have iterated the whole complexity vector
        if (count == complexity.size()) {
            return res;
        }

        // Iterate the complexity vector starting from max complexity
        if (max(complexity) <= max(computers)) {
            // Task can be completed
            res++;
            // Update used computer index to -1 
            computers[maxIndex(computers)] = -1;
        }
        // Update task considered to 0
        complexity[maxIndex(complexity)] = 0;
        // Go to next largest complexity
        return recursion(complexity, computers, res, count+1);
    }

    // Function to find maximum value and returns the maximum
    int max(vector<int> values) {
        int currentMax = values[0];
        for (int i=1; i<values.size(); i++) {
            if (values[i] > currentMax) {
                currentMax = values[i];
            }
        }
    return currentMax;
    }

    // Function to find maximum value and returns the index
    int maxIndex(vector<int> values) {
        int currentMax = values[0];
        int index = 0;
        for (int i=1; i<values.size(); i++) {
            if (values[i] > currentMax) {
                currentMax = values[i];
                index = i;
            }
        }
        return index;
    }
};