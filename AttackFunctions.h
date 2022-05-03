// AttackFunctions.h
#ifndef AttackFunctions
#define AttackFunctions

struct Player;


//struct for possible enemies
struct GhostData{
  float currenthealth;
  float maxhealth;
  int attack;
  int defense;
  int speed;
  std::string attackone;
  std::string attacktwo;
  std::string name;
  int momentarychange;
  bool inrepentance;
  int repentingturns;
  bool imdefending;
};

void catcafeMenu(Player &);
void showCatalogue(Player &);
void purchase(Player&);
void visitCafe(Player&);
void printstats(Player);
void MonsterAttack (GhostData &, Player &,int &hexed);
void MonsterDefend(GhostData &, Player &, int &hexed);
void banner(char o);
bool usermoves(Player &, GhostData &);
void enemymoves(Player &, GhostData &, int &hex);

char battlephase(Player &, char x);





#endif
