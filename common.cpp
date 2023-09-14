#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include "common.h"

using namespace std;

const int USERS = 71567;
const int MOVIES = 65133;
 
map<int, map<int, float>> ratings; //the data structure to store the ratings

int parser()
{
    ifstream f("ratings.dat");
    if (!f.is_open())
    {
        cerr << "Error opening file: ratings.dat" << endl;
        return -1;
    }

    string line;
    int userID, movieID;
    float rating;

    int count = 0;

    while (getline(f, line))
    {
        if (sscanf(line.c_str(), "%d::%d::%f::%*s", &userID, &movieID, &rating) == 3)
        {
            ratings[userID][movieID] = rating;
            count++;
        }
        else
        {
            cerr << "Error parsing" << endl;
            f.close();
            return -1;
        }
    }

    f.close();
    return count;
}


//implementation of the rating distance function
float ratingDistance(int userID1, int userID2)
{
    map<int, float>& user1Ratings = ratings[userID1];
    map<int, float>& user2Ratings = ratings[userID2];

    float totalDifference = 0.0;
    int commonMovies = 0;

    for (const auto& pair : user1Ratings)
    {
        int movieID = pair.first;
        float rating1 = pair.second;

        if (user2Ratings.find(movieID) != user2Ratings.end())
        {
            totalDifference += fabs(rating1 - user2Ratings[movieID]);
            commonMovies++;
        }
    }

    if (commonMovies > 0)
        return totalDifference / commonMovies;
    else
        return -1.0;
}

int isUserID(int userID)
{
    if(!(userID > 0 && userID <= USERS))
        return 0;
    return 1;
}

int isMovieID(int movieID)
{
    if(!(movieID > 0 && movieID <= MOVIES))
        return 0;
    return 1;
}