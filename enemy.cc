#include "enemy.h"
#include "player.h"
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <memory>
using namespace std;

Enemy::Enemy(int hp, int atk, int def, int max, int x, int y, string race, char notation, int gold, bool hostile, bool compass):
Character{hp, atk, def, max, x, y, race, notation}, gold{gold}, isHostile{hostile}, hasCompass{compass} {}

Enemy::~Enemy(){}

int Enemy::getGold(){
	return gold;
}

void Enemy::setGold(int g){
	gold = g;
}

bool Enemy::getHostile(){
	return isHostile;
}

void Enemy::setHostile(bool hostile){
	isHostile = hostile;
}

bool Enemy::getCompass(){
	return hasCompass;
}
void Enemy::setCompass(bool compass){
	hasCompass = compass;
}

void Enemy::attack(shared_ptr<Player> pc){ //this enemy attacks player pc
	if(isHostile){
		int random = rand()%2;
		if(random){
			int damage = ceil((100/(100+pc->get_Def()))*get_Atk());
			int curHP = pc->get_HP();
			if(curHP - damage > 0){
				pc->set_HP(curHP-damage);
				ostringstream combat_str;
    			combat_str << damage;
				pc->setAction(pc->getAction()+get_notation()+" deals "+combat_str.str()+"damage to PC.");
			} else{//player dies
				pc->set_HP(0);
			}
		} else{
			pc->setAction(pc->getAction()+get_notation()+" missed the target.");
		}
	}
}


