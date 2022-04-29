#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"



void catcafe(Player& x) {
    string tempkey;
    cout << "press any key to enter your Café";
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
 ____  _      ____ __ __      __    __ ____ ______ __ __      __ __  ___  __ __ ____          __  ____ ______  __________
|    \| |    /    |  |  |    |  |__|  |    |      |  |  |    |  |  |/   \|  |  |    \        /  ]/    |      |/ ___/     |
|  o  | |   |  o  |  |  |    |  |  |  ||  ||      |  |  |    |  |  |     |  |  |  D  )      /  /|  o  |      (   \_|  Y  |
|   _/| |___|     |  ~  |    |  |  |  ||  ||_|  |_|  _  |    |  ~  |  O  |  |  |    /      /  / |     |_|  |_|\__  |__|  |
|  |  |     |  _  |___, |    |  `  '  ||  |  |  | |  |  |    |___, |     |  :  |    \     /   \_|  _  | |  |  /  \ |  |__|
|  |  |     |  |  |     |     \      / |  |  |  | |  |  |    |     |     |     |  .  \    \     |  |  | |  |  \    |   __
|__|  |_____|__|__|____/       \_/\_/ |____| |__| |__|__|    |____/ \___/ \__,_|__|\_|     \____|__|__| |__|   \___|  |__|   Press (p)
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
        if (tempkey == "c") {
            ClearScreen();
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
            while (true) {
                getline(cin, tempkey);
                if (tempkey == "p") {
                    cout << "Which product do you wish to purchase?" << endl << "Press b to go back" << endl;
                    getline(cin, tempkey);
                    if (tempkey == "1") {
                        if (x.info.catnumber[0] == false) {
                            if (x.stats.mymoney >= 50) {
                                x.stats.mymoney -= 50;
                                x.info.catnumber[0] = true;
                                cout << "You have bought Cat #1!" << endl;
                                onesecsleep();
                                cout << endl << "His name is Pineapple." << endl;
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already have this cat -- or you should purchase other cats first!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "2") {
                        if (x.info.[1] == false) {
                            if (x.stats.mymoney >= 200) {
                                x.stats.mymoney -= 200;
                                x.info.catnumber[1] = true;
                                cout << "You have bought Cat #2!" << endl;
                                onesecsleep();
                                cout << endl << "Her name is Chocolate Cookie." << endl;
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already have this cat -- or you should purchase other cats first!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "3") {
                        if (x.info.catnumber[2] == false) {
                            if (x.stats.mymoney >= 500) {
                                x.stats.mymoney -= 500;
                                x.info.catnumber[2] = true;
                                cout << "You have bought Cat #3!" << endl;
                                onesecsleep();
                                cout << endl << "His name is Egg Tart." << endl;
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already have this cat -- or you should purchase other cats first!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "4") {
                        if (x.info.catnumber[3] == false) {
                            if (x.stats.mymoney >= 1200) {
                                x.stats.mymoney -= 1200;
                                x.info.catnumber[3] = true;
                                cout << "You have bought Cat #4!" << endl;
                                onesecsleep();
                                cout << endl << "Her name is Lemon Tea." << endl;
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already have this cat -- or you should purchase other cats first!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "5") {
                        if (x.info.catnumber[4] == false) {
                            if (x.stats.mymoney >= 2000) {
                                x.stats.mymoney -= 2000;
                                x.info.catnumber[4] == true;
                                cout << "You have bought a large supply of food" << endl;
                                onesecsleep();
                                cout << endl << "With all this food, you won't have to worry about feeding cats or any clients for many years!" << endl;
                                twosecsleep();
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already bought this, or you should buy more cats before!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "6") {
                        if (x.info.amountoffurniture == 1) {
                            if (x.stats.mymoney >= 3000) {
                                x.stats.mymoney -= 3000;
                                x.info.amountoffurniture += 1;
                                cout << "You have ordered full new furnishing for your cafe" << endl;
                                onesecsleep();
                                cout << endl << "It looks really fancy!" << endl;
                                onesecsleep();
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You have already bought this, or you should buy a cafe before!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "7") {
                        if (x.info.catnumber[5] == false) {
                            if (x.stats.mymoney >= 5000) {
                                x.stats.mymoney -= 5000;
                                x.info.catnumber[5] = true;
                                cout << "You have bought a really expensive cat" << endl;
                                onesecsleep();
                                cout << endl << "Her name is Strawberry" << endl;
                                twosecsleep();
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You already bought this, or you should buy more cats before!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "8") {
                        if (x.info.amountoffurniture == 2) {
                            if (x.stats.mymoney >= 10000) {
                                x.stats.mymoney -= 10000;
                                x.info.amountoffurniture += 1;
                                cout << "Woah, you have bought a store in Central!" << endl;
                                onesecsleep();
                                cout << endl << "The queue waiting to go inside your cafe is already quite long" << endl;
                                onesecsleep();
                                cout << "Your current money is: " << x.stats.mymoney << endl;
                                twosecsleep();
                                break; //or return
                            }
                            else {
                                cout << "Not enough money! Sorry..." << endl;
                                twosecsleep();
                            }
                        }
                        else {
                            cout << "You have already bought this, or you should buy other products before!" << endl;
                            twosecsleep();
                        }
                    }
                    else if (tempkey == "b") {
                        break; //or return
                    }
                    else {
                        cout << "this is not a valid key. Please try again" << endl;
                    }

                }
                else if (tempkey == "b") {
                    break; //or return?
                }
                else {
                    cout << "This key does nothing... Please try again" << endl;
                }
            }
        }
        else if (tempkey == "v") {
            ClearScreen();
            //print cafe
        }
        else if (tempkey == "p") {
            ClearScreen();
            //print cats
        }
        else if (tempkey == "b") {
            return;
        }
        else {
            cout << "This key does nothing... Please try again " << endl;
            getline(cin, tempkey);
        }
    }
}
