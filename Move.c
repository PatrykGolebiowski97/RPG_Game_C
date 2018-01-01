//
// Created by Patryk on 01.01.2018.
//

#include <stdio.h>
#include "Player.h"
#include <mem.h>
#include <stdlib.h>


static void Well(){
    printf("Jestes na poluudniu");
}

static void Camp(){
    char choice[30];
    gets(choice);

    if(strcmp(choice, "idz na polnoc") == 0){
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        Camp();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        Camp();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
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

