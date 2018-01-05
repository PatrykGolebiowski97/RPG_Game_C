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
    int exp = RInt(MonsterExpMin, MonsterExpMax);

    printf("Pokonales przeciwnika, otrzymujesz: %d punktow doswiadczenian\n", exp);
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
    MonsterNameOfTheMonster = "Zombie";
    MonsterDamageMin = 10 * get_PlayerLevel();
    MonsterDamageMax = 20 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite == 3){
        int random = RInt(2, 6);
        MonsterNameOfTheMonster = "Potężne Zombie";
        MonsterDamageMin = 10 * get_PlayerLevel() * random;
        MonsterDamageMax = 20 * get_PlayerLevel() * random;
    }
    MonsterLevel = get_PlayerLevel();
    MonsterHealth = 75 * get_PlayerLevel();
    MonsterHealthMax = 75 * get_PlayerLevel();
    MonsterMana = 30;
    MonsterManaMax = 30;
    MonsterMinMagicDmg = 5 * get_PlayerLevel();
    MonsterMaxMagicDmg = 10 * get_PlayerLevel();
    MonsterSpeedAttack = 1.1;
    MonsterExpMin = 10 * elite;
    MonsterExpMax = 50 * elite;
    MonsterDeffence = 5 * elite;
    MonsterResistance = 5 * elite;
}

void Wolf(){
    MonsterNameOfTheMonster = "Wilk";
    MonsterDamageMin = 15 * get_PlayerLevel();
    MonsterDamageMax = 25 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite >= 3 && elite <= 5){
        int random = RInt(2, 6);
        MonsterNameOfTheMonster = "Wilk Alfa";
        MonsterDamageMin = 10 * get_PlayerLevel() * random;
        MonsterDamageMax = 20 * get_PlayerLevel() * random;
    }
    MonsterLevel = get_PlayerLevel();
    MonsterHealth = 100 * get_PlayerLevel();
    MonsterHealthMax = 100 * get_PlayerLevel();
    MonsterMana = 45;
    MonsterManaMax = 45;
    MonsterMinMagicDmg = 2 * get_PlayerLevel();
    MonsterMaxMagicDmg = 4 * get_PlayerLevel();
    MonsterSpeedAttack = 1.5;
    MonsterExpMin = 20 * elite;
    MonsterExpMax = 60 * elite;
    MonsterDeffence = 8 * elite;
    MonsterResistance = 3 * elite;
}

void Bear(){
    MonsterNameOfTheMonster = "Niedźwiedź";
    MonsterDamageMin = 15 * get_PlayerLevel();
    MonsterDamageMax = 25 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 3 && elite >= 3 && elite <= 5){
        int random = RInt(2, 6);
        MonsterNameOfTheMonster = "Niedźwiedź Grizli";
        MonsterDamageMin = 30 * get_PlayerLevel() * random;
        MonsterDamageMax = 36 * get_PlayerLevel() * random;
    }
    MonsterLevel = get_PlayerLevel();
    MonsterHealth = 350 * get_PlayerLevel();
    MonsterHealthMax = 350 * get_PlayerLevel();
    MonsterMana = 30;
    MonsterManaMax = 30;
    MonsterMinMagicDmg = 3 * get_PlayerLevel();
    MonsterMaxMagicDmg = 6 * get_PlayerLevel();
    MonsterSpeedAttack = 1.0;
    MonsterExpMin = 40 * elite;
    MonsterExpMax = 75 * elite;
    MonsterDeffence = 10 * elite;
    MonsterResistance = 5 * elite;
}

void Floater(){
    MonsterNameOfTheMonster = "Utopiec";
    MonsterDamageMin = 7 * get_PlayerLevel();
    MonsterDamageMax = 20 * get_PlayerLevel();
    int elite = RInt(1, 7);
    if (get_PlayerLevel() > 7 && (elite >= 3 && elite <= 5)){
        int random = RInt(2, 6);
        MonsterNameOfTheMonster = "Topielec";
        MonsterDamageMin = 14 * get_PlayerLevel() * random;
        MonsterDamageMax = 32 * get_PlayerLevel() * random;
    }
    MonsterLevel = get_PlayerLevel();
    MonsterHealth = 319 * get_PlayerLevel();
    MonsterHealthMax = 319 * get_PlayerLevel();
    MonsterMana = 0;
    MonsterManaMax = 0;
    MonsterMinMagicDmg = 0 * get_PlayerLevel();
    MonsterMaxMagicDmg = 0 * get_PlayerLevel();
    MonsterSpeedAttack = 1.4;
    MonsterExpMin = 44 * elite;
    MonsterExpMax = 86 * elite;
    MonsterDeffence = 7 * elite;
    MonsterResistance = 0 * elite;
}

void Vampire(){
    int elite = RInt(1, 7);
    MonsterNameOfTheMonster = "Wampir";
    MonsterDamageMin = 100 * get_PlayerLevel();
    MonsterDamageMax =  200 * get_PlayerLevel();
    MonsterLevel = get_PlayerLevel();
    MonsterHealth = 780 * get_PlayerLevel();
    MonsterHealthMax = 780 * get_PlayerLevel();
    MonsterMana = 100;
    MonsterManaMax = 100;
    MonsterMinMagicDmg = 100 * get_PlayerLevel();
    MonsterMaxMagicDmg = 200 * get_PlayerLevel();
    MonsterSpeedAttack = 1.7;
    MonsterExpMin = 100 * elite;
    MonsterExpMax = 100 * elite;
    MonsterDeffence = 100;
    MonsterResistance = 140;
}