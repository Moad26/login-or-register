#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

int regist() {
  string name;
  string password;
  string confpass = "";
  string line;
  string compare;
  ofstream myfile;
  ifstream readfile("data.csv");


  myfile.open("data.csv", ios::app);
  if (!myfile) {
    cerr << "error opening the file" << endl;
    return 0;
  }


  cout << "give name" << endl;
  cin >> name;
  cout << "give password" << endl;
  cin >> password;
  cout << "confirm password" << endl;


  do {
    cin >> confpass;
  } while (password != confpass);


  compare = name + "," + password;
  while (getline(readfile, line)) {
    if (compare == line) {
      cout << "you alredy exist";
      return 0;
    }
  }


  myfile << name << "," << password << endl;
  myfile.close();
  readfile.close();
  return 0;
}

int login() {
  string name;
  string password;
  string compare;
  string line;
  ifstream myfile("data.csv");
  if (!myfile) {
    cerr << "error opening the file" << endl;
    return 0;
  }
  cout << "give name" << endl;
  cin >> name;
  cout << "give password" << endl;
  cin >> password;
  compare = name + "," + password;
  while (getline(myfile, line)) {
    if (compare == line) {
      cout << "you got access" << endl;
      return 0;
    }
  }
  cout << "you don't det access" << endl;
  myfile.close();
  return 0;
}

int main() {
  int b;
  cout << "login or register, 1 or 0" << endl;
  cin >> b;
  switch (b) {
  case 1:
    login();
    break;
  case 0:
    regist();
    break;
  }
  return 0;
}
