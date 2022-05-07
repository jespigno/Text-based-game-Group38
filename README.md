### Text-based-game-1340 - Super Ghost Hunter - 超級幽靈獵人

# Group Members:
Name: ESPINO PITTI Jose Alberto UID:3035946813

Name: OKPAPI Favour Emoshioriamhe UID:3035919963

# Compilation and execution instructions:

**Compilation**: In the terminal of the directory containing all cpp files, header files and savefile.txt, type: **make main**

**Compilation instruction (if not using Makefile)**: g++ -pedantic-errors -std=c++11 TimeIntervals.cpp maps.cpp AttackFunctions.cpp cafe.cpp main.cpp -o main

**Compilation flags**: g++ -pedantic-errors -std=c++11

**Execution**: type: **./main**, no need to specify standard input file

**Testing**: Program, including Makefile, was tested successfully Academy21 server


# Plot:
You are a trained ghostbuster and monster hunter. After working for some time helping townspeople get rid of their annoying spectral invasors, you have decided to change jobs – and open a cat cafe! However, property prices in Hong Kong aren't precisely cheap... Earn more money to retire and fill your café with feline residents by hunting ghosts around the city!



# Instructions:
-You are able to save your data at any time on the Main Menu. Press 'S' to record your progress.

-You are able to see your stats at any time on the Main Menu. Press 'T' to see your stats.

-Within each dungeon, you move with w(up) s(down) a(left) and d(right). **The user is represented as #**, monsters are represented as !, and loot is represented as +.





# Features 
-The main menu has two sections, ‘Quest’ allows you to choose a mission from a client. Each mission sends you to a dungeon where you fight monsters and ghosts to earn money. Upon successful completion of the job, you will receive payment. Each job has different requirements for completion, so read the mission carefully. 
The ‘cafe’ section allows you to visit your cafe, purchase new furniture or cats, and track your progress.


Dungeons: 
→ They are created with 2D arrays.
→ Enemies are placed randomly in it each round
→ Some random loot may appear around the map for the user to pick up.
→ The player’s goal is to solve the task given to them. This task can be either defeating the boss, finding a particular object (that might be dropped by defeating a random enemy), eliminating all of the enemies, etc. 
→ Enemies can be of different types (water ghosts, vengeful ghosts, hungry ghosts...). Ghost stats are generated randomly (but within ranges for each type of ghost) so that different ghosts feel distinct. They all also have different behaviour patterns, different attacks, and different weaknessess. 
→ The player can navigate the map with wasd. Every time the player performs an action, the game will update the array and print out the updated map. 


Battle:
→ Players have the option to attack, defend (which makes the ghost’s attack be less harmful), run (which might not work, depending on player and ghost levels), and pray (which may restore health). 
The effectiveness of the attacks depends on the type of ghost or monster being fought. 
Whether or not the attacks hit, the defence is successful, or the player can flee depends on luck. However, the odds will be more in the player’s favour the higher their level is. For instance, a level 5 player might be able to run if a random number generated is higher than 50, whereas a level 10 one might be able to run if the number is higher than, say, 20. We will have used a formula to make this consistent. 
-If a character’s health points get to zero, they die. The player must avoid this and try to make the ghosts reach this state to win the battle. 
-Lastly, enemies and the player have stats, such as attack, defence, and speed. The attack determines how strong the hits will be, the defence how good it can block the attack, and the speed determines who will attack first, and how easy it is to flee. These stats will increase depending on the level.


-Every time the player successfully completes a task, they will receive a monetary reward. That task will be considered complete and the player will no longer receive the money reward for it; however, they can still revisit the map to get experience points to level up and maybe more loot . 
-The game can be considered complete when the player has completed all of the tasks and has bought all the available merchandise/cats for the café.



# ~Coding elements:
1. Random event generation:
The place where enemies spawn on each task, the place where loot spawns, the amount of money each loot is worth, whether or not attacks land, whether or not the player is able to flee, whether or not objects will spawn, whether or not players can heal, are all events that depend on randomness. 
When levelling up, stat growth is also random.

2. Data structures for storing game status
-Dungeon maps each have an individual struct that containts a 2d array reprenseting the map, the entry and exit points, the possible points where enemies and loot can spawn, the integer for the level, and they have some struct functions. 

-Player and Enemy information will be stored in structs. These structs will include things like:
-HP (int),
-attack stats (int) ,
-Defense stats(int),
-Speed stats(int),
-etc
There will be another struc for the general game information that stores information like:
-things bought (array of bool),
-player name (string), and
-levels beaten (array bool).


3. Dynamic memory management
We used vectors for storing the possible loot points and the possible end points/start points.
In many sections of the game where random numbers need to be generated, these random numbers are stored in dynamic variables that get deleted after use.
For instance, the LevelUp() function (in AttackFunctions.cpp) and the MonsterAttack () function (in AttackFunctions.cpp) uses dynamic variables frequently.


4. File input/output
The user can store all the variables in external files to save the game, and then load their information the next time they open the game.


5. Program codes in multiple files
Structs, functions (like leveling up and attack), dialogue, and all saved information is stored in files separate from main.cpp.
The game consists of 
1. TimeIntervals.cpp, which contains functions related to pauses, loading, and saving the game.
2. cafe.cpp, which contains functions related to the cat cafe section of the game.
3. maps.cpp, which contains functions related to map generation, map movement, etc.
4. AttackFunctions.cpp, which contains functions related to the battle system, leveling up, displaying stats, enemy attacks, etc.

 

