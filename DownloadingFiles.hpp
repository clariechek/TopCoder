#include <vector>
#include <iostream>
using namespace std;

class DownloadingFiles {
    public:
    double actualTime(vector<string> tasks) {
        double totalBandwidth = 0;
        double totalFilesSize = 0;
        string speed = "";
        string time = "";

        for (int i=0; i<tasks.size(); i++) {
            speed = tasks[i].substr(0, tasks[i].find(" "));
            time = tasks[i].substr(tasks[i].find(" "),tasks[i].length());
            totalBandwidth += stoi(speed);
            totalFilesSize += stoi(time)*stoi(speed);
            // cout << "speed: " << speed << " time: " << time << " totalBandwidth: " << totalBandwidth << " totalFilesSize: " << totalFilesSize <<endl;
        }
        return totalFilesSize/totalBandwidth;
    }
};