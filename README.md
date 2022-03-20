# Text-based-game-1340
Group Members:
Name: ESPINO PITTI Jose Alberto UID:3035946813
Name: OKPAPI Favour Emoshioriamhe UID:

# Plot:
(Name) is an experienced ghostbuster and monster hunter. After working for decades helping townspeople get rid of their annoying spectral invasors, (Name) has decided to change jobs – and open a cat café! However, (Name) lost his savings by joining a pyramid scheme. Help (Name) earn enough money to retire and fill his café with feline residents by hunting ghosts and monsters in town!

# Features 
-The main menu has two sections, ‘find a job’ allows you to choose a mission from the newspaper. Each mission sends you to a dungeon where you fight monsters and ghosts to earn money. Upon successful completion of the job, you will receive payment. The ‘café’ section allows you to visit your café, purchase new furniture or cats, and track your progress. 
Dungeons: 
→ They are created with 2D arrays.
→ Enemies are placed randomly in it each round
→ Some random helpful objects, such as holy water and potions, might appear in the maps randomly every round.
→ The player’s goal is to solve the task given to them. This task can be either defeating the boss, finding a particular object (that might be dropped by defeating a random enemy), eliminating all of the enemies, etc. 
→ Enemies can be of different types (ghosts, vampires, ) and have different names that were the ones they had when living. These two features are determined at random. The ghosts’ power will be capped depending on the level to adjust difficulty. 
→ The player can navigate the map with wasd. Every time the player performs an action, the game will update the array and print out the updated map. 
Battle:
→ Players have the option to attack, defend (which makes the ghost’s attack be less harmful), run (which might not work, depending on player and ghost levels), and use objects (which might restore health, make the battle more easy, etc). 
The effectiveness of the attacks depends on the type of ghost or monster being fought. 
Whether or not the attacks hit, the defence is successful, or the player can flee depends on luck. However, the odds will be more in the player’s favour the higher their level is. For instance, a level 5 player might be able to run if a random number generated is higher than 50, whereas a level 10 one might be able to run if the number is higher than, say, 20. We will try to devise a formula to make this consistent. 
-If a character’s health points get to zero, they die. The player must avoid this and try to make the ghosts reach this state to win the battle. 
-Lastly, enemies and the player have stats, such as attack, defence, and speed. The attack determines how strong the hits will be, the defence how good it can block the attack, and the speed determines who will attack first, and how easy it is to flee. These stats will increase depending on the level.

-Every time the player successfully completes a task, their progress will be saved, and they will get to keep the money. That task will be considered complete and the player will no longer receive the money reward for it; however, they can still revisit the map to get experience points to level up and maybe find objects that could be useful in other tasks. 
-The game can be considered complete when the player has completed all of the tasks and has bought all the available merchandise/cats for the café.



# ~Coding elements:
1. Random event generation:
The amount of enemies in each task, whether or not attacks land, whether or not the player is able to flee, whether or not objects will spawn, whether or not ghosts drop objects after being defeated are all events that depend on randomness. 
When levelling up, stat growth is also semi-random. Stats will always increase, but the amount of points it increases can vary, a random number between 1 and 5.

2. Data structures for storing game status
-Player and Enemy information will be stored in structs. These structs will include things like:
-name (string),
-HP (int),
-attack stats (int) ,
-Defense stats(int),
-Speed stats(int),
-etc

There will be another struc for the general game that will store information like:
-money earnt (int),
-amount of enemies defeated (int), 
-player name (string), and
-cat café name (string).

3. Dynamic memory management
Arrays and pointers used in map generation for every task
Arrays also contain all the aforementioned data for users, enemies, and the game itself.


4. File input/output
The user can store all the variables in external files to save the game, and then load their information the next time they open the game. 

5. Program codes in multiple files
Structs, functions (like leveling up and attack), dialogue, and all saved information will be stored in files separate from main.cpp

 

Misc.
-Can also display an ascii version of ghost images for each ghost every time you have a fight. 
