#include <iostream>
#include <vector>

using namespace std;

class DerivativeSequence{
    public:
    vector<int> derSeq(vector<int> a, int n) {
        // If order 0, return original sequence
        if (n == 0) {
            return a;
        }

        // Derivation for order n
        for (int order=n; order>0; order--) {
            // Derivative for order 1
            for (int i=0; i<a.size()-1; i++) {
                int res = a[i+1]-a[i];
                // Add to vector
                a[i] = res;
                //cout << res << " ";
            }
            //cout << endl;
            // Remove last element from previous vector
            a.pop_back();
        }
        return a;
    }
};