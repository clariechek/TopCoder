#include <iostream>
#include <string>
using namespace std;

class Reppity {
    public:
    int longestRep(string input) {
        int longest = 0;
        int N = input.length();
        int n = input.length()-1;
        
        // if length is 2
        if (N == 2) {
            if (input[0] == input[1]) {
                return 1;
            } else {
                return 0;
            }
        }


        for (int start=0; start<n; ++start) {
            int count = 0;
            //cout << "N: " << N << endl;
            for (int len=N; len>0; --len) {
                string str = input.substr(start, len);
                string rem = input.substr(start+len, count);
                //cout << "Str: " << str << " Rem: " << rem << endl;
                if (rem.find(str) != string::npos) {
                    //cout << "Found match: " << str << endl;
                    // update max
                    if (str.length() > longest) {
                        longest = str.length();
                        //cout << "Longest match: " << str << " " << longest << endl;
                    }
                }
                count++;
            }
            N--;
        }
        
        return longest;
    }
};