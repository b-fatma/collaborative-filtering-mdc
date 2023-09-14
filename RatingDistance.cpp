#include <iostream>
#include <map>
#include <cmath>
#include "common.h"

using namespace std;

extern map<int, map<int, float>> ratings;

int main(int argc, char* argv[])
{

    if(argc != 3)
    {
        cerr << "Format: RatingDistance [UserID1] [UserID2]" << endl;
        return 1;
    }

    int userID1 = atoi(argv[1]);
    int userID2 = atoi(argv[2]);

    if(!isUserID(userID1))
    {
        cerr << "User 1 id out of bound." << endl;
        return 1;
    }
    if (!isUserID(userID2))
    {
        cerr << "User 2 id out of bound." << endl;
        return 1;
    }

    if(parser() == -1)
    {
        cerr << "Parsing error." << endl;
        return 1;
    }

    
    float ratingDist = ratingDistance(userID1, userID2);
    if(ratingDist == -1.0)
    {
        cout << "No common movies between users." << endl;
    }
    else
    {
        cout << "The rating distance is: " << ratingDist << endl;
    }
    return 0;
}

