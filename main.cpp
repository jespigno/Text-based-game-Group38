#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "TimeIntervals.h"

int main(){

    struct PlayerStats {
        int level;
        int maxhealth;
        int mycurrenthealth;
        int mydefense;
        int myattack;
        int myspeed;
        int mymoney;
        float experiencepoints;
    };
    struct PlayerInfo {
        string myname;
        int catnumber;
        int amountoffurniture;
        bool boughtcatcafe;
        bool level1complete;
        bool level2complete;
        bool level3complete;
        bool level4complete;
        bool level5complete;
    };
    struct Player {
        PlayerStats stats;
        PlayerInfo info;
    };

    Player defaultval = { 1, 10, 10, 3 ,3, 3, 0, 0.0, "Joe", 0, 0,false, false, false, false, false, false };


  

  char saveornot;
  cout<<R"(
    @@@@@@@@@@@@@@@@&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    @@@@@@@@@@@@@@@#**&@@@@@%(((((((((((((((%@@@@@@@@#*,#&@@%################&@@@@@@
    @@@@@@@@@@&&&&%(,*#%&&&&&%%%#*,(%%%%%#/*(@@@@@@&(**%@@@@#((*,*(((((((/*,/%@@@@@@
    @@@@@@@@@&#////*,,////(%@@@@#**%@@@@@&**#@@@@@&/*(@@@%(#&@&*,(@@@@@@&(**&@@@@@@@
    @@@@@@@@@@@@@@@#**&@@@@@@@@#**#&@@@@@%**#@@@&(,/%@@&(*/&@@&*,(@@@@@&/*/&@@@@@@@@
    @@@@@@@@@@&&&&&(**%&&&&@&#*,/%@#*,,,,,*#@@@&(****,,,*#@@@@&*,*#@@@&*,*/((((%@@@@
    @@@@@@@&#*,,,,,,,,,,,,,(&%%&@@@@@@@@@@@@@@@@@@@@%/,(&@@@@@%*,,*%@@@&%%%%(**(@@@@
    @@@@@@@@@@@&&&@@%,/%@@@@@&/*,,,,,,,,,,,*#@@@@@&/*/&@@@@@@@%,*//,%@@@@@@%**(@@@@@
    @@@@@@@@@@&(,(&@%,/%@@@@@&/*(@@@@@@@@%**#@@@&(,,,******#&&(,/%&**(&@@@#**#@@@@@@
    @@@@@@@@@@%/*%@@%,,,,,,/%&/*(@@@@@@@@%**#@@@@&%%&&&@@@@@@%*,#@@@(*/%%(**%@@@@@@@
    @@@@@@@@@@#*,(&@%,/%@@@@@&/*/########(,*#@@@@@@@@@@&%##@%/,(&@@@@%/,,*(&@@@@@@@@
    @@@@@@@@@&/***/((,/%@@@@@&/**((((((((/,*#@@@%#(/***/((#%/*/&@@@@%/*,*,*(%@@@@@@@
    @@@@@@@@&(*/&&#*,,*(%&&@@@@@@@@@@@@@@@&&&@@@%#%&@@@@@&#**(@@@%(*,*#@@%(*,*(%&@@@
    @@@@@@@@%*/%@@@@@%(/*********************/&@@@@@@@@@%/,/%@%*,,*(&@@@@@@@&(*,*#&@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@
  )";
  onesecsleep();
  cout<<R"(
    @@@@@@@@@@@@@@@@@@@@@@@%(#&@@@@@@@@@@@@@@@@@@@&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@@@@
    @@@@@@@@@@@@@@@@%//&@@@#*/%@@&(*(@@@@@@@@@@@@@%%%%%%%%%%%#/*(%%%%%%%%%%&@@@@@@@@
    @@@@@@@@@&/*#@@&//%@@@@#*/%@@(*(@@@@&/*#@@@%/*////////////*,////////////*/#@@@@@
    @@@@@@@@@&**#@@//#@@%%%#*/%@#*(&@&#%%/,#@@@%//%&#(((((((%&(/%&#(((((((%&(*#@@@@@
    @@@@@@@@@&**#&//%@@(*#&#*/##,#&@%*/%&/,#@@@&%%&&%#######&&(/%&%#######&&%#&@@@@@
    @@@@@@@@@&**/(,*//*,#&@#*//*,***,*%@&/,#@@@@@@&&&&&&&@@@&&&&&&&@@&&&&&&&&@@@@@@@
    @@@@@@@@@&**#@@@&(*%@@@#*/%@@@#//&@@&/,#@@@@@%*/#%#/*#&#,(#%#*(%&**(%#(*(&@@@@@@
    @@@@@@@@@&**#@@&(/%&&@@#*/%@@(/(&%&@&/,#@@@@@%*/#%#/*#&#,(%%#*(%&**(%%(*(&@@@@@@
    @@@@@@@@@&**#@%*(%@#*(&#*/%%/*#&&**#&/,#@@@@@%(#&&&#(%&%/%&&&(#&&((%&&%(#&@@@@@@
    @@@@@@@@@&**(#,,,*****(#*/((,*****,/#/,#@@@@%(****,,******,,******,,,***/#@@@@@@
    @@@@@@@@@&**#@@@@@@@&%##*/%@@@@@@@%%#/,#@@@@@@@&/*,*(%@@@%/*#@@@%**,/#&@@@@@@@@@
    @@@@@@@@@&**#@@@@@@@@@&#*/%@@@@@@@@@&/,#@@@@%/,*#@@@%/*/@%/*#&/**%@@&#*,*#@@@@@@
    @@@@@@@@@&*,,,,,,,,,,,,,,,,,,,,,,,,,,,,#@@@(**************,,**************/&@@@@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#(%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  )";
  onesecsleep();
  cout<<R"(
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    @@@@@@@@&&@@@@@&%@@@@&%(#&@@@%#(%@@@@#(#&@@@@@@@@@@@@@@@@@@%(#&@@@@@@@@@@@@@@@@@
    @@@@@@@&(*/%@&#**%&%(*/#@@&#//(%@@%(*/%@@@@@@@@@@@@@@@@@@@&(,*%@@@@@@@@@@@@@@@@@
    @@@@@@@@@&(*/**#@@&(*/#&@@#/*(%@@&#/*(%@@@@@@@@@@@@@@@@@@@%/,/%@@@@@@@@@@@@@@@@@
    @@@@@@@@@&#*,/%@@@@@@%/*(&@@@#/*(&@@@(**%@@@@@@@@@@@@@@@@@#*,(&@@@@@@@@@@@@@@@@@
    @@@@@@@%*,/((*(&@@&(,,,,,,,,,,,,,,,,,,,/@@@@@@@@@@@@@@@@@&(,,,#@@@@@@@@@@@@@@@@@
    @@@@@@@@@@@@&/*#@@&(,%@&#/**(%#*,*#&@(*/@@@@@@@@@@@@@@@@@(*,*,*#@@@@@@@@@@@@@@@@
    @@@@@@@@@@@@@(*/@@&(,%@&%/***(/**/#&@#*/@@@@@@@@@@@@@@@@#*,/@(**%@@@@@@@@@@@@@@@
    @@@@@@@@@@&#*,,/&@&(,//***/(((((/***(**/@@@@@@@@@@@@@@@#,,(&@@#*,#@@@@@@@@@@@@@@
    @@@@@@@@%/*/%#/*&@&%#%%%&&&%(#%&&&&%###%@@@@@@@@@@@@@&(,,(&@@@@%*,(&@@@@@@@@@@@@
    @@@@@@@&((%@@%/*%@&(,%#/*/##*(#(*/##*/%@@@@@@@@@@@@&#*,*#@@@@@@@&/,*(&@@@@@@@@@@
    @@@@@@@@@@@@@%/*%@&(,#%%&&&%*(#%&&&%*/%@@@@@@@@@@&#/,*(&@@@@@@@@@@#*,*(&@@@@@@@@
    @@@@@@@@@@@@@#*/&@&(,%&#//#%*(%%/*(#//%@&&@@@@@%/*,*(&@@@@@@@@@@@@@@#*,,*#&@@@@@
    @@@@@@@&##%#/*/#@@%(,%&&#/#%*(%@&####*(%//%@%/,,,/%@@@@@@@@@@@@@@@@@@@%(,,,,*#@@
    @@@@@@@&(/*/(&@@@@#*,,/#&@&(,,,*#&@@@/*,,#&@%*(&@@@@@@@@@@@@@@@@@@@@@@@@@&#(@@@@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  )";
  twosecsleep();
  cout<<R"(
    @@@@@@   @@@  @@@  @@@@@@@   @@@@@@@@  @@@@@@@
    @@@@@@@   @@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@
    !@@       @@!  @@@  @@!  @@@  @@!       @@!  @@@
    !@!       !@!  @!@  !@!  @!@  !@!       !@!  @!@
    !!@@!!    @!@  !@!  @!@@!@!   @!!!:!    @!@!!@!
    !!@!!!   !@!  !!!  !!@!!!    !!!!!:    !!@!@!
        !:!  !!:  !!!  !!:       !!:       !!: :!!
       !:!   :!:  !:!  :!:       :!:       :!:  !:!
    :::: ::   ::::: ::   ::        :: ::::  ::   :::
    :: : :     : :  :    :        : :: ::    :   : :

    @@@@@@@@  @@@  @@@   @@@@@@    @@@@@@   @@@@@@@
    @@@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@   @@@@@@@
    !@@        @@!  @@@  @@!  @@@  !@@         @@!
    !@!        !@!  @!@  !@!  @!@  !@!         !@!
    !@! @!@!@  @!@!@!@!  @!@  !@!  !!@@!!      @!!
    !!! !!@!!  !!!@!!!!  !@!  !!!   !!@!!!     !!!
    :!!   !!:  !!:  !!!  !!:  !!!       !:!    !!:
    :!:   !::  :!:  !:!  :!:  !:!      !:!     :!:
    ::: ::::  ::   :::  ::::: ::  :::: ::      ::
    :: :: :    :   : :   : :  :   :: : :       :

    @@@  @@@  @@@  @@@  @@@  @@@  @@@@@@@  @@@@@@@@  @@@@@@@
    @@@  @@@  @@@  @@@  @@@@ @@@  @@@@@@@  @@@@@@@@  @@@@@@@@
    @@!  @@@  @@!  @@@  @@!@!@@@    @@!    @@!       @@!  @@@
    !@!  @!@  !@!  @!@  !@!!@!@!    !@!    !@!       !@!  @!@
    @!@!@!@!  @!@  !@!  @!@ !!@!    @!!    @!!!:!    @!@!!@!
    !!!@!!!!  !@!  !!!  !@!  !!!    !!!    !!!!!:    !!@!@!
    !!:  !!!  !!:  !!!  !!:  !!!    !!:    !!:       !!: :!!
    :!:  !:!  :!:  !:!  :!:  !:!    :!:    :!:       :!:  !:!
    ::   :::  ::::: ::   ::   ::     ::     :: ::::  ::   :::
    :   : :   : :  :   ::    :      :     : :: ::    :   : :

  )"<<endl;
  while (saveornot != 'L' || saveornot != 'N'){
    cout<< "Load game (L) or New game (N)?"<<endl;
    cin >> saveornot;
    if (saveornot == 'L'){
        loadvalues(defaultval);
      cout<< "Welcome back, "<< defaultval.info.myname << endl;
      break;
    }else if (saveornot == 'N'){
      cout << "What's your name?" <<endl;
      cin >> defaultval.info.myname;
      break;
    }else{
      cout << "That's not an option :( try again)"<<endl;
    }
  }



  return 0;
}
