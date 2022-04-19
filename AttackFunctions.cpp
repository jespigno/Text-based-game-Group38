#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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


//bannerfunction
//takes in a char, outputs ASCII art related to the type of monster attacked.
void banner(char o){
  if (o == 'J'){
    //Troll by Veronica Karlsson https://www.asciiart.eu/mythology/monsters
    cout<< R"(
            -. -. `.  / .-' _.'  _
     .--`. `. `| / __.-- _' `
    '.-.  \  \ |  /   _.' `_
    .-. \  `  || |  .' _.-' `.
  .' _ \ '  -    -'  - ` _.-.
   .' `. %%%%%   | %%%%% _.-.`-
 .' .-. ><(@)> ) ( <(@)>< .-.`.
   (("`(   -   | |   -   )'"))
  / \\#)\    (.(_).)    /(#//\
 ' / ) ((  /   | |   \  )) (`.`.
 .'  (.) \ .md88o88bm. / (.) \)
   / /| / \ `Y88888Y' / \ | \ \
 .' / O  / `.   -   .' \  O \ \\
  / /(O)/ /| `.___.' | \\(O) \
   / / / / |  |   |  |\  \  \ \
   / / // /|  |   |  |  \  \ \  VK
 _.--/--/'( ) ) ( ) ) )`\-\-\-._
( ( ( ) ( ) ) ( ) ) ( ) ) ) ( ) )  )";
    onesecsleep();
    cout<<R"(
       .*(%%%%%%%%%%%%%%%%%%#/, .......................................
              ./#%#*.            .,*********************************,.
              ./%%#,            .*#%%(//******///#%%#(//*******//(%%%/
             .,(%#(,            .*#%#/.         .(#%(*.         .*#%%/
             ,/#%(/,.......     .*#%%#((///////((#%%##((///////((#%%%/
             *#%%%#########(*.  .*#%#(**********/#%%#//*********/(%%%/
            ./%%#(//////(%%%/.  .*#%#/.         .(#%(*.         .*#%%/
           ,/#%(/.     .*#%%/.  .*#%%%############%%%#############%%%/
          .*#%%/.      ./%%#*   .,/((/,,,,,,,,,,,,,,,,,,,,,,,,,,**(((*
         .*(%#(,      .*(%#(,
        .*#%%/...     ,(#%(*. ,/(######################################/*.
       ./#%#/*,(#(/,..*#%%/.   .........................................
      ,/#%#/ .,/%%%%%##%#(*     .,*//////////////////////////////////,
       .**,.    .*/#%%%%(,.     .*#%%#(/////////(#%%#((////////((#%%%/
                  .*(%%#*       .*#%#/.         .(#%(*.         .*#%%/
                 .,(%%(,.       .*#%%%###########%%%%%###########%%%%/
                ./#%#(*         .*#%%#///////////#%%#(///////////(%%%/
               *(#%#/.          .*#%#/.         .(#%(*.         .*#%%/
             ,/#%%(,.           .*#%%%###########%%%%#############%%%/
          .,/#%%#*.             .*/((/***************************/(((*
        .*##%%#*.                 ...                             ...
      .,(#%#(*.             .,(########################################(*.
        .,*,                  ...........................................
            *#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*
       *#%%%##(((((((((((((((((((((((((((((((((((((((((((((##%%%%*
       *#%%(*,                                             .*(%%%*
       *#%%(*.                                             .,(%%%*
       *#%%#/*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*/(%%%*
       *#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*
       *#%%#(/*********************************************/(#%%%*
       *#%%(*.                                               ....
       *#%%(*.
       *#%%(*,./%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%#(,
       *#%%(*, ,/////(##%%#(///////////////(#%%#(////////////////*,.
       *#%%(*.       *##%(*.               ,(#%(*.
       *#%%(*.     .*(%%#*                 ,(#%(*.
       *#%%(*.    ./%%%%#((((((((((((((/*. ,(#%(*.           .,*///,
      ./%%%/,.   *(#%###(((((((((((#%%%#/, ,(#%(*.      .,*/(#%%%%#/.
     .,/%%%/.. ,(#%##*............./%%%(*. ,(#%(*, .,/((##%%%%#(*,..
     .*(%%%* ,(#%%%/..           .*(%%%*   ,(#%%%%%%%%%%%##/.
     ,(#%##/,(%##/.,,/%#(/,.    ./#%%(*.   ,(#%%%%##(/*,
     *#%%#/, .*,,. .,*(#%%%#/*,*(#%##*     ,(#%#(*,.            ..,.
    ./%%%(,.           .,/##%%#%%%%/,.     ,(#%(*.             .,/##(*
   .*(%%%/                 *##%%%(*.       ,(#%(*.             .*(%%%*
   *#%%#(,             ..*(#%%#(*.         ,(#%(*.             ,/(%##*
 .,(%%%(,.         ..*/(#%%##/,.           ,(#%#(,             *(#%#(,
 *##%%#*       ..*((#%%%%(/,.              ,*(%%%(/**********/(#%%%(*.
,/%%%(*.   .,/#%%%%%%##*.                    *#%%%%%%%%%%%%%%%%%%#(*
 .,*(*       *((#((*.                          .,*////////////*,.
    )"
    halfasecsleep();
    ClearScreen();
  }
}
//battlephase Function
//takes in a struct that contains player info. Relevant for calculating battle issues
//output is either true or false. If true, the user won the battle. If false, the user lost the battle.
bool battlephase(Player x, char initial){
  GhostData ghost;
  srand(time(NULL));
  if (initial == 'J'){
    //zombie information
    banner('J');
    ghost.maxhealth = 10;
    ghost.currenthealth = maxhealth;
    ghost.attack = 3 + (rand()%5);
    ghost.defense = 8 - (rand()&5);
    ghost.speed = 2;
    ghost.attackone = "Rotten Fangs";
    ghost.attacktwo = "Scratch";
    ghost.name = "Zombie"
  }
  while (x.stats.mycurrenthealth > 0 && ghost.currenthealth > 0){
    usermoves(x,ghost);
    enemymoves(x,ghost);
  }
  if (ghost.currenthealth > 0){
    //user lost
    return false;
  }
  else{
    //user won!
    //Gain experience experience
    //if yes, level up.
    return true;
  }
}
