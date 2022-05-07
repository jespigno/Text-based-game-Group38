#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
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
  cout<< "Weapons Available: "<< endl << "1) Ling Fu - Talisman" << endl;
  if (x.stats.attackone != "xxxxxxxxxxxxxxx"){
    cout << "2) Sun Sing Zi Fo - Sacred Fire" << endl;
  }else {
    cout << "2) Not unlocked yet!" << endl;
  }
  if (x.stats.attacktwo != "xxxxxxxxxxxxxxx"){
    cout << "3) Calm Bell" << endl;
  }else {
    cout << "3) Not unlocked yet!" << endl;
  }
  if (x.stats.attackthree != "xxxxxxxxxxxxxxx"){
    cout << "4) Peach Tree Sword" << endl;
  }else {
    cout << "4) Not unlocked yet!" << endl;
  }
  cout << "Press x to continue";
  getline(cin, tempkey);
  ClearScreen();
}

//level up function
//input is user array, which will be modified randomly to grant user level up perks
//void, so produces no output.
void LevelUp(Player &z){
  z.stats.level +=1;
  cout<<R"(
           ('-.       (`-.     ('-.                              _ (`-.,---.
          _(  OO)    _(OO  )_ _(  OO)                            ( (OO  |   |
 ,--.    (,------,--(_/   ,. (,------,--.            ,--. ,--.  _.`     |   |
 |  |.-') |  .---\   \   /(__/|  .---|  |.-')        |  | |  | (__...--'|   |
 |  | OO )|  |    \   \ /   / |  |   |  | OO )       |  | | .-')|  /  | |   |
 |  |`-' (|  '--.  \   '   /,(|  '--.|  |`-' |       |  |_|( OO |  |_.' |  .'
(|  '---.'|  .--'   \     /__)|  .--(|  '---.'       |  | | `-' |  .___.`--'
 |      | |  `---.   \   /    |  `---|      |       ('  '-'(_.-'|  |    .--.
 `------' `------'    `-'     `------`------'         `-----'   `--'    '--'
  )";
  srand(time(NULL)*123);
  int * whatshouldIdo = new int (rand()% 100);
  if (*whatshouldIdo >= 50){
    z.stats.myattack +=1;
    cout << z.info.myname<<"\'s attack has increased by one point!"<<endl;
    twosecsleep();
  }
  delete whatshouldIdo;

  srand(time(NULL)*876);
  int * whatshouldIdo1 = new int (rand()% 100);
  if (*whatshouldIdo1 >= 50){
    z.stats.mydefense +=1;
    cout << z.info.myname<<"\'s defense has increased by one point!"<<endl;
    twosecsleep();
  }
  delete whatshouldIdo1;
  srand(time(NULL)*405);
  int * whatshouldIdo2 = new int (rand()% 100);
  if (*whatshouldIdo2 >= 50){
    z.stats.myspeed +=1;
    cout << z.info.myname<<"\'s speed has increased by one point!"<<endl;
    twosecsleep();
  }
  delete whatshouldIdo2;
  srand(time(NULL)*9182);
  int * whatshouldIdo3 = new int (rand()% 100);
  if (*whatshouldIdo3 >= 50){
    z.stats.maxhealth +=5;
    cout << z.info.myname<<"\'s maximum health points have increased by five points!"<<endl;
    twosecsleep();
  }
  delete whatshouldIdo3;
  z.stats.mycurrenthealth = z.stats.maxhealth;
  whatshouldIdo = 0;
  whatshouldIdo1 = 0;
  whatshouldIdo2 = 0;
  whatshouldIdo3 = 0;
  if (z.stats.level >= 3 && z.stats.attackone == "xxxxxxxxxxxxxxx"){
    z.stats.attackone = "SunSingZiFo-HolyFire";
    cout << z.info.myname<<" has unlocked the Holy Fire! It will burn down undead corpses to ashes"<<endl;
    twosecsleep();
  }
  if (z.stats.level >= 5 && z.stats.attacktwo == "xxxxxxxxxxxxxxx"){
    z.stats.attacktwo = "CalmBell";
    cout << z.info.myname<<" has unlocked the Calm Bell! It may make ghosts not attack in repentance."<<endl;
    twosecsleep();
  }
  if (z.stats.level >= 10 && z.stats.attackthree == "xxxxxxxxxxxxxxx"){
    z.stats.attacktwo = "PeachTreeSword";
    cout << z.info.myname<<" has unlocked the Peach Tree Sword! Its magic wood makes it effective against all kinds of enemies."<<endl;
    twosecsleep();
  }
  return;
}
//ExperienceGain function
//It calculates the amount of experience points gained by the user after the battle
//Modifies the player struct with any changes
//Triggers level up if conditions are met
void ExperienceGain(Player &x, GhostData g){
  float experienceneeded = (x.stats.level)*(x.stats.level)*(x.stats.level);
  int bonus;
  if (g.name == "Zombie"){
    bonus = 5 + x.stats.level;
  } else if (g.name == "Vengeful Spirit"){
    bonus = x.stats.level * 1.5;
  } else if (g.name == "Hungry Ghost"){
    bonus = (x.stats.level/5)*(x.stats.level/5) + x.stats.level * 4 + (44/x.stats.level) * 4;
  }else if (g.name == "Possessed Medium"){
    bonus = ((x.stats.level + x.stats.maxhealth) * 44)/4 + (x.stats.level * x.stats.maxhealth)/8;
  }else if (g.name == "Water Ghost"){
    bonus = 88 * x.stats.myattack + 4 * x.stats.myspeed + 4*x.stats.mydefense + x.stats.maxhealth *4;
  }
  float experiencegained = (bonus * 20)/5 + (x.stats.level *20 / 7);
  x.stats.experiencepoints += experiencegained;
  if (x.stats.experiencepoints >= experienceneeded){
    x.stats.experiencepoints -= experienceneeded;
    LevelUp(x);
  }
  cout << "You have just gained "<< experiencegained << " experience points!" << endl;
  onesecsleep();
  cout << "Current level is: "<< x.stats.level<<endl;
  onesecsleep();
  cout << "Current experience points are: "<<x.stats.experiencepoints<<endl;
  onesecsleep();
  cout << "Points until next level: "<< ((x.stats.level)*(x.stats.level)*(x.stats.level)) - x.stats.experiencepoints <<endl;
  return;
}

void MonsterAttack (GhostData &ghast, Player &pleya, int &hexed){
  cout << ghast.name << " will attack!" << endl;
  int secretnumber;
  if (ghast.name == "Zombie"){
    secretnumber = ghast.attack + ghast.defense;
  }else if (ghast.name == "Vengeful Spirit"){
    secretnumber = ghast.defense * 2;
  }else if (ghast.name == "Hungry Ghost"){
    secretnumber = ghast.speed * ghast.defense;
  }else if (ghast.name == "Possessed Medium"){
    secretnumber = ghast.speed + ghast.maxhealth + ghast.defense;
  }else if (ghast.name == "Water Ghost"){
    secretnumber = ghast.speed * ghast.defense * 4;
  }
  halfasecsleep();
  onesecsleep();
  int damage = 0;
  srand(time(NULL)+137);
  int * whatshouldIdo = new int (rand()% 100);
  string currentattack;
  if (hexed > 0){
    pleya.stats.mycurrenthealth -= (ghast.defense % 3 + 1);
    hexed -=1;
    cout << pleya.info.myname << " is being hurt by the hex." << endl;
    onesecsleep();
  }
  if (*whatshouldIdo > 50){
    currentattack = ghast.attackone;
  }else{
    currentattack = ghast.attacktwo;
  }
  if (currentattack == "Rotten Fangs"){
    cout << ghast.name << " bites with Rotten Fangs!" << endl;
    damage = ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 50)+ 2) * 1;

  }else if (currentattack == "Scratch"){
    cout << ghast.name << " uses long nails to scratch!" << endl;
    int scratchnumber = 0;
    int amountofscratch = *whatshouldIdo % 3;
    for (int i = scratchnumber; i <= amountofscratch; i++){
      onesecsleep();
      cout << ghast.name << " scratches "<< (i+ 1) << " time."<< endl;
      damage += ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 60)+ 2) ;
    }
    damage -= pleya.stats.mydefense/5;
  }else if (currentattack == "Undying Hex"){
    hexed = 4;
    onesecsleep();
    cout << ghast.name << " is casting a hex from the underworld..." << endl;
    onesecsleep();
    cout << "KUV MUAB RAU KOJ TUS VAJTSWV NTAWM QHOV TSAUS NTUJ IB TXHIA NTAWM KUV TUS KHEEJ KEV NOJ QAB HAUS HUV LOS FOOM TSIS ZOO RAU KUV COV YEEB NCUAB THIAB YEEJ QHOV KEV SIB NTAUS SIB TUA NO"<<endl;
    onesecsleep();
    halfasecsleep();
    cout << pleya.info.myname << " has been hexed!"<<endl;
    onesecsleep();
  }else if (currentattack == "Soul Eater"){
    cout << "I need to consume human souls........"<<endl;
    onesecsleep();
    cout << "souls...."<<endl;
    onesecsleep();
    damage += ((((((2*secretnumber)/5)+2) * (ghast.defense/pleya.stats.myattack))/ 50)+ 2);
    if (damage >= 0){
      ghast.currenthealth += damage%10;
      cout << "The " << ghast.name << " has absorbed " << damage << " health points from " << pleya.info.myname << endl;
      if (ghast.currenthealth == (ghast.maxhealth * 2)){
        cout << "Huh?"<<endl;
        onesecsleep();
        cout << ".";
        onesecsleep();
        cout << ".";
        onesecsleep();
        cout << "."<<endl;
        halfasecsleep();
        cout << "The " << ghast.name << "consumed too much soul energy. Its body cannot withstand it anymore."<<endl;
        twosecsleep();
        cout << ghast.name << " has been defeated."<< endl;
        ghast.currenthealth = 0;
      }
      twosecsleep();
    }
  }else if (currentattack == "Eternal Despair"){
    cout << ghast.name << " tries to swallow "<< pleya.info.myname << " into darkness" << endl;
      damage = ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 45)+ 2) * 1.3;
  }else if (currentattack == "Sharp Knife"){
    cout << ghast.name << " attacks "<< pleya.info.myname << " with a sharp knife!" << endl;
        damage = ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 35)+ 2) * 1.4;
  }else if (currentattack == "Tidal Wave"){
    cout << ghast.name << " brings forth a Tidal Wave of putrid water!" << endl;
    halfasecsleep();
    srand(time(NULL)+28);
    int * randomnumber = new int (rand()%10);
    if (*randomnumber >= 6){
      cout << pleya.info.myname << "\'s defense was pierced! Extra damage!"<<endl;
      damage = ((((((2*secretnumber)/5)+2) * (ghast.attack))/ 35)+ 2) * 1.4;
    }else {
      damage = ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 35)+ 2) * 1.2;
    }
    delete randomnumber;

  }else if (currentattack == "Underwater Chains"){
    cout << ghast.name << " pulls " << pleya.info.myname << " underwater with heavy chains."<< endl;
    damage = ((((((2*secretnumber)/5)+2) * (ghast.attack/pleya.stats.mydefense))/ 35)+ 2) * 1.5;
  }
  if (ghast.momentarychange != 0){
    damage -= ghast.momentarychange;
    ghast.momentarychange = 0;
  }
  if (damage < 0  ){
    damage = 0;
  }
  delete whatshouldIdo;
  pleya.stats.mycurrenthealth -= damage;
  cout << pleya.info.myname << " has been dealt " << damage << " damage by the "<<ghast.name<< endl;
  onesecsleep();
  halfasecsleep();
}

void MonsterDefend(GhostData &ghast, Player &pleya, int &hexed){
  cout << ghast.name << " will defend!" << endl;
  halfasecsleep();
  if (hexed > 0){
    pleya.stats.mycurrenthealth -= (ghast.defense % 3 + 1);
    hexed -=1;
    cout << pleya.info.myname << " is being hurt by the hex." << endl;
    onesecsleep();
  }
  ghast.imdefending = true;
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
  }else if (o == 'L'){
      cout << R"(
lXWWWWWWWWWNNWWWWNXX0kdl:;'...      ..,;cx0XNNNWWWWWWWWWMWWWWWWMWWWWWWWWWWWWWWWWWWWMWWWWWWWWWWMMMWWW
:XWWWWWWWWWWX0kdl:,'..                   ..';::codxkKNWWWWMWWWWWWWWWWWWWWWWWWWWWWWMWWWWWWWWNNNWWWWWW
:XWWWWWNKOo:'.                                    ..'cdk0XWWWWWWWWWWWWWWWWWWWWWWWWWMWWWWWNXKKXNNNNWW
lXWNXOo;.                                              .'ck0XNWWWWWWWWWWWWWWWWWWWWWWWWNXXXKKKKKKKXWW
dKkc'.                                                   .',:cclxOXWWWWWWWWMMMMWWWWWWWNXKKKKXXKO0NWW
,'                                                          ..   .,lONWWWWWMMWWWMMWWWNNNXKKXWNKOOXWW
                                                        ..          .;kXWWWWWWWWWWWWWWNNXXKXXK0KXWMW
                                                        ..            .;kNWWWWWWWWWWWWNXK00KXNNWNXNW
                                                       ..               .:0WWWWWWWWWWWWNK0KXNMWNK0KW
                                                     ....                 .oKWWWWWWWNNNXXNWWMMWWNKXW
                                                    ....                    ,kWWWWWNXNNNWWMMMMMMMWWW
                                                  .....                      .dNWWNXKXXNWWWWMMMMMMMW
                                                                              .dNWNXXXXNWWWWWMMMMMMW
                                                                               .oNNWWWWMMMMMMMMMMMMM
                                                                              ..;ONWWWMMMMMMMMMWWWWW
                                                  .                          .lxxdONWWWMWMMMMMMMMMMM
.                                         .      ...                          ....;KMWWMMWWMMMMMMMMW
                                          .    ...'.                              .oXNWMWWWMMMWMMMWX
                                          .   ......                             ..'lXWWMWWWWWWWWNKO
                 .....         .         .    ......   ...                          .xNWWWWWWWWXKOkd
                .......        .        ..   ...... .......                          ,0WWWWWWXKOkdoc
        ..   .. ........      ..     .. ...   ..... ...''...                          cKNNNX0kdocc:;
      ....  ............      ..    ........ ..........','..                          .dXX0kdlc:;;,,
     ...........''.....       ..    ........ .........',,'...                          .odlcc:;,,'''
    ....'......',,'.,,..     ...   ..................',,,'.....                         .,;;,,,'....
  ....',,...'',,;;',;;'..  .....   .................'',;,'''...                          .''''......
 ...',;;,..,',;;::;;c;.......'.. ...''''''........'',,;;;;,'....                          ..........
...';;::;,',;;cccc;:c:,.....,'....',,,,,;;';,.'..,:;;::::;;,....                           .........
..,clodddddddlc:;,,;::,.''';;'...,:;;:ccc;;l:',.':lc:cc:;;,,..'.                            ........
';coxkkkO0000xc'....,,',;;clc,..;ll:;clcc:co:''',clc:ll::;,'..'.                             .......
clodkkkOO0000Ox:......';:lxxc,':oddlloooollc:,.':lolcoocc:,..''..                             ......
oddxkOOOOOO000Oxlc:;,''cdO0xl:cx0Odoxxolc:;'...';clccllllc;'','...                            ......
oodxxkkxxkkOKK0OOxdddddk0KK0kxOKX0kxxdlcc:;;,,;:cclllcclol;'','...                             .....
ll:,'''..';lxOKKK0OOOO0KXXXXXKKXXK0kddocccccclodxkOOOkkkdl:;;,'......                          .....
lc,...;lll;',:dO0K0000KXXXXNNXXNXXKOxxdoodxxxkOO0KKK00OOxdol:;;,......                          ....
dolc,.:dxOOko''lk00000KKXXXNNXXXXXKOOkkkkO0000KK000KK00Okkxoc::,....'..                         ....
kOOOkdc;:okO0x;,dO0KK00KXXNNNXXXXKK0000KK00000O0000KKXXK0Oxdol:,',,;;,..                        ....
O0KKKKKOol::cdo:o0KKKKKKKXXXXXXXKKKKKKKK0koc::;:codx0KXKK0Okxolcccccc;..                        ....
00KKKKKKK0kl:::;o0K00KXKXXXXXKKKKKKKKXKxc,;clc;'...':ok0KKK0kxxxdoooc:.                         ....
O0000KKKKK0kxkOkk000000KKKKKK0000KKKXKd::lx0K0kdoc;'..:xO000K0Okxxxol:.                         ....
O0OOO00KKK0kxk0K0OOOOOO00000000000000d:coooodoccc;;;:ldkkO0KK0OOkkxol,.                         ...'
OOOOOO00000kxxO0OkkkkkkOO00000O000000kddddddoooodxkOOOOOO00000OOkkxoc'....                      .:xO
OO0OO000000kxxkOkkkkkkkO000000O00KK00KXXXKXNNXXKKKKK0000000000Okkxxo;......                     .xWW
00000000000OkOOOOkkkkkkO0KKK0000000KKKXXXNNXXKKKKKKKKKKKK00000Okxxdc'..,;'.                     .lXW
00000000000OOOOkkkxkOOO0KKK000OO00KKKKXXXXXXKKKKXXXXXXXKKK0000Okxdl,...,;'.                     .,OW
O000000K00kddxdddxkOO000KK00OOO00KKK0KXXXKKKKKKKKKXKKKKKKK00OOkxdl;....'..                      .'dN
O000000OkkocloddxkO00KKK000OOkOO00K00KKXXK00000KKKKKK0000OOOOkxoc;''....                        .':O
O0K000OkkxdloxkkOO0KKXKK00OOOkkkkO0KKKKXKK00000000000000OOOkkkdl:,,,'..                          ',l
kO00OOkkkkxdxkO00KKXXXKKK00OOkxxdk0XXXXKKKKKKKK0000000000Okkkkdc;;;,.                            .;;
dxxkkkkkkkkdddxO00KKXKK0000000kxdx0KKKXKKKKKKKKK00000000Okxxxdc;;:;'.                             ':
ddoooddddxdooddxkkO000OOkxdxOOOkxk00KKKKKKKKKKKK0000000OOkxxdc::c:,.                              .;
dolc:::clllloddxxkkkkkkxddddxkkkOO0000KKKKK000000000OOOOkxxdl,.''.                                 .
doc,'',,;;::ccoddxxxxkxxxddddddkkO0OO0KKK00000OO00000OOkkxxo,
ol:'..........,;cccldddddooooodxxxxxxxkOOOOOOOOOOOOOOOOkkxl,.
doc,.    ... . ......''',;:cclodoolllldxkkkOOOkkkOOOOOkxdl'
kxl,.    ...','........   ....';:c::::oxkOOOkkkkOOOOOkxoc.
Oxo;.       ...   ......''...   ...',:okkkOkxkkkOOOOkxo;.
kxo:.                 ..''...     ..,coxxxkkkkkkkkkxo:.
kxo:.      ..           ..       .,:coxkkxkkkkkxdolc,.
xddl'..    ...        ...       .:oddxkOOkkkkkdl:,..
xxxd:..     ............      .'cdkkOOOOOOkxdoc,.
dxxdl,.      .........      ..,ldkkOO00Okxol:,.
dxxdl:..                   .';lxkkkOOkkxdoc,..
dxxdl:;..   ..           ..'coxxkOOOkdooc;..
odxxdocc:'..  .        ..,cdxxxxkkkxoll:..
lodxxdddoool:;,'....',;coxkOOkkkkxdol;..
,ldxkkxxxkkkxdooolooddxkOOO0OOkkdl:,.
 'ldxkOO00KK0OOOkxxkxxkOKKK00Oxo:'.
  .:oxk0KXXXXKKK000OkkkO0KXKOo;.
    .cdk0KKXNNNXXKXK0OkOKKOd;.
      .,coxO0KKKKK0OO0kxo,...                              .               ..
          ..'',;:;;;,,.                                   ..             ...
                                                         ...            ...
                                                         ...            ...
      )"; //image source: https://lihkg.com/thread/400735/page/4
      onesecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMM
MMMMMMMMMMNOdollllllllllllllllllllllllllllllllllllllllllllllllllllllllxXWMMMMMMM
MMMMMMMMMWKd:'..'',,,,,,,,,,,,,'''''',,,,,,,,,,,,,,,'''''',,,,,,,,,,',l0WMMMMMMM
MMMMMMMMMWKd:'';lk0000000000000kxdodxkO00000000000OkdoodxOO00000000000KNMMMMMMMM
MMMMMMMMMWKd:,':xNMMMMMMMMMMMMWXxl:lkKWMMMMMMMMMMMWKd::oOXWMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMWXd:'':xXNXXXXXXXXXXXKOl;';okKXXXXXXXXXXXKkc'':dOKXXXXXXXXXXXNWMMMMMMMM
MMMMMMMMMWKd:'':x0kl:::::::::::;,''',;:::::::::::::;,''',;:::::::::::lxXWMMMMMMM
MMMMMMMMMWKd:,':xKOoccccccccccc:,''',:ccccccccccccc:,''';:cccccccccccokXWMMMMMMM
MMMMMMMMMWKd:,':xXWNNNNNNNNNNNX0d:;cd0XNNNNNNNNNNNXOl;;cx0XNNNNNNNNNNNWWMMMMMMMM
MMMMMMMMMWKd:,':xNMMMMMWNNNNNNNKkdodOKXNNNNNNNNNNNXKkdoxOKXNNNNNNWMMMMMMMMMMMMMM
MMMMMMMMMWKd:,':xNMMMMWKkoooooolllllllooooooooooooolllllllooooodkXWMMMMMMMMMMMMM
MMMMMMMMMWKd:,':xNMMMWNOl,',:clllllllllllc;,',;:clllllllllcc:,,;l0WMMMMMMMMMMMMM
MMMMMMMMMWKd:,':xNMMMWNOc'':kXNNNNNNNNNNNKd;',oOXNNNNNNNNNX0xc',l0WMMMMMMMMMMMMM
MMMMMMMMMWKd:,':xNMMMWNOc'':xKXXXXXXXXXXX0o;',lkKXXXXXXXXXK0d:',l0WMMMMMMMMMMMMM
MMMMMMMMMWKd:'':xNMMMWNOc'.,:ccccccccccccc;''',:ccccccccccc:;,',l0WMMMMMMMMMMMMM
MMMMMMMMMWKd:'':xNMMMWNOc'.,cooooooooooool:,'';coooooooooool:,',l0WMMMMMMMMMMMMM
MMMMMMMMMWKd:',:kNMMMWNOc'':ONWWWWWWWWWWWXd;',o0XWWWWWWWWWNKkc,,l0WMMMMMMMMMMMMM
MMMMMMMMMWKd;',ckNMMMWNOc'':d00KKKKKKKKK0Oo;',lxO0KKKKKKKK0Od:',l0WMMMMMMMMMMMMM
MMMMMMMMMWKo,',lONMMMWNOc'.';:::::::::::::,''',;::::::::::::;,',l0WMMMMMMMMMMMMM
MMMMMMMMMW0l,';o0WMMMWNOl'';ldxxxxxxxxxxxdc,',:ldxxxxxxxxxdol;,,l0WMMMMMMMMMMMMM
MMMMMMMMMNOc'':xKWMMMWWX0kkOXWWWWWWWWWWWWXx;';o0NWWWWWWWWWWNX0kk0XWMMMMMMMMMMMMM
MMMMMMMMWXk:''ckXWWWNXXXXXXXXXXXXXXXXXXXK0o;',lk0KXXXXXXXXXXXXXXXXXXXWMMMMMMMMMM
MMMMMMMMWKd;.'lONWN0dlcccccccccccccccccccc;''',:ccccccccccccccccccccdKWMMMMMMMMM
MMMMMMMMNOl,',oKWWXkc'',:clllllllllllllllc;''';:clllllllcclllllc:,.'c0WMMMMMMMMM
MMMMMMMWKd;'':xXMWXkc,,ckKXXXXXXXXXXXXXXX0d;',lkKXXXXX0kxk0KXXX0xc''cOWMMMMMMMMM
MMMMMMWNOc'';o0NMWXOc,,l0WMMMMMMMMMMWWWWWXx;',o0NWWWNKkl:lkXWMWNOc''cOWMMMMMMMMM
MMMMMMN0o;''ckXWMWXkc,,l0WWWNXXXXXKK00000kl,'':odxdolc;,'':xXWWNOc''cOWMMMMMMMMM
MMMMMWKd:'',oKWMMWXkc,,l0NXOl::::::;;;;:::;,,,;;;::;;;;;,',ckXWNOc''cOWMMMMMMMMM
MMMMWKx:'';lONMMMWXkc,,l0WN0o;;;;;::ccclooddxkkOOO00KKK0OoclkXWNOc''c0WMMMMMMMMM
MMMWXd:'''cONWMMMWXkc,,l0WMWXXXXXXXXXXNNNNNNWWWWWWMMWWXXK000KKKko;''c0WMMMMMMMMM
MMMWKd;',ckXMMMMMWXkc,,l0WMMMMMMMMMMMMMMMMMMMMMMMMMMW0o:;::c::;,'',cxXWMMMMMMMMM
MMMMNKxloONWMMMMMWXOc,,l0WMMMMMMMMMMMMMMMMMMMMMMMMMMWKo:;;;;;;;::cd0NWMMMMMMMMMM
MMMMMWWXXWMMMMMMMMNKxookKWMMMMMMMMMMMMMMMMMMMMMMMMMMMWXK0000000KXNNWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
      )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0kkkOKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOl,',;o0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0o;'.';oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWKx:''';lkNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,
MMMMMMMMMMMMWN0kkkkkkkkkkkkkkkkkkkxo:'.'';coxkkkkkkkkkkkkkkkkkkkkkkkkOXWMMMMMNd,
MMMMMMMMMMMMW0l,''''''''''''''''''''.....'''''''''''''''''''''''''''':ONMMMMMNd,
MMMMMMMMMMMMW0l,'',;cllllllllllllllllc;,'''',:cllllllllllllllllc:,'.':kNWMMMMNd,
MMMMMMMMMMMMW0l,',:d0NNNNNNNNNNNNNNNNKx:,'',ckXNNNNNNNNNNNNNNNNKkl;'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:xXWMMMMMMMMMMMMMMMNx:,'';lONMMMMMMMMMMMMMMMMNOo;'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:xXMMMMMMMMMMMMMMMWXx:,'';lONMMMMMMMMMMMMMMMMNOo;'':kNWMMMMNd,
MMMMMMMMMMMMW0l,',:xXWMMMMMMMMMMMMMMWXd;''';o0NMMMMMMMMMMMMMMMMNOo;'':kNWMMMMNd,
MMMMMMMMMMMMW0l,'';lk000000000000000Okl,''';lxO0000000000000000Odc,'':kNMMMMMNd,
MMMMMMMMMMMMW0l,'''',,,,,,,,,,,,,,,,,,''...'',,,,,,,,,,,,,,,,,,,'''.':kNMMMMMNd,
MMMMMMMMMMMMW0l,''',;:::::::::::::::;;,'..'',;;::::::::::::::::;,,'.':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:oOXXXXXXXXXXXXXXK0kc'..'cx0KXXXXXXXXXXXXXXXX0xl,'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:xXMMMMMMMMMMMMMMWXOl,..,l0NWMMMMMMMMMMMMMMMMNOo;'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:xXMMMMMMMMMMMMMMWXkc'..,oKWMMMMMMMMMMMMMMMMMNOo;'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:xXWMMMMMMMMMMMMMW0d:'.';dXWMMMMMMMMMMMMMMMMMNOo;'':kNMMMMMNd,
MMMMMMMMMMMMW0l,',:oOXXXXXXXXXXXXXXKxc,''':d0XXXXXXXXXXXXXXXXXX0xc,'':kNMMMMMNd,
MMMMMMMMMMMMW0l,''',;::::::::::::::;,'''''',;::::::::::::::::::;;,'.':kNMMMMMNd,
MMMMMMMMMMMMW0l,'''',,,,,,,,,,,,,,''...''',,,,,,,,,,,,,,,,,,,,,,'''.':kNMMMMMNd,
MMMMMMMMMMMMW0l,'';lk000000000000ko;''';cok000000000000OkkkOO00Odc;,,cONMMMMMNd,
MMMMMMMMMMMMW0o;,;lxXMMMMMMMMMMWN0o;'';ldxO0KXNWMMMMMWXOoccd0NWWX0kxkOXWMMMMMNd,
MMMMMMMMMMMMMNX000KNWMMMMMMMMMWNOo;'',ldxoc::d0NWMMMWXkc,,:d0NNXXXNWWWWMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKkl,'':okOko,.'ckXWMMWXkc,,cx0KOdllxKWMMMMMMMMMNd,
MMMMMMMMMMMMMMMMMMMMMMMMMMMWN0d:,'':d0X0ko,.'ckXWMW0d:,;lkXWN0o;,;oOXWMMMMWWWXd,
MMMMMMMMMMMMMMMMMMMMMMMMMWN0xc,'',cxKWN0ko,.'ckXNXOo;,;lOXWWWXOo:',ckKWMWXOdxdc'
MMMMMMMMMMMMMMMMMMMMMMMWN0xc,'',:oONWWN0ko,.'ck00xc,',:oxkkxddoc;'.':o0NN0o,,,,'
MMMMMMMMMMMMMMMMMMMMMWXOdc,'',:okXWMMWN0ko,.'ckOxl,.'',;;;;,,,,,''''';oO0Ol'....
MMMMMMMMMMMMMMMMMMWN0xl:,'.';lkKWMMMMWN0ko,.'ck00xc;:cclooddxxxkkxdl;;okOkc'.'.'
MMMMMMMMMMMMMMMWNKko:;'.',:oOXWMMMMMMWN0ko,.'ckXNX000KKXXNNWWWWMMWNXOOKX0d:'''''
MMMMMMMMMMMMWNKkdc;'''',cdOXWMMMMMMMMWN0ko,.'cxKWMMMMMMMMMMMMMMMMMMMWWWXkl,',,,'
MMMMMMMMWNKOxo:;'''',:okKNWMMMMMMMMMMMWK0d;'',cdOKXXNNNXXXXXXXXXXXXXK0kdc,'':c;'
MMMMMWNKkdc;,'.'',:lxOXWMMMMMMMMMMMMMMMNXOl;'.',:cllllllllllllllllllc:;'''';oxl,
MMMMMWNOo;'..',:lx0XWWMMMMMMMMMMMMMMMMMWWN0xl;,''''.''''''''''''''''.''';cokKKd,
MMMMMMWN0xc:loxOXWMMMMMMMMMMMMMMMMMMMMMMMMWNKOxddddddddddddddddddddddddxO0XWMNd,
MMMMMMMMWNKKXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMNd,
      )";
      halfasecsleep();
      ClearScreen();
    }else if (o == 'H'){
      //imagesource:https://zh-tw.ac-illust.com/clip-art/1883969/%E9%A4%93%E9%AC%BC
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWXOdllodxdddxOXWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWO;....',:cc::;cOWMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNKOxdol;............'';dXWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMWWWXkol:;,,',,,,,,,,........  .,lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0OOOo;,',;;,,,,,,,,,'...',;,,',,'...:0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWXKOl'.',,',,,,,,,,',,,,'..',;;;;;;:cc:;,.oWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWW0oc,...,,,,,,,,'',,,,,,'.....',,;;;;:cc::;;oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo;'. .,,,,,,,,,,,,,,,,,'...'',,,,;;;:::cc;;';OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc,....',;,,,,,,,,,,,,,,,'...',,;;,''',::::,:;.,kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx;..',,,,,,,;,,,,,,,,,,,,,'...,;;:::,''.';c:',:,.;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKl..',,,,,,',;,,,,,,,,,,,,',,''.';:::cc,''.,c,.;;..cKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo..,,,,,,,,,,;,',,,,,,,,,,,,,,,'.,:c::l;',,;;';;..'xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'.',,''',,,,,'..,,......''',,,,...':::l;,;,:;;;.''lNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc.,,,,,,,,,,,,........'''''',,,'.  .,','':;;::;';':XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx,,,'''''',,,,,..',,,,,,''....''.  .....':::cc;,:,cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO,.......',,,,,.',,'.........','.  ......,:cc:;,c:dNMMMMMMMMMWXKKXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0,.',,,,,,'.............:o;..,,.  .....'.':l:;';ccOWMMWWWWN0xl:;;;cxKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMX:.,,'......     . .lkxkO0l..,'.  ........cc;'.,;lKMWWWXOdc,,,,,,'..,oKWMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:.... ..c:........ .:ool:. .'...... ..'.':;,'...,lkkdc'..,,',,,,,,,''c0WWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKo;'...cdk0x'.,,,'''.........,'....  .....;l:,''....'.. .',,,,,,,,,,,,,,oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk:,,,..,ldo;.',,,'',',,''''',,'........ ..,;ll;,;;.... ..,,',,,,',,,,,,'cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx;''::'......',,'..',,'',,,,,,,...'',,. ..,,;cc'';;'.  .,,,,,,'..',,,,,'lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk;.'cc:'.','..''..',,,,':dc,,'....,,,'.  ..',;:;,',:. .',,'..'. .',,,,,'cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOl',l:;,.','.....,,,,,,';kOo;. ...'...    ..,;::c::;..,,,,'......,,,,,,'.dWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOl;:c;'..,c:,,'.'',:,'cllkk:.... .        ';:ccc;;'.',,,','.  .,,,,,,,,.;KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWXkolc,...;dxc'co'.cl',;..''','.          .;:ccc,,'',,,,,''.  .,,,,,,,,..oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMWKko:'''.'cc,,c,......''',,'.           .;:::c;,'',,,,,,'.  .',,,,,,,. 'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWXko:;,.',.... ..''...',,,,'..            ..;,'c:,,,,,,,,,'.  ..',,,,,,...lNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o;''','''',,'..',,,,,'''..........     .''.''':lc;,,,,,,,.. .  ..',,,,'. ,KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXd:..;,,,,,'',,'.............',,,''''...'',,''.':lc;;,',,,....''.. .',,,'. '0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo;..',;,,'..,,,,'......'',,,,,,,,,,,,,,,,,,,''.':c;,',,....',,,'. ..,,,,. 'OMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd:;''''''...,,,,,,,,,,,,,,,,,,,,,,,,,,'.',,,,,'..',;,'...,,,,,''.  .,,,,'.;XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0occ:'..  ..,,,'.''',,,,,,,,,,,,,,,,,,'',,,,,''''...'''',,,,''...  .,,,,'.oWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWKxoc:;,...,,,,.. ....',,,,,,,,,,,''''''..',,''',,,,''',,,''..     .,,,,.'xWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOoc:;'',,',,. ..  ....''''''...'''','.',,,,;;,,,,,,,,,,'.  .....,,',,.,0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXxcll;',,,,'......... ......'',''''..',''''''''',,,,'....'','..,,,,'..;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxdk:',,,,,..';,';d:.',...,,,''''''''''''''''''''''...,,,,,,..,,,,'...;xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKKXo',,,,,,.'c;;lxl',,'',,,,.. ..,,,,,'''......'',,,,,,,'....,,,,'...',oKWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWk,',,,,,''::;dx;,,,'',,,,'.  ...',,,,,,,''...''''''......',,,,'....,,cOWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMWWWWWMMMMMMMMMWNNNWMWMMMMMMWMMMMMMMMMMMMMMMNc..,,,,,'':oOk;',,...'',,'.   ....'''',,,,,''........,..',,,,.....,,,;xXWMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMNKXWWMWWWNKOxolc::lxxdxkO0XWMMMMMMMMMMMMMMMM0,..',,,''xNWO,.'........''....    ...''',,,,,,'''''.....',,'.....',,,,c0WMMMMMMMMMMMMMMMMMMMMMMM      )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMXdcldxxdoc;,''..''  ..',,;coxk0XWMWWMMMMMMMMNo..,,,,';OWNd. . ..:ol' 'kX0kOxc,..  .....',,,,,,,,'''........'..',,,,';xNMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMW0dc:::,.......',...','...',;;:ld0WMMMMMMMWMk'',,,,':kkl,.   ..dOd;.oNMMMMWWKc.       ....',,,,,,,,,'.   .'. .,,,''.'dWMMMMMMMMMMMMMMMMMMMMM
MWKkOO0KNWNKOdll:..'.....,':x0KXKx:...',,,';lkKNMMWMMMO;''.....'';;.....'kx;,lXMMWWWMWKl.           ...',,,,,,..  .... .','..'.,OMWWMMMMMMMMMMMMMMMMMM
MNxc:;,;::,....'....'''..''oNWWMWWN0o,..,,,,,,;lx0NWMWk,''....''......';dKkcl0MMMMWXx:.. .................',,,.   ... ..,'..',. :KWMMMMMMMMMMMMMMMMMMM
WMMNXKOkdlcoxkdc'... ... .,OMMWMMMWWMXx;..';,,,'',cdOKo'',....;;;:,..'dXWMNXNWWMWKo,.....'''',,,,,,,,''.....''. ..    .....',,...:KMWMMMMMMMMMMMMMMMMM
WMMWMNKOdoolc;..,ol. .;;. :XMMMMMMMMMWWNk;..'''''',,,;'.','. ,0NNNX0OKWMWMMMMWWKd;.',,,,,',,,,,,,,,,,,,,,''.....'....    .',','...cXMMMMMMMMMMMMMMMMMM
WWWWOl,,,:looook0x, .ld,.,kWWMMMMMMMMMMMWNk:...',,,,,,,'.',..lWMMMMMMMMMWMMWWXx:',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',,''....',,,,''',dWMMMMMMMMMMMMMMMMM
MWWXkdxOKNWWWNOo,.,lxo,,dKWWWMMMMMMMMMMMWWWNO:..',,,,,,,'',..xMMMMMMMMMMWWWXOc,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''...',,,,,,';0WMMMMMMMMMMMMMMMM
MWWWMMMMMWMNx:;lx0NXl,lKWWMMWMMMMMMMMMMMMMMWMWKd:,',,,,,',;.'OMMMMMMMMMMWXo:,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''',,,,,,',oXMMMMMMMMMMMMMMMM
MMMMMMMMMMNkcdKNWMWXxxNMMWMMWMMMMMMMMMMMMMMMMMMMNOdc,..''',':KMMMMMMMMMWKc,,,,,,'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',,,,,,,,,,,;kWMMMMMMMMMMMMMMM
MMMMMMMMMMWNNMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWKo'..',,dNMMMMMMWWXx:,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'cKMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWKdcldOXWWMMMMMW0:',,''',',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',,,,,,,,,,,,,,'.dWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWWMWWMMWWWO;',,'',,',,,,,,,,,,''',,,,,,,,,,,,',,,,,,,,,,'''',,,,,,,,,,,'','.'OWMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMWW0:',',,',,,,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'..,0WMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXl',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.;0WMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWx,',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.:0WMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc',,,,,,,,,,,,,,,,,,,,,,,,,',,,,,,,,,,,,,,,,,,,,,,,,,'',,,,,,,,,,,,'....cXMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO;',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',,,,,,,,,,,,'......cXMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk,',,,,,,'''',,,,,,,,,,,'',,,,,,,,,,,,,,,,,,,,,,,,''',,,,,,,,,,''.. ..'.;KWMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMk'',,,,'''',,,,,,,,,,,,''',,,,,,,,,,,,,,,,,,,,,,''''',,,,,,,,,''...'''.'OMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMO;',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,''....dWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc.,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'....'.'OWMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',,,,,,,,,,,,,,,,,,,'.....','..kWMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXc',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'...''',,..,oKMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWk;',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'',',,;locoKMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNo',,,,''',,,,,''.',,',,,,,,,,,,,,''',,,,,,,,,,,,'',,,,,,,,,,''',coddl:dNMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXc',''''',,',,,,..',,,,,,,,,,,,,'''''',,,,,,,'',,,,,',,,,,''';ldxdll:,lKMWMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKc',,,,,,,,,,,,'..',,,,,,,,,,,,,,,,,,,,,,,,,,,',,,','',,,;cdkkdocc::ccdXWMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXl,,,,,,,,,,,,,'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',:loooxkOOkxolcclllllxXWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0c'',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,',codooodkkkkkxoodkdlllloOWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWW0xdlc,'''',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,;loollodxkkkkkxxkkkkdllodokWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWXxoxOkxxdoc;,'',,,,,,,'',,,,,,,,,,,,,,,,,,,,,,;cllcclooodkkOkkkkkkkxooxkxlkWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOOdccldxxkkkkkdc:;,,'''''',,,,,,,,,,,''''''...';looodxxxxxkkkkkkkkkOkddkkOxlkWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOdodkkxdddooooddollllcccc::;,,'''''...........,coddxdddddxkkkkkkkkkkkkkkkkkkdlkWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWKddo:lkkkkxxddooollccclccloooddddollcccccc:;;;::clllllcloodxkkkkkkkkkkkkkkkkkxolkWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNkool,;dkkkkkxllllooooooolccclcclooddxxxdollllllc:cccllodxkkOOkkkkkkkkkkkkkkkkxollkWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNxll,...okkkOOkdlolllcllddxxddxdddooooooodddxxxxdocccldxkkkkkkkkkOkkkkkkkkOkkkxdollOMWMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWk:,.....co:lkxddocccclcllcokOOkOkkkkxdodkOOkkkoc::cldxkxxdxkkkkkOkkkkOkOOOOxdollocc0MMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWNk;.'''',,,...'..:c;::cllll:lkOkkkkkxolldkkOkxo:;,,:oxxxdlc:lkkkkkkkkkkkkOOOxollollcl0WWMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMW0o,',''',,,,,,'.  .:cdOdclclodkOkdxkdlc,:xkkxl'.... .oxc;,....lkkkOOkxxOkkkOkdllONKdl:xWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWKo;'',,,,,,'''....,oONWWWOc:dKXxddddoll:. 'dkl,.      .''..  ..:odkkkOdldkkkOOxooOWWWWXO0WWMMMMMM

      )";
      onesecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMWKO0NWMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0O0KXNWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMWO:..,o0NMMMMMMMMMMMMMMMMMMMMMMMMMMWO;...:xXWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMW0c.  .ckNMMMMMMMMMMMMMMMMMMWNKkxkXWWO;  .cKWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMW0c.  .l0WMMMMMMMMMWWWWNNXKOdc;.. .:OX0:  .oXMMMWNNWMMMMMMMMMM
MMMMMMMMMMMMMMMMMNk;.    .:d0NMMMMNKkdolc:,...   ..',:d0O:  .oXWNOo;;dKWMMMMMMMM
MMMMMMMMMMMMMMMWXx,  .:c,.  .cxKWWNk;.         .:xKXNWWW0:. .oXWXx,  .:kNMMMMMMM
MMMMMMMMMMMMMMNOc. .;kXNXkc.  .'lOXNOl:lodkkl. .dNMMMMMW0c. .oXMMNOc.  .l0WMMMMM
MMMMMMMMMMMMWKo'  .lOKXNMWN0o,.  .;dKNNWWWMNx' .dNMMMMMMKl. .oXMMMWXx,  .;kNMMMM
MMMMMMMMMMWKd,. .;xOo;,l0WMMWKx:.  ,kNMMMMMNx' .dNMMMMMMXl. .oNMMMMMNOc..'oKWMMM
MMMMMMMMN0d,.  'oKNXx;..,dKWMMWXkllONMMMMMMNx' .dNMMMMMMXl. .oNMMMMMMWKkxOXWMMMM
MMMMMMNOl'   .cONMMMW0l. .:ONMMMWWWWMMMMMMMNx' .dNMMMMMMXo. .dNMMMMMMMMMWMMMMMMM
MMMMMMN0l'..:xXWMMMMMMNk:':kNMMMMMWNNNNNNWWXd' .oXNWWWWWKo. .oKNWNWWWNWWNNNNWMMM
MMMMMMMMN0kOKNXKKXXXXXXKOkOKKXKKXXOl::ccccc:'.  ':cccccc:'.  ':ccccccccc:;:dXMMM
MMMMMMMMMMMMW0c,''''''''''''''',o0x;.                                     .lKMMM
MMMMMMMMMMMMW0:.  ...........  .lKX0kkkkkkkxc. .:xkkkkkkx:. .:xkkkkkkkkkkkOKWMMM
MMMMMMMMMMMMW0c. ,xKXXXXXXXKo. .oXMMMMMMMMMNx' .dNMMMMMMNx' .lXWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMW0:..;OWMMMMMMMNx' .oXMMMMMMMMMNx' .dNMMMMMMNk, .cKWMMMWXO0XNWMMMMMM
MMMMMMMMMMMMW0:. ;kNWWWWWWWXd' .oXMMMMMMMMMNx' .dNMMMMMMNO;  :0WMMWXd'.':dKWMMMM
MMMMMMMMMMMMW0:. .,:::::::::'. .oXMMMMMMMMMNx' .dNMWNK0KN0:  ,OWMMNk;   ,o0NMMMM
MMMMMMMMMMMMW0:.  ..........   .oXMMMMMMMMMNx' .lOko:''oKKc. 'kNMWKc. .;ONMMMMMM
MMMMMMMMMMMMW0:. ,d0KKKKKKK0o. .oXMMMMMMMMMNx'  ...  .;dXXd. .dXMXo.  ;kNMMMMMMM
MMMMMMMMMMMMW0:..;OWMMMMMMMNx' .oXMMMWWXX0xl'.   .,cdOKNWWk, .lKXx'  ,kNMMMMMMMM
MMMMMMMMMMMMW0:. ;kNWWWWWWWXx' .oKN0ko:,...    .cOXWMMMMMW0:..:kx,  'xXMMMMMMMMM
MMMMMMMMMMMMW0:. .;clllllllc,. .oK0l.    .,:;. .dNMMMMMMMMXo. .,.  'dXMMMMMMMMMM
MMMMMMMMMMMMW0:.   .......... .'oKNOc,:oxOXXx' .dNMMMMMMMMNk,     'xXMMMMMMMMMMM
MMMMMMMMMMMMW0:. 'oO0000OkxO0000XWMWNXNWMMMNx' .dNMMMMMMMMMKl.   ,xXMMMMMMMMMMMM
MMMMMMMMMMMMW0:. ;OWMMWKd:;oKWMMMMMMMMMMMMMNx' .dNMMMMMMMMWKl.  .dXMMMMMMMMMMMMM
MMMMMMMMMMMMW0:. ;OWMMW0c. .;kNMMMMMMMMMMMMNx' .dNMMMMMMMNO:.   .lKWMMMMMMMMMMMM
MMMMMMMMMMMMW0:..;OWMMMWXx,  .oKWMMMMMMMMMMNx' .dNMMMMMN0l.  ..  .oKWMMMMWWMMMMM
MMMMMMMMMMMMW0:..;OWMMMWNOc.  .:ONMMMMMMMMMNx' .dNMMWXOc.  .ckkc. .oKWMMW0xx0NWM
MMMMMMMMMMMMW0:..;OWNXOo;..     ,xXWMMMMMMMNx' .dKXOo;.  .:kXWW0l. .c0WMNd'..c0W
MMMMMMMMMMMMW0:. 'loc'.  .':ol' .:ONXKKKKK0k:. .oOo,   .:kXWMMMWKo. .,d0O:. .:0W
MMMMMMMMMMMMXd'      ..:dOXWWNOdd0NN0l,'....  .;kNXx:,:xXWMMMMMMMXx,  ....  ,kNM
MMMMMMMMMMMWKl.   .,lkKNWMMMMMWWWMMMNd'    ..,lONMMWNKXWMMMMMMMMMMW0l.     'dXWM
MMMMMMMMMMMMWKo;:o0NWMMMMMMMMMMMMMMMWKkdddxOKXWWMMMMMMMMMMMMMMMMMMMMNOl'..;xXMMM
MMMMMMMMMMMMMWNXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWK0OXWMMMM
      )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc,;cokKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.  .;dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:. .oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo. .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMWX0kO000000000000ko'  ,oO0000000000000000000000000OOk0NWMMMMMMMMMMMMM
MMMMMMMMMMMW0c................    .............................'lKWMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ..................    .....................   .oXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .cOXXXXXXXXXXXXXX0o.  'x0KXXXXXXXXXXXXXXXXXO:. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXd'  'kXNMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWWKd'  'xKXNWWWWWWWWWWWWWWNN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   .:cccccccccccccc:'.  .,:cccccccccccccccccc;.  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:                                                 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   'cooooooooooooool;.  .coooooooooooooooooooc'  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXo. .cKWWMMMMMMMMMMMMMMMMMKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMKl. .lXWMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMWKc. .dXMMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWNO;. 'dXWWWWWWWWWWWWWWWWWWN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ':llllllllllllll;.  .;lollllllllllllllllll:.  .oXMMMMMMMMMMMMMM
MMMMMMMMMMMW0:                                                 .lKWMMMMMMMMMMMMM
MMMMMMMMMMMWXkolllllllllollllolc'   .:lllllllllloollllc:ccllllldONMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNO;  .lOOdlodxOKWMMMMMMXkc;lkKWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  ;kKd'.. .cONMMMMMWO:. .:xXWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMW0l.  'dXNk,.  'dXMMMMMW0l. .o0NWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  .oKWWk,. .;kWMMMMWKl. 'dXWWXOxkKWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMNO:.  .lKWMWk,. .;OWMMMWKo..,dXWMXk:..:kXWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWXd,   'oKWMMNk,. .;OWMMW0l..;kNWMMWXk:. .l0WMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNOc.  .;xXWMMMWk,. .;ONN0o,..,ok0Okkxxo:.  .;xXWMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMN0o'   'o0WMMMMMWk,. .;ONXd'   .............  .;kNWWMMMMMMM
MMMMMMMMMMMMMMMMMMMN0o,.  .cONMMMMMMMWk,. .;OWWKd,..',:codxkOO00OxooOXNKOOKNWMMM
MMMMMMMMMMMMMMMMWKkc'   .ckXWMMMMMMMMWk,. .;OWMWN00KXNNWWWWMMMMMMWWWMMXx,.,o0NMM
MMMMMMMMMMMMWNXkl,.   'lONWMMMMMMMMMMNk,. .;OWMMMMMMMMMMMMMMMMMMMMMMMNO;.  ,kNMM
MMMMMMMMWNX0xc'.   .;d0NMMMMMMMMMMMMMNk,.  'dXWMMMMMMMMMMMMMMMMMMMMWXx;.  'dXMMM
MMMWNK0kdc'.    .,lOXWMMMMMMMMMMMMMMMWO;..  'cxkOOOO00KK00KK000OOkxo;.  .,xXWMMM
MWNOl,.      .;lkXWWMMMMMMMMMMMMMMMMMMXdc,         .............       'lONMMMMM
MMNKd;.  .':dOXWMMMMMMMMMMMMMMMMMMMMMMMNX0dc,...              ....',:lx0NWMMMMMM
MMMMWKdlokKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXK0OOOOOOOOOOOOOOOO00KKXNWWMMMMMMMMM
      )";
      halfasecsleep();
      ClearScreen();
      //credit https://www.deviantart.com/kostk2boss
    }else if (o == 'P'){
      cout << R"(

MMMMMMMMMMMMMMMWK0KXNNK0XNN0OkkkkOOOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWKkkO00OOKK0OkkO00KK0O0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMMMMMNK00000000000XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWX0OkOOOOO0000OKNNNNK0OOKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWXOxl'...........:dkKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMWX0O0XXK0KNNNXNWWWWNKOOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXxl;.                 'o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMN0O0XWNNNNNNWWWWNNNKOkOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMWXx;.                      'oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWNK0KNNNNNKKXNWNXKXKOkkOXWMMMMMMMMMMMMMMMMMMMMMMMMMWXx;.                          'o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMWNK0KX0KXKOO0XNKO00OkkOKNWWMMMMMMMMMMMMMMMMMMMMMWXx;.                              :0WMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMWWN000OO0OkkkO0OkkkkkkkO0NWMMMMMMMMMMMMMMMMMMMMNk;.    ..,;;::::::;'.              .:OWMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMWNK0OkkkkkkkkkkkkkkkkkO0XNNWWMMMMMMMMMMMMMMMWO;   .,:ldkO0000K000kdc;.             c0WWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMWWNKOOkkkkkkkkkkkkkkOOkOO0KXNNWMMMMMMMMMMMWO,   .coollldk0KKKK0OO00ko;.           .;0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWNXKKOOkOOkkkOkkkkkkkkkOOO0KXNWWWWMMMMNk:.  .:lccoddolokOOxlcldO00ko'           'kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWWNXXXK0OOOOOOOOkkkkkkkkkkO00KKXWWW0;   .;::okKK0xccloccdxdlldOOxl'          .;kNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNNNNNNNXK0OkkkOOkkkOkkkOOOko,.  .;:coxxdoloddl:c0NXko:ldxd:.           cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWNXKKK0Okkkkkkxdolcc;...cdocccodxO0Oo:ckKKklclxxl'..,c,       ,xXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWNXXKOkxolcccllcc;;loddxk0KKKK0koclllloxOOo,.'cdo,        'kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKkc'....';:::::lllodxO0KKKKOkdlcoxO0kl'';ll:'.        .kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0Ox:..            .:ollclooddooolodk00kl'.  ...           .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWXkoc'.     .'.         .;codxkkkkkkxxxxkkl'.                   .cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNKxc::,.     .'coc;.           .;coxOOOOOOkxdc'.                      ;0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMXklc,........:xOOkl.               ..';:cccc;,...                       .;OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXXKKKXKKXXNN0l.                .';;;cdxdc'                            .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMWMMMMMN0l.                 .:dkxdk0Oo,.     ....   ..               ,xXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0l.                   .lOKKKKKk:. ..  ......   ...              ;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMWX0kl.                  .. .lOKKKKOc. ...  .......   ...             'xXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWN0xo;.                    .....;d0K0kc......  ........   ...             .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXklcc;.       .',.            .......,dxxc........  ........   ...            .lXWMMMMMMMWMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOl,.      ....:ddc'.            .....................  .......   ...             .lKWMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNOc;;,,,;lOKKKOd,.    ..        .....................  .......   .         ..     'OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNNNNNWWWXx;.    .;c;.       ......................  ......            .ol.    .:OWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMMMWKd;.    .ck0c         .......................  ......            'cc.     cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM)";
      halfasecsleep();
      cout<< R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd;.    .cONWXc           .....................   .....             :Oo.    .:0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd,.    .cONWWXx,     ...   .....................    .....            'oOd.    .c0WMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKd,.  .,ldONWMWNx.      ...   ......................   .....             .x0o.     :KWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWWMMMMWKd;.  .,dKWMMMWMNd'      ....   ......................     .....     .c;   .oKKo.    .:0WMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMWKd,. .,:dKWMMMMN0kd,              ...................    .........     'xl.   .cKXd.    .c0NWWMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0occoONNWWMMMW0d:,,'''''..'''''.  .................   ............     'kk:.   ,0WKo'     'o0WMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWMMMMMWN0d::cllolllllllllool:..............   ...............      'OWO,   .:OWW0l'     'o0XNWMMWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0o:;;:::cc:::c:::clddxdl,.....     ...................       'OWKc.   .oNMWN0l'     .':x000XWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;';:;,'','..','',:clloc;'....  ......................        'OWWKl.   ;kNWWWN0l'      ...:kNMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx'.,::;;,,''''',;::::;,'..',:;'.................... .';.      'OWMW0l.   ,0WMMMMW0l'     'o0WWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXkc...';::cccccc:;;::,'....';ldxxl'.................   ck:.     'OWMMMKc.  'xNWMMMMMW0kxxxk0WMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0olc'....;ll:,,,;cl:'........'';xKk,..............      cKKl.    'OWMMMWKl.  .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWOclc.....;ll;'..':ol'.........'ck0x, ............       cXWx.    'OWMMMMW0l.  lXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0llc'...';ll:;,,;clc;........:xOOxl. ...........        cXWKo.   'OWMMMMMMKc. .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0o,..'';:::cllllc:::;,'',,..lkxl,.............         cXMMXl.  'OWMMMMMMWKo. .kWMMMWWMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXd'':cc;,,:;,,::,,:llc:;'..';,.  ...........    .     ,xXWWXo. .oKWMMWMMMMKc.'kWMMMWWWMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'.,cc:;:c:;:cc:;:clc,..        ..........   ...      'kWMWKo. .lXMMWWMMMWXl:OWMWWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk.  .,:cccccccccccc;...         .........    ...      .dXWMWXl..lXMMMMMMMMWK0XMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk.    .............   .         ........    ....       .oXMMWXd,lXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'          ..        ..         .......   ......       :KMMMMKdkNMWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM)";
      halfasecsleep();
      cout<< R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXd'         ....      .            .....   ......  .;'  .c0WMMWWWMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl.         .    .   ..           ....    ....... 'xd.  .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNx,.            ..   ..           ....   ........ 'kXk' .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMNk'            ..   ..            ...   ........ .cOKd,.dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMW0;.          ...   ...            ..   ......... .lXNx:xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0c.        .....   ...                ......... .cXWNKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:.       ......  ...                ......... .cXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXx;.    .......  ...                ...........'oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXx;.  .......  ....               ........... 'kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXo. .......  ....               ........... .kWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk. .......  .....              ........... .xWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'........  ......             .............;xNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'......... .......            ............ .:KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk'.........  ........           ...........  :KMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNx..........  ...........       ............ .:0WWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd,........... .................................:OWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:............ ................................ .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:............ ................................ .dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:............ ................................ .,dXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNO;............ .................................  ;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,............. .................................  ;0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWd. ............  ................................. .l0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXo. ............  .................................. .oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKl................  ................................. .c0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM0;  ..............  ....................................;0WMMMMWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMK:. ..............  ................................... .:kXWWMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc. .............  .......................................c0WWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWO;..............  .......................................:0WMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMWKx;............  .................................  ..:xXWMMMMWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXx;..........  .................................,ldkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kl,''..    ...................    ...'';okOOKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNXKK0o:;;'.         .      .';;;;:d0XXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNN0dlllllllllllllllld0NNNNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWMWMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWMMMMMMMMMWMMMMMMMMWMMMMMMMMMMMMMMWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM)";
      onesecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMNKkdoxKNMMMMMMMMMMMMMMMMWKkddkKNMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWXkc'.;kXWMMMMMMMMMMMMMMWNk:''ckXWMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMWWWWWWWWWWWWWWWNKkc'.;xKNWWWWWWWWWWWWWWNXx:'':xKNWWWWWWWWWWWWWWWMMMMMMM
MMMMMMMMXOdoooooooooooooll:,'.,:lloooooooooooooool:,'',:clooooooooooooooxXWMMMMM
MMMMMMMWKxc;,,;;;;;;;;;;,,,''''',,,;;,;;,;;;;;;;;,,'''',,,;,;;;;,;;,;;,;l0WMMMMM
MMMMMMMMNK0OOOOOOOOOOOOOkxl;'.,lxkOOOOOOOOOOOOOOkxl,'';lxkOOOOOOOOOOOOOO0NWMMMMM
MMMMMMMMMMWWWWWWWWWWWWWWWXkl,,ckXWWWXKKKKXNWWWWWWXkc,;lkXWWWWWWWWWWWWWWWWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMWXOkkOXWMWXx:,:cd0NWMMMMWXOkkOKNMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMWNXXXXXXXXXXXKXXXXXKOo,.';ck0XXXXXXXXKXXNWMMMMWWX0O0XWMMMMMMMMMMM
MMMMMMMMMMMMMMWXkollllllllllllllllcc;'.'',:clllllllllloxKWMWX0xl;,;o0NMMMMMMMMMM
MMMMMMMMMMMMMMWKd;,,,,,,,,,,,,,,,,,'''...'',,,,,,,,,,,;lOK0xl:,'';lx0NMMMMMMMMMM
MMMMMMMMMMMMMMWN0kxxxxxxxxxxxxxxxxxoc'.',:ldxxxxxxxxxxoool:,'';cdOXWWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWKd,.,;lONWMMMWWNXOxl:,'';cdOKWMMMMMMMMMMMMMMM
MMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWN0o,.';lOXWWWNKkdc;,'';cdkKNNWWWWWWWWWWWMMMMMM
MMMMMMMWXOdollllooollllllllllllllllc;'.'';:lloll:,'....',:clooolllllllloxKNMMMMM
MMMMMMMWKd:,''''''''''''''''''''','''''........''',,,,,,,,''''''''''''',ckNWMMMM
MMMMMMMMWX00OOOOOOOOOOOOOOOOOOOOOOkxo:,'...',,:okOOOOOOOOOOOOOOOOOOOOOOO0XWMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNX0koc;,,,,,:lx0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMWWNXKOxlc;,''',cdxk0KXNNNNNNNNWNNNNNNNNNWWMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMWWNXKOxo:;,,'....',:looodddddddddddddddddddddkKNWMMMMMMMMMMMMM
MMMMMMMMMMMMWWNXK0Odl:;,,,,,,,,,,,,,;;;;;;;;;;;;;;;;;;;;;;;;,',ckXWMMMMMMMMMMMMM
MMMMMMMWNK00kxoc;,,'''..';ldxkkkkkkkkkkkkkkkkkkkkkkkkkkkkxxo;'':kXWMMMMMMMMMMMMM
MMMMMMWNOl;,'''',;:cc:'.'lOXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNOc''ckXWMMMMMMMMMMMMM
MMMMMMMWKdc::codk0XXKd;.'ckKNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXkc''ckXWMMMMMMMMMMMMM
MMMMMMMMWX00KXWWWMMWXx;.';cloooooooooooooooooooooooooooooooc;''ckXWMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWXx;..',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.':kXWMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWXx;.':oxkOOkkOOOOOOOOOOOOOOOkOkkkOOOkkko:'':kXWMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWXx;.'lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN0l'':kXWMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMWXx;.'ckKNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXkc'':kXWMMMMMMMMMMMMW
MMMMMMMMMMMMMMMMMMMWXx;.',;:ccccccccccccccccccccccccccccccc:,''ckXWMMMMMMMMMWNKO
MMMMMMMMMMMMMMMMMMMWXx;..',,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,'.'ckXWMMMMMMMMN0dc;
MMMMMMMMMMMMMMMMMMMWXx:',cx0KKKKKKKKKKKKKKKKKKKKKKKKKKKKKK0kc,,ckXWMMMMMMMMWKxc,
MMMMMMMMMMMMMMMMMMMWNKkdxOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxxkKNMMMMMMMMMMWN0x      )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNXXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc,;cokKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.  .;dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:. .oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo. .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMWX0kO000000000000ko'  ,oO0000000000000000000000000OOk0NWMMMMMMMMMMMMM
MMMMMMMMMMMW0c................    .............................'lKWMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ..................    .....................   .oXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .cOXXXXXXXXXXXXXX0o.  'x0KXXXXXXXXXXXXXXXXXO:. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXd'  'kXNMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWWKd'  'xKXNWWWWWWWWWWWWWWNN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   .:cccccccccccccc:'.  .,:cccccccccccccccccc;.  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:                                                 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   'cooooooooooooool;.  .coooooooooooooooooooc'  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXo. .cKWWMMMMMMMMMMMMMMMMMKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMKl. .lXWMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMWKc. .dXMMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWNO;. 'dXWWWWWWWWWWWWWWWWWWN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ':llllllllllllll;.  .;lollllllllllllllllll:.  .oXMMMMMMMMMMMMMM
MMMMMMMMMMMW0:                                                 .lKWMMMMMMMMMMMMM
MMMMMMMMMMMWXkolllllllllollllolc'   .:lllllllllloollllc:ccllllldONMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNO;  .lOOdlodxOKWMMMMMMXkc;lkKWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  ;kKd'.. .cONMMMMMWO:. .:xXWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMW0l.  'dXNk,.  'dXMMMMMW0l. .o0NWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  .oKWWk,. .;kWMMMMWKl. 'dXWWXOxkKWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMNO:.  .lKWMWk,. .;OWMMMWKo..,dXWMXk:..:kXWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWXd,   'oKWMMNk,. .;OWMMW0l..;kNWMMWXk:. .l0WMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNOc.  .;xXWMMMWk,. .;ONN0o,..,ok0Okkxxo:.  .;xXWMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMN0o'   'o0WMMMMMWk,. .;ONXd'   .............  .;kNWWMMMMMMM
MMMMMMMMMMMMMMMMMMMN0o,.  .cONMMMMMMMWk,. .;OWWKd,..',:codxkOO00OxooOXNKOOKNWMMM
MMMMMMMMMMMMMMMMWKkc'   .ckXWMMMMMMMMWk,. .;OWMWN00KXNNWWWWMMMMMMWWWMMXx,.,o0NMM
MMMMMMMMMMMMWNXkl,.   'lONWMMMMMMMMMMNk,. .;OWMMMMMMMMMMMMMMMMMMMMMMMNO;.  ,kNMM
MMMMMMMMWNX0xc'.   .;d0NMMMMMMMMMMMMMNk,.  'dXWMMMMMMMMMMMMMMMMMMMMWXx;.  'dXMMM
MMMWNK0kdc'.    .,lOXWMMMMMMMMMMMMMMMWO;..  'cxkOOOO00KK00KK000OOkxo;.  .,xXWMMM
MWNOl,.      .;lkXWWMMMMMMMMMMMMMMMMMMXdc,         .............       'lONMMMMM
MMNKd;.  .':dOXWMMMMMMMMMMMMMMMMMMMMMMMNX0dc,...              ....',:lx0NWMMMMMM
MMMMWKdlokKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXK0OOOOOOOOOOOOOOOO00KKXNWWMMMMMMMMM

      )";
      onesecsleep();
      cout << R"(
MMMMMMMMMMMWNKXXNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNXXXNWMMMMMM
MMMMMMMMMMWXx:,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,,:kNWMMMMM
MMMMMMMMMMWXd,........................       ..........................,xXWMMMMM
MMMMMMMMMMMWX000000000000000000000000Oo'.  .ck0000000000000000000000000KXWMMMMMM
MMMMMMWNXXNNNNNNNNNNNNNNNNNNNNNNNNNNNXx,.  .oKNNNNNNNNNNNNNNNNNNNNNNNNNNNNXXXWMM
MMMMMWXd;;;::::::::::::::::::::::::::;'.    .;:::::::::::::::::::::::::::;;:o0WM
MMMMMWKl.                                                                  .:0WM
MMMMMWXd.  'lkOOOOOOOOOOOOOOOOOOOOOOOkl..  .:xOOOOOOOOOOOOOOOOOOOOOOOOkd,  .c0WM
MMMMMWXd.  ;kNMWNKkkkkOOOOOOOOOkkOKNMWk,.  'dXMMWXOkkkOOOOOOOOOkkOKNMMW0c. .c0WM
MMMMMWXd.  ;kNMW0:.              .lKWNk,.  .dXMWKo'.             .l0WMW0c. .c0WM
MMMMMWXd.  ;kNMWXkolooooooooooooldONWNk,.  .dXMMN0doooooooooooooldONMMW0:  .:0WM
MMMMMWKo.  ,xNMMWXKKXXXXXXXXXXXXKXNMMNx,.  .oXMMWXKXXXXXXXXXXXXXXXXWMMNO:...cOWM
MMMMMWKo'..:kNMW0l...............:ONWNx,...'oKWWKl'..............,l0WMMNX00KXNMM
MMMMMMNX0O00XWMWKd;;;;;;;;;;;;;;;l0WWWKkxxxk0NWWKd;,;;;;;;;;;;;;;:d0WMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWNWWWWWWWWWWWWWNWWMMMMWWWWWMMMMWWNWWWWNWWWWWWWWWNWWMMMMMMMMMMMM
MMMMMMMMMWXK0KXXXXXXXXXXKKKXWWWXKKKXXXXXXXXXXXXXKKXWWNXKKKXXXXXXXXXXXXKXNMMMMMMM
MMMMMMMMWXx;...'''''''''.';xXWNO:'.''''''''''''.'cONWXd;'.'''''''''''';dXWMMMMMM
MMMMMMMMMNx'  ..''''''..  'dXWNO;   .''''''''..  ;OWMXo.  ..'''''''.  .dXMMMMMMM
MMMMMMMMMNk, .:kXNNNNXOc. 'dXWWO:  ,xKNNNNNNXk;  :0WMXo. .cONNNNNNKo. 'dXMMMMMMM
MMMMMMMMMNk, .:0WMMMMWKl. 'dXWWO:  ;kNMMMMMMW0:. :0WMXo. .lKWMMMMMXd. 'dXMMMMMMM
MMMMMMMMMNk,  ;x0XXXXKk:. 'dXWWO:  'd0XXXXXK0x;  ;0WMXo. .ckKXXXXKOl. .dXMMMMMMM
MMMMMMMMMNx'   ........   .dXWNO;   ..........   ;ONWXo.   .........  .oKWMMMMMM
MMMMMMMMMNOc;;;;;;;;;;;;;;ckNWW0o;,;;;;;;;;;;;;,;o0NWXkc;;;;;;;;;;;;;;ckXMMMMMMM
MMMMMMMMMMWWNNWWWWWWWWWWWWWWMMMWWNWWWWWWWWWWWWWWWWWMMMWWWWWWWWWWWWWWWNNWMMMMMMMM
MMMMMMMMMWXK0KXXXXXNNNXNXXNNXXXNXXXXXXXNXXNNXXXXXNXXXXXXXXXXNXXXXXNNXXKKXWMMMMMM
MMMMMMMMWXx,...''''''''''''''''''''''''''''''''''''''''''''''''''''''..'oKWMMMMM
MMMMMMMMWNk;'''''''''''.     .''''''''..    ..'''''''''''..   ..''''''',dXWMMMMM
MMMMMMMMMMWNNNNNNNNNNX0o'  .cOXNNNNNNXOc,. .cOXNNNNNNNNX0o'  .l0XNNNNNNNWWMMMMMM
MMMMMMMMMMMMMMMMMMMMWKo'  'oKWMMMMMMMWKl;. .lKWMMMMMMMWXd,  .oKWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMWNOc.  .:ONWMMMMMMMWKl,. .lKWMMMMMMW0l.   .:kXWWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMWNOl'. ....'cxKNWMMMMWKl,. .lKWMMMMWXx;. ......,lkKWMMMMMMMMMMMM
MMMMMMMMMMMMMMWKkc'..'lkko;...'cxKNMMWKl;. .lKWMMWXx:. .,o00xc'. .,oOXWMMMMMMMMM
MMMMMMMMMMMNKkl,. .'lONWMWXkl'. .,oONWKl,. .lKNN0d;.  .cONMMWN0d;.  .;d0NMMMMMMM
MMMMMMMMMNKx:.  .;o0NWMMMMMMN0o,..'oKWKl;. .l0X0l'  .:kXWMMMMMMWXx:..'lONMMMMMMM
MMMMMMWWWWN0xc:lkKWMMMMMMMMMMMN0xdOXWWKl;. .l0NNKxookXWMMMMMMMMMMWXOk0XWMMMWWWMM
MMMMMN0kxkkkkxdxkkkkkkkkkkkkkkkkkkkkkko;.. .,okkkkxxkkkkkkkkkkkkkkkkkkkkkkxxkKWM
MMMMMXo'.                                                                  .,xXM
MMMMMNOdlllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllox0WM )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMMMMMMMWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXXXNWMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMXdclxKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd;',oXMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMXo....':oOXWMMMMMMMMMMMMMMMMMMMMMMMMMXo...cXMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMWKxc,.....,lkKWMMMWNXXXXXXXXXXXXXXXXX0c...:OXXXXXXXXXXXXXXXNWMMMMMM
MMMMMMMMMMMMMMMMWXkc,....'dXMMMKl,,,,,,,,,,,,,,,,,'.....',,,,,,,,,,,,,,,:OWMMMMM
MMMMMMMMMMMMMMMMMMMWXkc,,dXMMMM0;.......................................'kWMMMMM
MMMMMMMMMMWKO0NMMMMMMMWXKWMMMMM0;...l0000000000000Oc...;k000K000000d,...cKMMMMMM
MMMMMMMMMNk;..;lkXWMMMMMMMMMMMM0;..'xWMMMMMMMMMMMMXo...cXMMMMMMMMWKc...;OWMMMMMM
MMMMMMMMMXx;.....,cxKNMMMMMMMMM0;..'xWMMMMMMMMMMMMXo...cXMMMMMMMMMN0xooOWMMMMMMM
MMMMMMMMMMWNOo;.....'lKMMMMMMMMO;...cxxxxxxxxxxxxxd;...,dxxxxxxxxxxxxxkXWMMMMMMM
MMMMMMMMMMMMMMN0d:..,xNMMMMMMMWk'.....................................'xWMMMMMMM
MMMMMMMMMMMMMMMMMN0kKWMWWWMMMMNd...'::......:lllllllllllllllllll:'....;OWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMNOlckNMMM0:...lXNk:'...;d0NWMMMMMMMMMMMMWKx:...'lKWMMMMMMMM
MMMMMMMMMMMMMMMMMMWXk:....lKMNo...,OWMWXKkc...':d0NWMMMMMWX0dc'...,o0WMMMMMMMMMM
MMMMMMMMMMMMMMMMWXx:.....:xNNx'...dNMMMMMMNOo,....;lx00Odc,....,lkXWMMMMMMMMMMMM
MMMMMMMMMMMMMMWKd;.....ckNWXd'...oXMMMMMMMMMWXx;............,lkXWMMMMMMMMMMMMMMM
MMMMMMMMMMMMNOl'....'lONMW0c....oKNNXK0Okkxolc;'............':coxkO0KXNWWWMMMMMM
MMMMMMMMMWXx:.....,o0WMWXd'...,xXKo;'...........';:lxkxoc;'.........',;;::o0WMMM
MMMMMMMMW0c.....;dKWMMMWKo,..c0WMNx'...'',:codkOKNWMMMMMWNKOxdl:;'........lXMMMM
MMMMMMMMMNOc..;xXWMMMMMMMWKxkXMMNk:..,ckKXWMMMMMMMMMMMMMMMMMMMMWNX00OkdoldXWMMMM
MMMMMMMMMWNKxx0NNNNNNNNNNNNNNNN0c....'l0XNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNWMMMMM
MMMMMMMMMNx:;;;;;;;;;;;;;;;;;;,.......,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;cOWMMMM
MMMMMMMMMXo..............................................................'xWMMMM
MMMMMMMMMWKkkkkkkkkkkkkkkd;....'cxkkkkkkkkkkkkkkkkkkkxl'....,oxkkkkkkkkkkOXWMMMM
MMMMMMMMMMMMMMMMMMMMMMMNOc...'l0NMMMMMMMMMMMMMMMMMMWKo,....l0WMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMW0l'...'o0NWMMMMMMMMMMMMMMMWXOl'....:ONMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMNk;.......';:loxk0KNNWWMMWXOo;.....ckNMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMWNKOkdlc;,........',;:cloc,.....;o0NMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWNX0Okoc;...............'lxOKNNWMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMWWNXX0kxoc,...................',;codkOKXNWMMMMMMMMMMMMM
MMMMMMMMMMWNNNXXXKK0Okddolc;,'.........,;:ox0KKOxdl:,'.........',;codk0XNMMMMMMM
MMMMMMMMMWOc;,''''..............';codOKXNWMMMMMMMMMWXK0kdl:,'..........:OWMMMMMM
MMMMMMMMMMKc.........'',;:lodxOKXNWMMMMMMMMMMMMMMMMMMMMMMWWNX0xdl:,'..'dNMMMMMMM
MMMMMMMMMMWKxoddxxkO0KXNNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNKOkONMMMMMMMM
)";
      halfasecsleep();
      ClearScreen();
      //Image source https://www.sgss8.com/tpdq/1089436/
    }else if (o == 'W'){
      cout << R"(
llclooolccloolcloddlcoddolcloc'';;,.....  ...',;'..','.......        ......................';;'............',,;;,;c:,,,'..............            ....
::cllcccccllc::lodolcllc::;,;:cll:'..... ..,;,::;,'''........     .......',,'.....,,...''.',;::,,'.............'..,;,.............                  ..
:cool::codoolllooolccc;,,,',lxdl;'...'....':c,'..'''...............',,;;;;::,''',,::'..';:cc,,:ll:'..............................                    .
ooc::cloolloolooooc;;;,,'.'cdoc,.....'.....',..............',;c:,,,;ldlcc:;'',,,'....';:::llc:;;,'............  .   ....  ........
oolcccclccccllllc:,'.';;,';ll:;,'.....................''...,:cl:,'.';;'......,c:'.'':oxxdlllodl;,,,.... .......           ......
cclcccccc::ccc:;,''.':c;',::,'..........'....   ....',,,,,..''''....... ......;;'';ldOKX0xoodxxl;cdl;'.........          ...
c:::cc:::::cccccc;,,;ll;';;,'......,,........  ......'..'...........       .....',:okKXXX0xllxkdloxOxl::,......
olc::::::::ccllolc:;;:c;,;;,'.....''....  .........................       ......;cox0XNXXKOxooxxddk0KOkdo:'..........    ....
dlllcccc::cc:;::;;:c:'';:;'..........     .........................    ... ....':ok00XNNNNX0xooxkxkOKXK0kdl;'.........   .....
cloolccllc::;;,,;:cc:,'::'.  .....        .......       ...........    ........,cx0XKKXNXNNXOdoxOkxk0XNNKOxoc,.......... ....
clolcc:ccccc:;,,;:c:;,,'...  ...              ...       .....'.....  .........';lxKNXXNNNNXX0kdxOOxk0XNNXK0kxc;'........ ....
oolc:ccc:::::;,',;;'.......       ..         ....   .  .....,;'..............,;:lxKNNNNNNNNNKOxkO0kkkOKXXKK0Odc,..  ...  .....
c::::clc::::;,'',;,....  ..                  .....  ......'';:,..............,cloxKNNNWNXNWWX0OO000kOOOKXNXKOxdc'..  .     ...
:;:cccccc:::;,'.',.......            ..            ......'',::'.......  ....';lodxKNNNNNNWWWNK00KK0O0KKXNNNXKOxl,...
::ccccclcccc:,'....             ....               .....,,,;:,...... .......,:oodk0XNXXNWWNNWNXKKKKO0KXXWWWNNX0d:'..         .      ..
loolcccclllc:;,....               ..       .       ...'',,;:;'....     .....':oddkO0XNNWWWNNNNXKKXKOO0XNNWWWNNKkl,..         .       .
llcllllllcc:cc:'.                  .              ..',,',;;:;.        ......';lddxkO0XNWWWWNNXXKKXKOO0XXNWWWWNKOo;'.
ccclllclllcccc:'.                 ..              ..';;;,,;;,.      ........,codddxO0KNWWWWWXKKKKXXOxOKXNNNNWNKOd:,.                   ..
lccllllooc::c:,..               . ..              ..,:::,,;;'.     ........';odxddxOKKXNWWWWNX000KX0dd0XXXNWWN0Odc,.                    ..
cllcclolccc::;'..                 ..             ...;c::;,,'.      .....'.',:oxkxodkO0KXNNWWNX0OO000xokXKKXWWNKkxdc.                ...   .
:llccccccll:;,..                   .      .      ...:ll::;'.. .   .''..',''':oxkkddxxO0KKKKXKK0kkkOOxodO0O0XNXK0OOo'.               ...
lollc::::clc;..                   .             ...':ooc:;'.      .,'..','.';ldddooxxxkOOkkkxxxdddxkkolxOO0XNXKOO0x,.               .'..
docc:::clooc'.                                  ..'';lolc,..     ..''...,'..,cllcloddxkkkxddollllooddlcdOO0XNNKkOKx,..              .'..
cccc:::codl,.                                   .',,;:ll:..     ..'''..','..':lcccoodkO0OkdollccclllooclxxxOKK0xk0d,..               ....
c::::llcll;'..                                 ..,;;;;::,..   . ..,,,',,,,'',:llccloxO000Oxdlccccllloolcododxxdldxl'...               ......  .......
ccccloooc;,'..                                  .,::;;,'..      .';;,',,,,;;;cllllldk0KK0Okxolllllooooolloolllc:cc;'''....             ........''.....
llccodolc:;'                                    .';:,,'.....    .........',;;clllldxk0XXKOkxdolllllllc:::;;,,,,'','.','.....            ......,;,'....
llccclcc;...                                ......,;,''.....            .....;clloxO0KXX0Okkxdlc::;,'..........    ......'..             .....,;,,,''.
l:coolc;,..                                 ......',;'...                   ..',:ldk0KKKK0kxdoc;'....                  ..''....        ......',;;::;'.
c:col:,'...                                  .....';;,...                    ...,:okOKXNNXOxdl:'....                  ...''.....       .......'';::;,'
;;:::,'...                                   ..'..,;:;,'..                  .....;okOXNWWWXOxlc;.....               ...',,,'''....     .........,;:;,'
::::,'....                 ...                .'.';cllc:,'..             ...''...;dkKXWWWWNXOdoc:::;,''... . .....'',,;cccc:;,,''.    ...........,;;,.
:cc;'....                   .                 .''';oO0kddxo:,''''........,;;;,'..ck0XNWWMWWX0kxddddxxkkxdlclllllllcclooddlllc;;,,.    ..........',;,'.
:::,'''..                    .                ..'';d0XK00XK0xddddocc:;:cllcclll::oO0XWWMMMWNKOkOOO0KXNNXXKKK0000OOkO0OOOkdool:;,'.   ..........',,,'..
:;,'''...                                      .',;oOKKKXNNNKKKKXKOkdddxxxdddkOxdkO0XWMMMMMWNK0KXXNWWWWWWNNWWWWWNXXNXKXXXKkdl:,'.............',,,,'...
;,'......                       ...             .';lOKK0KNNXXXXXXNKOkxkkOOOOO00OkO0KXWMMMMMWWNXNNNNWMMWWWWWWMWWWWWWWWWNWWN0xo:,'.',,,,'......',,,'....
,,'.......                    .....             ..,cx0K0O0KXXNNXXXKOOOkO0KXXXXXKK000XWMMMMMWWWNWWWWMMMMMMMMMWWWWWWWWWWWWWNKOdl;'..'',,'.....',,'......
;:,''.....                   .....               ..;ok0K0O00KKKK00000OO0XNNNNNXK0O0KNWMMMMMMWWWMMMWMMMMMMMMMMMMMMMMMMWWWNXK0xo:'',''''.....',,'.. ....
,,'.....                     ...                  .':dO00KXX0KKKKK00000KNNNXX0xodkOXWMMMMMMMMWWMMWWMMMMMMMMMMMMMMMMMMMWNNNXKko;,;,'.......''..... ....
'......                                            .,lxkOKNWNNNNNNNXXXNNWWNXKxlcok0XWMMMMMMMWWWMMWWWMMMMMMMMMMMMMMMMMMWWNXX0xl;::,............... ....
,.'..    ...                   ...                  .;oxOXNWWWWNNWWNWWWWWWNX0dldk0KNWWMMMMMWWWWMMWWWWWMMMMMMMMMMMMMMMMWWXKKOd::oc'........  . ........)";
      halfasecsleep();
      cout << R"(
......    .                                          .:dOKXNWWWNNNNWWWWWWWNNXOxkOOO0KXXXXKK0000KXXKKXWMMMMMMMMMMMMMMWWWNXK0xc:lo:'......    .........
.......                                              .,lx0KXNWWWWNNNNWWMMWWWWX0kxdolodxdddoollllddddONWMMMMMMMMMMMWWWWNXK0kocldl;'.....      ........
... ...                                              ..;ox0KNWWMWWWXXNWWWWWMWWNOdll::clolllll:;;:::lkXWMMMMMMMMMMWWWWNXK0kolodl:,'....        ...
    ....                   ..... ..                   ..;lxOKNWMMWMWNXXNWWWWWWWXOdooodxxdoodddddddxOXWWWWWWMMWWWWWNNNXK0Ododdc:,'.....         . .
   .  ...              ..........                      ..;ldOKNWWWMMWWXKKNWWWMMMWNKOOkkkkxdxO0XNNWWWWMMWWWWWWWWWNNXXXK0Oddxdc;,'.......           .
                    .''.''.......        ...  .        ...;cok0KXNWWWWNX00KXXWMMMWWNX0OkkOOO0KKNWWWWWWWWWWWWWNNXXXKK00kdldoc;,''.........            .
                .  .';,....'....       ....        ........,:ldk0KXXXXXXXKkxOXNWWWNXOo;,:oxdc;,cdOXXXXKKKXXXXXKKK000Oxolcc;,,'''....  ..... ...      .
               ................       .....        .........,;cldkO0000KK0kdxkxxddo:'.  ..........;::c:::dOKK0000OOkxocc:;,;,,'..     ....  ....   ...
                .................   .........................';:codxkOO00Odolol;''.. ... ............,;''ck0K00OOkxdllcc:;;;;,'..           ..........
                 ....... ............'....'''.................'';clodxkkOOkdddkdc:;.................:dkxxk0KKK0Okdolllccc:::;'...  .       .........'.
             .....'...  .............'...........................,:cloxxkOkkxdkkoc:;...  ......   .;oxO0KKKKKK0kdoollcccc::;,''.. ........... ........
           .........   ...........................................';:lodxkkOkddkkxl:;'............,:lok0KKXXK0kkxdolccccc:;;,,'...  . ..  ..  ........
          .....       ............. .................................,:clodxkkddOOkdc:;;,,,,'''',,;coxk0KXKKOkkkxolccccc::::;;,'...   ...............'
    ..  ..  ..        .....';:,''....','''''''..........................,:cclddoxO0OkdolcccccllooxkO0KKKK0Okkkdollllccccccc::;,,'..   ..   .........';
    .....             ....,:ccccc,.';c;,,,,;ll:,..........................'',:cllxO0000OOOOOO0KKXXXXKXKKOkkxdollllccccllllcc::;;,...  ..  ....',,''';:
      .....           ..,::;;;;;:::ccc;;;::lkkl;.......'''........ ......  ...';:coxkOO0KXXXXNNXXXKKK0kxxddollcclllllllllllccc:;,'............,:llc:::
         ..    .    ...;c;''';:;;;:::::;;:coxxc,.....',,,'..............     .';;:cclodxkkO00KKKK0Okxdoddollcccllooooooooollcc::;,'..........,lxOxlc:;
    ...        .   ...';,...'';cc;,,,',,coolc:;'.....';;:,..............    ..,;::cccclloodxxxkxxddollllllllloooooooooooooolllccc:,'.........:xOOxolc:
    ....          .   ........';c:;,;;;cddl:;,,,,,'...,;cc,...........    ...',;:cccllllllloollllllllllllllooodoooooooddoooollllcc:;,'.......;ldoooc:;
    ..'.      ..        .....',;:;,:ldxOkoc:;,;::::,'.',:l:,.......      ....,;::ccclloooooddddddoollllc:;;:cloddoddddddoooooolllcc::,''.';coddoll:;::
   ......                 .....'',:clodxdoddc;;;;,;;,'',;:clc;'....    ...''';:ccclllooodddddddddol:;;;;;,;,,;:odddddddooooooooolllcc:;;cdOOOOkxxdlcc:
    .  ....                ......':lc::cllodolllcccc;,,;;;;:loc,...  ....',,;:ccllloooooooooooooc:;,;cc:;;;;,,,:lodddddooooooddooollccldkOOOOkxxxoccc:
                           .......',,,,:c:ccllc:::cc;;;;;:;;:c:,'......',;;;;::cllloolllccccc::::::;:::;,;;:;;;;:lodddddddddddxxdoolldOKKOOOkxddolcccc
                            .........',,;::cllc;;,,,;;;:::c:;;:::;'..',;:::::::cloddoc:;;,;cc:;:c::;;:cc::c:;;;;:cldxxxddddxxxxxxdodkKNNK00Oxdolllllod
                           ...........'''',;:cool:;,;:::::::;:clcc:;;;:::ccclc;:loddl:,,;,;cc:;;::c::ccc:;:;,;:::coxxxxxxxxxxxxxxk0XNXK000Oxoollcc:cll
                              ...........',,;:ldol:;;;::;;:cccccoolcccccclllll::codoc;,,;;:cc:;;::c:;:cc:::::;:::loxxxkxxxxkkkO0KNWWN0kxxxkxoooollc:;;
                             ...... ......'''',;::;;;;:;;;:ccllllolccccccllloollcllc;,,;::clllllcc:;;:lolc:;;;::cldkkkkkkkk0KXNWWWWX0xolloxxddolccc:::

      )";
      onesecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWNNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0o::ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...oNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMMMMMMMMWMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,...cKMMMMMMMMMMMMMMMWXxlxXWMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWk,....oXMMMMMMMMMMMMMNk:...;xNMMMMMM
MMMMMMMMMMMMMMMMWKOOOOOOOOOOOOOOOOOOOOXWMMMWk,....'xNMMMMMMMMMMNOc.....:kNMMMMMM
MMMMMMMMMMMMMMMMNo...................'dNMMMWk,.....,kNMMMMMMMNOc.....:xXMMMMMMMM
MMMMMMMMMMMMMMMMNd,'''.'''''''''......dNMMMWk,......,kWMMMMNOc'....:xXWMMMMMMMMM
MMMMMMMMMMMMMMMMWNXKKKKKXXXXXXXK0l...,kWMMMWk,.......;kWWXkc.....ckXWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO;...oXMMMMWk,...;;...,od;....'lONMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXl...;0WMMMMWk,...okc........,o0WMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNd'..'xWMMMMMWk,...dX0c.....;xXWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMNk,...oXMMMMMMWk,...dNW0c....c0WMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWk;...cKMMMMMMMWk,...dNMWKl....;OWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWk;...:0WMMMMMMMWk,...dNMMMXd'...'dXWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMNk,...;OWMMMMMMMMWk,...dNMMMMNk;....:ONMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMXd,...:OWMMMMMMMMMWk,...dNMMMMMW0c....'l0WMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMWKl....:0WMMMMMMMMMMWk,...dNMMMMMMMXd,....,dKWMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMWO:....c0WMMMMMMMMMMMWk,...dNMMMMMMMMW0l.....;dXWMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMXd,...'oXWMMMMMMMMMMMMWk,...dNMMMMMMMMMMNk:.....;dKWMMMMMMM
MMMMMMMMMMMMMMMMMMMWO:....;kNMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMWXx;.....,lONMMMMM
MMMMMMMMMMMMMMMMMWKo'....l0WMMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMMMWKd,......:xKWMM
MMMMMMMMMMMMMMMWXx,....,xNMMMMMMMMMMMMMMMMMWk,...dNMMMMMMMMMMMMMMMWKd;......:OWM
MMMMMMMMMMMMMMMNx,...'l0WMMMMMMMMMMMMMMMMMMWx'...dNMMMMMMMMMMMMMMMMMWXk:...:kNMM
MMMMMMMMMMMMMMMMNkc,cONMMMMMMMMWWMMMMMMMMMNO:...'xNMMMMMMMMMMMMMMMMMMMMNOdkXMMMM
MMMMMMMMMMMMMMMMMMNXNMMMMMMMMMXklllooooool:'....cKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo...............c0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:'''''''''';:oONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXKKKKKKKKKXXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
      )";
      halfasecsleep();
      cout << R"(
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNOc,;cokKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.  .;dKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWO:. .oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo. .lKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMWX0kO000000000000ko'  ,oO0000000000000000000000000OOk0NWMMMMMMMMMMMMM
MMMMMMMMMMMW0c................    .............................'lKWMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ..................    .....................   .oXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .cOXXXXXXXXXXXXXX0o.  'x0KXXXXXXXXXXXXXXXXXO:. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXd'  'kXNMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWWKd'  'xKXNWWWWWWWWWWWWWWNN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   .:cccccccccccccc:'.  .,:cccccccccccccccccc;.  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:                                                 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   'cooooooooooooool;.  .coooooooooooooooooooc'  'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMXo. .cKWWMMMMMMMMMMMMMMMMMKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMMKl. .lXWMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .lKWMMMMMMMMMMMMWKc. .dXMMMMMMMMMMMMMMMMMMWKc. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:  .c0NWWWWWWWWWWWWNO;. 'dXWWWWWWWWWWWWWWWWWWN0c. 'dXMMMMMMMMMMMMMM
MMMMMMMMMMMWK:   ':llllllllllllll;.  .;lollllllllllllllllll:.  .oXMMMMMMMMMMMMMM
MMMMMMMMMMMW0:                                                 .lKWMMMMMMMMMMMMM
MMMMMMMMMMMWXkolllllllllollllolc'   .:lllllllllloollllc:ccllllldONMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNO;  .lOOdlodxOKWMMMMMMXkc;lkKWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  ;kKd'.. .cONMMMMMWO:. .:xXWMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMW0l.  'dXNk,.  'dXMMMMMW0l. .o0NWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMW0c.  .oKWWk,. .;kWMMMMWKl. 'dXWWXOxkKWMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMNO:.  .lKWMWk,. .;OWMMMWKo..,dXWMXk:..:kXWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWXd,   'oKWMMNk,. .;OWMMW0l..;kNWMMWXk:. .l0WMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMNOc.  .;xXWMMMWk,. .;ONN0o,..,ok0Okkxxo:.  .;xXWMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMN0o'   'o0WMMMMMWk,. .;ONXd'   .............  .;kNWWMMMMMMM
MMMMMMMMMMMMMMMMMMMN0o,.  .cONMMMMMMMWk,. .;OWWKd,..',:codxkOO00OxooOXNKOOKNWMMM
MMMMMMMMMMMMMMMMWKkc'   .ckXWMMMMMMMMWk,. .;OWMWN00KXNNWWWWMMMMMMWWWMMXx,.,o0NMM
MMMMMMMMMMMMWNXkl,.   'lONWMMMMMMMMMMNk,. .;OWMMMMMMMMMMMMMMMMMMMMMMMNO;.  ,kNMM
MMMMMMMMWNX0xc'.   .;d0NMMMMMMMMMMMMMNk,.  'dXWMMMMMMMMMMMMMMMMMMMMWXx;.  'dXMMM
MMMWNK0kdc'.    .,lOXWMMMMMMMMMMMMMMMWO;..  'cxkOOOO00KK00KK000OOkxo;.  .,xXWMMM
MWNOl,.      .;lkXWWMMMMMMMMMMMMMMMMMMXdc,         .............       'lONMMMMM
MMNKd;.  .':dOXWMMMMMMMMMMMMMMMMMMMMMMMNX0dc,...              ....',:lx0NWMMMMMM
MMMMWKdlokKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXK0OOOOOOOOOOOOOOOO00KKXNWWMMMMMMMMM

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
    double damage = 0;
    if (thisturnsattack == "1"){
      cout<< p.info.myname << " uses the Ling Fu on " << g.name<<endl;
      if (g.name == "Hungry Ghost" || g.name == "Possessed Medium"){
        damage = (((((2*p.stats.level/5)+2) * (p.stats.myattack/g.defense))/50)+2) * 1.5;
      }else{
        damage = ((((((2*p.stats.level)/5)+2) * (p.stats.myattack/g.defense))/ 50)+ 2) * 1;
      }
    }else if ((thisturnsattack == "2") && (p.stats.attackone != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << " uses Sun Sing Zi Fo on " << g.name<<endl;
      damage = (((((2*p.stats.level/5)+2) * (p.stats.myattack/g.defense))/40)+2) * 1;
      if ((g.name == "Zombie") || (g.name == "Vengeful Spirit")){
        damage *= 1.5;
      }
      if ((g.name == "Water Ghost") || (g.name == "Possessed Medium")){
        damage *= 0.75;
      }
    }else if ((thisturnsattack == "3") && (p.stats.attacktwo != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << " uses Calm Bell on " << g.name<<endl<<"The Calm Bell binds the "<< g.name<< "\'s power. It might not be able to move. "<< endl;
      g.inrepentance = true;
      g.repentingturns = 0;

    }else if ((thisturnsattack == "4") && (p.stats.attackthree != "xxxxxxxxxxxxxxx")){
      cout<< p.info.myname << "uses Peach Tree Sword on " << g.name<<endl;
      damage = (((((2*p.stats.level/5)+2) * (p.stats.myattack/g.defense))/25)+2) * 1;
    }else{
      cout << "Invalid move!"<< g.name << " will take advantage of this slip-up..."<<endl;
    }
    srand(time(NULL)*88);
    int * rnumber = new int (rand()%7);
    damage += *rnumber;
    delete rnumber;
    if (g.imdefending == true){
      damage -= (g.defense - (whatshouldIdo % 3));
      g.imdefending = false;
    }
    if (damage < 0 ){
      damage = 0 ;
    }
    g.currenthealth -= damage;
    cout << p.info.myname << " has dealt " << damage << " damage to the "<<g.name<< endl;
    onesecsleep();
    halfasecsleep();
  }else if (playerchoice == "d"){
    cout << p.info.myname<< " is defending for next turn"<<endl;
    g.momentarychange = p.stats.mydefense;

  }else if (playerchoice == "f"){

    if ((p.stats.myspeed)>(g.speed)){
      if (whatshouldIdo >= 25){
        cout << p.info.myname << " was able to flee"<<endl;
        onesecsleep();
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
    cout << "God of Thunder vanquish and exterminate the malicious ghosts and bring us purity."<< endl;
    halfasecsleep();
    onesecsleep();
    cout << "Separate the heads from the demons, expel that which is malicious and keep us safe from harm forever more." << endl;
    halfasecsleep();
    onesecsleep();
    cout << "Let this decree from Tai Shang Lao Jun be executed quickly" << endl; //chant from https://en.wikipedia.org/wiki/Lei_Ting_curse_charm
    onesecsleep();
    onesecsleep();
    if (((p.stats.myspeed + g.speed) *88) % 10 > whatshouldIdo % 10 - 2){
      cout<<"Healing Successful!"<<endl;
      onesecsleep();
      if ((p.stats.mycurrenthealth + (whatshouldIdo % 10) + 1) <= p.stats.maxhealth){
        p.stats.mycurrenthealth += ((whatshouldIdo % 10) + 3);
      }else{
        p.stats.mycurrenthealth = p.stats.maxhealth;
      }
    }
    else{
      cout <<"Void prayer. Healing was unsuccessful."<<endl;
      onesecsleep();
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
void enemymoves (Player &p, GhostData &g, int &hex){
  ClearScreen();
  cout << R"(
   ('-.      .-') _  ('-. _   .-')                        _ (`-. ('-. .-.  ('-.     .-')     ('-.
 _(  OO)    ( OO ) _(  OO( '.( OO )_                     ( (OO  ( OO )  / ( OO ).-.( OO ). _(  OO)
(,------,--./ ,--,(,------,--.   ,--.),--.   ,--.       _.`     ,--. ,--. / . --. (_)---\_(,------.
 |  .---|   \ |  |\|  .---|   `.'   |  \  `.'  /       (__...--'|  | |  | | \-.  \/    _ | |  .---'
 |  |   |    \|  | |  |   |         |.-')     /         |  /  | |   .|  .-'-'  |  \  :` `. |  |
(|  '--.|  .     |(|  '--.|  |'.'|  (OO  \   /          |  |_.' |       |\| |_.'  |'..`''.(|  '--.
 |  .--'|  |\    | |  .--'|  |   |  ||   /  /\_         |  .___.|  .-.  | |  .-.  .-._)   \|  .--'
 |  `---|  | \   | |  `---|  |   |  |`-./  /.__)        |  |    |  | |  | |  | |  \       /|  `---.
 `------`--'  `--' `------`--'   `--'  `--'             `--'    `--' `--' `--' `--'`-----' `------'
  )" ;
  twosecsleep();
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
    if ((rand ()% 100) >= 40){
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
    if (whatshouldIdo < 25){
      MonsterDefend (g, p, hex);
    }else{
      MonsterAttack (g, p, hex);
  }
  }else if (g.name == "Vengeful Spirit"){
    if (whatshouldIdo > 35){
      MonsterDefend (g, p, hex);
    }else{
      MonsterAttack (g, p, hex);
    }
  }else if (g.name == "Hungry Ghost"){
    if (whatshouldIdo >= 20){
      MonsterAttack (g, p, hex);
    }else{
      MonsterDefend (g, p, hex);
  }
  }else if (g.name == "Possessed Medium"){
    if (whatshouldIdo >= 50){
      MonsterAttack (g, p, hex);
    }else{
      MonsterDefend (g, p, hex);
  }
  }else if (g.name == "Water Ghost"){
    if (whatshouldIdo >= 30){
      MonsterAttack (g, p, hex);
    }else{
      MonsterDefend (g, p, hex);
  }
  }
}


//HERE
//HERE
//HERE

//battlephase Function
//takes in a struct that contains player info. Relevant for calculating battle issues
//output is a character. If W, the user won the battle. If l, the user lost the battle, if F, the player fled from the battle.
char battlephase(Player &x, char initial){
  int repentingturns = 0;
  int isplayerhexed = 0;
  GhostData ghost;
  bool primeraqueataco = true;
  srand(time(NULL));
  if (initial == 'J'){
    //zombie information
    banner('J');
    //dynamic array here maybe?
    ghost.maxhealth = 8 + x.stats.level;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 3 + (rand() % 5) + (x.stats.mydefense % 6);
    ghost.defense = 8 - (rand() % 5);
    ghost.speed = 2;
    ghost.attackone = "Rotten Fangs";
    ghost.attacktwo = "Scratch";
    ghost.name = "Zombie";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
    ghost.imdefending = false;
  } else if (initial == 'L'){
    //vengeful spirit information
    banner('L');
    ghost.maxhealth = 20;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 1 + (rand() % 10);
    ghost.defense = 8 + (rand() % 3);
    ghost.speed = 7;
    ghost.attackone = "Undying Hex"; //
    ghost.attacktwo = "Scratch";
    ghost.name = "Vengeful Spirit";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
    ghost.imdefending = false;
  } else if (initial == 'H'){
        //Hungry Ghost information
    banner('H');
    ghost.maxhealth = 10;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 5 + (rand() % 10);
    ghost.defense = 5 + (rand() % 3);
    ghost.speed = 5 + (rand() % 10 );
    ghost.attackone = "Soul Eater"; //
    ghost.attacktwo = "Rotten Fangs";
    ghost.name = "Hungry Ghost";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
    ghost.imdefending = false;
  }else if (initial == 'P'){
        //Possessed Medium information
    banner('P');
    ghost.maxhealth = 14;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = 7 + (rand() % 13);
    ghost.defense = 2 + (rand() % 13);
    ghost.speed = 6 + (rand() % 13 );
    ghost.attackone = "Eternal Despair"; //
    ghost.attacktwo = "Sharp Knife";
    ghost.name = "Possessed Medium";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
    ghost.imdefending = false;
  } else if (initial == 'W'){
        //Water Ghost information
    banner('W');
    ghost.maxhealth = 10;
    ghost.currenthealth = ghost.maxhealth;
    ghost.attack = x.stats.myattack + (rand() % 10);
    ghost.defense = x.stats.mydefense - (rand() % 3);
    ghost.speed = 6 + (rand() % 10 );
    ghost.attackone = "Underwater Chains"; //
    ghost.attacktwo = "Tidal Wave";
    ghost.name = "Water Ghost";
    ghost.momentarychange = 0;
    ghost.inrepentance = false;
    ghost.repentingturns =0;
    ghost.imdefending = false;
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
      if (x.stats.mycurrenthealth < 0 || ghost.currenthealth < 0){
        break;
      }
      enemymoves(x,ghost, isplayerhexed);
    }

    else {
      enemymoves(x,ghost, isplayerhexed);
      if (x.stats.mycurrenthealth < 0 || ghost.currenthealth < 0){
        break;
      }
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
    cout << R"(
                                                                  .-')   .-') _                    ,-.
                                                                ( OO ).(  OO) )                  /  |
  ,--.   ,--.-'),-----. ,--. ,--.          ,--.     .-'),-----.(_)---\_/     '._       .-.      '  .'
   \  `.'  ( OO'  .-.  '|  | |  |          |  |.-')( OO'  .-.  /    _ ||'--...__)      `-'      |  |
 .-')     //   |  | |  ||  | | .-')        |  | OO /   |  | |  \  :` `.'--.  .--'               |  |
(OO  \   / \_) |  |\|  ||  |_|( OO )       |  |`-' \_) |  |\|  |'..`''.)  |  |         .-.      |  |
 |   /  /\_  \ |  | |  ||  | | `-' /      (|  '---.' \ |  | |  .-._)   \  |  |         `-'      '  '.
 `-./  /.__)  `'  '-'  ('  '-'(_.-'        |      |   `'  '-'  \       /  |  |                   \  |
   `--'         `-----'  `-----'           `------'     `-----' `-----'   `--'                    `-'
    )";
    return 'L';
  }
  else{
    cout << R"(
                                            (`\ .-') /`                .-') _,---.
                                             `.( OO ),'               ( OO ) |   |
  ,--.   ,--.-'),-----. ,--. ,--.         ,--./  .--.  .-'),-----.,--./ ,--,'|   |
   \  `.'  ( OO'  .-.  '|  | |  |         |      |  | ( OO'  .-.  |   \ |  |\|   |
 .-')     //   |  | |  ||  | | .-')       |  |   |  |,/   |  | |  |    \|  | |   |
(OO  \   / \_) |  |\|  ||  |_|( OO )      |  |.'.|  |_\_) |  |\|  |  .     |/|  .'
 |   /  /\_  \ |  | |  ||  | | `-' /      |         |   \ |  | |  |  |\    | `--'
 `-./  /.__)  `'  '-'  ('  '-'(_.-'       |   ,'.   |    `'  '-'  |  | \   | .--.
   `--'         `-----'  `-----'          '--'   '--'      `-----'`--'  `--' '--'
    )";
    //user won!
    //Gain experience experience
    ExperienceGain(x,ghost);
    //if yes, level up.
    return 'W';
  }
}



//Quest menu functions
//Lets user pick a Quest
//Input is the player array. It will be edited in other functions, so it is passed by reference here as well.
//This will also autoheal the user in case they have previously been defeated in a battle.
//Function is void so produces no output.
void Questmenu(Player &x){
    string tempkey;
    bool levelwon;
    if (x.stats.mycurrenthealth <= 0){
      x.stats.mycurrenthealth = x.stats.maxhealth;
    }
    while (true){

        cout<<R"(
    +==============================+===========+======================================+==============+
    |******************************************JOB REQUESTS******************************************|
    +==============================+===========+======================================+==============+
    | Case Number                  | Location  | Details                              | Reward       |
    +------------------------------+-----------+--------------------------------------+--------------+
    | 001                          | The Peak  | Please help me! The Dragon Lodge     | HKD1000      |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | is prime real estate location,       |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | but its filled with undead and       |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | whatnot. No one wants to buy         |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | hoong zak, even when it's on the     |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | most exclusive area of HK. Please!   |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | come kill all the monsters!          |              |
    +------------------------------+-----------+--------------------------------------+--------------+
      )";
        cout << "Press any key to read the next case"<< endl;
        getline(cin,tempkey);
        cout << R"(
    | 002                          | Wan Chai  | Nam Koo Terrace supposedly is        | HKD2000      |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | filled with spirits of women         |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | want revenge from the evils of       |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | the Japanese invaders. I don't       |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | know about that, I just know         |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | the Terrace is filled with treasure! |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | Please go and retrive all the loot.  |              |
    +------------------------------+-----------+--------------------------------------+--------------+
      )";

        cout << "Press any key to read the next case"<< endl;
        getline(cin,tempkey);
        cout << R"(
    | 003                          | Yuen Long | Tak Tak School was closed decades    | HKD3000      |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | ago, now it's one of the most haun-  |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | ted places in the entire City.       |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | Don't ask me how I know this, but    |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | apparently all those ghosts are      |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | guarding the most heavenly can of    |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | Abalone your eyes will ever see. I   |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | would go fetch it myself, but the    |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | place is like a maze, and those      |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | ghosts are not about to surrender    |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | some godly Abalone easily.           |              |
    +------------------------------+-----------+                                      +--------------+
    |                              |           | Help me out and I'll pay generously! |              |
    +------------------------------+-----------+--------------------------------------+--------------+
      )";
        twosecsleep();
        cout<< "Choose a quest! Please input the case number you want to tackle, or press b to go back."<<endl;

        getline(cin,tempkey);
        if (tempkey == "001"){
            levelwon = loadlevel(1, x);
            if (levelwon == true and x.info.level1complete == false) {
                x.info.level1complete = true;
                x.stats.mymoney += 3000; //reward, can discuss later
                cout << "You have been rewarded "<< "3000"<< " HKD. Thanks for your help!"<< endl;
                return;
            }
        }
        else if (tempkey == "002"){
            levelwon = loadlevel(2, x);
            if (levelwon == true and x.info.level2complete == false) {
                x.info.level2complete = true;
                x.stats.mymoney += 6500; //reward, can discuss later
                cout << "You have been rewarded "<< "6500"<< " HKD. Thanks for your help!"<< endl;
                return;
            }
        }
        else if (tempkey == "003"){
            levelwon = loadlevel(3, x);
            if (levelwon == true and x.info.level3complete == false) {
                x.info.level3complete = true;
                x.stats.mymoney += 8000; //reward, can discuss later
                cout << "You have been rewarded "<< "8000"<< " HKD. Thanks for your help!"<< endl;
                return;
            }
        }
        else if (tempkey == "b"){
            return;
        }
        else if (tempkey == "test"){
            battlephase(x, 'J'); //testing purposes
            x.stats.mycurrenthealth = x.stats.maxhealth;
            twosecsleep();
            cout << "prepare for round 2 ";
            twosecsleep();
            battlephase(x, 'L');
            cout << "prepare for round 3 ";
            twosecsleep();
            battlephase(x, 'H');
            cout << "prepare for round 4 ";
            twosecsleep();
            battlephase(x, 'P');
            cout << "prepare for round 5 ";
            twosecsleep();
            battlephase(x, 'W');
        }
        else{
            cout << "Not a valid input. Try again!"<<endl;
        }
    }

}
