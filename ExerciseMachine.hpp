#include <string>
#include <tgmath.h>
using namespace std;

class ExerciseMachine
{
    public:
    int getPercentages(string time) {
        // Get hours, minutes and seconds
        string subHours = time.substr(0,2);
        string subMins = time.substr(3,2);
        string subSecs = time.substr(6,2);
        // Convert to float
        float hours = stof(subHours);
        float mins = stof(subMins);
        float secs = stof(subSecs); 
        // Convert total timeDisplay to seconds
        float total = (hours*60*60) + (mins*60) + secs;
        // Get timeDisplay to 1%
        float timeDisplay = total/100;
        // Get last digit of timeDisplay
        float last = getlast(timeDisplay);
        // Convert to whole number
        timeDisplay = makewhole(timeDisplay, last);
        // Find the number of timeDisplays percentages is displayed
        int display = (total / timeDisplay) - 1;
        return display;
    }

    // Function to get last digit
    float getlast(float timeDisplay) {
        // Get last digit of timeDisplay
        float temp = timeDisplay;
        // temp = ceil(temp*100.0)/100.0;
        // Convert to whole number and get the last digit
        while (remainder(temp,float(1)) != 0) {
            // Keep multiplying by 10 until becomes a whole number
            temp = temp*10;
        }
        float last = remainder(temp,10);
        return last;
    }

    // Function to turn decimal into whole number
    float makewhole(float timeDisplay, float last) {
        // If it is not a whole number, keep multiplying until it is a whole number
        while (remainder(timeDisplay,float(1)) != 0) {
            if  (remainder(float(last),float(2)) == 0) {
                // If it is even, multiply by 5 to get whole number, and update last
                timeDisplay = timeDisplay*5;
                last = getlast(timeDisplay);
            } else if (remainder(float(last),float(5)) == 0) {
                // If it is a multiple of 5, multiply by 2 to get whole number, and update last
                timeDisplay = timeDisplay*2;
                last = getlast(timeDisplay);
            } else {
                // Otherwise, only can multiply by 10 to get whole number, and update last
                if (ceil(timeDisplay*10*100.0)/100.0 != ceil(timeDisplay*100.0)/100.0) {
                    string num = to_string(round(timeDisplay));
                    string sub = num.substr(num.find('.'),num.find('.')+2);
                    if (sub[1] != '0') {
                        timeDisplay = timeDisplay*10;
                        last = getlast(timeDisplay);
                    } else {
                        timeDisplay = timeDisplay*10;
                        break;
                    }
                }
            }
        }
        return timeDisplay;
    }
};