/*
Author: Peter Jin
Date: 10/14/19
Videogame header child class of media
*/

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Videogame : public Media{

 public:

  //Constructor
  Videogame(char*, int, char*, int);

  //Override getType
  int getType();

  //Get publisher
  char* getPublisher();
  
  //Get rating
  int getRating();

  //Destructor
  ~Videogame();

 private:

  int rating;
  char* publisher;

};

  


