//
// Created by Patryk on 01.01.2018.
//

#ifndef GAMERPG_MONSTER_H
#define GAMERPG_MONSTER_H

void set_MonsterHealth(int current, int max);
int get_MonsterHealth();
int get_MonsterHealthMax();

void set_MonsterMana(int curent, int max);
int get_MonsterMana();
int get_MonsterManaMax();

void set_MonsterDamage(int min, int max);
int get_MonsterDamageMin();
int get_MonsterDamageMax();

void set_MonsterSpeedAttack(double addSpeedAttack);
double get_MonsterSpeedAttack();

void set_MonsterMagicDamage(int min, int max);
int get_MonsterMinMagicDmg();
int get_MonsterMaxMagicDmg();

void set_MonsterCoinDrop(int min, int max);
int get_MonsterCoinDropMin();
int get_MonsterCoinDropMax();

void set_MonsterExp(int min, int max);
int get_MonsterExpMin();
int get_MonsterExpMax();

void set_MonsterLevel(int level);
int get_MonsterLevel();

void set_MonsterNameOfTheMonster(char *name);
char *get_MonsterNameOfTheMonster();

void set_MonsterDeffence(int addDefence);
int get_MonsterDeffence();

void set_MonsterResistance(int addResistatnce);
int get_MonsterResistance();

void die();

int monsterTakeDamage(int damage);

void monsterPhysicAttack(int damageMin, int damageMax);

void Zombie();


#endif //GAMERPG_MONSTER_H
