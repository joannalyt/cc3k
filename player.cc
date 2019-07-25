#include <iostream>
#include <sstream>
#include <memory>
#include <cmath> //cmath or math? 
#include <string>
#include "player.h"
#include "item.h"
#include "gold.h" //??
#include "enemy.h"//??

using namespace std;

Player::Player(int hp, int atk, int def,int maxHP, int x, int y, string race, int id):
Character {hp, atk ,def,maxHP, x, y, race, '@'},gold{0},id{id},baseAtk{atk},baseDef{def}{
    action = "Player character has spawned.";
}

int Player::getId(){
    return id;
}

void Player::setId(const int i)
{
    this->id = i;
}

std::string Player::getAction()
{
    return action;
}

int Player::getBaseAtk()
{
    return baseAtk;
}

int Player::getBaseDef()
{
    return baseDef;
}


int Player::getGold(){
    return gold;
}

//setGold and update Action
void Player::setGold(shared_ptr<Gold> g)
{
    if(g->isPickable()){
        gold += g->getGold();
    }
    ostringstream gold_str;
    gold_str << g->getGold();

    action = "you get: " + gold_str.str() + " ."
   /* if(g->get_Itemtype() == "normal"){
        action = "PC gets a normal gold. Value:1";
    }
    else if(g->get_Itemtype()=="small"){
        action = "PC gets a small gold. Value:2";
    }
    else if(g->get_Itemtype()=="merchant hoard"){
        action = "PC gets a merchant hoard. Value:4";
    }
    else if(g->get_Itemtype()=="dragon hoard"){
        action = "PC gets a dragon hoard. Value:6";
    } */

}

void Player::setAction(const string s)
{
    this->action = s;
}

//ceiling((100/(100+Def (Defender)))∗Atk(Attacker)),
void Player::damage(shared_ptr<Enemy> e)
{
    int combat = (int) ceil ((100 / (100+get_Def()))*e->get_Atk());

    ostringstream combat_str;
    combat_str << combat;
    int newdamage = e->get_HP() - combat;
    ostringstream hp_str;
    
    if(newdamage > 0)
    {
    e->set_HP(newdamage);
    hp_str << newdamage; 
    action = "PC attacked" + e->get_race() + ". Dealed "+ combat_str.str() + "damage. [ hp:" + hp_str.str() + " ]";
    } else { // the enemy is killled
       e->set_HP(0);
       action = e->get_race()+ " is killed";
       if(e->get_race()!="Merchant" && e->get_race()!="Dragon")
       gold+=1;
       //gold += e->getGold(); ????
   /* if (e->getRace() == "Dragon") {
      e->setHoardPickable();
     } figure out wt this means*/
    }
     if (e->get_race() == "Merchant") {
      e->sethostile(true);
    }
}

//changes the direction of the PC 
void Player::move(string dir)
{
    if(direction == "no"){
        set_y(get_x()-1);
        action = "PC moves North.";
    }
    else if(direction == "so"){
        set_y(get_x()+1);
        action = "PC moves South.";
    }
    else if(direction == "we"){
        set_x(get_y()-1);
        action = "PC moves West.";
    }
    else if(direction == "ea"){
        set_x(get_y()+1);
        action = "PC moves East.";
    }    
    else if(direction == "ne"){
        set_x(get_x()-1);
        set_y(get_y()+1);
        action = "PC moves NorthEast.";
    }
    else if(direction == "se"){
        set_x(get_x()+1);
        set_y(get_y()+1);
        action = "PC moves SouthEast.";
    }
    else if(direction == "sw"){
        set_x(get_x()+1);
        set_y(get_y()-1);
        action = "PC moves SouthWest.";
    }
    else if(direction == "nw"){
        set_x(get_x()-1);
        set_y(get_y()-1);
        action = "PC moves NorthWest.";    
    }
}     

void Player::usePotion(shared_ptr<Potion> p)
{
    p->getPotion();

}



//initializes the PC 
Human :: Human(int x,int y,int id):Player{140,20,20,140,x,y,"Human",id} {}

Dwarf :: Dwarf(int x,int y,int id):Player{100,20,30,100,x,y,"Dwarf",id} {}

Elf :: Elf(int x,int y,int id):Player{140,30,10,140,x,y,"Elf",id}{}

Orc :: Orc(int x,int y,int id):Player{180,30,25,180,x,y,"Orc",id}{}



