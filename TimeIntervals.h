// TimeIntervals.h
#ifndef TimeIntervals
#define TimeIntervals

struct PlayerStats {
    int level;
    float maxhealth;
    float mycurrenthealth;
    int mydefense;
    int myattack;
    int myspeed;
    int mymoney;
    float experiencepoints;
    std::string attackone;
    std::string attacktwo;
    std::string attackthree;
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

struct Point {
    int x;
    int y;
};

struct Map {
    int level;
    int map[30][45];
    Point entry;
    Point exit;
    int num_enemies;
    int num_loot;
    std::vector<Point> possible_loot;
    std::vector<Point> possible_enemy;
    std::vector<Point> loot;
    std::vector<Point> enemy;

    bool check_win();
    void spawn_enemies();
    void spawn_loot();
    void create_map(Point &);
    void print_map();
};
void makeMove(Map, Player&, Point&, char);
void takeLoot(int, int&);
bool loadlevel(Map , Player&);
char randomise_enemy(Map);

//function prototypes
void twosecsleep();
void onesecsleep();
void halfasecsleep();
void fivesecsleep();
void tensecsleep();
void ClearScreen();
void loadvalues(Player &);
void saveValues(Player);
#endif
