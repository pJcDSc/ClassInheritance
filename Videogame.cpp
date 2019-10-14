/*
Author: Peter Jin
Date: 10/14/19
Videogame child class of Media
*/

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Videogame.h"

using namespace std;

//Constructor
Videogame::Videogame(char* title, int year, char* publisher, int rating) : Media(title, year) {
  this -> publisher = publisher;
  this -> rating = rating;
}

//Get publisher
char* Videogame::getPublisher() {
  return publisher;
}

//Get rating
int Videogame::getRating() {
  return rating;
}

//Get type
int Videogame::getType() {
  return 1;
}

//Destructor
Videogame::~Videogame() {
  delete publisher;
}
