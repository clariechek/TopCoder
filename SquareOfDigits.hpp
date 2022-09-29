#include <iostream>
#include <string>
#include <vector>
#include <tgmath.h>

using namespace std;

class SquareOfDigits
{
    public:
    int getMax(vector<string> data) {
        int max = 1;
        // Iterate each cell and check for same number in subsequent cells of the same row
        for (int row=0; row<data.size()-1; row++) {
            for (int col=0; col<data[0].length()-1; col++) {
                char currentNum = data[row][col];
                // cout << "currentNum " << currentNum - '0' << endl;
                // Subsequent iterates all the cols after the current col
                for (int subsequent=col+1; subsequent<data[0].length(); subsequent++) {
                    int distance = subsequent-col;
                    // cout << "subsequent " << subsequent << " distance " << distance << endl;
                    // cout << "Subsequent " << data[row][subsequent] << endl;
                    if (currentNum == data[row][subsequent]) {
                        // Check bottom right edge
                        // cout << "Match so check bottom right " << data[row+distance][subsequent] << endl;
                        if (row+distance < data.size() && currentNum == data[row+distance][subsequent]) {
                            // Check bottom left edge
                            // cout << "Match so check bottom left " << data[row+distance][col] << endl;
                            if (row+distance < data.size() && currentNum == data[row+distance][col]) {
                                // cout << "Square obtained, distance is " << subsequent+1 << ", currentNum " << currentNum << ", row " << row << ", col " << col << endl;
                                // Update max distance
                                if (pow(distance+1,2) > max) {
                                    max = pow(distance+1,2);
                                    // cout << "New MAX " << max << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        // return the maximum square
        return max;
    }
};