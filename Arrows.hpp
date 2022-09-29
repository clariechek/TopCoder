#include <iostream>
#include <string>

using namespace std;

class Arrows {
    public:
    int longestArrow(string s) {
        int longest = -1;
        for (int i=0; i<s.length(); i++) { 
            // Reset count for new arrow sequence
            int count = -1;
            if (s[i] == '<') {
                char nextChar = checkNextChar(s, i+1);
                count = countRight(s, i+1, nextChar);
            } 
            if (s[i] == '>') {
                char nextChar = checkNextChar(s, i-1);
                count = countLeft(s, i-1, nextChar);
            }
            // Update longest arrow sequence
            if (count > longest) {
                longest = count;
            }
        }
        return longest;
    }

    // Function to check if next character is - or =, otherwise return 0.
    char checkNextChar(string s, int nextIndex) {
        char nextChar = '0';
        if (s[nextIndex] == '-' || s[nextIndex] == '=') { 
            nextChar = s[nextIndex];
        }
        return nextChar;
    }

    // Function to count arrow sequence to the right and returns its length
    int countRight(string s, int startIndex, char nextChar) {
        int length = 1;
        while (s[startIndex] == nextChar && startIndex != s.length()) {
            length++;
            startIndex++;
        }
        return length;
    }

    // Function to count arrow sequence to the left and returns its length
    int countLeft(string s, int startIndex, char nextChar) {
        int length = 1;
        while (s[startIndex] == nextChar && s[startIndex] != -1) {
            length++;
            startIndex--;
        }
        return length;
    }
};