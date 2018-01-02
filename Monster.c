//
// Created by Patryk on 01.01.2018.
//

#include <stdio.h>
#include "Player.h"
#include "Random.h"

static double MonsterHealth;
static double MonsterHealthMax;
static double MonsterMana;
static double MonsterManaMax;
static double MonsterDamageMin;
static double MonsterDamageMax;
static double MonsterSpeedAttack;
static double MonsterMinMagicDmg;
static double MonsterMaxMagicDmg;
static int MonsterCoinDropMin;
static int MonsterCoinDropMax;
static int MonsterExpMin;
static int MonsterExpMax;
static int MonsterLevel;
static char *MonsterNameOfTheMonster;
static double MonsterDeffence;
static double MonsterResistance;

//SETTERS
void set_MonsterHealth(double current, double max){
    MonsterHealth = current;
    MonsterHealthMax = max;
}

void set_MonsterMana(double current, double max){
    MonsterMana = current;
    MonsterManaMax = max;
}

void set_MonsterDamage(double min, double max){
    MonsterDamageMin = min;
    MonsterDamageMax = max;
}

void set_MonsterSpeedAttack(double addSpeedAttack){
    MonsterSpeedAttack += addSpeedAttack;
}

void set_MonsterMagicDamage(double min, double max){
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

void set_MonsterDeffence(double addDefence){
    MonsterDeffence += addDefence;
}

void set_MonsterResistance(double addResistance){
    MonsterResistance += addResistance;
}

//GETTERS
double get_MonsterHealth(){
    return MonsterHealth;
}

double get_MonsterHealthMax(){
    return MonsterHealthMax;
}

double get_MonsterMana(){
    return MonsterMana;
}

double get_MonsterManaMax(){
    return MonsterManaMax;
}

double get_MonsterDamageMin(){
    return MonsterDamageMin;
}

double get_MonsterDamageMax(){
    return MonsterDamageMax;
}

double get_MonsterSpeedAttack(){
    return MonsterSpeedAttack;
}

double get_MonsterMinMagicDmg(){
    return MonsterMinMagicDmg;
}

double get_MonsterMaxMagicDmg(){
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

char get_MonsterNameOfTheMonster(){
    return *MonsterNameOfTheMonster;
}

double get_MonsterDeffence(){
    return MonsterDeffence;
}

double get_MonsterResistance(){
    return MonsterResistance;
}

void die(){
    int coin = RInt(MonsterCoinDropMin, MonsterCoinDropMax);
    int exp = RInt(MonsterExpMin, MonsterExpMax);

    printf("Pokonales przeciwnika, otrzymujesz: %d pieniedzy i %d punktow doswiadczenian\n", coin, exp);
    set_PlayerMoney(coin);
    set_PlayerExp(exp);
}

int monsterTakeDamage(double damage){
    MonsterHealth -= damage;
    printf("%c ma teraz: %f / %f punktow zycia\n", *MonsterNameOfTheMonster, MonsterHealth, MonsterHealthMax);
    if (MonsterHealth < 0){
        die();
        return 1;
    }
    else{
        return 0;
    }
}

void monsterPhysicAttack(double damageMin, double damageMax){
    double damage = RInt((int)damageMin, (int)damageMax);
    printf("%c zadal Ci: %f punktow obrazen!\n", *MonsterNameOfTheMonster, damage);
    set_PlayerHealth(get_PlayerHealth() - damage, get_PlayerHealthMax());
}

void Zombie(){
    set_MonsterHealth(75, 75);
    set_MonsterMana(30, 30);
    set_MonsterDamage(10, 20);
    set_MonsterSpeedAttack(1.0);
    set_MonsterMagicDamage(5, 15);
    set_MonsterCoinDrop(5, 10);
    set_MonsterExp(10, 20);
    set_MonsterLevel(1);
    set_MonsterNameOfTheMonster("Zombie");
    set_MonsterDeffence(5);
    set_MonsterResistance(5);
}