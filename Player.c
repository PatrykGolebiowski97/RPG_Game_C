//
// Created by Patryk on 31.12.2017.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Random.h"
#include "Monster.h"
#include "HeroMagic.h"

//PLAYER
static int PlayerHealth = 100;
static int PlayerHealthMax = 100;
static int PlayerMana = 30;
static int PlayerManaMax = 30;
static double PlayerSpeedAttack = 1.0;
static int PlayerDeffence = 5;
static int PlayerResistance = 5;
static int PlayerAttack = 5;
static int PlayerLevel = 1;
static int PlayerExp = 0;
static int PlayerAgility = 5;
static int PlayerIntelligence = 5;
static int PlayerStrength = 5;
static int PlayerCrit = 1;
static int PlayerClass; //1 - Warrior, 2 - Rogue, 3 - Mage

//OTHERS
char fight[100];

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

void set_PlayerResistance(int addResistance){
    PlayerResistance += addResistance;
}

void set_PlayerAttack(int addAttack){
    PlayerAttack += addAttack;
}

void set_PlayerLevel(int addLevel){
    PlayerLevel += addLevel;
    printf("Gratulacje! Awansowałeś, masz teraz %d poziom. Twoje statystyki wzrosły.\n", PlayerLevel);
    if (PlayerClass == 1){
        PlayerHealth += 20;
        PlayerHealthMax += 20;
        PlayerSpeedAttack += 0.05;
        PlayerDeffence += 2;
        PlayerAttack += 2;
        PlayerStrength += 1;
    }
    else if(PlayerClass == 2){
        PlayerHealth += 10;
        PlayerHealthMax += 10;
        PlayerSpeedAttack += 0.1;
        PlayerAttack += 1;
        PlayerAgility += 1;
        PlayerCrit += 3;
    }
    else{
        PlayerHealth += 10;
        PlayerHealthMax += 10;
        PlayerAttack += 1;
        PlayerResistance += 2;
        PlayerIntelligence += 3;
    }

} //Dodać zwiększanie podstawowych atrybutów

void set_PlayerExp(int addExp){
    PlayerExp += addExp;
    playerLevelUp();
}

void set_PlayerAgility(int addAgility){
    PlayerAgility += addAgility;
}

void set_PlayerIntelligence(int addInteligence){
    PlayerIntelligence += addInteligence;
}

void set_PlayerStrength(int addStrength){
    PlayerStrength += addStrength;
}

void set_PlayerCrit(int addCrit){
    PlayerCrit += addCrit;
}

void set_PlayerClass(int setClass){
    PlayerClass = setClass;
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

int get_PlayerResistance(){
    return PlayerResistance;
}

int get_PlayerAttack(){
    return PlayerAttack;
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

int get_PlayerStrength(){
    return PlayerStrength;
}

int get_PlayerCrit(){
    return PlayerCrit + (PlayerCrit * (PlayerAgility * 1/2));
}

int get_PlayerAttackPower(){
    return RInt( (PlayerAttack * PlayerStrength) * 3/4, (PlayerAttack * PlayerStrength) );
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
    printf("Sila: %d\n", PlayerStrength);
    printf("Szansa na uderzenie krytyczne: %d\n", get_PlayerCrit());
}

int get_PlayerClass(){
    return PlayerClass;
}

//METHODS
void playerDie(){
    printf("Zostałeś pokonany, koniec gry!\n");
    exit(0);
}

void playerTakeDamage(int damage){
    PlayerHealth -= damage;
    printf("%s zadał Ci: %d punktów obrażeń!\n", get_MonsterNameOfTheMonster(), damage);
    printf("Twoje zdrowie wynosi teraz: %d / %d\n", PlayerHealth, PlayerHealthMax);
    if (PlayerHealth < 0){
        playerDie();
    }
}

void playerPhysicAttack(){
    int damage = RInt( (PlayerAttack * PlayerStrength) * 3/4, (PlayerAttack * PlayerStrength) ) / ( get_MonsterDeffence() * 7/20);

    if(Crit() == 1){
        damage *= 2;
        printf("Zadałeś: %d punktów obrażeń!\n", damage);
        monsterTakeDamage(damage);
    }
    else{
        printf("Zadałeś: %d punktów obrażeń!\n", damage);
        monsterTakeDamage(damage);
    }
};

void playerDealDamage(){
    printf("Co chcesz teraz zrobic?\n");
    fgets(fight,100,stdin);
    fight[strlen(fight)-1] = '\0';

    if(strcmp(fight, "atakuj") == 0){
        printf("Atakujesz mieczem\n");
        playerPhysicAttack();
    }
    else if(strcmp(fight, "magia" ) == 0 && get_PlayerMana() >= 15){
        playerMagicAttack();
    }
    else if(strcmp(fight, "magia") == 0 && get_PlayerMana() < 15){
        printf("Nie masz many\n");
        playerDealDamage();
    }
    else{
        printf("Zła komenda\n");
        playerDealDamage();
    }
}

void playerMagicAttack(){
    printf("Jakiego zaklęcia chciałbyś użyć?\n");
    fgets(fight,100,stdin);
    fight[strlen(fight)-1] = '\0';

    if (strcmp(fight, "kula ognia") == 0){
        playerUseFireBall();
    }
    else if (strcmp(fight, "lodowy szpikulec") == 0){
        playerUseIceSpike();
    }
    else if (strcmp(fight, "uleczenie") == 0){
        playerUseHeal();
    }
    else if (strcmp(fight, "kradziez zycia") == 0){
        playerUseStealHealth();
    }
    else if (strcmp(fight, "wzmocniony atak") == 0){
        playerUseReinforcedAttack();
    }
    else if (strcmp(fight, "pomoc") == 0){
        printf("Dostępne komendy to: kula ognia, lodowy szpikulec, uleczenie, kradziez zycia, wzmocniony atak\n");
    }
    else{
        printf("Podałeś złą komendę, spróbuj ponownie\n");
        playerDealDamage();
    }
}

void playerLevelUp(){
    if (PlayerExp > 100){
        set_PlayerLevel(1);
    }
    else if (PlayerExp > 100 && PlayerExp < 200){
        set_PlayerLevel(2);
    }
}

//PLAYER CLASS
void Warrior(){
    PlayerHealth += 50;
    PlayerHealthMax += 50;
    PlayerStrength += 5;
    PlayerClass = 1;
}

void Rogue(){
    PlayerHealth -= 20;
    PlayerHealthMax -= 20;
    PlayerCrit += 5;
    PlayerSpeedAttack += 0.2;
    PlayerClass = 2;
}

void Mage(){
    PlayerHealth -= 30;
    PlayerHealthMax -= 30;
    PlayerMana += 30;
    PlayerManaMax += 30;
    PlayerIntelligence += 5;
    PlayerClass = 3;
}

void setClass(){
    char choice[100];

    printf("Wybierz swoja klase (podaj odpowiednia cyfre)\n");
    printf("1 - Wojownik\n2 - Lotr\n3 - Mag\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "1") == 0){
        printf("Wybrales Wojownika, powodzenia!\n");
        Warrior();
    }
    else if(strcmp(choice, "2") == 0){
        printf("Wybrales Lotra, powodzenia!\n");
        Rogue();
    }
    else if(strcmp(choice, "3") == 0){
        printf("Wybrales maga, powodzenia!\n");
        Mage();
    }
    else{
        printf("Wybierz jeszcze raz\n");
        setClass();
    }
}