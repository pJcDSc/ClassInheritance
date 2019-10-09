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

int strToInt(char*);
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

  vector <Media*> medList;
  vector <Media*>* mediaList = &medList;
  
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
  for (int i = 0; i < strlen(input); i++){
    input[i] = toupper(input[i]);
  }
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
    case(2):
      addMovie(v);
      break;
    case(3):
      addMusic(v);
      break;
  }
}

void del (vector<Media*>* v) {
  cout << "Del function enter" << endl;
}

void search (vector<Media*>* v) {
  cout << "Search by Year or Title? (y/t)" << endl;

  char mode = ' ';
  bool accepted = false;
  while(!accepted) {
    cin >> mode;
    cin.clear();
    cin.ignore(999, '\n');

    if (mode == 'y' || mode == 't') {
      accepted = true;
    } else {
      cout << "Please enter either 'y' or 't'" << endl;
    }
  }

  cout << "Please enter the search term." << endl;
  char search[80] = "";
  cin.get(search, 80);
  cin.clear();
  cin.ignore();
  
  vector<Media*>::iterator it;

  cout << "Got here" << endl;
  
  while (it != v -> end()){
    cout << "Getting there" << endl;
    // if (mode == 'y' && (*it) -> getYear() == strToInt(search) || mode == 't' && strcmp((*it)->getTitle(), search) == 0) {
    //cout << "Mathced:!" << endl;
    // }
    cout << "Here" << endl;
    cout << (mode == 'y') << endl;
    cout << "There" << endl;
    cout << v -> at(0) -> getYear() << endl;
    cout << ((*it) -> getYear() == 5/*strToInt(search)*/) << endl;
    cout << (mode == 't') << endl;
    cout << (strcmp((*it)->getTitle(), search) == 0) << endl;
  }
}

void printHelp() {
  cout << "HELP MANUAL:" << endl;
  cout << "Type \"ADD\" to add a media to the database" << endl;
  cout << "Type \"DELETE\" to delete medias from the database" << endl;
  cout << "Type \"SEARCH\" to search for medias in the database" << endl;
  cout << "Type \"QUIT\" to exit the program" << endl;
}

void quit() {
  cout << "Thank you for using Media database. " << endl;
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
  cout << "Videogame \"" << title << "\" has been added to the list." << endl;
  return;
}

void addMovie(vector <Media*>* v) {
  char title[60];
  int year;
  char director[40];
  int duration;
  int rating;
  cout << "Please enter the title" << endl;
  cin.get(title, 60);
  cin.get();
  cout << "Please enter the year" << endl;
  cin >> year;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Please enter the director" << endl;
  cin.get(director, 40);
  cin.get();
  cout << "Please enter the duration" << endl;
  cin >> duration;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Please enter the rating" << endl;
  cin >> rating;
  cin.clear();
  cin.ignore(999, '\n');
  v -> push_back(new Movie(title, year, director, duration, rating));
  cout << "Movie \"" << title << "\" has been added to the list." << endl;
}

void addMusic(vector <Media*>* v) {
  char title[60];
  int year;
  char artist[40];
  char publisher[40];
  int duration;
  cout << "Please enter the title" << endl;
  cin.get(title, 60);
  cin.get();
  cout << "Please enter the year" << endl;
  cin >> year;
  cin.clear();
  cin.ignore(999, '\n');
  cout << "Please enter the artist" << endl;
  cin.get(artist, 40);
  cin.get();
  cout << "Please enter the publisher" << endl;
  cin.get(publisher, 40);
  cin.get();
  cout << "Please enter the duration" << endl;
  cin >> duration;
  cin.clear();
  cin.ignore(999, '\n');
  v -> push_back(new Music(title, year, artist, publisher, duration));
  cout << "Music \"" << title << "\" has been added to the list." << endl;
}

int strToInt(char* c) {
  int total = 0;
  for(int i = 0; i < strlen(c); i++){
    total *= 10;
    total += c[i] - '0';
  }
  return total;
}
