// TimeIntervals.h
#ifndef TimeIntervals
#define TimeIntervals

struct PlayerStats {
    int level;
    int maxhealth;
    int mycurrenthealth;
    int mydefense;
    int myattack;
    int myspeed;
    int mymoney;
    float experiencepoints;
    std::string attackone;
    std::string attacktwo;
    std::string attackthree;
    Point position;
};
struct PlayerInfo {
    std::string myname;
    bool catnumber[6];
    int amountoffurniture;
    bool boughtcatcafe;
    bool level1complete;
    bool level2complete;
    bool level3complete;
    bool level4complete;
    bool level5complete;
    bool firsttime;
};
struct Player {
    PlayerStats stats;
    PlayerInfo info;
};


//function prototypes
void twosecsleep();
void onesecsleep();
void halfasecsleep();
void fivesecsleep();
void tensecsleep();
void ClearScreen();
void loadvalues(Player &);
#endif
