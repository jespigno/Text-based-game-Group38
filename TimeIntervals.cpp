#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;
#include <iostream>
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
