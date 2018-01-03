//
// Created by patryk on 1/3/18.
//
#include <stdio.h>
#include "Player.h"
#include "Monster.h"
#include "Random.h"

int requiredMana;
int spellDamage;

void playerUseFireBall(){
    requiredMana = 20;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 );
    else
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() );

    if ( requiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana mana: %d, posiadasz %d\n", requiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Kula Ognia! Zadałeś: %d punktów obrażeń!\n", spellDamage);
        set_PlayerMana(get_PlayerMana() - requiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(spellDamage);
    }
}

void playerUseIceSpike(){
    requiredMana = 40;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 );
    else
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() );

    if ( requiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", requiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś magii Lodowy Szpikulec! Zadałeś %d punktów obrażeń\n", spellDamage);
        set_PlayerMana(get_PlayerMana() - requiredMana, get_PlayerManaMax());
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(spellDamage);
    }
}

void playerUseHeal(){
    requiredMana = 30;

    if (get_PlayerClass() == 3) //Sprawdza czy klasa postaci to mag
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1, get_PlayerLevel() * get_PlayerIntelligence() * 3 );
    else
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() );

    if ( requiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", requiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( spellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            spellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Uleczyłeś się o: %d punktów życia!\n", spellDamage);
            set_PlayerHealth( get_PlayerHealth() + spellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - requiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
        else{
            printf("Uleczyłeś się o: %d punktów życia\n", spellDamage);
            set_PlayerHealth( get_PlayerHealth() + spellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - requiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        }
    }
}

void playerUseStealHealth(){
    requiredMana = 15;

    if (get_PlayerClass() == 2) //Sprawdza czy klasa postaci to łotr
        spellDamage = RInt( get_PlayerLevel() * get_PlayerAgility() * 3/2, get_PlayerLevel() * get_PlayerAgility() * 3 );
    else
        spellDamage = RInt( get_PlayerLevel() * get_PlayerIntelligence() * 1/2, get_PlayerLevel() * get_PlayerIntelligence() );

    if ( requiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", requiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        if ( spellDamage >= get_PlayerHealthMax() - get_PlayerHealth() ){
            spellDamage = get_PlayerHealthMax() - get_PlayerHealth();
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", spellDamage);
            set_PlayerHealth( get_PlayerHealth() + spellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - requiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(spellDamage);
        }
        else{
            printf("Użyłeś Kradzieży życia i uleczyłeś się za: %d punktów życia!\n", spellDamage);
            set_PlayerHealth( get_PlayerHealth() + spellDamage, get_PlayerHealthMax() );
            printf("Twoje zdrowie wynosi teraz: %d / %d\n", get_PlayerHealth(), get_PlayerHealthMax());
            set_PlayerMana( get_PlayerMana() - requiredMana, get_PlayerManaMax() );
            printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
            monsterTakeDamage(spellDamage);
        }
    }
}

void playerUseReinforcedAttack(){
    requiredMana = 30;

    if (get_PlayerClass() == 1) //Sprawdza czy klasa postaci to wojownik
        spellDamage = RInt( get_PlayerAttackPower() * 2, get_PlayerAttackPower() * 4 );
    else
        spellDamage = RInt( get_PlayerAttackPower(), get_PlayerAttackPower() * 3/2);

    if ( requiredMana > get_PlayerMana() ){
        printf("Nie masz many na to zaklęcie!\nWymagana: %d, posiadasz %d\n", requiredMana, get_PlayerMana());
        playerDealDamage();
    }
    else{
        printf("Użyłeś wzmocnionego ataku i zadałeś: %d punktów obrażeń!\n", spellDamage);
        set_PlayerMana( get_PlayerMana() - requiredMana, get_PlayerManaMax() );
        printf("Twoja mana wynosi teraz: %d / %d\n", get_PlayerMana(), get_PlayerManaMax());
        monsterTakeDamage(spellDamage);
    }
}
