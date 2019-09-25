#include <iostream>
#include <cstring>
#include "Media.h"
//#include "Videogame.h"
//#include "Movie.h"
//#include "Music.h"

int main() {
  cout << "Hello World!" << endl;
  char* title = new char[20];
  strcpy (title, "hello!");
  Media* m = new Media(title, 2019);
  int a = m->getYear();
  char* b = m->getTitle();
  cout << a << ";;;" << b << endl;
  return 0;
}
