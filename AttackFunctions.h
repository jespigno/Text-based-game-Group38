// AttackFunctions.h
#ifndef AttackFunctions
#define AttackFunctions

struct Player;
void printstats(Player);





//structs for possible enemies
struct GhostData{
  int currenthealth;
  int maxhealth;
  int attack;
  int defense;
  int speed;
  string attackone;
  string attacktwo;
  
};

#endif
