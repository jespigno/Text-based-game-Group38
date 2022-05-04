#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"

Point position;


//checks if player has met the winning condition of their specific level
bool Map::check_win() const {
	//level 1 objective is to defeat all the monsters
	if (level = 1) {
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 45; j++) {
				if (map[i][j] == 3) {
					return false;
				}
			}
		}
		return true;
	}
	//level 2 objective is to collect all treasures
	else if (level == 2) {
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 45; j++) {
				if (map[i][j] == -1) {
					return false;
				}
			}
		}
		return true;
	}
	//level 3 objective is to collect a specific treasure
	else if (level == 3) {
		if (map[15][21] == 0) {
			return true;
		}
		return false;
	}
}

//randomly selects points from the possible enemy positions to add to the actual enemy positons
void Map::spawn_enemies() {
	while (loot.size() < num_loot) {
		int n = rand() % (possible_enemy.size() - 1);
		for (int i = 0; i < enemy.size(); i++) {//checks that point has not already been selected
			if (enemy[i] == possible_enemy[n]) {
				continue;
			}
		}
		enemy.push_back(possible_enemy[n]);
	}
}

//randomly selects points from the possible loot positions to add to the actual loot positons
void Map::spawn_loot() {
	while (loot.size() < num_loot) {
		int n = rand() % (possible_loot.size() - 1);
		for (int i = 0; i < loot.size(); i++) {
			if (loot[i] == possible_loot[n]) {////checks that point has not already been selected
				continue;
			}
		}
		loot.push_back(possible_loot[n]);
	}
}

//adds enemies, loot and the player to the map
void Map::create_map(Point &position) {
	spawn_loot();
	spawn_enemies();
	position = entry;
	map[entry.x][entry.y] == 2; //places player at start position
	for (int i = 0; i < loot.size(); i++) {
		map[loot[i].x][loot[i].y] == -1;
	}
	for (int i = 0; i < enemy.size(); i++) {
		map[enemy[i].x][enemy[i].y] == 3;
	}
}

//prints current map with players's position, loot and enemies
void Map::print_map() const {
	for (int i = 0; i < 30; i++) {
		cout << "                    ";
		for (int j = 0; j < 45; j++) {
			if (map[i][j] == 1) {
				cout << '+' << ' ';
			}
			else if (map[i][j] == 2) {
				cout << '$' << ' ';//whatever icon we have picked to represent the user
			}
			else if (map[i][j] == 3) {
				cout << '@' << ' ';//enemies
			}
			else if (map[i][j] == -1) {
				cout << '~' << ' ';//treasure
			}
			else {
				cout << ' ' << ' ';
			}
		}
		cout << endl;
	}
}

Map map1, map2, map3;
map1.level = 1;
map1.map = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1},
	{0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1},
	{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1},
	{1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1},
	{1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1},
	{1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
map1.entry = { 18, 0 };
map1.exit = { 6,4 };
map1.num_enemies = 8;
map1.num_loot = 4;
map1.possible_loot = { {2,35},{3,40}, {4, 9}, {4, 29}, {5,18}, {7,11}, {10,8},
	{10,32}, {13, 37}, {15, 12}, {15, 38}, {17, 28}, {18,41}, {19,18},
	{19,40}, {22,36}, {23,13}, {25, 25}, {25, 32}, { 26, 41 } };

map1.possible_enemy = { {2, 39 }, { 3,12 }, { 4,23 }, { 5,36 }, { 6,7 },
	{ 6,40 }, { 9,10 }, { 9,29 }, { 10,19 }, { 12,34 }, { 15,18 }, { 16,40 }, { 18,7 },
	{ 20,15 }, { 24,15 }, { 25,6 }, { 25,30 } };
map1.loot = { {11, 24}, {27,3} };//some positions already predetermined
map1.enemy = { {20,21}, {24, 42}, {3, 42} };

map2.level = 2;
map2.map = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,1},
		{1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,0,0,0,1,1,0,1},
		{1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,0,1,1,0,1},
		{1,1,0,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
		{1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1},
		{1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,1,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1},
		{1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1},
		{1,1,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1},
		{1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,0,1,1},
		{1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1},
		{1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1},
		{1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1},
		{1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
map2.entry = { 22,2 };
map2.exit = { 1,0};
map2.num_enemies = 12;
map2.num_loot = 6;
map2.possible_loot = { {1,30 }, {2,43 }, {3,19 }, {3,36 }, {4,26 }, {5,7 }, {6,13 }, {6,17 }, 
	{8,29 }, {8,38 }, {9,23 }, {11,1 }, {12,34 }, {12,41 }, {13,10 }, {13,17 }, {13,26 }, {13,30 }, {15,42 }, 
	{16,16 }, {17,22 }, {17,37 }, {18,32 }, {20,15 }, {20,19 }, {20,26 }, {20,30 }, {21,35 }, {21,42 }, 
	{23,3 }, {24,30 }, {24,38 }, {25,28 }, {26,7 }, {26,34 },, {27,15 }, {27,24 } };
map2.possible_enemy = { {1,3 }, {1,40 }, {3,27 }, {4,6 }, {4,39 }, {5,18 }, {6,2 }, {7,14 }, {7,25 }, 
	{8,37 }, {9,10 }, {9,20 }, {10,1 }, {11,14 }, {11,34 }, {12,6 }, {12,11 }, {12,18 }, {12,25 }, {12,29 },
	{13,42 }, {16,37 }, {17,3 }, {17,15 }, {18,33 }, {20,42 }, {21,15 }, {21,29 }, {21,34 }, {23,38 }, {24,4 }, 
	{25,30 }, {26,8 }, {26,21 }, {26,35 }, {28,11 } };
map2.loot = { {5,38 }, {18,4 }, {26,42 }};
map2.enemy = { {3,41}, {18, 6}, {25, 42} };

map3.level = 3;
map3.map = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
		{1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
		{1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1},
		{1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1},
		{1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1},
		{1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1},
		{1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1,0,1},
		{1,0,0,1,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,1,0,1},
		{1,1,0,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1}
};
map3.entry = { 15,0 };
map3.exit = { 29,44 };
map3.num_enemies = 6;
map3.num_loot = 6;
map3.possible_loot = {};
map3.possible_enemy = {};
map3.loot = {};
map3.enemy = {};




//move user icon on the map
//only allows player to move in free space i.e. no walls
//input: map, player's current coordinates and move they're making
//output: integer indicating whether player has lost to a monster, completed the level, or is continuing
//1: no monster encountered, or monster defeated or fled from. No further action required
//2: level completed, end level
//3: player defeated, end level
int makeMove(Map &m, Player &p, Point &position, char move) {
	//valid input
	int x = position.x;
	int y = position.y;
	Point e; //enemy coordinates
	if (move == 'w' or move == 'a' or move == 's' or move == 'd') {
		if (move == 'w' and m.map[x - 1][y] < 1) {
			if (m.map[x - 1][y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x - 1][y] = 2;
			m.map[x][y] = 0;
			x = x - 1; //update coordinates
		}
		else if (move == 'a' and m.map[x][y - 1] < 1) {
			if (m.map[x][y - 1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x][y - 1] = 2;
			m.map[x][y] = 0;
			y = y - 1;
		}
		else if (move == 's' and m.map[x][y + 1] < 1) {
			if (m.map[x][y+1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x][y + 1] = 2;
			m.map[x][y] = 0;
			y = y + 1;
		}
		else if (move == 'd' and map[x + 1][y] < 1) {
			if (m.map[x + 1][y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x + 1][y] = 2;
			m.map[x][y] = 0;
			x = x + 1;

		}
	}
	else {
		cout < "That's not a valid move. Try again." << endl;
		onesecsleep();
		return 1;
	}

	char enemy, win;
	//check if player is within sensing distance of an enemy
	if (m.map[x - 1][y - 1] == 3) {
		e.x = x - 1;
		e.y = y - 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') { //player won, continue on map
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') { //player lost, level is ended
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			//player is teleported outside of the area where the enemy can detect them
			//checkfree functions are ordered such that best case scenario is player gets teleported ahead in
			//the direction they were originally headed
			//worst case scenario is the player gets teleported backwards by one step

			m.map[position.x][position.y] = 0;  //remove player from current spot on the map
			//update position to most convenient free spot on the map
			if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			//drop player in new spot on the map
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x - 1][y] == 3) {
		e.x = x - 1;
		e.y = y;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.x] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x - 1][y + 1] == 3) {
		e.x = x - 1;
		e. y = y + 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x][y - 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = x;
		e.y = y - 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x][y + 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = x;
		e.y = y + 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x + 1][y - 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = x + 1;
		e.y = y - 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x + 1][y] == 3) {
		//enemy senses player. insert battle functions here
		e.x = x + 1;
		e.y = y;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[x + 1][y + 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = x + 1;
		e.y = y + 1;
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[e.x][e.y] = 0;
			onesecsleep();
			return 1;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			m.map[position.x][position.y] = 0;
			if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree1(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	//checks if player has reached the exit point
	//if they have, checks if they've won
	if (position == m.exit) {
		if (m.check_win() == true) {
			return 2;
		}
		else {
			cout << "You have not yet completed this level's objective. Please return quickly!" << endl;
			onesecsleep();
			return 1;
		}
	}
	return 1;
}


//called when player encounters loot
//randomises earnings gained based on level
//input: map level, player's current earnings
void takeLoot(int level, int& money) {
	//player finds treasure
	int loot;
	//increase player money by a random number whose range will depend on what level this is
	if (level == 1) {
		loot = 20 + rand() % 30;
	}
	else if (level == 2) {
		loot = 30 + rand() % 70;
	}
	else if (level == 3) {
		loot = 50 + rand() % 100;
	}
	cout << "You picked up a treasure worth " << loot << "dollars!";
	money += loot;
}

//loads an entire level of the game depending on level of map loaded
//links all attack functions and map functions
//input: map struct, player struct
//output: bool indicating whether player has completed the level successfully
bool loadlevel(Map m, Player& x) {
	Map* map;
	Point position;
	map = new Map;
	*map = m;
	map.create_map(position);
	char move;
	int val= 1;
	while (val == 1) {
		getline(cin, move);
		val = makeMove(map, x, position, move);
	}
	if (val == 3) {
		cout << "You have lost this round. What a pity :C. Better luck next time!" << endl;
		twosecsleep();
		ClearScreen();
		delete map;
		return false;
	}
	else if (val == 2) {
		cout << "You have completed the level. Congratulations!" << endl;
		twosecsleep();
		ClearScreen();
		delete map;
		return true;
	}
}


//randomises enemy from an array with enemies sorted from weakest to strongest
//only parts of the array are avilable to choose from depending on the level
//input:map
//output: a character symbolising what type of enemy the user has encountered
char randomise_enemy(Map m) {
	char enemy;
	char possible[] = { 'J','L', 'H', 'P', 'W' };
	if (m.level == 1) {
		enemy = possible[rand() % 2];
	}
	else if (m.level == 2) {
		enemy = possible[rand() % 3];
	}
	else if (m.level == 3) {
		enemy = possible[2 + rand() % 3];
	}
	return enemy;
}


//these functions check for points on the map that are a safe distance from the monster and teleport the user to them
//input: map struct, enemy coordinates, user position
//output: boolean. True if spot is empty and player teleported there. False otherwise
bool checkfree1(Map m, int x, int y,Point &p) {
	if (m.map[x - 2][y - 2] < 2) {
		p.x = x - 2;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree2(Map m, int x, int y, Point& p) {
	if (m.map[x - 2][y - 1] < 2) {
		p.x = x - 2;
		p.y = y - 1;
		return true;
	}
	return false;
}
bool checkfree3(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y] < 2) {
		p.x = x - 2;
		p.y = y;
		return true;
	}
	return false;
}
bool checkfree4(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y+ 1] < 2) {
		p.x = x - 2;
		p.y = y + 1;
		return true;
	}
	return false;
}
bool checkfree5(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y + 2] < 2) {
		p.x = x - 2;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree6(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 1][y - 2] < 2) {
		p.x = x - 1;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree7(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 1][y + 2] < 2) {
		p.x = x - 1;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree8(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x][y - 2] < 2) {
		p.x = x;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree9(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x][y + 2] < 2) {
		p.x = x;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree10(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 1][y - 2] < 2) {
		p.x = x + 1;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree11(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 1][y + 2] < 2) {
		p.x = x + 1;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree12(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y - 2] < 2) {
		p.x = x + 2;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree13(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y - 1] < 2) {
		p.x = x + 2;
		p.y = y - 1;
		return true;
	}
	return false;
}
bool checkfree14(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y] < 2) {
		p.x = x + 2;
		p.y = y;
		return true;
	}
	return false;
}
bool checkfree15(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y + 1] < 2) {
		p.x = x + 2;
		p.y = y + 1;
		return true;
	}
	return false;
}
bool checkfree16(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y + 2] < 2) {
		p.x = x + 2;
		p.y = y + 2;
		return true;
	}
	return false;
}





