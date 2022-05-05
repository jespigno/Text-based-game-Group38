#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;
#include "TimeIntervals.h"
#include "AttackFunctions.h"

//works
inline bool operator==(const Point& a, const Point& b)
{
	return (a.x == b.x) && (a.y == b.y);
}


//checks if player has met the winning condition of their specific level
//works
bool Map::check_win() const {
	//level 1 objective is to defeat all the monsters
	if (level == 1) {
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
//works
void Map::spawn_enemies() {
	Point newenemy;
	while (enemy.size() < num_enemies) {
		int n = rand() % (possible_enemy.size() - 1);
		newenemy = possible_enemy[n];
		for (int i = 0; i < enemy.size(); i++) {//checks that point has not already been selected
			if (enemy[i] == newenemy) {
				continue;
			}
		}
		enemy.push_back(newenemy);
	}
}

//randomly selects points from the possible loot positions to add to the actual loot positons
//works
void Map::spawn_loot() {
	Point newloot;
	while (loot.size() < num_loot) {
		int n = rand() % (possible_loot.size() - 1);
		newloot = possible_loot[n];
		for (int i = 0; i < loot.size(); i++) {//checks that point has not already been selected
			if (loot[i] == newloot) {
				continue;
			}
		}
		loot.push_back(newloot);
		cout << "added\n";
		cout << loot.size();
	}
}

//adds enemies, loot and the player to the map
//works
Point Map::create_map() {
	map[entry.x][entry.y] = 2;//places player at start position
	for (int i = 0; i < loot.size(); i++) {
		map[loot[i].x][loot[i].y] = -1;
	}
	for (int i = 0; i < enemy.size(); i++) {
		map[enemy[i].x][enemy[i].y] = 3;
	}
	return entry;
}

//prints current map with players's position, loot and enemies
//works
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

//works
Map choose(int x) {
	int level1[30][45] = {
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
	int level2[30][45] = {
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
	int level3[30][45] = {
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
	Map m;

	if (x == 1) {
		m.level = 1;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 45; j++) {
				m.map[i][j] = level1[i][j];
			}
		}
		m.entry = { 18, 0 };
		m.exit = { 6, 4 };
		m.num_enemies = 8;
		m.num_loot = 4;
		m.possible_loot = { {2,35},{3,40}, {4, 9}, {4, 29}, {5,18}, {7,11}, {10,8},
			{10,32}, {13, 37}, {15, 12}, {15, 38}, {17, 28}, {18,41}, {19,18},
			{19,40}, {22,36}, {23,13}, {25, 25}, {25, 32}, { 26, 41 } };

		m.possible_enemy = { {2, 39 }, { 3,12 }, { 4,23 }, { 5,36 }, { 6,7 },
			{ 6,40 }, { 9,10 }, { 9,29 }, { 10,19 }, { 12,34 }, { 15,18 }, { 16,40 }, { 18,7 },
			{ 20,15 }, { 24,15 }, { 25,6 }, { 25,30 } };
		m.loot = { {11, 24}, {27,3} };//some positions already predetermined
		m.enemy = { {20,21}, {24, 42}, {3, 42} };
	}
	else if (x == 2) {
		m.level = 2;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 45; j++) {
				m.map[i][j] = level2[i][j];
			}
		}
		m.entry = { 22,2 };
		m.exit = { 1,0 };
		m.num_enemies = 12;
		m.num_loot = 6;
		m.possible_loot = { {1,30 }, {2,43 }, {3,19 }, {3,36 }, {4,26 }, {5,7 }, {6,13 }, {6,17 },
			{8,29 }, {8,38 }, {9,23 }, {11,1 }, {12,34 }, {12,41 }, {13,10 }, {13,17 }, {13,26 }, {13,30 }, {15,42 },
			{16,16 }, {17,22 }, {17,37 }, {18,32 }, {20,15 }, {20,19 }, {20,26 }, {20,30 }, {21,35 }, {21,42 },
			{23,3 }, {24,30 }, {24,38 }, {25,28 }, {26,7 }, {26,34 }, {27,15 }, {27,24 } };
		m.possible_enemy = { {1,3 }, {1,40 }, {3,27 }, {4,6 }, {4,39 }, {5,18 }, {6,2 }, {7,14 }, {7,25 },
			{8,37 }, {9,10 }, {9,20 }, {10,1 }, {11,14 }, {11,34 }, {12,6 }, {12,11 }, {12,18 }, {12,25 }, {12,29 },
			{13,42 }, {16,37 }, {17,3 }, {17,15 }, {18,33 }, {20,42 }, {21,15 }, {21,29 }, {21,34 }, {23,38 }, {24,4 },
			{25,30 }, {26,8 }, {26,21 }, {26,35 }, {28,11 } };
		m.loot = { {5,38 }, {18,4 }, {26,42 } };
		m.enemy = { {3,41}, {18, 6}, {25, 42} };
	}
	else if (x == 3) {
		m.level = 3;
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 45; j++) {
				m.map[i][j] = level3[i][j];
			}
		}
		m.entry = { 15,0 };
		m.exit = { 29,44 };
		m.num_enemies = 6;
		m.num_loot = 6;
		m.possible_loot = { {1,2 }, {1,16 }, {1,23 }, {1,36 }, {2,19 }, {2,39 }, {2,43 }, {3,16 }, {3,22 }, {3,27 },
			{3,34 }, {4,5 }, {4,41 }, {6,3 }, {6,39 }, {6,43 }, {7,9 }, {7,14 }, {8,35 }, {8,42 }, {9,1 }, {9,18 }, {10,5 },
			{10,11 }, {10,22 }, {11,3 }, {11,8 }, {11,16 }, {11,30 }, {12,38 }, {13,35 }, {13,41 }, {14,43 }, {15,3 },
			{15,11 }, {15,21 }, {16,7 }, {16,16 }, {16,33 }, {17,27 }, {17,39 }, {18,14 }, {18,31 }, {19,3 }, {20,7 },
			{20,17 }, {21,1 }, {21,23 }, {21,41 }, {22,28 }, {22,43 }, {23,9 }, {24,3 }, {24,13 }, {24,26 }, {24,35 },
			{24,39 }, {25,27 }, {25,41 }, {26,5 }, {26,9 }, {27,1 }, {27,13 }, {27,15 }, {28,8 }, {28,32 }, {28,40 },
			{29,23 } };
		m.possible_enemy = { {1,1 }, {1,15 }, {1,19 }, {1,35 }, {1,39 }, {1,43 }, {2,23 }, {2,27 }, {3,5 },
			{3,11 }, {3,31 }, {5,19 }, {5,27 }, {5,35 }, {5,41 }, {6,9 }, {7,15 }, {8,1 }, {9,19 }, {9,41 }, {10,9 },
			{11,15 }, {11,23 }, {12,29 }, {13,39 }, {13,43 }, {14,11 }, {14,35 }, {15,17 }, {16,3 }, {16,22 }, {18,15 },
			{18,26 }, {18,39 }, {19,7 }, {20,1 }, {21,29 }, {21,43 }, {22,9 }, {22,13 }, {22,17 }, {22,24 }, {24,21 },
			{25,5 }, {25,37 }, {25,43 }, {26,10 }, {26,15 }, {26,27 }, {28,2 }, {28,24 }, {28,33 }, {28,41 } };
		m.loot = { {15,21 }, };//must collect to win
		m.enemy = { {16,22 } , };
	}
	return m;
}



//move user icon on the map
//only allows player to move in free space i.e. no walls
//input: map, player's current coordinates and move they're making
//output: integer indicating whether player has lost to a monster, completed the level, or is continuing
//1: no monster encountered, or monster defeated or fled from. No further action required
//2: level completed, end level
//3: player defeated, end level
void makeMove(Map& m, Player& p, Point& position, string move) {
	//valid input
	cout << "establishd coordinates";
	if (move == "w" || move == "s" || move == "a" || move == "d") {
		if (move == "w" and m.map[position.x - 1][position.y] < 1) {
			if (m.map[position.x - 1][position.y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[position.x - 1][position.y] = 2;
			m.map[position.x][position.y] = 0;
			position.x = position.x - 1; //update coordinates
		}
		else if (move == "a" and m.map[position.x][position.y - 1] < 1) {
			if (m.map[position.x][position.y - 1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[position.x][position.y - 1] = 2;
			m.map[position.x][position.y] = 0;
			position.y = position.y - 1;
		}
		else if (move == "d" and m.map[position.x][position.y + 1] < 1) {
			if (m.map[position.x][position.y + 1] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[position.x][position.y + 1] = 2;
			m.map[position.x][position.y] = 0;
			position.y = position.y + 1;
		}
		else if (move == "s" and m.map[position.x + 1][position.y] < 1) {
			if (m.map[position.x + 1][position.y] == -1) {
				takeLoot(m.level, p.stats.mymoney);
			}
			m.map[position.x + 1][position.y] = 2;
			m.map[position.x][position.y] = 0;
			position.x = position.x + 1;

		}
	}
	else {
		cout << "That's not a valid move. Try again." << endl;
		onesecsleep();
	}
	return;
}

int sense_enemy_diagonal(Map& m, Player& p, Point& position) {
	char enemy, win;
	Point e;
	if (m.map[position.x - 1][position.y - 1] == 3) {
		e.x = position.x - 1;
		e.y = position.y - 1;
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
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
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
	else if (m.map[position.x - 1][position.y + 1] == 3) {
		e.x = position.x - 1;
		e.y = position.y + 1;
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
	else if (m.map[position.x + 1][position.y - 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = position.x + 1;
		e.y = position.y - 1;
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
	else if (m.map[position.x + 1][position.y + 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = position.x + 1;
		e.y = position.y + 1;
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
	return 1;
}
//check if player is within sensing distance of an enemy
//sensing distance is within one square of the enemy
//enemies cannot sense diagonally because stack overflow :C
int sense_enemy(Map& m, Player& p, Point& position) {
	char enemy, win;
	Point e;
	if (m.map[position.x - 1][position.y] == 3) {
		e.x = position.x - 1;
		e.y = position.y;
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
	else if (m.map[position.x][position.y - 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = position.x;
		e.y = position.y - 1;
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
	else if (m.map[position.x][position.y + 1] == 3) {
		//enemy senses player. insert battle functions here
		e.x = position.x;
		e.y = position.y + 1;
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
			if (checkfree9(m, e.x, e.y, position)) {}
			else if (checkfree7(m, e.x, e.y, position)) {}
			else if (checkfree11(m, e.x, e.y, position)) {}
			else if (checkfree5(m, e.x, e.y, position)) {}
			else if (checkfree16(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree15(m, e.x, e.y, position)) {}
			else if (checkfree3(m, e.x, e.y, position)) {}
			else if (checkfree14(m, e.x, e.y, position)) {}
			else if (checkfree4(m, e.x, e.y, position)) {}
			else if (checkfree13(m, e.x, e.y, position)) {}
			else if (checkfree2(m, e.x, e.y, position)) {}
			else if (checkfree12(m, e.x, e.y, position)) {}
			else if (checkfree6(m, e.x, e.y, position)) {}
			else if (checkfree10(m, e.x, e.y, position)) {}
			else if (checkfree8(m, e.x, e.y, position)) {}
			else {
				cout << "Flee failed";
			}
			m.map[position.x][position.y] = 2;
			return 1;
		}
	}
	else if (m.map[position.x + 1][position.y] == 3) {
		//enemy senses player. insert battle functions here
		e.x = position.x + 1;
		e.y = position.y;
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
	return 1;
}

//checks if player has completed the level. 2 conditions: 1.complete the requirements of the level
//2. be at the exit point
//works
bool level_complete(Map m, Point position) {
	//checks if player has reached the exit point
	//if they have, checks if they've won
	if (position == m.exit) {
		if (m.check_win() == true) {
			return true;
		}
		else {
			cout << "You have not yet completed this level's objective. Please return quickly!" << endl;
			onesecsleep();
			return false;
		}
	}
	return false;
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
	cout << "You picked up a treasure worth " << loot << "dollars!\n";
	money += loot;
	twosecsleep();
}

//loads an entire level of the game depending on level of map loaded
//links all attack functions and map functions
//input: map struct, player struct
//output: bool indicating whether player has completed the level successfully
bool loadlevel(int level, Player& x) {
	Map m;
	Point position;
	m = choose(level);
	m.spawn_enemies();
	m.spawn_loot();
	position = m.create_map();

	string move;
	int val = 1;
	bool complete = false;
	while (val == 1 and complete == false) {
		m.print_map();
		getline(cin, move);
		makeMove(m, x, position, move);
		val = sense_enemy(m, x, position);
		if (val == 3)
			break;
		val = sense_enemy_diagonal(m, x, position);
		if (val == 3)
			break;
		complete = level_complete(m, position);
	}
	if (val == 3) {
		onesecsleep();
		ClearScreen();
		return false;
	}
	else if (complete == true) {
		cout << "You have completed the level. Congratulations!" << endl;
		twosecsleep();
		ClearScreen();
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
bool checkfree1(Map m, int x, int y, Point& p) {
	if (m.map[x - 2][y - 2] < 1) {
		p.x = x - 2;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree2(Map m, int x, int y, Point& p) {
	if (m.map[x - 2][y - 1] < 1) {
		p.x = x - 2;
		p.y = y - 1;
		return true;
	}
	return false;
}
bool checkfree3(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y] < 1) {
		p.x = x - 2;
		p.y = y;
		return true;
	}
	return false;
}
bool checkfree4(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y + 1] < 1) {
		p.x = x - 2;
		p.y = y + 1;
		return true;
	}
	return false;
}
bool checkfree5(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 2][y + 2] < 1) {
		p.x = x - 2;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree6(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 1][y - 2] < 1) {
		p.x = x - 1;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree7(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x - 1][y + 2] < 1) {
		p.x = x - 1;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree8(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x][y - 2] < 1) {
		p.x = x;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree9(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x][y + 2] < 1) {
		p.x = x;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree10(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 1][y - 2] < 1) {
		p.x = x + 1;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree11(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 1][y + 2] < 1) {
		p.x = x + 1;
		p.y = y + 2;
		return true;
	}
	return false;
}
bool checkfree12(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y - 2] < 1) {
		p.x = x + 2;
		p.y = y - 2;
		return true;
	}
	return false;
}
bool checkfree13(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y - 1] < 1) {
		p.x = x + 2;
		p.y = y - 1;
		return true;
	}
	return false;
}
bool checkfree14(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y] < 1) {
		p.x = x + 2;
		p.y = y;
		return true;
	}
	return false;
}
bool checkfree15(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y + 1] < 1) {
		p.x = x + 2;
		p.y = y + 1;
		return true;
	}
	return false;
}
bool checkfree16(Map m, int x, int y, Point& p) { // top left corner
	if (m.map[x + 2][y + 2] < 1) {
		p.x = x + 2;
		p.y = y + 2;
		return true;
	}
	return false;
}





