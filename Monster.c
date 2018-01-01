//
// Created by Patryk on 01.01.2018.
//

static double MonsterHealth;
static double MonsterHealthMax;
static double MonsterMana;
static double MonsterManaMax;
static double MonsterDamageMin;
static double MonsterDamageMax;
static double MonsterSpeedAttack;
static double MonsterMinMagicDmg;
static double MonsterMaxMagicDmg;
static double MonsterCoinDropMin;
static double MonsterCoinDropMax;
static double MonsterExpMin;
static double MonsterExpMax;
static int MonsterLevel;
static char MonsterNameOfTheMonster;
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

void set_MonsterCoinDrop(double min, double max){
    MonsterCoinDropMin = min;
    MonsterCoinDropMax = max;
}

void set_MonsterExp(double min, double max){
    MonsterExpMin = min;
    MonsterExpMax = max;
}

void set_MonsterLevel(double level){
    MonsterLevel = level;
}

void set_MonsterNameOfTheMonster(char name){
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

double get_MonsterCoinDropMin(){
    return MonsterCoinDropMin;
}

double get_MonsterCoinDropMax(){
    return MonsterCoinDropMax;
}

double get_MonsterExpMin(){
    return MonsterExpMin;
}

double get_MonsterExpMax(){
    return MonsterExpMax;
}

double get_MonsterLevel(){
    return MonsterLevel;
}

char get_MonsterNameOfTheMonster(){
    return MonsterNameOfTheMonster;
}

double get_MonsterDeffence(){
    return MonsterDeffence;
}

double get_MonsterResistance(){
    return MonsterResistance;
}


Monster(double health, double healthMax, double mana, double manaMax, double damageMin, double damageMax, double speedAttack, double minMagicDmg, double maxMagicDmg, double coinDropMin, double coinDropMax, double expMin, double expMax, int level, char nameOfTheMonster, double deffence, double resistance){
    health = MonsterHealth;
    healthMax = MonsterHealthMax;
    mana = MonsterMana;
    manaMax = MonsterManaMax;
    damageMin = MonsterDamageMin;
    damageMax = MonsterDamageMax;
    speedAttack = MonsterSpeedAttack;
    minMagicDmg = MonsterMinMagicDmg;
    maxMagicDmg = MonsterMaxMagicDmg;
    coinDropMin = MonsterCoinDropMin;
    coinDropMax = MonsterCoinDropMax;
    expMin = MonsterExpMin;
    expMax = MonsterExpMax;
    level = MonsterLevel;
    nameOfTheMonster = MonsterNameOfTheMonster;
    deffence = MonsterDeffence;
    resistance = MonsterResistance;
}