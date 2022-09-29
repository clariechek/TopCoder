#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

class MagicSpell
{
    public:
    string fixTheSpell(string spell) 
    {
        stack<char> az;
        map<int, char> spells;
        for (int i=0; i<spell.length(); i++) {
            if (spell[i] != 'A' && spell[i] != 'Z') {
                // Copy non AZ values into map
                spells[i] = spell[i];
            } else {
                // Push AZ values into stack
                az.push(spell[i]);
            }
        }

        for (int j=0; j<spell.length(); j++) {
            if (spells.count(j) == 0) {
                // If empty position in map, copy top stack value into map
                spells[j] = az.top();
                // pop top stack value
                az.pop();
            }
        }

        // Copy re-arranged spell into spell
        for (int k=0; k<spell.length(); k++) {
            spell[k] = spells[k];
        }

        return spell;
    }
};