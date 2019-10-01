#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media {

 public:

  //Constructor
  Movie(char*, int, char*, int, int);

  //Override getType
  int getType();

  //Get director
  char* getDirector();

  //Get rating
  int getRating();

  //Get duration
  int getDuration();

  //Destructor
  ~Movie();
  
 private:

  int rating;
  int duration;
  char* director;

};
  
