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


void MonsterAttack (GhostData &ghast, Player &pleya, int &hexed){
  cout << ghast.name << " will attack!" << endl;
  halfasecsleep();
  onesecsleep();
  int damage = 0;
  srand(time(NULL)+137);
  int whatshouldIdo = (rand())% 100;
  string currentattack;
  if (hexed > 0){
    pleya.stats.mycurrenthealth -= (ghast.defense % 3 + 1);
    hexed -=1;
    cout << pleya.info.myname << " is being hurt by the hex." << endl;
    onesecsleep();
  }
  if (whatshouldIdo > 50){
    currentattack = ghast.attackone;
  }else{
    currentattack = ghast.attacktwo;
  }
  if (currentattack == "Rotten Fangs"){
    cout << ghast.name << " bites with Rotten Fangs!" << endl;
    damage = (ghast.attack - pleya.stats.mydefense) + whatshouldIdo%3;

  }else if (currentattack == "Scratch"){
    cout << ghast.name << " uses long nails to scratch!" << endl;
    int scratchnumber = 0;
    int amountofscratch = whatshouldIdo % 3;
    for (int i = scratchnumber; i <= amountofscratch; i++){
      onesecsleep();
      cout << ghast.name << " scratches "<< (i+ 1) << " time."<< endl;
      damage += ghast.attack % 4 + 1;
    }
    damage -= pleya.stats.mydefense;
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
    damage += (ghast.defense - pleya.stats.myattack);
    if (damage >= 0){
      ghast.currenthealth += damage;
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
  }
  if (ghast.momentarychange != 0){
    damage -= ghast.momentarychange;
    ghast.momentarychange = 0;
  }
  if (damage < 0  ){
    damage = 0;
  }
  pleya.stats.mycurrenthealth -= damage;
  cout << pleya.info.myname << " has been dealt " << damage << " damage by the "<<ghast.name<< endl;
  onesecsleep();
  halfasecsleep();
}

void MonsterDefend(GhostData &ghast, Player &pleya, int &hexed){
  cout << ghast.name << " will defend!";
  halfasecsleep();
  if (hexed > 0){
    pleya.stats.mycurrenthealth -= (ghast.defense % 3 + 1);
    hexed -=1;
    cout << pleya.info.myname << " is being hurt by the hex.";
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
      cout<< p.info.myname << " uses the Ling Fu on " << g.name<<endl;
      if (g.name == "Hungry Ghost" || g.name == "Possessed Medium"){
        damage = (((((2*p.stats.level/5)+2) * (p.stats.myattack/g.defense))/50)+2) * 1.5;
      }else{
        damage = (((((2*p.stats.level/5)+2) * (p.stats.myattack/g.defense))/50)+2) * 1;
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
    if (g.imdefending = true){
      damage -= (g.defense - (whatshouldIdo % 3));
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
    if (p.stats.myspeed % 10 > whatshouldIdo % 10){
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
    if (whatshouldIdo < 25){
      MonsterDefend (g, p, hex);
    }else{
      MonsterAttack (g, p, hex);
  }
  }else if (g.name == "Vengeful Spirit"){
    if (whatshouldIdo > 50){
      MonsterDefend (g, p, hex);
    }else{
      MonsterAttack (g, p, hex);
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
      enemymoves(x,ghost, isplayerhexed);
    }

    else {
      enemymoves(x,ghost, isplayerhexed);
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
