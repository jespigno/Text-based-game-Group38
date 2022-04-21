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


//banner function
//takes in a char, outputs ASCII art related to the type of monster attacking.
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
 )";
    halfasecsleep();
    ClearScreen();
  }
}

//This function lets the player move and decide what to do.
//It has a bool output; however, it will modify both arrays according to what happens in the battle.
//The bool output will almost in all cases just be true. However, if it returns false, the battle will end immediately and the user will have escaped.
bool usermoves(Player &p, GhostData &g){
  cout <<R"(
  ( OO ).-(  OO) ) (  OO) )   ( OO ).-.         \  ( OO )
  / . --. /     '._/     '._  / . --. /  .-----.,--. ,--.
  | \-.  \|'--...__|'--...__) | \-.  \  '  .--./|  .'   /
.-'-'  |  '--.  .--'--.  .--.-'-'  |  | |  |('-.|      /,
 \| |_.'  |  |  |     |  |   \| |_.'  |/_) |OO  |     ' _)
  |  .-.  |  |  |     |  |    |  .-.  |||  |`-'||  .   \
  |  | |  |  |  |     |  |    |  | |  (_'  '--'\|  |\   \
 _`.-')`_-'  ('-.     `--'    `('-.`--'  .-')-_'_-.-')-_'  Press (a)  to attack!
( (  OO) ) _(  OO)           _(  OO)    ( OO ) ( (  OO) )
 \     .'_(,------.  ,------(,------,--./ ,--,' \     .'_
 ,`'--..._)|  .---('-| _.---'|  .---|   \ |  |\ ,`'--..._)
 |  |  \  '|  |   (OO|(_\    |  |   |    \|  | )|  |  \  '
 |  |   ' (|  '--./  |  '--.(|  '--.|  .     |/ |  |   ' |
 |  |   / :|  .--'\_)|  .--' |  .--'|  |\    |  |  |   / :
 |  '--'  /|  `---. \|  |_)  |  `---|  | \   |  |  '--'  /
 `-------' `------'  ('-.    ('-.---`--'  `--'  `-------'   Press (d) to defend!
                   _(  OO) _(  OO)
   ,------,--.    (,------(,------.
('-| _.---|  |.-') |  .---'|  .---'
(OO|(_\   |  | OO )|  |    |  |
/  |  '--.|  |`-' (|  '--.(|  '--.
\_)|  .--(|  '---.'|  .--' |  .--'
  \|  |_) |      | |  `---.|  `---.                       Press (f) to flee!
 .-')-_   `('-.-_' `.-')--'`-_-(`-.            ('-.           _ (`-. _  .-')    ('-.                  ('-. _  .-')
(  OO) ) _(  OO( '.( OO )_  ( (OO  )         _(  OO)         ( (OO  ( \( -O )  ( OO ).-.            _(  OO( \( -O )
/     '.(,------,--.   ,--._.`     \,--.    (,------.       _.`     \,------.  / . --. / ,--.   ,--(,------,------.
|'--...__|  .---|   `.'   (__...--''|  |.-') |  .---'      (__...--''|   /`. ' | \-.  \   \  `.'  / |  .---|   /`. '
'--.  .--|  |   |         ||  /  | ||  | OO )|  |           |  /  | ||  /  | .-'-'  |  |.-')     /  |  |   |  /  | |
   |  | (|  '--.|  |'.'|  ||  |_.' ||  |`-' (|  '--.        |  |_.' ||  |_.' |\| |_.'  (OO  \   /  (|  '--.|  |_.' |
   |  |  |  .--'|  |   |  ||  .___.(|  '---.'|  .--'        |  .___.'|  .  '.' |  .-.  ||   /  /\_  |  .--'|  .  '.'
   |  |  |  `---|  |   |  ||  |     |      | |  `---.       |  |     |  |\  \  |  | |  |`-./  /.__) |  `---|  |\  \
   `--'  `------`--'   `--'`--'     `------' `------'       `--'     `--' '--' `--' `--'  `--'      `------`--' '--'   Press (t) to pray!
  )";
  string playerchoice;
  getline(cin,playerchoice);
  srand(time(NULL));
  int whatshouldIdo = rand()% 100;

  if (playerchoice == "a"){
    cout << "I am attacking";

  }else if (playerchoice == "d"){
    cout << "I am defending";

  }else if (playerchoice == "f"){
    if ((p.stats.myspeed)>(g.speed)){
      cout << "You were able to flee"; //add more chance to this
      return false;
    }else{
      cout << "The monster is too fast. Impossible to run!";
    }
  } else if (playerchoice == "t"){
    if (p.stats.myspeed % 10 > whatshouldIdo % 10){
      cout<<"Healing Successful!";

    }
    else{
      cout <<"Void prayer. Healing was unsuccessful.";

    }
  }else {
    cout << "Wrong move! Now the "<< g.name << " will attack!";
  }
  return true;
}

//Enemy moves Function
//It receives player and ghostdata structs as input.
//It has no output; however, it will modify both arrays according to what happens in the battle.
void enemymoves (Player &p, GhostData &g){
  srand(time(NULL));
  int whatshouldIdo = rand()% 100;
  //different monsters have different behaviours.
  if (g.name == "Zombie"){
    if (whatshouldIdo > 25){
      //ghostwilldefend(g,p);
      cout << "Monster attack";
    }else{
      //ghostwillattack(g,p);
      cout << "Monster defend";
    }
  }
}



//battlephase Function
//takes in a struct that contains player info. Relevant for calculating battle issues
//output is a character. If W, the user won the battle. If l, the user lost the battle, if F, the player fled from the battle.
char battlephase(Player &x, char initial){
  GhostData ghost;
  bool primeraqueataco = true;
  srand(time(NULL));
  if (initial == 'J'){
    //zombie information
    banner('J');
    ghost.maxhealth = 10;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 3 + (rand() % 5);
    ghost.defense = 8 - (rand() % 5);
    ghost.speed = 2;
    ghost.attackone = "Rotten Fangs";
    ghost.attacktwo = "Scratch";
    ghost.name = "Zombie";
  }
  while (x.stats.mycurrenthealth > 0 && ghost.currenthealth > 0){
    bool checkme; //can maybe make x dynamic variable
    if (x.stats.myspeed >= ghost.speed){
      if (primeraqueataco == true){
         cout<< R"(
               ('-. .-.                         .-')     ('-.           ('-.        .-') _          ('-.             .-') _                         .-') _,---.
          ( OO )  /                        ( OO ). _(  OO)         ( OO ).-.   ( OO ) )        ( OO ).-.        (  OO) )                       ( OO ) |   |
   .-----.,--. ,--..-'),-----. .-'),-----.(_)---\_(,------.        / . --. ,--./ ,--,'         / . --. /  .-----/     '._,-.-') .-'),-----.,--./ ,--,'|   |
  '  .--./|  | |  ( OO'  .-.  ( OO'  .-.  /    _ | |  .---'        | \-.  \|   \ |  |\         | \-.  \  '  .--.|'--...__|  |OO( OO'  .-.  |   \ |  |\|   |
  |  |('-.|   .|  /   |  | |  /   |  | |  \  :` `. |  |          .-'-'  |  |    \|  | )      .-'-'  |  | |  |('-'--.  .--|  |  /   |  | |  |    \|  | |   |
 /_) |OO  |       \_) |  |\|  \_) |  |\|  |'..`''.(|  '--.        \| |_.'  |  .     |/        \| |_.'  |/_) |OO  ) |  |  |  |(_\_) |  |\|  |  .     |/|  .'
 ||  |`-'||  .-.  | \ |  | |  | \ |  | |  .-._)   \|  .--'         |  .-.  |  |\    |          |  .-.  |||  |`-'|  |  | ,|  |_.' \ |  | |  |  |\    | `--'
(_'  '--'\|  | |  |  `'  '-'  '  `'  '-'  \       /|  `---.        |  | |  |  | \   |          |  | |  (_'  '--'\  |  |(_|  |     `'  '-'  |  | \   | .--.
   ('-.--'`.-')`_-' .-')-_---' ('-.`-----' `----.-.`.-')--'        `--' `--`--'  `--'          `--' `--'  `-----'  `--'  `--'       `-----'`--'  `--' '--'
 )";
        primeraqueataco = false;
      }
      checkme = usermoves(x,ghost);
      if (checkme == false){
        return 'F';
      }
      enemymoves(x,ghost);
    }

    else {
      enemymoves(x,ghost);
        if (primeraqueataco == true){
         cout<<R"(
               ('-. .-.                         .-')     ('-.           ('-.        .-') _          ('-.             .-') _                         .-') _,---.
          ( OO )  /                        ( OO ). _(  OO)         ( OO ).-.   ( OO ) )        ( OO ).-.        (  OO) )                       ( OO ) |   |
   .-----.,--. ,--..-'),-----. .-'),-----.(_)---\_(,------.        / . --. ,--./ ,--,'         / . --. /  .-----/     '._,-.-') .-'),-----.,--./ ,--,'|   |
  '  .--./|  | |  ( OO'  .-.  ( OO'  .-.  /    _ | |  .---'        | \-.  \|   \ |  |\         | \-.  \  '  .--.|'--...__|  |OO( OO'  .-.  |   \ |  |\|   |
  |  |('-.|   .|  /   |  | |  /   |  | |  \  :` `. |  |          .-'-'  |  |    \|  | )      .-'-'  |  | |  |('-'--.  .--|  |  /   |  | |  |    \|  | |   |
 /_) |OO  |       \_) |  |\|  \_) |  |\|  |'..`''.(|  '--.        \| |_.'  |  .     |/        \| |_.'  |/_) |OO  ) |  |  |  |(_\_) |  |\|  |  .     |/|  .'
 ||  |`-'||  .-.  | \ |  | |  | \ |  | |  .-._)   \|  .--'         |  .-.  |  |\    |          |  .-.  |||  |`-'|  |  | ,|  |_.' \ |  | |  |  |\    | `--'
(_'  '--'\|  | |  |  `'  '-'  '  `'  '-'  \       /|  `---.        |  | |  |  | \   |          |  | |  (_'  '--'\  |  |(_|  |     `'  '-'  |  | \   | .--.
   ('-.--'`.-')`_-' .-')-_---' ('-.`-----' `----.-.`.-')--'        `--' `--`--'  `--'          `--' `--'  `-----'  `--'  `--'       `-----'`--'  `--' '--'
 )";
        primeraqueataco = false;
      }
      checkme = usermoves(x,ghost);
      if (checkme == false){
        return 'F';
      }
    }
  }
  if (ghost.currenthealth > 0){
    //user lost
    return 'L';
  }
  else{
    //user won!
    //Gain experience experience
    //if yes, level up.
    return 'W';
  }
}
