#define ME 0
#define VI 1
#define MO 2
#define MU 3
#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Videogame.h"
#include "Movie.h"
#include "Music.h"

void printHelp();
bool parse (char*, vector<Media*>*);
void add (vector <Media*>*);
void search (vector <Media*>*);
void del (vector <Media*>*);
void quit ();
void addMovie(vector <Media*>*);
void addVideogame(vector <Media*>*);
void addMusic(vector <Media*>*);

using namespace std;

int main() {
  cout << "Welcome to Media databest." << endl;
  cout << "Type \"h\" for help." << endl;

  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);

  vector<Media*>* mediaList = new vector<Media*>;
  
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

bool parse (char* input, vector<Media*>* v) {
  cout << "Parse called" << endl;
  if (strcmp("H", input) == 0 || strcmp("h", input) == 0) {
    cout << "Help Call" << endl;
    printHelp();
  } else if (strcmp("ADD", input) == 0) {
    cout << "Add Call" << endl;
    add (v);
  } else if (strcmp("DELETE", input) == 0) {
    cout << "Delete Call" << endl;
    del (v);
  } else if (strcmp("SEARCH", input) == 0) {
    cout << "Search Call" << endl;
    search(v);
  } else if (strcmp("QUIT", input) == 0) {
    cout << "Quit Call" << endl;
    quit();
    return false;
  } else {
    cout << "Input not recognized: " << input << endl;
  }
  return true;
}

void add (vector<Media*>* v) {
  cout << "Add function enter" << endl;
  cout << "Type \"1\" for Videogame, \"2\" for Movie, and \"3\" for Music." << endl;

  bool accept = false;
  int type = 0;
  while(!accept){
    cin >> type;
    cin.clear();
    cin.ignore(999, '\n');
    
    if (type > 3 || type < 1) {
      cout << "Please enter \"1\", \"2\", or \"3\"." << endl;
    } else accept = true;
  }

  switch (type) {
    case(1):
      addVideogame(v);
      break;
   
  }
}

void del (vector<Media*>* v) {
  cout << "Del function enter" << endl;
}

void search (vector<Media*>* v) {
  cout << "Search function enter" << endl;
}

void printHelp() {
  cout << "TODO help" << endl;
}

void quit() {
  cout << "Quit function enter" << endl;
}

void addVideogame(vector <Media*>* v){
  char title[60];
  int year;
  char publisher[40];
  int rating;
  cout << "Please enter title" << endl;
  cin.get(title, 60);
  cin.get();
  cout << "Please enter year" << endl;
  cin >> year;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Please enter the publisher" << endl;
  cin.get(publisher, 40);
  cin.get();
  cout << "Please enter the rating" << endl;
  cin >> rating;
  cin.clear();
  cin.ignore(999, '\n');
  v -> push_back(new Videogame(title, year, publisher, rating));
  return;
}
