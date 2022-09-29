#include <iostream>
#include <map>
#include <utility>

using namespace std;

class UnsealTheSafe
{
    public:
    map<pair<int,int>,long> m;
    long count = 0;
    long countPasswords(int N) {
        long levelsLeft = N-1;
        
        count = nextNumber(0, levelsLeft) + nextNumber(1, levelsLeft) + nextNumber(2, levelsLeft) + nextNumber(3, levelsLeft) + nextNumber(4, levelsLeft) + nextNumber(5, levelsLeft) + nextNumber(6, levelsLeft) + nextNumber(7, levelsLeft) + nextNumber(8, levelsLeft) + nextNumber(9, levelsLeft);
        return count;
    }

    // Recursive function to count all possible password combinations of length N and returns count
    long nextNumber(int num, long levelsLeft) {
        // base case: If we have achieved N digits, then this is one combination
        if (levelsLeft == 0) {
            return 1;
        }
        // Check if value is already in map otherwise add to map
        auto key = make_pair(num, levelsLeft);
        int found = m.count(key);
        // already calculated so just return the value
        if (found == 1) {
            // cout << "found key" << endl;
            return m[key];
        }

        // Call recursive function for each number adjacent to num
        switch (num) {
            case 0:
                count = nextNumber(7, levelsLeft-1);
                break;
            case 1:
                count = nextNumber(2, levelsLeft-1) + nextNumber(4, levelsLeft-1);
                break;
            case 2:
                count = nextNumber(1, levelsLeft-1) + nextNumber(5, levelsLeft-1) + nextNumber(3, levelsLeft-1);
                break;
            case 3:
                count = nextNumber(2, levelsLeft-1) + nextNumber(6, levelsLeft-1);
                break;
            case 4:
                count = nextNumber(1, levelsLeft-1) + nextNumber(5, levelsLeft-1) + nextNumber(7, levelsLeft-1);
                break;
            case 5:
                count = nextNumber(2, levelsLeft-1) + nextNumber(4, levelsLeft-1) + nextNumber(6, levelsLeft-1) + nextNumber(8, levelsLeft-1);
                break;
            case 6:
                count = nextNumber(3, levelsLeft-1) + nextNumber(5, levelsLeft-1) + nextNumber(9, levelsLeft-1);
                break;
            case 7:
                count = nextNumber(4, levelsLeft-1) + nextNumber(8, levelsLeft-1) + nextNumber(0, levelsLeft-1);
                break;
            case 8:
                count = nextNumber(5, levelsLeft-1) + nextNumber(7, levelsLeft-1) + nextNumber(9, levelsLeft-1);
                break;
            case 9:
                count = nextNumber(6, levelsLeft-1) + nextNumber(8, levelsLeft-1);
                break;
            }

        // map doesn't have the value so store it in map
        if (found == 0) {
            // cout << "add key " << key.first << " " << key.second << endl;
            m[key] = count;
        }
        return count;
    }
};