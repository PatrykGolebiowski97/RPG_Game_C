//
// Created by Patryk on 01.01.2018.
//

#include <stdio.h>
#include "Player.h"
#include "Monster.h"
#include "Fight.h"
#include <stdlib.h>
#include <string.h>

char choice[100];


void Well(){
    printf("Jestes na polnocy\n");
}

void Camp(){
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "idz na polnoc") == 0){
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        Zombie();
        printf("Jestes na poludniu\n");
        startBattle();
        Camp();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Jestes na wschodzie\n");
        Camp();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Jestes na zachodzie\n");
        Camp();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Camp();
    }
    else if(strcmp(choice, "koniec") == 0){
        EXIT_SUCCESS;
    }
    else{
        printf("Niepoprawna komenda\n");
        Camp();
    }
}

