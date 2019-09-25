#include <iostream>
#include <cstring>

using namespace std;

class Media {

 public:

  //Constructor
  Media(char[20], int);

  //Get title of Media
  char* getTitle();

  //Get year of Media
  int getYear();

  //Get type of Media
  int getType();
  
  //Destructor
  ~Media();

  
  
 private:

  int year;
  char* title;
  int type;
  
};  
  
