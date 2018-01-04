//
// Created by patryk on 1/3/18.
//

#include <stdio.h>
#include <string.h>
#include "Monster.h"
#include "Player.h"
#include "Random.h"

int monsterRequiredMana;
int monsterSpellDamage;

void monsterUseFireBall(){
    monsterRequiredMana = 20;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    printf( "%s użył Kuli Ognia!\n", get_MonsterNameOfTheMonster() );
    //printf("Obrazenia: %d", monsterSpellDamage);
    playerTakeDamage(monsterSpellDamage);
    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
}

void monsterUseIceSpike(){
    monsterRequiredMana = 40;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    printf( "%s użył Lodowego Szpikulca!\n", get_MonsterNameOfTheMonster(), monsterSpellDamage );
    playerTakeDamage(monsterSpellDamage);
    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
}

void monsterUseHeal(){
    monsterRequiredMana = 30;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    if ( monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth() ){
        monsterSpellDamage = get_MonsterHealthMax() - get_MonsterHealth();
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        printf("%s użył Uleczenia, odnowił %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        printf("leczenie 1");
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
    }
    else{
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        printf("%s użył Uleczenia, odnowił %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        printf("Leczenie 2");
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
    }
}

void monsterUseStealHealth(){
    monsterRequiredMana = 15;
    monsterSpellDamage = get_MonsterLevel() * RInt( get_MonsterMinMagicDmg(), get_MonsterMaxMagicDmg() ) / (get_PlayerResistance() * 1/5);

    if ( monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth() ){
        monsterSpellDamage = monsterSpellDamage >= get_MonsterHealthMax() - get_MonsterHealth();
        printf("%s użył Kradzieży Życia, ukradł Ci %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
        playerTakeDamage(monsterSpellDamage);
    }
    else{
        printf("%s użył Kradzieży Życia, ukradł Ci %d puntków życia! Jego życie wynosi teraz: %d / %d\n", get_MonsterNameOfTheMonster(), monsterSpellDamage, get_MonsterHealth(), get_MonsterHealthMax() );
        set_MonsterHealth( get_MonsterHealth() + monsterSpellDamage, get_MonsterHealthMax() );
        set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );
        playerTakeDamage(monsterSpellDamage);
    }
}

void monsterUseReinforcedAttack(){
    monsterRequiredMana = 20;
    monsterSpellDamage = RInt( get_MonsterDamageMin() * 3/2, get_MonsterDamageMax() * 2) / (get_PlayerDeffence() * 7/20);

    set_MonsterMana( get_MonsterMana() - monsterRequiredMana, get_MonsterManaMax() );

    printf( "%s użył Wzmocnionego Ataku i zadał Ci %d punktów obrażeń!\n", get_MonsterNameOfTheMonster(), monsterSpellDamage );
    playerTakeDamage(monsterSpellDamage);
}

void monsterUseMagic(){
    int typeOfAttack;

    if ( get_MonsterMana() >= 20 && get_MonsterMana() < 30 ){
        monsterUseFireBall();
    }
    else if( get_MonsterMana() >= 30 && get_MonsterMana() < 40){
        typeOfAttack = RInt(1, 2);

        if (typeOfAttack == 1){
            monsterUseFireBall();
        }
        else{
            if (strcmp(get_MonsterNameOfTheMonster(), "Zombie") == 0)
                monsterUseReinforcedAttack();
            else
                monsterUseHeal();
        }
    }
    else if( get_MonsterMana() >= 40){
        typeOfAttack = RInt(1, 3);

        if ( typeOfAttack == 1){
            monsterUseFireBall();
        }
        else if( typeOfAttack == 2){
            if (strcmp(get_MonsterNameOfTheMonster(), "Zombie") == 0)
                monsterUseReinforcedAttack();
            else
                monsterUseHeal();
        }
        else{
            monsterUseIceSpike();
        }
    }

}