#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

//Constructor
Music::Music(char* title, int year, char* artist, char* publisher, int duration) : Media(title, year) {
  cout << "Music constructor called" << endl;
  this -> artist = artist;
  this -> publisher = publisher;
  this -> duration = duration;
}

//Get publisher
char* Music::getPublisher() {
  return publisher;
}

//Get artist
char* Music::getArtsit() {
  return artist;
}

//Get duration
int Music::getDuration() {
  return duration;
}

//Get type
int Music::getType() {
  return 3;
}

//Destructor
Music::~Music() {
  cout << "Music deconstructor called" << endl;
  delete artist;
  delete publisher;
}
  
