#include <chrono>
#include <thread>
#include <string>
using namespace std::this_thread;
using namespace std::chrono;
#include <iostream>
#include <fstream>
using namespace std;
#include "TimeIntervals.h"







// twosecsleep function
// has no input parameters and is void. It provides a two second pause.
//It is useful when displaying sprites to the user.
void twosecsleep(){//pause of two seconds
  sleep_for(nanoseconds(2000000000));
}


// onesecsleep function
// has no input parameters and is void. It provides a one second pause.
//It is useful when displaying sprites to the user.
void onesecsleep(){
  sleep_for(nanoseconds(1000000000));
}


// halfasecsleep function
// has no input parameters and is void. It provides half a second pause.
//It is useful when displaying sprites to the user.
void halfasecsleep(){
  sleep_for(nanoseconds(1000000000/2));
}


// fivesecsleep function
// has no input parameters and is void. It provides a five second pause.
//It is useful when displaying sprites to the user.
void fivesecsleep(){
  sleep_for(nanoseconds(5000000000));
}

// tensecsleep function
// has no input parameters and is void. It provides a five second pause.
//It is useful when displaying sprites to the user.
void tensecsleep(){
  sleep_for(nanoseconds(10000000000));
}

//ClearScreen Function
//Has no input and is void. Prints out many \n to make the screen empty and improve readability.
void ClearScreen(){
  for (int i = 0; i < 5; i++){
    cout<< "\n\n\n\n\n\n";
  }
}

//Function takes a struct of type Player as an input, outputs nothing as it is void
//This function will alter the values of the inputed struct and replace them with the ones found in a text file
//This is useful for game loading purposes
void loadvalues(Player &x){
  ifstream loadfromfile;
  loadfromfile.open("Savefile.txt");
  if ( loadfromfile.fail() ){
		cout << "No save file found, sorry!"
			<< endl;
 		exit(1);
 	}
  loadfromfile >> x.stats.level >> x.stats.maxhealth >> x.stats.mycurrenthealth >> x.stats.mydefense >> x.stats.myattack >> x.stats.myspeed >> x.stats.mymoney >> x.stats.experiencepoints;
  loadfromfile >> x.stats.attackone >> x.stats.attacktwo >> x.stats.attackthree;
  loadfromfile >> x.info.myname >> x.info.catnumber >> x.info.amountoffurniture >> x.info.boughtcatcafe >> x.info.level1complete >> x.info.level2complete >> x.info.level3complete >> x.info.level4complete >> x.info.level5complete;
  x.info.firsttime = 0;
  loadfromfile.close();
}
