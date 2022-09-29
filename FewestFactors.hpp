#include <iostream>
#include <vector>
#include <algorithm>
#include <tgmath.h>
#include <string>
#include <limits.h>
using namespace std;

class FewestFactors {
    public:
    int number(vector<int> digits) {
        int current = numeric_limits<int>::max();
        int min = numeric_limits<int>::max();
        sort(digits.begin(), digits.end());
        string num = "";
        do {
            num = "";
            for (int i=0; i<digits.size(); i++) {
                num += to_string(digits[i]);
            }
            int val = stoi(num);
            // cout << val << endl;
            int fac = countFac(val);
            if (fac < min) {
                min = fac;
                current = val;
            }
        } while (next_permutation(digits.begin(),digits.end()));

        return current;
    }

    int countFac(int num) {
        int count = 0;
        for (int i=1; i<=num; i++) {
            if (num%i == 0) count++;
        }
        return count;
    }


};