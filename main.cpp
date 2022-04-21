#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"


void mainmenu(Player x);

int main(){
    Player defaultval = { 1, 10, 10, 3 ,3, 3, 0, 0.0, "Joe", 0, 0,false, false, false, false, false, false, true};
    string saveornot;
    while (saveornot != "L" && saveornot != "N"){
      cout<< "Load game (L) or New game (N)?"<<endl;
      getline(cin, saveornot);
      if (saveornot == "L"){
        loadvalues(defaultval);
        cout<< "Welcome back, "<< defaultval.info.myname << endl;
      }else if (saveornot == "N"){
        cout << "What's your name?" <<endl;
        getline(cin, defaultval.info.myname);
        cout<< "Welcome, "<< defaultval.info.myname << endl;
      }else{
        cout << "That's not an option :( try again)"<<endl;
      }
    }
    if (defaultval.info.firsttime == true){
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
      halfasecsleep();
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
      halfasecsleep();
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
      onesecsleep();
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
      twosecsleep();
      ClearScreen();
    }
  onesecsleep();
  mainmenu(defaultval);//options: cat cafe, battle, display stats



  return 0;
}

void mainmenu(Player x){
  string mycurrentchoice;
  cout<< R"(
                                                   .-') _            .-')                  ('-.   .-')   .-') _   ,------.
                                              ( OO ) )         .(  OO)               _(  OO) ( OO ).(  OO) ) '  .--.  '
  ,----.    .-'),-----.        .-'),-----.,--./ ,--,'         (_)---\_)  ,--. ,--.  (,------(_)---\_/     '._|  |  |  |
 '  .-./-')( OO'  .-.  '      ( OO'  .-.  |   \ |  |\         '  .-.  '  |  | |  |   |  .---/    _ ||'--...__'--'  |  |
 |  |_( O- /   |  | |  |      /   |  | |  |    \|  | )       ,|  | |  |  |  | | .-') |  |   \  :` `.'--.  .--'   __.  |
 |  | .--, \_) |  |\|  |      \_) |  |\|  |  .     |/       (_|  | |  |  |  |_|( OO (|  '--. '..`''.)  |  |     |   .'
(|  | '. (_/ \ |  | |  |        \ |  | |  |  |\    |          |  | |  |  |  | | `-' /|  .--'.-._)   \  |  |     |___|
 |  '--'  |   `'  '-'  '         `'  '-'  |  | \   |          '  '-'  '-('  '-'(_.-' |  `---\       /  |  |     .---.
  `------'      `-----'            `-----'`--'  `--'           `-----'--' `-----'    `------'`-----'   `--'     '---'
                                    Press                        Q
        (`-.           .-')           .-') _                     ('-.                ('-.  ,------.
    _(OO  )_        ( OO ).        (  OO) )                   ( OO ).-.          _(  OO)'  .--.  '
,--(_/   ,. \,-.-')(_)---\_) ,-.-')/     '._          .-----. / . --. /  ,------(,------|  |  |  |
\   \   /(__/|  |OO/    _ |  |  |OO|'--...__)        '  .--./ | \-.  \('-| _.---'|  .---'--'  |  |
 \   \ /   / |  |  \  :` `.  |  |  '--.  .--'        |  |('-.-'-'  |  (OO|(_\    |  |       __.  |
  \   '   /, |  |(_/'..`''.) |  |(_/  |  |          /_) |OO  \| |_.'  /  |  '--.(|  '--.   |   .'
   \     /__,|  |_..-._)   \,|  |_.'  |  |          ||  |`-'| |  .-.  \_)|  .--' |  .--'   |___|
    \   /  (_|  |  \       (_|  |     |  |         (_'  '--'\ |  | |  | \|  |_)  |  `---.  .---.
     `-'     `--'   `-----'  `--'     `--'            `-----' `--' `--'  `--'    `------'  '---'
                                    Press                         C
  )"<< endl;
  while (mycurrentchoice != "Q" && mycurrentchoice != "C"){
    getline(cin, mycurrentchoice);
    if (mycurrentchoice == "Q"){
      //Quest(); CODE THIS
    }else if (mycurrentchoice == "C"){
      //VisitCafe(); CODETHIS
      cout<<"this loop works!"<<endl;
      printstats(x); //testing purposes
      battlephase(x, 'J'); //testing purposes
    }else{
      cout << "That's not an option :( try again)"<<endl;
    }
  }
}
