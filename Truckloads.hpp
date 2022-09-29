#include <iostream>
using namespace std;

class Truckloads
{
    public:
    int numTrucks(int numCrates, int loadSize) {
        // base case
        if (numCrates <= loadSize) {
            return 1;
        }

        int sum = 0;
        if (numCrates % 2 == 0) {
            // If even number of crates
            sum += numTrucks(numCrates/2, loadSize) + numTrucks(numCrates/2, loadSize);
        } else {
            // If odd number of crates
            sum += numTrucks(numCrates/2, loadSize) + numTrucks((numCrates+1)/2, loadSize);
        }
        return sum;
    }
};