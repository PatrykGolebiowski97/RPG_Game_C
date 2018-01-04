//
// Created by Patryk on 01.01.2018.
//

#include <stdio.h>
#include "Player.h"
#include "Random.h"
#include "MonsterMagic.h"

//MONSTER
static int MonsterHealth;
static int MonsterHealthMax;
static int MonsterMana;
static int MonsterManaMax;
static int MonsterDamageMin;
static int MonsterDamageMax;
static double MonsterSpeedAttack;
static int MonsterMinMagicDmg;
static int MonsterMaxMagicDmg;
static int MonsterCoinDropMin;
static int MonsterCoinDropMax;
static int MonsterExpMin;
static int MonsterExpMax;
static int MonsterLevel;
static char *MonsterNameOfTheMonster;
static int MonsterDeffence;
static int MonsterResistance;

//SETTERS
void set_MonsterHealth(int current, int max){
    MonsterHealth = current;
    MonsterHealthMax = max;
}

void set_MonsterMana(int current, int max){
    MonsterMana = current;
    MonsterManaMax = max;
}

void set_MonsterDamage(int min, int max){
    MonsterDamageMin = min;
    MonsterDamageMax = max;
}

void set_MonsterSpeedAttack(double addSpeedAttack){
    MonsterSpeedAttack += addSpeedAttack;
}

void set_MonsterMagicDamage(int min, int max){
    MonsterMinMagicDmg = min;
    MonsterMaxMagicDmg = max;
}

void set_MonsterCoinDrop(int min, int max){
    MonsterCoinDropMin = min;
    MonsterCoinDropMax = max;
}

void set_MonsterExp(int min, int max){
    MonsterExpMin = min;
    MonsterExpMax = max;
}

void set_MonsterLevel(int level){
    MonsterLevel = level;
}

void set_MonsterNameOfTheMonster(char *name){
    MonsterNameOfTheMonster = name;
}

void set_MonsterDeffence(int addDefence){
    MonsterDeffence += addDefence;
}

void set_MonsterResistance(int addResistance){
    MonsterResistance += addResistance;
}

//GETTERS
int get_MonsterHealth(){
    return MonsterHealth;
}

int get_MonsterHealthMax(){
    return MonsterHealthMax;
}

int get_MonsterMana(){
    return MonsterMana;
}

int get_MonsterManaMax(){
    return MonsterManaMax;
}

int get_MonsterDamageMin(){
    return MonsterDamageMin;
}

int get_MonsterDamageMax(){
    return MonsterDamageMax;
}

double get_MonsterSpeedAttack(){
    return MonsterSpeedAttack;
}

int get_MonsterMinMagicDmg(){
    return MonsterMinMagicDmg;
}

int get_MonsterMaxMagicDmg(){
    return MonsterMaxMagicDmg;
}

int get_MonsterCoinDropMin(){
    return MonsterCoinDropMin;
}

int get_MonsterCoinDropMax(){
    return MonsterCoinDropMax;
}

int get_MonsterExpMin(){
    return MonsterExpMin;
}

int get_MonsterExpMax(){
    return MonsterExpMax;
}

int get_MonsterLevel(){
    return MonsterLevel;
}

char *get_MonsterNameOfTheMonster(){
    return MonsterNameOfTheMonster;
}

int get_MonsterDeffence(){
    return MonsterDeffence;
}

int get_MonsterResistance(){
    return MonsterResistance;
}

//METHODS
void die(){
    int coin = RInt(MonsterCoinDropMin, MonsterCoinDropMax);
    int exp = RInt(MonsterExpMin, MonsterExpMax);

    printf("Pokonales przeciwnika, otrzymujesz: %d monet i %d punktow doswiadczenian\n", coin, exp);
    set_PlayerMoney(coin);
    set_PlayerExp(exp);
}

int monsterTakeDamage(int damage){
    MonsterHealth -= damage;
    printf("%s ma teraz: %d / %d punktow zycia\n", MonsterNameOfTheMonster, MonsterHealth, MonsterHealthMax);
    if (MonsterHealth <= 0){
        die();
        return 1;
    }
    else{
        return 0;
    }
}

void monsterPhysicAttack(int damageMin, int damageMax){
    int damage = RInt(damageMin, damageMax) / (get_PlayerDeffence() * 7/20);
    playerTakeDamage(damage);
}

void monsterMagicAttack(){
    monsterUseMagic();
}

void Zombie() {
    int random = 1;
    if (get_PlayerLevel() > 3)
        random = RInt(2, 3);

    MonsterHealth = 75 * get_PlayerLevel() * random;
    MonsterHealthMax = 75 * get_PlayerLevel() * random;
    MonsterMana = 30;
    MonsterManaMax = 30;
    MonsterDamageMin = 10 * get_PlayerLevel();
    MonsterDamageMax = 20 * get_PlayerLevel();
    MonsterMinMagicDmg = 5 * get_PlayerLevel();
    MonsterMaxMagicDmg = 10 * get_PlayerLevel();
    MonsterSpeedAttack = 1.1;
    MonsterCoinDropMin = 5 * get_PlayerLevel();
    MonsterCoinDropMax = 10 * get_PlayerLevel();
    MonsterExpMin = 10;
    MonsterExpMax = 50;
    MonsterNameOfTheMonster = "Zombie";
    MonsterDeffence = 5;
    MonsterResistance = 5;
}