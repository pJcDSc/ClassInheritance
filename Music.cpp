/*
Author: Peter Jin
Date: 10/14/19
Music child class of Media
*/

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

//Constructor
Music::Music(char* title, int year, char* artist, char* publisher, int duration) : Media(title, year) {
  this -> artist = artist;
  this -> publisher = publisher;
  this -> duration = duration;
}

//Get publisher
char* Music::getPublisher() {
  return publisher;
}

//Get artist
char* Music::getArtist() {
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
  delete artist;
  delete publisher;
}
  
