#include <iostream>
#include <string>
#include <map>

using namespace std;


class NiceOrUgly {
    public:
    // Map where key is index,(c,v) and value is "NICE", "UGLY" or "42"
    map<pair<int,pair<int,int>>, string> m;
    string describe(string s) {
        // clear map
        m.clear();
        // if no ? no need recursion
        
        string res = recursion(0, 0, 0, s);
        
        return res;
    }

    string recursion(int i, int c, int v, string s) {
        // cout << i << " " << c << " " << v << endl;
        // Check if ugly
        if (isUgly(c,v)) {
            return "UGLY";
        }
        
        // Base case: reached end of string
        if (i == s.length()) {
            return "NICE";
        }

        // Check if value already counted. If so, return from map
        auto key = make_pair(i,make_pair(c,v));
        if (m.count(key) == 1) {
            return m[key];
        }
        string res = "";
        // If ?, then consider 2 cases: if vowel and if consonant
        if (s[i] == '?') {
            string consonant = recursion(i+1, c+1, 0, s);
            string vowel = recursion(i+1, 0, v+1, s);

            // If both UGLY, return UGLY
            if (consonant == "UGLY" && vowel == "UGLY") {
                res = "UGLY";
            } else if (consonant == "NICE" && vowel == "NICE") {
                // Else if both NICE, return NICE
                res = "NICE";
            } else {
                // Else if one UGLY, and one NICE, means both possible
                res = "42";
            }
        } else if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ) {
            // If vowel, call next letter with preceeding vowel
            res = recursion(i+1, 0, v+1, s);
        } else {
            // If consonant, call next letter with preceeding consonant
            res = recursion(i+1, c+1, 0, s);
        }

        // Add new value to map
        if (m.count(key) == 0) {
            m[key] = res;
        }
        // cout << "Index " << i << " res " << res << endl;
        return res;
    }

    // Function to check if case is UGLY 
    bool isUgly(int c, int v) {
        if (c >= 5 || v >= 3) {
            return true;
        } 
        return false;
    }
};