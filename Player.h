//
// Created by Patryk on 31.12.2017.
//

#ifndef GAMERPG_MODULE_H
#define GAMERPG_MODULE_H

void set_PlayerHealth(double current, double max);
double get_PlayerHealth();
double get_PlayerHealthMax();

void set_PlayerMana(double current, double max);
double get_PlayerMana();
double get_PlayerManaMax();

void set_PlayerSpeedAttack(double addAttackSpeed);
double get_PlayerSpeedAttack();

void set_PlayerDeffence(double addDefence);
double get_PlayerDeffence();

void set_PlayerAttack(double addAttack);
double get_PlayerAttack();

void set_PlayerMoney(double addMoney);
double get_PlayerMoney();

void set_PlayerLevel(int addLevel);
int get_PlayerLevel();

void set_PlayerExp(double addExp);
double get_PlayerExp();

void set_PlayerAgility(double addAgility);
double get_PlayerAgility();

void set_PlayerIntelligence(double addInteligence);
double get_PlayerIntelligence();

void set_PlayerVitality(double addVitality);
double get_PlayerVitality();

void set_PlayerStrength(double addStrength);
double get_PlayerStrength();

void set_PlayerCrit(double addCrit);
double get_PlayerCrit();

double get_PlayerAttackPower();

void get_PlayerStats();

void playerPhysicAttack();

void playerDealDamage();

#endif //GAMERPG_MODULE_H
