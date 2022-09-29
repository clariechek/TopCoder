#include <vector>
#include <string>
using namespace std;

class RGBStreet
{
    public:
    int estimateCost(vector<string> houses)
    {
        // Convert values for first house to int
        vector<int> cost = convert(houses, 0);
        // Store first house values
        vector<vector<int>> m(houses.size(), vector<int>(3, 0));
        m[0][0] = cost[0];
        m[0][1] = cost[1];
        m[0][2] = cost[2];

        // cout << m[0][0] << " " << m[0][1] << " " << m[0][2] << endl;
        
        for (int house=1; house<houses.size(); house++) 
        {
            // Convert values of current house
            cost = convert(houses, house);
            m[house][0] = min(m[house-1][1], m[house-1][2]) + cost[0];
            m[house][1] = min(m[house-1][0], m[house-1][2]) + cost[1];
            m[house][2] = min(m[house-1][0], m[house-1][1]) + cost[2];
            // cout << m[house][0] << " " << m[house][1] << " " << m[house][2] << endl;
        }
        int lastCol = houses.size()-1;
        int minimum = min(m[lastCol][0], min(m[lastCol][1], m[lastCol][2]));

        return minimum;
        // return 0;
    }

    int min(int num1, int num2) 
    {
        return (num1 < num2) ? num1 : num2;
    }

    // Function that converts costs of r,g,b paint of house i 
    // and returns the cost in a vector
    vector<int> convert(vector<string> houses, int h) 
    {
        vector<int> cost;

        // Separate values for r, g, b
        int pos = houses[h].find(" ");
        string r = houses[h].substr(0, pos);
        string rem = houses[h].substr(pos+1, houses[h].length());
        string g = rem.substr(0, rem.find(" "));
        string b = rem.substr(rem.find(" ")+1, rem.length());

        // Convert to int and store in vector
        cost.push_back(stoi(r));
        cost.push_back(stoi(g));
        cost.push_back(stoi(b));

        return cost;
    }
};