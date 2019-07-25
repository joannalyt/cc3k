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
public:
	Floor(int level, std::string file = "default.txt");
	void printFloor();
	void genGold();
	void genPlayer();
	void genStair();
	void genPotion();
	void genChamber();
	//void genEnemy();
	
	//void createFloor();
};








#endif
