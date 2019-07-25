#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include <memory>

class Player;
class Enemy;
class Chamber;
class Potion;
class Gold;

class Floor{
	int level;
	std::shared_ptr<Player> player;
	std::vector<std::vector<char>> display;
	std::vector<std::shared_ptr<Enemy>> enemies;
	std::vector<std::shared_ptr<Chamber>> chambers;
	std::vector<std::shared_ptr<Potion>> potions;
	std::vector<std::shared_ptr<Enemy>> golds;
	char origSymbol;
public:
	Floor(int level, std::string file = "default.txt");
	void printFloor();//add display msg
	void genGold();
	void genPlayer(std::shared_ptr<Player> pp);
	void genStair();
	void genPotion();
	void genChamber();
	void genEnemy();
	std::vector<int> checkTile(std::string dir);//returns position after moving player to dir
	void movePlayer(std::string dir);
	int getLevel();
	
	//void createFloor();
};








#endif
