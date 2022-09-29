#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class PartySeats
{
    public:
    vector<string> seating(vector<string> attendees)
    {
        vector<string> res;
        int N = attendees.size();
        int n = N/2;
        // Special cases: No way to alternate for odd number of people and if only 2 people
        if (N % 2 == 1 || N <= 2 || n % 2 == 1) 
        {
            return res;
        }
        // Split into boys and girls array
        vector<string> boys, girls;
        for (int i=0; i<N; i++) 
        {
            // Get the gender of the attendee
            int index = attendees[i].find(" ");
            // Get the name of the attendee
            string name = attendees[i].substr(0,index);
            if (attendees[i][index+1] == 'b') {
                boys.push_back(name);
            } else {
                girls.push_back(name);
            }
        }
        if (boys.size() % 2 == 1 || girls.size() % 2 == 1 || boys.size() != girls.size()) {
            return res;
        }
        // Arrange by alternating boys and girls up
        res.push_back("HOST");
        for (int j=0; j<N/4; j++) 
        {
            res.push_back(find(girls));
            girls = update(girls);
            res.push_back(find(boys));
            boys = update(boys);
        }
        // Sit HOSTESS across from HOST
        res.push_back("HOSTESS");
        // Add the rest of the attendees in alternate
        for (int k=0; k<N/4; k++)
        {
            res.push_back(find(boys));
            boys = update(boys);
            res.push_back(find(girls));
            girls = update(girls);
        }
        return res;
    }

    // Function to find earliest alphabetically
    string find(vector<string> names) 
    {
        // Initialise earliest to first name
        string currentMin = names[0];
        int minIndex = 0;
        // Iterate vector to find earliest alphabetically
        for (int i=1; i<names.size(); i++) 
        {
            // If no same letters
            if (names[i][0] < currentMin[0])
            {
                currentMin = names[i];
                minIndex = i;
            }
            // If same letters
            if (names[i][0] == currentMin[0]) 
            {
                // Check for shorter name
                if (names[i].length() < currentMin.length()) 
                {
                    // names[i] is shorter
                    int j = 1;
                    while(names[i][j] == currentMin[j]) 
                    {
                        // Continue checking until end of shorter name
                        if (j == names[i].length() && (names[i][j] == currentMin[j]))
                        {
                            // If reached end and no different alphabet,
                            // then names[i] comes first
                            currentMin = names[i];
                            minIndex = i;
                            break;
                        }
                        j++;
                    }
                    // Found different letter
                    if (names[i][j] < currentMin[j])
                    {
                        // If names[i] letter is earlier, then names[i] comes first
                        currentMin = names[i];
                        minIndex = i;
                    } // Otherwise, currentMin stays the same
                } else {
                    // CurrentMin is shorter
                    int j = 1;
                    while(names[i][j] == currentMin[j]) 
                    {
                        // Continue checking until end of shorter name
                        if (j == currentMin.length() && (names[i][j] == currentMin[j]))
                        {
                            // If reached end and no different alphabet,
                            // then currentMin comes first
                            break;
                        }
                        j++;
                    }
                    // Found different letter
                    if (names[i][j] < currentMin[j])
                    {
                        // If names[i] letter is earlier, then names[i] comes first
                        currentMin = names[i];
                        minIndex = i;
                    } // Otherwise, currentMin stays the same
                }
            }
        }
        // Update
        names[minIndex] = "~";
        // Return the earliest name alphabetically
        return currentMin;
    }

    // Function to update vector after getting earliest lexicogrpahically
    vector<string> update(vector<string> names) 
    {
        // Initialise earliest to first name
        string currentMin = names[0];
        int minIndex = 0;
        // Iterate vector to find earliest alphabetically
        for (int i=1; i<names.size(); i++) 
        {
            // If no same letters
            if (names[i][0] < currentMin[0])
            {
                currentMin = names[i];
                minIndex = i;
            }
            // If same letters
            if (names[i][0] == currentMin[0]) 
            {
                // Check for shorter name
                if (names[i].length() < currentMin.length()) 
                {
                    // names[i] is shorter
                    int j = 1;
                    while(names[i][j] == currentMin[j]) 
                    {
                        // Continue checking until end of shorter name
                        if (j == names[i].length() && (names[i][j] == currentMin[j]))
                        {
                            // If reached end and no different alphabet,
                            // then names[i] comes first
                            currentMin = names[i];
                            minIndex = i;
                            break;
                        }
                        j++;
                    }
                    // Found different letter
                    if (names[i][j] < currentMin[j])
                    {
                        // If names[i] letter is earlier, then names[i] comes first
                        currentMin = names[i];
                        minIndex = i;
                    } // Otherwise, currentMin stays the same
                } else {
                    // CurrentMin is shorter
                    int j = 1;
                    while(names[i][j] == currentMin[j]) 
                    {
                        // Continue checking until end of shorter name
                        if (j == currentMin.length() && (names[i][j] == currentMin[j]))
                        {
                            // If reached end and no different alphabet,
                            // then currentMin comes first
                            break;
                        }
                        j++;
                    }
                    // Found different letter
                    if (names[i][j] < currentMin[j])
                    {
                        // If names[i] letter is earlier, then names[i] comes first
                        currentMin = names[i];
                        minIndex = i;
                    } // Otherwise, currentMin stays the same
                }
            }
        }
        // Update
        names[minIndex] = "~";
        // Return the vector
        return names;
    }
};