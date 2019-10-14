/*
Author: Peter Jin
Date: 10/14/19
Movie child class of media
*/

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"

using namespace std;

//Constructor
Movie::Movie(char* title, int year, char* director, int duration, int rating) : Media(title, year) {
  this -> director = director;
  this -> rating = rating;
  this -> duration = duration;
}

//Get director
char* Movie::getDirector() {
  return director;
}

//Get rating
int
Movie::getRating() {
  return rating;
}

//Get duration
int Movie::getDuration() {
  return duration;
}

//Get type
int Movie::getType() {
  return 2;
}

//Destructor
Movie::~Movie() {
  delete director;
}
