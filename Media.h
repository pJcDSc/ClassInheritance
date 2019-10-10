#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media {

 public:

  //Constructor
  Media(char*, int);

  //Get title of Media
  char* getTitle();

  //Get year of Media
  int getYear();

  //Get type of Media
  virtual int getType();
  
  //Destructor
  virtual ~Media();
  
 private:

  int year;
  char* title;
  int type;
  
};  
  
#endif
