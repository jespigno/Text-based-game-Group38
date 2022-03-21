
// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
  string line;
  ifstream myfile ("example.txt");
  ifstream datfile ("character.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  if (datfile.is_open())
  {
    while ( getline (datfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";
  cout << "WATER GHOST"<<endl<<"I AM GOING TO DEVOUR YOUR SOUL"<<endl<< "COME!";
  return 0;
}
