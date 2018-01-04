//
// Created by Patryk on 31.12.2017.
//

#ifndef GAMERPG_MODULE_H
#define GAMERPG_MODULE_H

void set_PlayerHealth(int current, int max);
int get_PlayerHealth();
int get_PlayerHealthMax();

void set_PlayerMana(int current, int max);
int get_PlayerMana();
int get_PlayerManaMax();

void set_PlayerSpeedAttack(double addAttackSpeed);
double get_PlayerSpeedAttack();

void set_PlayerDeffence(int addDefence);
int get_PlayerDeffence();

void set_PlayerResistance(int addResistance);
int get_PlayerResistance();

void set_PlayerAttack(int addAttack);
int get_PlayerAttack();

void set_PlayerLevel(int addLevel);
int get_PlayerLevel();

void set_PlayerExp(int addExp);
int get_PlayerExp();

void set_PlayerAgility(int addAgility);
int get_PlayerAgility();

void set_PlayerIntelligence(int addInteligence);
int get_PlayerIntelligence();

void set_PlayerStrength(int addStrength);
int get_PlayerStrength();

void set_PlayerCrit(int addCrit);
int get_PlayerCrit();

int get_PlayerAttackPower();

void set_PlayerClass(int setClass);
int get_PlayerClass();

//METHODS
void playerDie();

void playerTakeDamage(int damage);

void get_PlayerStats();

void playerPhysicAttack();

void playerDealDamage();

void playerMagicAttack();

void playerLevelUp();

//PLAYER CLASS
void Warrior();

void Rogue();

void Mage();

void setClass();



#endif //GAMERPG_MODULE_H
