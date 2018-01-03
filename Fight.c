//
// Created by patryk on 1/2/18.
//

#include <stdio.h>
#include "Monster.h"
#include "Player.h"
#include "Random.h"

void endFight(){
    printf("Koniec walki\n");
}

void continueBattle(){
    double attack = RInt(1, 2);

    if (get_MonsterHealth() > 0 && get_PlayerHealth() > 0){
        if(get_PlayerSpeedAttack() >= get_MonsterSpeedAttack() ){
            playerDealDamage();
            if (get_MonsterHealth() > 0){
                if (attack == 1 && get_MonsterMana() > 15 ){
                    printf("Monster - Atak magia\n");
                }
                else{
                    monsterPhysicAttack(get_MonsterDamageMin(), get_MonsterDamageMax());
                }
            }
            printf("-------------------------------------------------------------\n");
            continueBattle();
        }
        else{
            if (get_MonsterHealth() > 0){
                if (attack == 1 && get_MonsterMana() > 15 ){
                    printf("Monster - Atak magia\n");
                }
                else{
                    monsterPhysicAttack(get_MonsterDamageMin(), get_MonsterDamageMax());
                }
            }
            printf("-------------------------------------------------------------\n");
            playerDealDamage();
            continueBattle();
        }
    }
    else{
        endFight();
    }
}

void startBattle(){
    printf("-------------------------------------------------------------\n");
    printf("Zostales zaatakowany przez: %s\n", get_MonsterNameOfTheMonster());
    printf("-------------------------------------------------------------\n");
    continueBattle();
}

