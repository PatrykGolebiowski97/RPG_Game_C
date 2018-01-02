//
// Created by Patryk on 31.12.2017.
//


#include <stdio.h>
#include <string.h>
#include "Random.h"
#include "Monster.h"
#include "Move.h"

static int PlayerHealth = 100;
static int PlayerHealthMax = 100;
static int PlayerMana = 30;
static int PlayerManaMax = 30;
static double PlayerSpeedAttack = 1.0;
static int PlayerDeffence = 5;
static int PlayerAttack = 5;
static int PlayerMoney = 0;
static int PlayerLevel = 1;
static int PlayerExp = 0;
static int PlayerAgility = 5;
static int PlayerIntelligence = 5;
static int PlayerVitality = 5;
static int PlayerStrength = 5;
static int PlayerCrit = 1;

//SETTERS
void set_PlayerHealth(int current, int max){
    PlayerHealth = current;
    PlayerHealthMax = max;
}

void set_PlayerMana(int current, int max){
    PlayerMana = current;
    PlayerManaMax = max;
}

void set_PlayerSpeedAttack(double addSpeedAttack){
    PlayerSpeedAttack += addSpeedAttack;
}

void set_PlayerDeffence(int addDefence){
    PlayerDeffence += addDefence;
}

void set_PlayerAttack(int addAttack){
    PlayerAttack += addAttack;
}

void set_PlayerMoney(int addMoney){
    PlayerMoney += addMoney;
}

void set_PlayerLevel(int addLevel){
    PlayerLevel += addLevel;
}

void set_PlayerExp(int addExp){
    PlayerExp += addExp;
}

void set_PlayerAgility(int addAgility){
    PlayerAgility += addAgility;
}

void set_PlayerIntelligence(int addInteligence){
    PlayerIntelligence += addInteligence;
}

void set_PlayerVitality(int addVitality){
    PlayerVitality += addVitality;
}

void set_PlayerStrength(int addStrength){
    PlayerStrength += addStrength;
}

void set_PlayerCrit(int addCrit){
    PlayerCrit += addCrit;
}

//GETTERS
int get_PlayerHealth(){
    return PlayerHealth;
}

int get_PlayerHealthMax(){
    return PlayerHealthMax;
}

int get_PlayerMana(){
    return PlayerMana;
}

int get_PlayerManaMax(){
    return PlayerManaMax;
}

int get_PlayerSpeedAttack(){
    return PlayerSpeedAttack;
}

int get_PlayerDeffence(){
    return PlayerDeffence;
}

int get_PlayerAttack(){
    return PlayerAttack;
}

int get_PlayerMoney(){
    return PlayerMoney;
}

int get_PlayerLevel() {
    return PlayerLevel;
}

int get_PlayerExp(){
    return PlayerExp;
}

int get_PlayerAgility(){
    return PlayerAgility;
}

int get_PlayerIntelligence(){
    return PlayerIntelligence;
}

int get_PlayerVitality(){
    return PlayerVitality;
}

int get_PlayerStrength(){
    return PlayerStrength;
}

double get_PlayerCrit(){
    return PlayerCrit;
}

int get_PlayerAttackPower(){
    return PlayerAttack * PlayerStrength;
}

void get_PlayerStats(){
    printf("Obecne zdrowie: %d\n", PlayerHealth);
    printf("Maksymalne zdrowie: %d\n", PlayerHealthMax);
    printf("Obecna mana: %d\n", PlayerMana);
    printf("Maksymalna mana: %d\n", PlayerManaMax);
    printf("Predkosc ataku: %.2f\n", PlayerSpeedAttack);
    printf("Obrona: %d\n", PlayerDeffence);
    printf("Atak: %d\n", PlayerAttack);
    printf("Level: %d\n", PlayerLevel);
    printf("Exp: %d\n", PlayerExp);
    printf("Zrecznosc: %d\n", PlayerAgility);
    printf("Inteligencja: %d\n", PlayerIntelligence);
    printf("Witalnosc: %d\n", PlayerVitality);
    printf("Sila: %d\n", PlayerStrength);
    printf("Szansa na uderzenie krytyczne: %d\n", PlayerCrit);
}

void playerPhysicAttack(){
    int damage = PlayerAttack * PlayerStrength;

    if(Crit() == 1){
        damage *= 2;
        printf("Zadales: %d punktow obrazen!\n", damage);
        monsterTakeDamage(damage);
    }
    else{
        printf("Zadales: %d punktow obrazen!\n", damage);
        monsterTakeDamage(damage);
    }
};

void playerDealDamage(){
    printf("Co chcesz teraz zrobic?\n");
    char fight[15];
    gets(fight);

    if(strcmp(fight, "atakuj") == 0){
        printf("Atakujesz mieczem\n");
        playerPhysicAttack();
    }
    else if(strcmp(fight, "magia" ) == 0 && get_PlayerMana() >= 15){
        printf("Atakujesz magia\n");
    }
    else if(strcmp(fight, "magia") == 0 && get_PlayerMana() < 15){
        printf("Nie masz many\n");
    }
    else{
        printf("Zla komenda\n");
        playerDealDamage();
    }
}

void Warrior(){
    PlayerHealth += 50;
    PlayerHealthMax += 50;
    PlayerStrength += 5;
}

void Rogue(){
    PlayerHealth -= 20;
    PlayerHealthMax -= 20;
    PlayerCrit += 5;
}

void Mage(){
    PlayerHealth -= 30;
    PlayerHealthMax -= 30;
    PlayerMana += 30;
    PlayerManaMax += 30;
    PlayerIntelligence += 5;
}

void setClass(){
    printf("Wybierz swoja klase (podaj odpowiednia cyfre)\n");
    printf("1 - Wojownik\n2 - Lotr\n3 - Mag\n");
    int chooseClass;
    scanf("%d", &chooseClass);

    switch(chooseClass){
        case 1:
            printf("Wybrales wojownika, powodzenia!\n");
            Warrior();
            break;
        case 2:
            printf("Wybrales lotra, powodzenia!\n");
            Rogue();
            break;
        case 3:
            printf("Wybrales maga, powodzenia!\n");
            Mage();
            break;
        default:
            printf("Sprobuj ponownie\n");
            setClass();
            break;
    }
}

