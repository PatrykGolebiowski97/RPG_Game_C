//
// Created by Patryk on 01.01.2018.
//
#include "Player.h"
#include <stdlib.h>

static double RInt(double min, double max){
    double scaled = (double)rand()/RAND_MAX;

    return (max - min +1)*scaled + min;
}




static int Crit(){
    int R = 100;
    int C = (int)get_PlayerCrit();

    int array[R];
    int array1[C];

    for(int b = 1; b < R; b++){
        array[b] = b + 1;
    }

    for (int b = 1; b < C; b++){
        array1[b] = b + 1;
    }

    int x = (int)RInt(1, sizeof(array));

    if (x <= C){
        return 1; //Uderzenie krytyczne
    }
    else{
        return 0;
    }
}


