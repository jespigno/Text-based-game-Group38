// AttackFunctions.h
#ifndef AttackFunctions
#define AttackFunctions

struct Player;

//struct for possible enemies
struct GhostData{
  int currenthealth;
  int maxhealth;
  int attack;
  int defense;
  int speed;
  std::string attackone;
  std::string attacktwo;
  std::string name;
};

void printstats(Player);
void banner(char o);
bool usermoves(Player &, GhostData &);
void enemymoves(Player &, GhostData &);

char battlephase(Player &, char x);





#endif
