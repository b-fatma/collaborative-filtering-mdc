#compiler
CXX = g++ -O3

#dependencies
COMMON_SRC = common.cpp common.h
RATING_DISTANCE_SRC = RatingDistance.cpp $(COMMON_SRC)
MOVIE_RATE_SRC = MovieRate.cpp $(COMMON_SRC)


#targets
all: RatingDistance MovieRate

RatingDistance: $(RATING_DISTANCE_SRC)
	$(CXX) -o RatingDistance $(RATING_DISTANCE_SRC)

MovieRate: $(MOVIE_RATE_SRC)
	$(CXX) -o MovieRate $(MOVIE_RATE_SRC)

clean:
	rm -f RatingDistance MovieRate

.PHONY: all clean
