#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <tgmath.h>

using namespace std;

class MooingCows
{
    public:
    int dissatisfaction(vector<string> farmland) {
        int min = numeric_limits<int>::max();
        // Iterate each square of the farmland
        for (int row=0; row<farmland.size(); row++) {
            for (int col=0; col<farmland[0].length(); col++) {
                int totalDissatisfaction = 0;
                // If there is a cow, start calculating total dissatisfaction
                if (farmland[row][col] == 'C') {
                    // cout << "Curren cow: row " << row << " col " << col << endl;
                    for (int subrow=0; subrow<farmland.size(); subrow++) {
                        for (int subcol=0; subcol<farmland[0].length(); subcol++) {
                            // If there is a cow,  add dissatisfaction
                            if (farmland[subrow][subcol] == 'C') {
                                // cout << "Neighbour cow dissatisfaction " << pow(row-subrow,2) + pow(col-subcol,2) << endl;
                                totalDissatisfaction += pow(row-subrow,2) + pow(col-subcol,2);
                            } 
                        }
                    }
                    // Update the minimum total dissatisfaction
                    // cout << "Total dissatisfaction " << totalDissatisfaction << endl;
                    if (totalDissatisfaction < min) {
                        min = totalDissatisfaction;
                        // cout << "New min " << min << endl;
                    }
                }
            }
        }
        // Return minimum total dissatisfaction
        return min;
    }
};