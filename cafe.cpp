#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"

void catcafeMenu(Player& x) {
    string tempkey;
    cout << "press any key to enter your Cafe";
    getline(cin, tempkey);
    while (true) {
        cout << R"(
 ___ ___   ___ ____  __ __
|   |   | /  _|    \|  |  |
| _   _ |/  [_|  _  |  |  |
|  \_/  |    _|  |  |  |  |
|   |   |   [_|  |  |  :  |
|   |   |     |  |  |     |
|___|___|_____|__|__|\__,_|
  _____  ___   ___         __  ____ ______  ____ _      ___   ____ __ __   ___ _____
 / ___/ /  _] /  _]       /  ]/    |      |/    | |    /   \ /    |  |  | /  _/     |
(   \_ /  [_ /  [_       /  /|  o  |      |  o  | |   |     |   __|  |  |/  [_|  Y  |
 \__  |    _|    _]     /  / |     |_|  |_|     | |___|  O  |  |  |  |  |    _|__|  |
 /  \ |   [_|   [_     /   \_|  _  | |  | |  _  |     |     |  |_ |  :  |   [_   |__|
 \    |     |     |    \     |  |  | |  | |  |  |     |     |     |     |     |   __
  \___|_____|_____|     \____|__|__| |__| |__|__|_____|\___/|___,_|\__,_|_____|  |__|   Press (c)
 __ __ ____ _________ ______      __ __  ___  __ __ ____          __  ____ _____  ___ _____
|  |  |    / ___|    |      |    |  |  |/   \|  |  |    \        /  ]/    |     |/  _/     |
|  |  ||  (   \_ |  ||      |    |  |  |     |  |  |  D  )      /  /|  o  |   __/  [_|  Y  |
|  |  ||  |\__  ||  ||_|  |_|    |  ~  |  O  |  |  |    /      /  / |     |  |_|    _|__|  |
|  :  ||  |/  \ ||  |  |  |      |___, |     |  :  |    \     /   \_|  _  |   _|   [_   |__|
 \   / |  |\    ||  |  |  |      |     |     |     |  .  \    \     |  |  |  | |     |   __
  \_/ |____|\___|____| |__|      |____/ \___/ \__,_|__|\_|     \____|__|__|__| |_____|  |__|     Press (v)
  ____  ___       ____   ____    __ __  _ _____
 /    |/   \     |    \ /    |  /  |  |/ /     |
|   __|     |    |  o  |  o  | /  /|  ' /|  Y  |
|  |  |  O  |    |     |     |/  / |    \|__|  |
|  |_ |     |    |  O  |  _  /   \_|     \  |__|
|     |     |    |     |  |  \     |  .  |   __
|___,_|\___/     |_____|__|__|\____|__|\_|  |__|
                                                     Press (b)

  )";
        getline(cin, tempkey);
        ClearScreen();
        if (tempkey == "c") {
            showCatalogue(x);
        }
        else if (tempkey == "v") {
            visitCafe(x);
        }
        else if (tempkey == "b") {
            //go back to main menu
            return;
        }
        else {
            cout << "This key does nothing... Please try again " << endl;
            getline(cin, tempkey);
        }
    }
}

void showCatalogue(Player& x) {
    string tempkey;
    while (true) {
        cout << "Your current money is " << x.stats.mymoney << endl;
        cout << R"(
          1 ........ Cat #1                  50 dollars
          2 ........ Cat #2                 200 dollars
          3 ........ Cat #3                 500 dollars
          4 ........ Cat #4                1200 dollars
          5 ........ Large supply of food  2000 dollars
          6 ........ New Furnishing        3000 dollars
          7 ........ Cat #5                5000 dollars
          8 ........ Store in Central     10000 dollars

          Do you wish to purchase anything? Press p.
          Wish to go back? Press b.
        )";

        getline(cin, tempkey);
        if (tempkey == "p") {
            purchase(x);
        }
        else if (tempkey == "b") {
            return;
        }
        else {
            cout << "That key does nothing. Please try again!" << endl;
        }
    }
}

void purchase(Player& x) {
    string tempkey;
    cout << "Which product do you wish to purchase?" << endl << "Press b to go back" << endl;
    getline(cin, tempkey);
    if (tempkey == "1") {
        if (x.info.catnumber[1] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 50) {
                    x.stats.mymoney -= 50;
                    x.info.catnumber[1] = true;
                    cout << "You have bought Cat #1!" << endl;
                    twosecsleep();
                    cout << endl << "His name is Pineapple. Visit your cafe to see him!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep Pineapple :C. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already have this cat. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "2") {
        if (x.info.catnumber[2] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 200) {
                    x.stats.mymoney -= 200;
                    x.info.catnumber[2] = true;
                    cout << "You have bought Cat #2!" << endl;
                    twosecsleep();
                    cout << endl << "Her name is Chocolate Cookie. Visit your cafe to see her!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep Chocolate Cookie. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already have this cat. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "3") {
        if (x.info.catnumber[3] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 500) {
                    x.stats.mymoney -= 500;
                    x.info.catnumber[3] = true;
                    cout << "You have bought Cat #3!" << endl;
                    twosecsleep();
                    cout << endl << "His name is Egg Tart. Visit your cafe to see him!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep this Egg tart :C. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already have this cat. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "4") {
        if (x.info.catnumber[4] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 1200) {
                    x.stats.mymoney -= 1200;
                    x.info.catnumber[4] = true;
                    cout << "You have bought Cat #4!" << endl;
                    twosecsleep();
                    cout << endl << "Her name is Lemon Tea. Visit your cafe to see her!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep this Lemon tea :C. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already have this cat. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "5") {
        if (x.info.catnumber[0] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 2000) {
                    x.stats.mymoney -= 2000;
                    x.info.catnumber[0] = true;
                    cout << "You have bought a large supply of food. Visit your cafe to see it!" << endl;
                    twosecsleep();
                    cout << endl << "With all this food, you won't have to worry about feeding cats or any clients for many years!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep this. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already bought this. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "6") {
        if (x.info.amountoffurniture == 0) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 3000) {
                    x.stats.mymoney -= 3000;
                    x.info.amountoffurniture += 1;
                    cout << "You have ordered full new furnishing for your cafe" << endl;
                    twosecsleep();
                    cout << endl << "It looks really fancy!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep this. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You have already bought this, or you should buy a cafe before!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "7") {
        if (x.info.catnumber[5] == false) {
            if (x.info.boughtcatcafe == true) {
                if (x.stats.mymoney >= 5000) {
                    x.stats.mymoney -= 5000;
                    x.info.catnumber[5] = true;
                    cout << "You have bought a really expensive cat" << endl;
                    twosecsleep();
                    cout << endl << "Her name is Strawberry. Visit your cafe to see her!" << endl;
                    twosecsleep();
                    cout << "Your current money is: " << x.stats.mymoney << endl;
                    twosecsleep();
                    return;
                }
                else {
                    cout << "Not enough money! Sorry..." << endl;
                    twosecsleep();
                    return;
                }
            }
            else {
                cout << "You don't have anywhere to keep Strawberry :C. Try buying a cafe first!" << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You already bought this. Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "8") {
        if (x.info.boughtcatcafe == false) {
            if (x.stats.mymoney >= 10000) {
                x.stats.mymoney -= 10000;
                x.info.amountoffurniture += 1;
                x.info.boughtcatcafe = true;
                cout << "Woah, you have bought a store in Central!" << endl;
                twosecsleep();
                cout << endl << "The queue waiting to go inside your cafe is already quite long" << endl;
                twosecsleep();
                cout << "Your current money is: " << x.stats.mymoney << endl;
                twosecsleep();
                return;
            }
            else {
                cout << "Not enough money! Sorry..." << endl;
                twosecsleep();
                return;
            }
        }
        else {
            cout << "You have already bought this! Get a new friend instead!" << endl;
            twosecsleep();
            return;
        }
    }
    else if (tempkey == "b") {
        return;
    }

    else {
        cout << "That key does nothing. Please try again" << endl;
        return;
    }
}

void visitCafe(Player& x) {
    if (x.info.boughtcatcafe == true) {
        cout << "Welcome to " << x.info.myname << "'s amazing cat paradise!";
        onesecsleep();
        cout << R"(
                                                                                   #
                                                        *@@@@@@@.
                                                     %@@@@@@@@@@@@@*
                       (((((((((((                @@@@@@@@@@@@@@@@@@@@%
                       @@@@@@@@@@@            ,@@@@@@@@@@@@@@@@@@@@@@@@@@@
                       @@@@@@@@@@@         #@@@@@@@@@@@@@%     @@@@@@@@@@@@@@*
                       @@@@@@@@@@@      @@@@@@@@@@@@@@,           #@@@@@@@@@@@@@%
                       @@@@@@@@@@@  .@@@@@@@@@@@@@@                  ,@@@@@@@@@@@@@@
                       @@@@@@@@@@@@@@@@@@@@@@@@&                         @@@@@@@@@@@@@@,
                       @@@@@@@@@@@@@@@@@@@@@/                               %@@@@@@@@@@@@@(
                       @@@@@@@@@@@@@@@@@@.                                     *@@@@@@@@@@@@@&
                       @@@@@@@@@@@@@@&                                             @@@@@@@@@@@@@@.
                    @@@@@@@@@@@@@@(                                                   @@@@@@@@@@@@@@/
                 @@@@@@@@@@@@@@.                                                         /@@@@@@@@@@@@@&
             *@@@@@@@@@@@@@@                                                                .@@@@@@@@@@@@@@.
          #@@@@@@@@@@@@@#                                                                       &@@@@@@@@@@@@@/
       @@@@@@@@@@@@@@,                                                                             (@@@@@@@@@@@@@%
   ,@@@@@@@@@@@@@@                                                                                    ,@@@@@@@@@@@@@@
#@@@@@@@@@@@@@&                                                                                           @@@@@@@@@@@@@@
   @@@@@@@@*                                                                                                 #@@@@@@@@
     (@@                                                                                                        ,@@,
        --------------------------------------------------------------------------------------------------------
                     )";
        twosecsleep();
        //check first if they don;t own any cats
        if (x.info.catnumber[1] == false and x.info.catnumber[2] == false and x.info.catnumber[3] == false
            and x.info.catnumber[4] == false and x.info.catnumber[5] == false) {
            cout << "Your cafe is empty and lonely :C. Get some friends to keep you company!";
            twosecsleep();
        }
        //they own at least one cat. Display cat(s)
        else {
            if (x.info.catnumber[1] == true) {
                cout << R"(
                                                            .. ../(**.                     .,,..
                           ......**#(###(*.%%##/.           ., .,,,.
                        .......,/(%*%(#(#/,,/&&&&&%&%/,.,****. .,,..
                        ...... *%%(/**##%#%%&&&&&&&&(,*((#(#*,...,..
                        .. .  */%###%%%%%&&&&&&&&&&&&%%%#/,(**...,..             ........
                    ..,*,*,*/*/%&&&&&&&&&%%%%#%%&%%%%%%#(**..   ....    ..         ......
                   .,*/(#%%&%%%&&&&&&&%#((  *//%@#/###%%#(,     ,,,.                ....
                .,,/#%%%&&&&%&&&&@&&&&%#((##(%&&&,,/###(/,.  .....
               .,(#%%&&&&&&&&&&@@&@@@&&&&&@@@&@&%&@##(((*    ....
            ..*##%%%%&&&&&&&&&&@@@@@@@@&&%&&&&#/&&&#%##*                                 ..
           ..*(##%%%%&&&&&&&&&&&&@&&@@@&&&&%%%#####&%(,...                    ...   ..   ........
           .*#%%%%%%&&%%&&&%&&&&@&@&&&&&@@@&&&&&&%%(,*/,/,,..        ..,,.    .,,.  ..   ........
          .*(#%%%&&%&&%%%&&&@@@@@@@&@&&&&&&&&&&&&%(*,*.,,....        ....       ......
          .,(%%%&&&&&&&%&&&&@@@@@&@@&&&&&&&&&&%%**.. ..                         ....
          .*#%%&&&&&&&@&&&&@@@@@@@@&&&&&&&&%%%#(.,           ................  ......   ...
        ..*#%%%&&&&&&&&&&%&&@@@@@@@&&&&&&&&&&##..   .....,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.........
.......,,,(#%%%%&&&&&&@&&&%%&&@@@@@@&&&&&&@@&%/,,,*////(((((((##########%%%%%%##########(((((////**,
.....,,,,,*(#%%%%&&&&&&&&&&%%&@@@@@&&%&&&@@@@&******///**///**/*///*/**/**//(////////********,,,,,,,
,,,,,,,****/#%%%&&&&&&&&&&&%%%@@@@&&&%%&&@@@&%/(((((###########((##########%%##%%#########((((((//**
....,,,,,,,,/##%&&&&&&&%%%%###&@@@@@&/#&&@@@&/*///(((((((((((/////#%%%%%%##(((((((((/////**,****,,,,
......,,,,,*(####%%&&&&&%(///#%&@@&&&(#&&&&&&&&%#((((((((((((/(((#%%%%%%%###////////*/*****,,,,,,...
.,,,,,,****//(((/*/#%%#%%((((/*/#%%/*(/#%&&&&&&%%(((((((((((((((((#########(//////////****,**,,,.,..
.,,,,,****////((((((####((###%#%%%%%%#%#######################(##**/####((**((((((//////******,,,,,,

                         )";
                onesecsleep();
                cout << "Pineapple wants pets!! Pets please!!!";
                twosecsleep();
            }
            if (x.info.catnumber[2] == true) {
                cout << R"(



                   .....


             . . .,#%&@&&#*..
             ../&@@@@@@@@@@&/
            .(@@@@@@@/..,#@&&(..
         . .%@@@@@%
          .%@@@@@#
          ,%@@@@@*
          .#@@@@@( .
          .#@@@@@@
           ,%@@@@@%.                                                                    ,
            ,&@@@@@%                                                                  /&&&.
             ,&@@@@@%.                                                             ,%@@@@%.
              .#@@@@@@@*                                                      .(@@@@@@@@@@@@@/
                *&@@@@@@@@@@@&@@&@@@@@@@@@@@@&&@&&@&%#*,.                  ,%@@@@@@@@@@@@@@@@@@
                 .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%&@@@@@@@@@@@@@@@@@@@@@@@@&@&.
                  .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.
                  ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
                 .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*
                .%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/
                *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
                *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*
               *%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
             .(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*
           *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
          &@@@@@@@@@@@@@%&@@@@@@@@@@@(...,.              #@@@@@@@@@&&%%((&@@@@@@@@@@@%
         &@@@@@&%(,     ,%@@@@@@@@@@/                    &@@@@@@/          ,&@@@@@@@@@#
        %@@@&           ,&@@@@@@@@(                     *@@@@@&              /&@@@@@@@@@.
       %@@@#            (@@@@@@@%                       %@@@@#                  /@@@@@@@@%
      ,@@&&              &@@@@@.                       #@@@@(                      ,&@@@@@@&.
      &&@@,               (@@@@&                       &@@@*                           #@@@@&&,
      ,&@#                  (@&@@@,                   .&@@@(.                            .&@@@@@@(%*
     ...,.....................(@@@@@@@%...............,%@@@@&*.........................,.,,,,/@@@@@@
                  ............,,,*///*,,..............,,,,,,............................


)";
                onesecsleep();
                cout << "Chocolate cookie is very hungry...what do you mean I just ate?";
                twosecsleep();
            }
            if (x.info.catnumber[3] == true) {
                cout << R"(


                                                          ,@&.
                                                         @@@@@            %@@/
                                                       .@@&&@@#          &@@@@&
                           .#@@@@@@@@@@@@@@@@#,.      .@@&%&&@@.        %@@%%@@(
                       *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@%%%%@@@       #@@%&&&@@
                     &@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&%&&@@*
                   #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%.
                 .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%      %@@@@@@@@@@@@@@@@@@@@@@@
                /@@@@@@@@@@@@@@@@@@@@@@@@//%@@@@@@@@&   *#(   .@@@@@@@&.    .#@@@@@@@@@,
               *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,  ,@&&%   @@@@@@*   (@*   &@@@@@@@@(
               &@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#*&@@@@@         #@@/&@@   (@@@,  *@@@@@@@@@,.*((
              .@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@&&&@@@@@%@(@@@        .@@@@@@@@@@/
              /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&@@@@@@@@@@@@@/
           ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
         .@@@@@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&
        ,@@@@&   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
        %@@@@(    /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/
        %@@@@&      .@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*
        *@@@@@@         /@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%
         *@@@@@@%            *&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/
           &@@@@@@@&,                ./#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,
             /@@@@@@@@@@@@@&%#/*.                 (@@@@@@@@,          *@@@@@@@@.
                *@@@@@@@@@@@@@@@@@@@@@.             %@@@@@@@,           .@@@@@@,
                    (@@@@@@@@@@@@@@@@@@/              ,&@@@@                ,.
                         (@@@@@@@@@@@%





)";
                onesecsleep();
                cout << "MISCHIEF?! MAYHEM??!! Egg tart would NEVER!!";
                twosecsleep();
            }
            if (x.info.catnumber[4] == true) {
                cout << R"(


                                ,(
       /#%%*                 .%%(*(*
        #(/(%%#            .&&%(/#(.
        .#(##%%%&&&%%#%%&&&&&%(####
          #%#%%%%&&&&&&&&%&%%&%%##%
          (%#%%%&&&&@&&&&&&&&&&&&@%
          %%&%%/(%&&&&&&&&/*(%&&&&&                                    ,,*,   ..*.,
          %%&%(,**&&&&&&&(,*%&&@&&&@%
          .%%%&&&&&@&&&&&&&&@&@&&&&&&&&&.
            %%%%%&&&&&@&&&&%&%&&&&&&&&&&&&&&.
             (((#%%&%@&&%%%%%&%%&&%%&&&&&&&&&&&%%&%*
               %#%&%%%&%&&&%%%&&&&&&&&&&&&&&&&&&&&&&%%&&&%%&%(.
                .&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&%%%%%%%%%%&%.
                 %%%%%%%%&&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&&&&%%%%%%%%%%%%#
                 ##%%%%%%%%&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&&&&&&&&&%%%%%%%%%&.
                 /##%%%%%%%%%&&&&&&&&&&&&&&&%%&&&@@&&&&&&&&&&&&&&&&%&&%%%%%&&(
                  *#%%%%%%%%%%%&&&&&&&&&&&&%&&&&&&&&&&&&&&&&&&&&&&&&&&%&&%%%%%&/
                   .%%%%&&&&%%%%&&&&&&&&&%&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%%&&
                     .%%%#%&&&&%%%&&&&&&&%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&%%%%&&
                        #%%%%&&&&%%%&&&&&%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%%%&,
                          /%&%&&&&&%%&&&%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%&&
                            /%&&&&&&%%&&%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@&&&&&&&&&&&&
                             #%&&&&&%%%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
                             %%&&&&&%%%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&,
                             %%%&&&&%%%&&&&&@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
                             %%%&&&&%%%&&&&&&&&&%%&&%%&&&&&&&&&&&&&&&%%&&&&&&&&&&&&&&&&&&&.
                             %%&&&&&%%%&&&&@(&&&%%%&%%&%&&&&&&&&&%%&%%%%%%%&&&&&&&&&&&&&&&@.
                             %%&&&&,%%&&&&@(  .%&&%&&%&&&&&&&&&%%%%%%%%&%%%%&&&&&&&&&&&&&&&@
                            %&&&@@&*%%&&&&&      #&&&%&&&&&&%%%&%%%&&&&&&%&&&&&&&&&@@&&&%&&&(
                      ,&%%&@@@@@@* %&&&&&@#        *&&&&&&&&&&&&&&&&&&&&&&&&&&@@@@@&%%%%&&@@*
                     (@&@&&@@@@&@&@@@@&@&,   ,(&&@&&&&&&&&&&&&&&%&%%%%%%%%%%%%%%%%%%&&&&&@@&.
                       ..,,,,*&&&@&@@@@&#%%%%%%%%%%%%&%%&&%%%%&%%%%&&&&&&&%%&&%%&&&&&@&@@@&/,
                              .*//*,,,.../&&&@@@@@@@@&@@@&&&&&@&@@@@@@@&@&@&&&@@&@@@@@@@%/,.
                                                        .......,,**/#%&&&&&&&&&&%#/*,.

)";
                onesecsleep();
                cout << "Fish? Fish? Human, do you have any fish?";
                twosecsleep();
            }
            if (x.info.catnumber[5] == true) {
                cout << R"(



          .(%&&%*                          (&%%%%%
          #(####%%&&#                  ,&&%##(**(#
           %(/////#%%&&@%.     .  .,(@&&&%%(***#%
            %#((/***#%%&&&%%%%&&&&&&&&&&&%#//((#
             (#((%##%&&&%&&&%%&&&&@&%%&&&@%(##%
               ####%&&&&..,/&&%&@&&/../&&&&%##
                 &&&&&%#%&&%&@&%&&@&&&&%&@&@
                   ,%%&&@&&@&%%##%@&&@&&&#
                     (&&&%##%&&&&&&&&&&&%
                     .&&&%&&&&&@&@&%%&&&,
                     %%&&@@@&&%%%%&@@@@@&
                    *&&&@@&&&@@@@@@@@@@@@%
                    &&@&&&&&&&@@@@@@@&&&&@@
                   %%&&@@&&&&&&@@@@@@&&&&&@@
                  .&&&&@@&&&&&&&@&@@@@&&&&@&&
                  ,&%%&&@@@&&&&&&&&&&&&&&@@@@
                  ,%%%&&&@@@&&&&&@@&&&&&&@@@@*
                  /&%%&&&&&&&&&&&@@&&&&&@@@@@/
                  *&%%%%&&@&&&&&&&&&&&&&&@@@@/
                  .&%%%%&%&%%%&&&&&&&&&&&@@&&,
                   @&&&@@@&&%%%&&&&@@@@@&&@@@.
                  (&%&&@@@@@@&%&&@@@@@@@&&&@@
                 .&%%&&@@@@@@@&&&@@@@@@@&&@@&&
                 &%%%%&@@@@@@@@@@@@@@@@@&&&&@&(
                 @%&&&&&@@@@@@@@@@@@@@@@&&@&@&&
                (@&#&&&@&@@@&&@&@@@&@@&&&&@@@&&
              ,&&&&%%&&&&@@&&&&@&&&@@&&&&&&&@@@&*
             %%&&&&@%&&&&@@&&&&&&&&@@&&&&@&&@@@@&/
            *&&&&&&&%&&&&&@@&&&&&&&&&&&&@@&@@@@&&%
            %&&&&&&&%&%%&&&&@&&&%&&@&%&&@&@@@@@@&&
            %%&&&&&&&#&%&@@&&@&&&&@&%&&@@&@@@@@@@&
           .%%%%&&@@&%%&&&@&@@&&&&@%&&&@@&&&@@@&&%
           .&%%%%&&&&%&%&@@&@@&&@&@#&&&@&@@@@@@@&(
           .&&%%%&&&&&%&&&@&@@@&&&@#&&&@&@@@@&&@@@@@&&&&%%%####/*,
            .&%%%&&&&@#%%@@&@&&&@&@%&&&@&@@@&&@@@@@@@@@@&&@@&&&&&&&&&&%%%##%%.
              ,%&&&&&&%%&&&&@@&@&&&%&&&@&@@&&&@&%(,.                 ...*#&&&&%%#%*
                (%%&&&%&&&@&@@&&&@%%&&@@&@&&(.                                .*%@%#%(
                   /&@%&&&@&&@&&&@#&&&@@&/                                         ,%&%#(
                   #&&&%&&@@&@&&@&%&&&@@/                                              ,&%%
                  .%&@&@&&@@@/,..(&&&&&@@#
                    ,%%&&&&@@&.  .%%#&&%&@&*
                    .&&%&%@@%.    (&%%@&%@%.

)";
                onesecsleep();
                cout << "I truly can't believe you left me with these hooligans. Such a place does not befit a feline of my stat- ooooooooh is that catnip?";
                twosecsleep();
            }
            if (x.info.catnumber[0] == true) {
                cout << R"(


                                                                                                                                                                     ..
                                                                (/%#,*,.
                                                             ((%/&&#&#%%
                                                              #@@@@@&&(
                                          #(#*/*,/             ,&&@&#,
                          .%%(*          &&&&&&&&%(.            &@@.
                        .**(###%%%#&/*##@@@&%&#/*               &&
                           .%@&%*#&&&@@%(&&*           (*#&%&&%&&@(%((
                            /&#&%%@&%&(#@/%#%&%%.  ,,&/*#(%%/##&@@@(%#%%&/
                        ,((*/(%&&&%(/&#/%/(#/&%%%&#/.,%/*#((&%&@@@@%*#%&%%&%%.
                     ,///(%(/#%%&@*(/(@(%@/((#(@##%@(%,/#/,,(&&@@&%@%/%&&&(&@&&@
                  .,*/#**//(%%&&@&//(#%%%##%###(%&%#%@&(%/,*&%%%&###&.%#&%###&&&%#
                  ,((,,*//%%&@@@@#/(/(&/*&%#%##((#&%%#%&%%(%%&&&&%/&%*%@#%%%#%%&&%&#
                 ,,,.***%&@&#@&@@&(/#*&/.%&(###&&&##@#%#%%%&&&&(%&#@&%%%%%%%%%%#%#%#%(
                 /(%#/(%((##(%&&@//%(.%#.(%*%%%%%%%#%&%%#%%#&&&(#&%@&%&&%(%%%%%##%###(,
                *((###/%(#(%&&#%@*%%,.*#*##%*%%%#%%&#%&&%##(&@@&@&&&@&&&%%%%%%%#######(
               */(###%%%#%(#((/%&(%#%&%%%&%##%%%%%&%&%%%&##%%&@@@@%&&&&%%%&%%%%%########
              ((////#((///##&##&%#%((#%%%%%%%%%%%%%&%&%%%%#&%%@@@@&&&&%%&%%%%%%%%########
             /%(%////*//(%(/#%%&/&&%%%&%%%%%%%%%%%%%%%%%%%%#&%@@@@@&&%&%%&%%%%%&%#######%
             *##%%%#(//((##((/&%%%%%%###%%%%%%%%%%%%%%%%%#%%(%@@@&&&&&&&&&&%%%%%&%####(#(.
             (/(%*(%###(/(((%%#(&&&&%%&%%&&%%%%%%%%%%%%%%%%##%&@@@&%%&&&&&&%%%%%%&%####(#.
            /%##*#%(%#%%/#((((#(#%#&&&&%&&&&&&&&%%%%%%%%%%%%#%#&@@@@&&&&&&&%%&&&%%%####(#
           .(((#/(###(((#((((%(#(#(##%&%&&&&&%%%%%%%%%%%%%%%%%##@@@@@@&&&&&&&&&&&&&%#%%##
           /#(*/%/#(#%%%##((%(#(#%#(#&&##%%&%&%%%%%%%%%%%%%%%%#%#@@@@@@&&&&&&&&&&@&%#&#%@
           *(#(((#(#######((####((###&%#&&%%%%%%%%%%%%%%%%%&%%%%%@@@@@&&&&&&&@@@&&%@@&&(.
            ####((/((##############(########%%%%%%%%%%%%&%%%##%%%##%%&@@@&@@@@@@&&@&&#,..
             ###%((((########################%%%&&%%%%%%%%%%%%#%%#********,***,**,,,,....
             .#(((####(#######################%%%%%%%%%%%%%%%##%%(,,,,,,,,,.............
                 ,(%&&&&&&@@@&&&&&&&&&&&&%%%%%%%%%%%%%%%%%%%%%%&%,,,,,.................
                          ..,/(###%%%%%&&&&&&@@@@@@&&%%%%%%&@@&/*,,,.................
                                      ...,*//((####%%%&&&&%(**,.,.................
                                                        ........



)";
                onesecsleep();
                cout << "***  Food noises   ***";
                twosecsleep();
            }
        }
        cout << R"(
        --------------------------------------------------------------------------------------------------------
        --------------------------------------------------------------------------------------------------------
)";
        cout << "Goodbye~";
        string n;
        getline(cin, n);
        return;
    }
    //they don't own a cat cafe yet
    else {
        cout << "You don't own a cafe yet :C" << endl;
        twosecsleep();
        return;
    }
}
