#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

using namespace std;

class PrefixFreeSets {
    public:
    int maxElements(vector<string> words) {
        int n = words.size();
        // cout << "n " << n << endl;
        // Special case: if n=0 or n=1, return 0 or 1 respectively
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        list<string> l;
        // Copy vector values to list
        for (int i = 0; i < n; i++) {
            l.push_back(words[i]);
        }
        bool end = false;
        // // Print list
        // for (auto it = l.cbegin(); it != l.cend(); it++) {
        //     cout << *it << endl;
        // }
        // Remove prefixes from list
        while (end == false) {
            // Reset end to true. If no prefix found, and reach end of list, then finish.
            end = true;
            // Index to remove prefix if found
            int remove = -1;
            for (int i=0; i<l.size(); i++) {
            // cout << "i " << i << ": " << words[i] << endl;
                for (int j=0; j<l.size(); j++) {
                    // cout << "j " << j << ": " << words[j] << words[j].find(words[i]) << endl;
                    if (i != j) {
                        auto l_front = l.begin();
                        advance(l_front, i);
                        string li = *l_front;
                        l_front = l.begin();
                        advance(l_front, j);
                        string lj = *l_front;
                        // cout << li << " " << lj << endl;
                        // If found a prefix, remove it and continue checking new list
                        if (lj.find(li) == 0 && li.length() <= lj.length()) {
                            remove = i;
                            // Set end to false to continue checking
                            end = false;
                            break;
                        }
                    }
                }
                // Stop checking further for this prefix
                if (remove >= 0) {
                    break;
                }
            }
            // Remove the prefix
            if (remove >= 0) {
                list<string>::iterator it = l.begin();
                advance(it, remove);
                l.erase(it);
            }
        }
        // Final size of the list is largest prefix-free set
        int res = l.size();
        return res;
    }
};