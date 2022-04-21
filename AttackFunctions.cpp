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
  string tempkey;
  cout<< "Ghosthunter Licence\nGhosthunter name:" << x.info.myname<<endl;
  cout << "Current Health: "<< x.stats.mycurrenthealth << "/" << x.stats.maxhealth << endl;
  cout << "Strength: " << x.stats.myattack<<endl;
  cout << "Defense: " << x.stats.mydefense<<endl;
  cout << "Speed: "  << x.stats.myspeed<<endl;
  cout << "Money in bank account: " << x.stats.mymoney<<endl;
  cout << "Press x to continue";
  getline(cin, tempkey);
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
          )";
          halfasecsleep();
          cout << R"(
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
    string thisturnsattack;
    cout << "Choose an attack!"<<endl<<"(1) Ling Fu - Talisman"<<endl<<"(2) "<<p.stats.attackone<<endl<<"(3) "<<p.stats.attacktwo<<endl<<"(4) "<<p.stats.attackthree<<endl;
    getline(cin,thisturnsattack);
    int damage = 0;
    if (thisturnsattack == "1"){
      cout<< p.info.myname << "uses the Ling Fu on " << g.name<<endl;
      damage = (g.defense - p.stats.myattack) + whatshouldIdo % 4;
      g.currenthealth -= damage;
    }else if ((thisturnsattack == "2") && (p.stats.attackone != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << "uses Sun Sing Zi Fo on " << g.name<<endl;
      damage = (g.defense - p.stats.myattack) + whatshouldIdo % 5;
      if ((g.name == "Zombie") || (g.name == "Hanged Ghost")){
        damage += 5;
      }
      g.currenthealth -= damage;
    }else if ((thisturnsattack == "3") && (p.stats.attacktwo != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << " uses Calm Bell on " << g.name<<endl<<"The Calm Bell binds the "<< g.name<< "\'s power. It might not be able to move. "<< endl;
      g.inrepentance = true;
      g.repentingturns = 0;

    }else if ((thisturnsattack == "4") && (p.stats.attackthree != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << "uses Peach Tree Sword on " << g.name<<endl;
    }else{
      cout << "Invalid move!"<< g.name << " will take advantage of this slip-up..."<<endl;
    }
  }else if (playerchoice == "d"){
    cout << p.info.myname<< " is defending for next turn"<<endl;
    g.momentarychange = p.stats.mydefense;

  }else if (playerchoice == "f"){

    if ((p.stats.myspeed)>(g.speed)){
      if (whatshouldIdo >= 25){
        cout << p.info.myname << " was able to flee"<<endl;
        return false;
      }
      else{
        cout << "The monster is too fast. Impossible to run!"<<endl;
      }
    }else{
      if (whatshouldIdo >= 90){
        cout << p.info.myname << " was able to flee"<<endl;
        return false;
      }
      else{
        cout << "The monster is too fast. Impossible to run!"<<endl;
      }
    }
  } else if (playerchoice == "t"){
    if (p.stats.myspeed % 10 > whatshouldIdo % 10){
      cout<<"Healing Successful!"<<endl;
      if ((p.stats.mycurrenthealth + (whatshouldIdo % 10) + 1) <= p.stats.maxhealth){
        p.stats.mycurrenthealth += ((whatshouldIdo % 10) + 1);
      }else{
        p.stats.mycurrenthealth = p.stats.maxhealth;
      }
    }
    else{
      cout <<"Void prayer. Healing was unsuccessful."<<endl;

    }
  }else {
    cout << "Wrong move! Now the "<< g.name << " will attack!"<<endl;
  }
  onesecsleep();
  cout<< p.info.myname <<"\'s current health is " << p.stats.mycurrenthealth << "/" << p.stats.maxhealth << endl;
  float charreport;
  charreport = ((static_cast<float>(g.currenthealth))/g.maxhealth) * 100;
  onesecsleep();
  cout<< g.name << " still has " << charreport << "% of its total health" <<endl;
  onesecsleep();
  return true;
}

//Enemy moves Function
//It receives player and ghostdata structs as input.
//It has no output; however, it will modify both arrays according to what happens in the battle.
void enemymoves (Player &p, GhostData &g){
  srand(time(NULL));
  int whatshouldIdo = rand()% 100;
  if (g.inrepentance == true){
    if (g.repentingturns == 3){
      g.repentingturns = -1;
      g.inrepentance = false;
    }
    cout << "The "<<g.name << " is feeling repentance from the calm bell."<<endl;
    cout << ".";
    onesecsleep();
    cout << ".";
    onesecsleep();
    cout << "."<<endl;
    halfasecsleep();
    if (rand ()% 100 >= 20){
      cout << "Enough of that, I will attack!"<<endl;
      g.repentingturns +=1;
    }
    else {
      cout << "The enemy is paralysed!"<< endl;
      g.repentingturns +=1;
      return;
    }
  }
  //different monsters have different behaviours.
  if (g.name == "Zombie"){
    if (whatshouldIdo > 25){
      //ghostwilldefend(g,p);
      cout << "Monster attack" << endl;
    }else{
      //ghostwillattack(g,p);
      cout << "Monster defend" << endl;
    }
  }
}



//battlephase Function
//takes in a struct that contains player info. Relevant for calculating battle issues
//output is a character. If W, the user won the battle. If l, the user lost the battle, if F, the player fled from the battle.
char battlephase(Player &x, char initial){
  int repentingturns = 0;
  GhostData ghost;
  bool primeraqueataco = true;
  srand(time(NULL));
  if (initial == 'J'){
    //zombie information
    banner('J');
    ghost.maxhealth = 15;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 3 + (rand() % 5);
    ghost.defense = 8 - (rand() % 5);
    ghost.speed = 2;
    ghost.attackone = "Rotten Fangs";
    ghost.attacktwo = "Scratch";
    ghost.name = "Zombie";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
  }
  while (x.stats.mycurrenthealth > 0 && ghost.currenthealth > 0){
    bool checkme; //can maybe make x dynamic variable
    onesecsleep();
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
