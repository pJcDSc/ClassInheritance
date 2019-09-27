#define ME 0
#define VI 1
#define MO 2
#define MU 3
#include <iostream>
#include <cstring>
#include "Media.h"#include "Videogame.h"
//#include "Movie.h"
//#include "Music.h"

void printHelp();
bool parse (char*, vector<Media*>*);
void 

int main() {
  cout << "Welcome to Media databest." << endl;
  cout << "Type \"h\" for help." << endl;

  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.prescision(2);

  bool running = true;
  while(running) {
    char input[10] = "";
    cin.get(input, 10);
    cin.clear();
    cin.ignore(999, '\n');

    running = parse(input, mediaList);
  }
  
  return 0;
}
