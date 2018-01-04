//
// Created by Patryk on 01.01.2018.
//

#include <stdio.h>
#include "Player.h"
#include "Monster.h"
#include "Fight.h"
#include <stdlib.h>
#include <string.h>
#include "Random.h"

char choice[100];

void Castle(){

}

void Forest(){
    printf("Co chesz teraz zrobić?\n");
    int bleh = RInt(1, 25);
    if(get_PlayerLevel() < 5){
        if (bleh == 5){
            Wolf();
            startBattle();
        }
    }
    else{
        printf("Towarzyszy Ci dziwny niepokój, jakbyś w każdym momencie mógł zostać zaatakowanym\n");
        int randomInt = RInt(1,8);
        if (randomInt == 3){
            Wolf();
            startBattle();
            Forest();
        }
        else if(randomInt == 6){
            Bear();
            startBattle();
            Forest();
        }
    }

    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Forest();
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Nie możesz tutaj spać! Musisz wrócić do obozu\n");
        Forest();
    }
    else{
        printf("Nie ma co tu zwiedzać\n");
        Forest();
    }
}

void Well(){
    int getBucket;
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "obejrzyj studnie") == 0){
        getBucket = 1;
        if (getBucket == 0){
            printf("Znalazłeś tylko stare wiaderko i linę, ale być może coś jest w środku?\n");
            getBucket = 1;
            Well();
        }
        else {
            printf("Niczego już tu nie ma");
            Well();
        }
    }
    else if(strcmp(choice, "zajrzyj do studni") == 0){
        printf("Widzisz coś świecącego na dnie\n");
        if(getBucket == 1){
            printf("Po kilkunastu próbach udaje Ci się wyłowić klucz ze studni\n");
            Well();
        }
        else {
            printf("Musisz najpierw znaleźć wiadro\n");
            Well();
        }
    }
    else if(strcmp(choice, "idz na polnoc") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Nie możesz tam iść, możesz tylko zawrócić\n");
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Wracasz do obozu\n");
        Camp();
    }
    else{
        printf("Niepoprawna komenda\n");
        Well();
    }
}

void Camp(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "idz na polnoc") == 0){
        printf("Doszedłeś do zniszczonej studni\n");
        Well();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        int randomInt = RInt(1,3);
        if (randomInt == 1){
            Zombie();
            startBattle();
        }
        printf("Jestes na poludniu\n");
        Camp();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Widzisz przed sobą wielki las, zbliżając się słyszałeś, że czyha tam wiele niebezpieczeństw\n");
        printf("Jesteś pewien, że chcesz iść dalej?\n");
        fgets(choice,100,stdin);
        choice[strlen(choice)-1] = '\0';
        if(strcmp(choice, "tak") == 0){
            Forest();
            printf("Wszedłeś do lasu, czujesz się cały czas obserwowany\n");
            if(get_PlayerLevel() < 5)
                printf("Zaczynasz się zastanawiać czy to był dobry pomysł\n");
        }
        else if(strcmp(choice, "nie") == 0){
            printf("Zawracasz\n");
            Camp();
        }
        else{
            printf("Zła odpowiedź\n");
            Camp();
        }
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
        exit(0);
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Poszedłeś spać. Odnowiłeś zdrowie i mane\n");
        set_PlayerMana(get_PlayerManaMax(), get_PlayerManaMax());
        set_PlayerHealth(get_PlayerHealthMax(), get_PlayerHealthMax());
        Camp();
    }
    else{
        printf("Niepoprawna komenda\n");
        Camp();
    }
}

