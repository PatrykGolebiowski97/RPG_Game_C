//
// Created by Patryk on 01.01.2018.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "Player.h"

int RInt(int min, int max){
    srand(time( NULL ));
    return min + rand() % (max+1 - min);
}


int Crit(){
    int chance = RInt(1,get_PlayerCrit());
    int possibilities = RInt(1, 100);
    if (possibilities <= chance){
        printf("cryt siadł, szansa: %d > możliwości: %d\n", chance, possibilities);
        return 1;
    }
    else {
        printf("cryt nie siadł, szansa: %d < możliwości: %d\n", chance, possibilities);
        return 0;
    }
}



