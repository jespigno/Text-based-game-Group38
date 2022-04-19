#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"


//printstats Function
//takes in a struct of type Player where it can read the player's stats.
//no output, however it prints out relevant status features.
void printstats(Player x){
  char tempkey;
  cout<< "Ghosthunter Licence\nGhosthunter name:" << x.info.myname<<endl;
  cout << "Current Health: "<< x.stats.mycurrenthealth << "/" << x.stats.maxhealth << endl;
  cout << "Strength: " << x.stats.myattack<<endl;
  cout << "Defense: " << x.stats.mydefense<<endl;
  cout << "Speed: "  << x.stats.myspeed<<endl;
  cout << "Money in bank account: " << x.stats.mymoney<<endl;
  cout << "Press any key to continue";
  cin >> tempkey;
  ClearScreen();

}
