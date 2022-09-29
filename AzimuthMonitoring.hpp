#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AzimuthMonitoring
{
    public:
    int getAzimuth(vector<string> instructions) {
        int pos = 0;
        string strNum = "";
        bool mix = false;
        int num;  
        
        for (int i=0; i<instructions.size(); i++) {
            // Reset
            strNum = "";
            mix = false;
            // cout << "Instruction " << i+1 << " " << instructions[i] << endl; 
            // End if instruction is HALT
            if (instructions[i] == "HALT") {
                break;
            }

            // Check if there is number in string
            for (int j=0; j<instructions[i].length(); j++) {
                // cout << "Instruction i j " << instructions[i][j] << endl;
                if (isdigit(instructions[i][j])) {
                    // cout << "It is a digit" << endl;
                    strNum += instructions[i][j];
                    // cout << "strNum " << strNum << endl;
                    mix = true;
                }
            }

            if (mix == true) {
                num = stoi(strNum);
                if (instructions[i][0] == 'L') {
                    // If left then minus the value
                    pos -= num;
                    // cout << "L so minus " << num << " pos is " << pos << endl;
                } else {
                    // If right then add the value
                    pos += num;
                    // cout << "R so add " << num << " pos is " << pos << endl;
                }
            }
            
            // Otherwise, it is a standard valued instruction (LEFT, RIGHT, TURN AROUND)
            if (instructions[i] == "LEFT") {
                pos -= 90;
                // cout << "LEFT so minus 90 " << " pos is " << pos << endl;
            } else if (instructions[i] == "RIGHT") {
                pos += 90;
                // cout << "RIGHT so add 90 " << " pos is " << pos << endl;
            } else if (instructions[i] == "TURN AROUND") {
                pos +=180;
                // cout << "TURN AROUND so add 180 " << " pos is " << pos << endl;
            }
        }

        // Check if result is negative or more than 360
        // Add 360 until no longer negative
        while (pos < 0) {
            pos += 360;
            // cout << "POS < 0 so add 360 " << " pos is " << pos << endl;
        }
        // Deduct 360 until < 360
        while (pos > 360) {
            pos -= 360;
            // cout << "POS > 360 so minus 360 " << " pos is " << pos << endl;
        }
        if (pos == 360) {
            pos = 0;
        }
        return pos;
    }
};

// // Check for LEFT x and RIGHT x instructions
            // if (isdigit(instructions[i][4]) || isdigit(instructions[i][5])) {
            //     for (string::iterator j=instructions[i].begin(); j<instructions[i].end(); j++) {
            //         if (isdigit(instructions[i][j])) {
            //             // if there is a digit then find the length of the digit
            //             length = instructions[i].end() - j;
            //             // Copy number value and convert to int
            //             strNum = substr(j, length);
            //             num = stoi(strNum);
            //         }
            //     }
            //     // Check if left then minus the digit, if right then add the digit.
            //     if (instructions[i][0] == 'L') {
            //         pos -=num;
            //     } else {
            //         pos +=num;
            //     }
            // }