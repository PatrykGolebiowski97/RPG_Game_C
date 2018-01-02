//
// Created by Patryk on 01.01.2018.
//

#ifndef GAMERPG_MONSTER_H
#define GAMERPG_MONSTER_H

void set_MonsterHealth(double current, double max);
double get_MonsterHealth();
double get_MonsterHealthMax();

void set_MonsterMana(double curent, double max);
double get_MonsterMana();
double get_MonsterManaMax();

void set_MonsterDamage(double min, double max);
double get_MonsterDamageMin();
double get_MonsterDamageMax();

void set_MonsterSpeedAttack(double addSpeedAttack);
double get_MonsterSpeedAttack();

void set_MonsterMagicDamage(double min, double max);
double get_MonsterMinMagicDmg();
double get_MonsterMaxMagicDmg();

void set_MonsterCoinDrop(int min, int max);
int get_MonsterCoinDropMin();
int get_MonsterCoinDropMax();

void set_MonsterExp(int min, int max);
int get_MonsterExpMin();
int get_MonsterExpMax();

void set_MonsterLevel(int level);
int get_MonsterLevel();

void set_MonsterNameOfTheMonster(char name);
char get_MonsterNameOfTheMonster();

void set_MonsterDeffence(double addDefence);
double get_MonsterDeffence();

void set_MonsterResistance(double addResistatnce);
double get_MonsterResistance();

void die();

int monsterTakeDamage(double damage);

void monsterPhysicAttack(double damageMin, double damageMax);

void Zombie();


#endif //GAMERPG_MONSTER_H
