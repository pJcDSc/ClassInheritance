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
  cout << "Media constructor called" << endl;
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
  cout << "Media destructor Called" << endl;
  delete[] title;
}




