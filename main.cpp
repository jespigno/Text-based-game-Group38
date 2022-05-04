#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"


void mainmenu(Player x);

int main(){
    Player defaultval = { 5, 10, 10, 5 ,6, 5, 0, 0.0 ,"xxxxxxxxxxxxxxx","xxxxxxxxxxxxxxx","xxxxxxxxxxxxxxx","Joe", false, false, false, false, false, false, 0,false, false, false, false, false, false, true};
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
        cout << "That's not an option :( try again!"<<endl;
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
      //art by jgs & ejm97 https://www.asciiart.eu/buildings-and-places/cities
      cout<< R"(
                                           .''.
       .''.      .        *''*    :_\/_:     .
      :_\/_:   _\(/_  .:.*_\/_*   : /\ :  .'.:.'.
  .''.: /\ :    /)\   ':'* /\ *  : '..'.  -=:o:=-
 :_\/_:'.:::.  | ' *''*    * '.\'/.'_\(/_'.':'.'
 : /\ : :::::  =  *_\/_*     -= o =- /)\    '  *
  '..'  ':::' === * /\ *     .'/.\'.  ' ._____
      *        |   *..*         :       |.   |' .---"|
        *      |     _           .--'|  ||   | _|    |
        *      |  .-'|       __  |   |  |    ||      |
     .-----.   |  |' |  ||  |  | |   |  |    ||      |
 ___'       ' /"\ |  '-."".    '-'   '-.'    '`      |____
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                       ~-~-~-~-~-~-~-~-~-~   /|
          )      ~-~-~-~-~-~-~-~  /|~       /_|\
        _-H-__  -~-~-~-~-~-~     /_|\    -~======-~
~-\XXXXXXXXXX/~     ~-~-~-~     /__|_\ ~-~-~-~
~-~-~-~-~-~    ~-~~-~-~-~-~    ========  ~-~-~-~
)";

      onesecsleep();
      cout << "Ah, another year in big old Hong Kong..."<<endl;
      twosecsleep();
      cout << "When will I finally do something I like?"<<endl;
      onesecsleep();
      cout << "Something normal, none of this \"spooky\" business...";
      onesecsleep();
      cout << endl << "and the more cats I get to live with, the better..." << endl;
      cout << ".";
      twosecsleep();
      twosecsleep();
      cout << ".";
      halfasecsleep();
      cout << "." << endl;
      onesecsleep();
      cout <<endl;
      cout << R"(
        ///-\\\
        |^   ^|
        |O   O|
        |  ~ *That's it*!!
         \ O /
          | |
      )";
      cout << "I will open a cat cafe!!"<<endl;
      twosecsleep();
      cout << "but rent is so expensive in this city... This will be my last round of ghost hunting."<<endl;
      twosecsleep();
      twosecsleep();
      cout<< "As soon as I get all the money I need, I'm out! " <<endl;
      twosecsleep();
      ClearScreen();
    }
  onesecsleep();
  mainmenu(defaultval);//options: cat cafe, battle, display stats



  return 0;
}

void mainmenu(Player x){
  string mycurrentchoice;
  while (true) {
      cout << R"(
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
  )" << endl;
          getline(cin, mycurrentchoice);
          if (mycurrentchoice == "Q") {
              //Quest(); CODE THIS
              printstats(x); //testing purposes
              Questmenu(x);
          }
          else if (mycurrentchoice == "C") {
              //VisitCafe(); CODETHIS
              catcafeMenu(x);
          }
          else {
              cout << "That's not an option :( try again)" << endl;
          }
  }
}
