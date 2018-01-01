//
// Created by Patryk on 31.12.2017.
//


#include <stdio.h>

static double PlayerHealth = 100;
static double PlayerHealthMax = 100;
static double PlayerMana = 30;
static double PlayerManaMax = 30;
static double PlayerSpeedAttack = 1.0;
static double PlayerDeffence = 5;
static double PlayerAttack = 5;
static double PlayerMoney = 0;
static int PlayerLevel = 1;
static double PlayerExp = 0;
static double PlayerAgility = 5;
static double PlayerIntelligence = 5;
static double PlayerVitality = 5;
static double PlayerStrength = 5;
static double PlayerCrit = 1;

//SETTERS
void set_PlayerHealth(double current, double max){
    PlayerHealth = current;
    PlayerHealthMax = max;
}

void set_PlayerMana(double current, double max){
    PlayerMana = current;
    PlayerManaMax = max;
}

void set_PlayerSpeedAttack(double addSpeedAttack){
    PlayerSpeedAttack += addSpeedAttack;
}

void set_PlayerDeffence(double addDefence){
    PlayerDeffence += addDefence;
}

void set_PlayerAttack(double addAttack){
    PlayerAttack += addAttack;
}

void set_PlayerMoney(double addMoney){
    PlayerMoney += addMoney;
}

void set_PlayerLevel(int addLevel){
    PlayerLevel += addLevel;
}

void set_PlayerExp(double addExp){
    PlayerExp += addExp;
}

void set_PlayerAgility(double addAgility){
    PlayerAgility += addAgility;
}

void set_PlayerIntelligence(double addInteligence){
    PlayerIntelligence += addInteligence;
}

void set_PlayerVitality(double addVitality){
    PlayerVitality += addVitality;
}

void set_PlayerStrength(double addStrength){
    PlayerStrength += addStrength;
}

void set_PlayerCrit(double addCrit){
    PlayerCrit += addCrit;
}

//GETTERS
double get_PlayerHealth(){
    return PlayerHealth;
}

double get_PlayerHealthMax(){
    return PlayerHealthMax;
}

double get_PlayerMana(){
    return PlayerMana;
}

double get_PlayerManaMax(){
    return PlayerManaMax;
}

double get_PlayerSpeedAttack(){
    return PlayerSpeedAttack;
}

double get_PlayerDeffence(){
    return PlayerDeffence;
}

double get_PlayerAttack(){
    return PlayerAttack;
}

double get_PlayerMoney(){
    return PlayerMoney;
}

int get_PlayerLevel() {
    return PlayerLevel;
}

double get_PlayerExp(){
    return PlayerExp;
}

double get_PlayerAgility(){
    return PlayerAgility;
}

double get_PlayerIntelligence(){
    return PlayerIntelligence;
}

double get_PlayerVitality(){
    return PlayerVitality;
}

double get_PlayerStrength(){
    return PlayerStrength;
}

double get_PlayerCrit(){
    return PlayerCrit;
}

double get_PlayerAttackPower(){
    return PlayerAttack * PlayerStrength;
}

void get_PlayerStats(){
    printf("Obecne zdrowie: %.2f\n", PlayerHealth);
    printf("Maksymalne zdrowie: %.2f\n", PlayerHealthMax);
    printf("Obecna mana: %.2f\n", PlayerMana);
    printf("Maksymalna mana: %.2f\n", PlayerManaMax);
    printf("Predkosc ataku: %.2f\n", PlayerSpeedAttack);
    printf("Obrona: %.2f\n", PlayerDeffence);
    printf("Atak: %.2f\n", PlayerAttack);
    printf("Level: %d\n", PlayerLevel);
    printf("Exp: %.2f\n", PlayerExp);
    printf("Zrecznosc: %.2f\n", PlayerAgility);
    printf("Inteligencja: %.2f\n", PlayerIntelligence);
    printf("Witalnosc: %.2f\n", PlayerVitality);
    printf("Sila: %.2f\n", PlayerStrength);
    printf("Szansa na uderzenie krytyczne: %.2f\n", PlayerCrit);
}