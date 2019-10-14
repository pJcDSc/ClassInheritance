/*
Author: Peter Jin
Date: 10/14/19
Media parent class
*/

#define ME 0
#define VI 1
#define MO 2
#define MU 3
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//Constructor
Media::Media(char* title, int year) {
  this -> title = title;
  this -> year = year;
}

//Get title 
char* Media::getTitle() {
  return title;
}

//Get year
int Media::getYear() {
  return year;
}

//Get type of media
int Media::getType() {
  //To be overriden by children classes
}

//Destructor 
Media::~Media() {
  delete[] title;
}




