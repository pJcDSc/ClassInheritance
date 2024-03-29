/*
Author: Peter Jin
Date: 10/13/19
Media database with add, delete, search, and quit function
*/
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
void printMedia(Media*);

using namespace std;

int main() {
  cout << "Welcome to Media databest." << endl;
  cout << "Type \"h\" for help." << endl;

  /* I realized this isn't needed but I'll keep it in incase it is
  //Configure cout to show 2 decimal points
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  */

  //Create media vector, and pointer to media vector
  vector <Media*> medList;
  vector <Media*>* mediaList = &medList;

  //While running (quit isn't called) read and parse input
  bool running = true;
  while(running) {
    //Normalize input, clear extra garbage input
    char input[10] = "";
    cin.get(input, 10);
    cin.clear();
    cin.ignore(999, '\n');

    //Parse input and pass in media vector
    running = parse(input, mediaList);
  }
  
  return 0;
}

//Calls functions based on input value
bool parse (char* input, vector<Media*>* v) {
  //Convert all characters to uppercase
  for (int i = 0; i < strlen(input); i++){
    input[i] = toupper(input[i]);
  }
  if (strcmp("H", input) == 0 || strcmp("HELP", input) == 0) {
    printHelp();
  } else if (strcmp("ADD", input) == 0) {
    add (v);
  } else if (strcmp("DELETE", input) == 0) {
    del (v);
  } else if (strcmp("SEARCH", input) == 0) {
    search(v);
  } else if (strcmp("QUIT", input) == 0) {
    // Return false in order to quit
    quit();
    return false;
  } else {
    cout << "Input not recognized: " << input << endl;
  }
  return true;
}
void add (vector<Media*>* v) {
  cout << "Type \"1\" for Videogame, \"2\" for Movie, and \"3\" for Music." << endl;

  //Prompt user for type of media
  bool accept = false;
  int type = 0;
  while(!accept){
    cin >> type;
    cin.clear();
    cin.ignore(999, '\n');

    //Only accept 1, 2, or 3
    if (type > 3 || type < 1) {
      cout << "Please enter \"1\", \"2\", or \"3\"." << endl;
    } else accept = true;
  }

  //Call separate adding functions for each type
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
  cout << "Delete by Year or Title, or delete all? (y/t/a)" << endl;

  //Get user input for delete mode
  char mode = ' ';
  bool accepted = false;
  while(!accepted) {
    cin >> mode;
    cin.clear();
    cin.ignore(999, '\n');

    //Only accept y, t, and a
    if (mode == 'y' || mode == 't' || mode == 'a') {
      accepted = true;
    } else {
      cout << "Please enter either 'y', 't' or 'a'" << endl;
    }
  }

  //Prompt user for search term (unless deleting all)
  char search[80] = "";
  if (mode != 'a') {
    cout << "Please enter the deletion search term." << endl;
    cin.get(search, 80);
    cin.clear();
    cin.ignore();
  }

  //Iterate through list, and print all the ones that will be deleted
  bool anyFound = false;
  vector<Media*>::iterator it = v -> begin();
  while (it != v -> end()){
    if (mode == 'y' && (*it) -> getYear() == strToInt(search) || mode == 't' && strcmp((*it)->getTitle(), search) == 0 || mode == 'a') {
      if(!anyFound) {
	anyFound = true;
	cout << endl << "These medias were found:" << endl << endl;
      }
      printMedia(*it);
    }
    ++it;
  }
  //If no medias are found return, nothing is going to be deleted
  if(!anyFound) {
    cout << "No medias were found matching the search term." << endl;
    return;
  }
  cout << "Delete these medias? (y/n)" << endl;

  //Verify that user wants delete the medias
  char answer = ' ';
  accepted = false;
  while (!accepted) {
    cin >> answer;
    cin.clear();
    cin.ignore(999, '\n');

    //Only accept y and n
    if (answer == 'n' || answer == 'y') {
      accepted = true;
    } else {
      cout << "Please enter either 'y' or 'n'" << endl;
    }
  }

  //If they don't want to delete return
  if (answer == 'n') {
    cout << "Deletion canceled." << endl;
    return;
  } else {
    //Otherwise notify that medias are being deleted
    int delCount = 0;
    cout << "Deleting..." << endl;
    it = v -> begin();

    //Use modified iterator loop to delete
    while (it != v -> end()){
      if (mode == 'y' && (*it) -> getYear() == strToInt(search) || mode == 't' && strcmp((*it)->getTitle(), search) == 0 || mode == 'a') {
	//Delete value of pointer
	delete *it;
	//Remove pointer from vector
	it = v -> erase(it);
	//Count number of deleted items
	++delCount;
      } else {
	++it;
      }
    }
    cout << "Succesfully deleted " << delCount << " media(s)." << endl; 
  }

}

void search (vector<Media*>* v) {
  cout << "Search by Year or Title, or print all? (y/t/a)" << endl;

  //Prompt for search type
  char mode = ' ';
  bool accepted = false;
  while(!accepted) {
    cin >> mode;
    cin.clear();
    cin.ignore(999, '\n');

    //Only accept y, t, and a
    if (mode == 'y' || mode == 't' || mode == 'a') {
      accepted = true;
    } else {
      cout << "Please enter either 'y', 't' or 'a'" << endl;
    }
  }

  //Prompt for search term if not a
  char search[80] = "";
  if (mode != 'a') {
    cout << "Please enter the search term." << endl;
    cin.get(search, 80);
    cin.clear();
    cin.ignore();
  }

  //Iterate through vector and print matching search terms
  bool anyFound = false;
  vector<Media*>::iterator it = v -> begin();
  while (it != v -> end()){
    if (mode == 'y' && (*it) -> getYear() == strToInt(search) || mode == 't' && strcmp((*it)->getTitle(), search) == 0 || mode == 'a') {
      if(!anyFound) {
	anyFound = true;
	cout << endl << "These medias were found:" << endl << endl;
      }
      printMedia(*it);
    }
    ++it;
  }
  //If no medias found say so
  if(!anyFound) {
    cout << "No medias were found matching the search term." << endl;
  }
}

//Print help: prints commands that are in the program
void printHelp() {
  cout << "HELP MANUAL:" << endl;
  cout << "Type \"ADD\" to add a media to the database" << endl;
  cout << "Type \"DELETE\" to delete medias from the database" << endl;
  cout << "Type \"SEARCH\" to search for medias in the database" << endl;
  cout << "Type \"QUIT\" to exit the program" << endl;
}

//Print quit message
void quit() {
  cout << "Thank you for using Media database. " << endl;
}

//Function to get input for videogame fields
void addVideogame(vector <Media*>* v){
  char* title = new char[60];
  int year;
  char* publisher = new char[40];
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

//Function to get input for Movie fields
void addMovie(vector <Media*>* v) {
  char* title = new char[60];
  int year;
  char* director = new char[40];
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

//Function to get input for Music fields
void addMusic(vector <Media*>* v) {
  char* title = new char[60];
  int year;
  char* artist = new char[40];
  char* publisher = new char[40];
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

//Function which converts char array to int 
int strToInt(char* c) {
  int total = 0;
  for(int i = 0; i < strlen(c); i++){
    total *= 10;
    total += c[i] - '0';
  }
  return total;
}

//Print fields in media based on getType
void printMedia(Media* m) {
  //Switch off of type of media
  switch(m -> getType()) {
    //Print respective fields
    case(VI):
      {
      Videogame* v = (Videogame*)(m);
      cout << "Videogame: \"" << v -> getTitle() << "\"" << endl;
      cout << "Year: " << v -> getYear() << endl;
      cout << "Publisher: " << v -> getPublisher() << endl;
      cout << "Rating: " << v -> getRating() << endl << endl;;
      break;
      }
    case(MO):
      {
      Movie* mo = (Movie*)(m);
      cout << "Movie: \"" << mo -> getTitle() << "\"" << endl;
      cout << "Year: " << mo -> getYear() << endl;
      cout << "Director: " << mo -> getDirector() << endl;
      cout << "Duration: " << mo -> getDuration() << endl;
      cout << "Rating: " << mo -> getRating() << endl << endl;
      break;
      }
    case(MU):
      {
      Music* mu = (Music*)(m);
      cout << "Music: \"" << mu -> getTitle() << "\"" << endl;
      cout << "Year: " << mu -> getYear() << endl;
      cout << "Artist: " << mu -> getArtist() << endl;
      cout << "Publisher: " << mu -> getPublisher() << endl;
      cout << "Duration: " << mu -> getDuration() << endl << endl;
      break;
      }
  }
}
