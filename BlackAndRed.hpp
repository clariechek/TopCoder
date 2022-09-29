#include<iostream>
#include <string>

using namespace std;

class BlackAndRed
{
    public:
    int cut(string deck) {
        int sum = 0;
        int currentMin = 0;
        int pos = 0;
        // If card is R, minus 1, if it is B, add 1
        for (int i=0; i<deck.length(); i++) {
            if (deck[i] == 'R') {
                sum--;
            } else {
                sum++;
            }
            // Find the minimum sum to get earliest cut position
            if (sum < currentMin) {
                currentMin = sum;
                pos = i+1;
            }
        }
        return pos;
    }
};