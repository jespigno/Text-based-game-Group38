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
bool Map::check_win() {
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
void Map::print_map() {
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
map1.possible_loot = { {2,35},{3,40}, {4, 9}, {4, 29}, {5,18}, {7,11}, {10,8},
	{10,32}, {13, 37}, {15, 12}, {15, 38}, {17, 28}, {18,41}, {19,18},
	{19,40}, {22,36}, {23,13}, {25, 25}, {25, 32}, { 26, 41 } };
map1.possible_enemy = { {2,39}, {3,12}, {3,42} }
  {18,7}, {6,7}, {10,19}, {25, 30}, {5, 36}, {2,39} };
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
		{1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,2,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1},
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
map2.possible_loot = {};
map2.possible_enemy = {};
map2.loot = {};
map2.enemy = {};

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
map3.possible_loot = {};
map3.possible_enemy = {};
map3.loot = {};
map3.enemy = {};




//move user icon on the map
//only allows player to move in free space i.e. no walls
//input: map, player's current coordinates and move they're making
int makeMove(Map m, Player &p, Point &position, char move) {
	//valid input
	int x = position.x;
	int y = position.y;
	if (move == 'w' or move == 'a' or move == 's' or move == 'd') {
		if (move == 'w' and m.map[x - 1][y] < 1) {
			if (m.map[x - 1][y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x - 1][y] = 2;
			m.map[x][y] = 0;
			x = x - 1; //update coordinates
			return 1;
		}
		else if (move == 'a' and m.map[x][y - 1] < 1) {
			if (m.map[x][y - 1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x][y - 1] = 2;
			m.map[x][y] = 0;
			y = y - 1;
			return 1;
		}
		else if (move == 's' and m.map[x][y + 1] < 1) {
			if (m.map[x][y+1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x][y + 1] = 2;
			m.map[x][y] = 0;
			y = y + 1;
			return 1;
		}
		else if (move == 'd' and map[x + 1][y] < 1) {
			if (m.map[x - 1][y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[x + 1][y] = 2;
			m.map[x][y] = 0;
			x = x + 1;
			return 1;
		}
		else {
			cout << "There is an obstacle. Try another direction";
			onesecsleep();
			return 1;
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
		enemy = randomise_enemy(m);
		win = battlephase(p, enemy);
		if (win == 'W') {
			cout << "You defeated the monster!";
			m.map[x - 1][y - 1] = 0;
			onesecsleep();
			return 2;
		}
		else if (win == 'L') {
			cout << "You lost to the monster!";
			onesecsleep();
			cout << "You have been thrown from the battle ground. Better luck next time!";
			onesecsleep();
			return 3;
		}
		else if (win == 'F') {
			//teleport player away
		
		}
	}
	else if (m.map[x - 1][y] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x - 1][y + 1] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x][y - 1] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x][y + 1] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x + 1][y - 1] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x + 1][y] == 3) {
		//enemy senses player. insert battle functions here
	}
	else if (m.map[x + 1][y + 1] == 3) {
		//enemy senses player. insert battle functions here
	}
	//checks if player has reached the exit point
	//if they have, checks if they've won
	if (position == m.exit) {
		if (m.check_win() == true) {
			//end level
			//display win message
			//maybe display stats as well?
		}
	}
}

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

bool loadlevel(Map m, Player& x) {
	Map* map;
	Point position;
	map = new Map;
	*map = m;
	map->create_map(position);
	char move;
	int val= 1;
	while (val == 1) {
		getline(cin, move);
		val = makeMove(map, x, position, move);
	}
	if (val == 2) {
		cout << "You have lost this round. What a pity :C. Better luck next time!" << endl;
		twosecsleep();
		return false;
	}
	else if (val == 3) {
		cout << "You have completed the level. Congratulations!" << endl;
		twosecsleep();
		return true;
	}
}

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