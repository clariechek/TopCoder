#include <iostream>
#include <string>
using namespace std;

class StrangeComputer
{
    public:
    int setMemory(string mem) {
        int flip = 0;
        // Start current consecutive value as 0.
        char current = '0';
        // Iterate through mem
        for (int i=0; i<mem.length(); i++) {
            // If current digit in mem is not the current consecutive value then flip
            if (mem[i] != current) {
                flip++;
                // Change current to match mem[i]. This is the current consecutive value.
                current = (current == '0')? '1' : '0';
            }
        }
        return flip;
    }
};

// string num = "";
        // int flip = 0;
        // for (int i=0; i<mem.length(); i++) {
        //     num += "0";
        // }
        // for (int i=0; i<mem.length(); i++) {
        //     // If don't match, then flip num[i] until N to match mem[i]
        //     if (num[i] != mem[i]) {
        //         flip++;
        //         if (mem[i] == '1') {
        //             // Flip num[i] to N to '1'
        //             for (int change=i; change<mem.length(); change++) {
        //                 num[change] = '1';
        //             }
        //         } else {
        //             // Flip num[i] to N to '0'
        //             for (int change=i; change<mem.length(); change++) {
        //                 num[change] = '0';
        //             }
        //         }
        //     }
        // }
        // return flip;