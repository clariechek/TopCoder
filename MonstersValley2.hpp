#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class MonstersValley2
{
    public:
    int minimumPrice(vector<int> dread, vector<int> price) {
        // Initiase Manao's party to the first monster
        int totalPaid = price[0];
        long totalDreadManao = dread[0];
        int index = 0;
        totalPaid = nextMonster(index+1, dread, price, totalPaid, abs(totalDreadManao));
        return totalPaid;   
    }

    // Recursive function
    int nextMonster(int index, vector<int> dread, vector<int> price, int totalPaid, long totalDreadManao) {
        // base case: when we reach the end of the valley/passed all monsters, return the minimum price paid to pass the valley.
        if (index == dread.size()) {
            return totalPaid;
        }

        // If cannot pass, then must bribe the next monster
        if (dread[index] > totalDreadManao) {
            totalPaid += price[index];
            totalDreadManao += dread[index];
            // Call recursively
            return nextMonster(index+1, dread, price, totalPaid, totalDreadManao);
        } else {
            // Can pass so find the minimum cost of walking past or bribing
            return min(nextMonster(index+1, dread, price, totalPaid, totalDreadManao), nextMonster(index+1, dread, price, totalPaid + price[index], totalDreadManao + dread[index]));
        }
        // Go to the next monster
        return nextMonster(index+1, dread, price, totalPaid, totalDreadManao);
    }

    // Function to find minimum and returns minimum
    int min(int num1, int num2) {
        int res = (num1 < num2) ? num1 : num2;
        return res;
    }
};