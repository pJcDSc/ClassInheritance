/*
Author: Peter Jin
Date: 10/14/19
Music header child class of Media
*/

#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media {

 public:

  //Constructor
  Music(char*, int, char*, char*, int);

  //Override getType
  int getType();

  //Get artist
  char* getArtist();

  //get publisher
  char* getPublisher();

  //get duration
  int getDuration();

  //Destructor
  ~Music();
  
 private:

  int duration;
  char* artist;
  char* publisher;

};
