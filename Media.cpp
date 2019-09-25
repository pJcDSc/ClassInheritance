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
  return type;
}

Media::~Media() {
  delete[] title;
}




