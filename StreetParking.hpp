#include <iostream>
#include <string>

using namespace std;

class StreetParking 
{
    public:
    int freeParks(string street) {
        int free = 0;
        bool none = true;
        for (int i=0; i<street.length(); i++) {
            // If only letters then no free parks
            if (street[i] == '-') {
                none = false;
            }
        }
        if (none == true) {
            return 0;
        }
        for (int i=0; i<street.length(); i++) {
            // Check for before Bus stop
            if (street[i] == 'B' && i == 1) {
                if (street[i-1] == '-') {
                    street[i-1] = '0';
                }
            }
            if (street[i] == 'B' && i > 1) {
                if (street[i-1] == '-') {
                    street[i-1] = '0';
                }
                if (street[i-2] == '-') {
                    street[i-2] = '0';
                }
            }
            // Check for before side street
            if (street[i] == 'S' && i==0) {
                if (street[i+1] == '-') {
                    street[i+1] = '0';
                }
            }
            if (street[i] == 'S' && i>0 && i<street.length()-1) {
                if (street[i+1] == '-') {
                    street[i+1] = '0';
                }
                if (street[i-1] == '-') {
                    street[i-1] = '0';
                }
            }
            if (street[i] == 'S' && i==street.length()-1) {
                if (street[i-1] == '-') {
                    street[i-1] = '0';
                }
            }   
        }
        // Calculation number of free parking
        for (int i=0; i<street.length(); i++) {
            if (street[i] == '-') {
                free++;
            }
        } 
        return free;
    }
};