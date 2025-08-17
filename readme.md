# Collaborative Filtering (cf-mdc)

A simple C++ implementation of user-based collaborative filtering for movie rating prediction using the MovieLens 10M dataset.

## Features

- Predicts movie ratings for a user based on similar users.
- Calculates rating distance between users.
- Command-line tools for prediction and distance calculation.

## Usage

1. Place `ratings.dat` in the project directory.
2. Compile:
    ```sh
    g++ -o MovieRate MovieRate.cpp common.cpp
    g++ -o RatingDistance RatingDistance.cpp common.cpp
    ```
3. Run:
    ```
    ./MovieRate [UserID] [MovieID]
    ./RatingDistance [UserID1] [UserID2]
    ```
