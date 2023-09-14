#include <iostream>
#include <map>
#include <limits>
#include "common.h"

using namespace std;

extern map<int, map<int, float>> ratings;

float movieRate(int userID, int movieID);



int main(int argc, char* argv[])
{

    if(argc != 3)
    {
        cerr << "Format: MovieRate [UserID] [MovieID]" << endl;
        return 1;
    }

    int userID = atoi(argv[1]);
    int movieID = atoi(argv[2]);

    if(!isUserID(userID))
    {
        cerr << "User id out of bounds." << endl;
        return 1;
    }
    if (!isMovieID(movieID))
    {
        cerr << "Movie id out of bounds." << endl;
        return 1;
    }

    if(parser() == -1)
    {
        cerr << "Parsing error." << endl;
        return 1;
    }
    
    movieRate(userID, movieID);

    return 0;
}


float movieRate(int userID, int movieID)
{
    int simUser = -1;
    float minDist = numeric_limits<float>::max();

    for (const auto& pair : ratings)
    {
        int userID1 = pair.first;
        map<int, float>& userRatings1 = ratings[userID1];

        if (userID1 == userID)
            continue;

        if (userRatings1.find(movieID) != userRatings1.end())
        {
            float dist = ratingDistance(userID, userID1);
            if(dist < minDist && dist >= 0)
            {
                simUser = userID1;
                minDist = dist;
            }
        }

    }

    if(simUser == -1)
    {
        cout << "No similar user found." << endl;
        return -1.0;
    }
    else
    {
        float predictedRating = ratings[simUser][movieID];
        cout << "The predicted rating for UserID: " << userID 
        << " and MovieID: " << movieID << " is " << predictedRating 
        << " based on the most similar user: " << simUser << 
        " with a rating distance: " << minDist << endl;
        return predictedRating;
    }
}