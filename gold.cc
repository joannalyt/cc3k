#include <string>
#include "gold.h"

Gold::Gold(int x, int y, std::string item, char notation, int gold, bool ispickable)
:item{x,y,item,notation}, gold{gold},ispickable{ispickable} {}

void Gold::setGold(int gold)
{
	this->gold = gold; 
}

int getGold()
{
	return gold;
}

bool isPickable()
{
	return ispickable;
}

void setIspickable(bool pickable)
{
	ispickable = pickable;
}

