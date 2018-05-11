#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void displayStory(int);
void drawChestUI();
bool fight(int, int, bool, int);
int fightInput(char, int, int);
void idle();
int drawScene(int);
int playerInput(int, int);
int calculateScene(int, int, int);
int drawScene(int, int, int, char, bool, bool);
void drawPlayerLine(int);
bool checkIfTheresATree(int);
void drawTreeRight(int, int);
void drawTreeLeft(int, int);
bool checkIfTheresEnemy(int, int);
void drawFightScene(int);
char takeInput(char);
int calculatePlayerHP(int, int);
int calculateEnemyHP(int);
bool fightIsOver();
void inventoryUI();
void printItemName(int, int);
void printSpaces(int);
void printItemInfo(int);
int nextID(int, int);
void printRestLine(int, bool, int, int);
int invInput();
void givePlayerLoot();
void endProgram();


int chapter{0};
int enemiesAccured{0};
int playersY{1};
int enemysY{8};
int scene{2};
char input;
bool enemyAccurs{false};
int enemyHP;
int enemyDMG{0};
bool fightActive{true};
bool drawEnemy{true};
int currentID{0};
int invY{3};

char ItemNames[][255] =
{
{'A','p','p','l','e', '/'},
{'P','o','t','i','o','n', '/'},
{'S','w','o','r','d','(','C',')','/'},     // Common
{'S','w','o','r','d','(','R',')', '/'},     // Rare
{'S','w','o','r','d','(','L',')', '/'},     // Legendary
{'A','x','e','(','C',')', '/'},     // Common
{'A','x','e','(','R',')', '/'},     // Rare
{'A','x','e','(','L',')', '/'},     // Legendary
{'D','a','g','g','e','r','(','C',')', '/'},     // Common
{'D','a','g','g','e','r','(','R',')', '/'},     // Rare
{'D','a','g','g','e','r','(','L',')', '/'}      // Legendary
};
bool ItemFound[11] = {true, false, false, false, false, false, false, false, true, false, false};
std::string ItemKind[] = {"Food", "Food", "Weapon", "Weapon", "Weapon", "Weapon", "Weapon", "Weapon", "Weapon", "Weapon", "Weapon"};
std::string ItemUse[] =
{
"Restores 20HP",
"Restores 50HP",
"Common Sword, deals 13DMG", "Rare Sword, deals 15DMG", "Legendary Sword, deals 20DMG",
"Common Axe, deals 9DMG", "Rare Axe, deals 13DMG", "Legendary Axe, deals 15MG",
"Common Dagger, deals 5DMG", "Rare Dagger, deals 7DMG", "Common Dagger, deals 10DMG"
};
int ItemEffectiveness[] = {20, 50, 13, 15, 20, 9, 13, 15, 5, 7, 10,};

struct Monster
{
    int health;
    int attack;
};
Monster Alien{50, 5};
Monster Zombie{25, 10};

#endif // FUNCTIONS_H_INCLUDED
