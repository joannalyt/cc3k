#include "chamber.h"
#include <cstdlib> //rand
#include <memory> //shared ptr
using namespace std;
Chamber::Chamber(int id, vector<std::vector<char>>& display): display{display}{
	if(id == 1){ //top left
		chamberNum = 1;
		row = 4;
		col = 26;
		topLeft = {3,3};
	} else if(id == 2){ //bottom left
		chamberNum = 2;
		row = 7;
		col = 21;
		topLeft = {15,4};
	} else if(id == 3){//top right
		chamberNum = 3;
		row = 10;
		col = 37;
		topLeft = {3,39};
	} else if(id == 4){//middle
		chamberNum = 4;
		row = 3;
		col = 12;
		topLeft = {10,38};
	} else{//bottom right
		chamberNum = 5;
		row = 6;
		col = 39;
		topLeft = {16,37};
	}
}

Chamber::~Chamber(){}

int Chamber::getChamberNum(){
	return chamberNum;
}

int Chamber::getRow(){
	return row;
}

int Chamber::getCol(){
	return col;
}

int Chamber::checkTile(int x, int y){ //incomplete, come back after floor!
	
}








