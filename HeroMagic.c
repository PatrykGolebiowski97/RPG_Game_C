//
// Created by patryk on 1/3/18.
//
#include <stdio.h>
#include "Player.h"
#include "Monster.h"
#include "Random.h"

int playerRequiredMana;
int playerSpellDamage;

void playerUseFireBall(){
    playerRequiredMana = 20;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 ) / (get_MonsterResistance() * 1/5);
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() ) / (get_MonsterResistance() * 1/5);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana mana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Kula Ognia! Zadałeś: %d punktów obrażeń!\n", playerSpellDamage);
        set_PlayerMana(get_PlayerMana() - playerRequiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}

void playerUseIceSpike(){
    playerRequiredMana = 40;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 ) / (get_MonsterResistance() * 1/5);
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() ) / (get_MonsterResistance() * 1/5);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Lodowy Szpikulec! Zadałeś %d punktów obrażeń\n", playerSpellDamage);
        set_PlayerMana(get_PlayerMana() - playerRequiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}

void playerUseHeal(){
    playerRequiredMana = 30;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 );
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() );

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( playerSpellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            playerSpellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Uleczyłeś się o: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
        else{
            printf("Uleczyłeś się o: %d punktów życia\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
    }
}

void playerUseStealHealth(){
    playerRequiredMana = 15;

    if (get_PlayerClass() == 2) //Sprawdza czy klasa postaci to łotr
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerAgility() * 3/2, get_PlayerLevel() * get_PlayerAgility() * 3 ) / (get_MonsterResistance() * 1/5);
    else
        playerSpellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() ) / (get_MonsterResistance() * 1/5);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( playerSpellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            playerSpellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(playerSpellDamage);
        }
        else{
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", playerSpellDamage);
            set_PlayerHealth( get_PlayerHealth() + playerSpellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(playerSpellDamage);
        }
    }
}

void playerUseReinforcedAttack(){
    playerRequiredMana = 30;

    if (get_PlayerClass() == 1) //Sprawdza czy klasa postaci to wojownik
        playerSpellDamage = RInt( get_PlayerAttackPower() * 2, get_PlayerAttackPower() * 4 ) / (get_MonsterDeffence() * 7/20);
    else
        playerSpellDamage = RInt( get_PlayerAttackPower(), get_PlayerAttackPower() * 3/2) / (get_MonsterResistance() * 7/20);

    if ( playerRequiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", playerRequiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś wzmocnionego ataku i zadałeś: %d punktów obrażeń!\n", playerSpellDamage);
        set_PlayerMana( get_PlayerMana() - playerRequiredMana, get_PlayerManaMax() );
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(playerSpellDamage);
    }
}
