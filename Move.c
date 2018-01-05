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
int haveBucket = 0; //(0) - brak wiaderka, (1) - znalezione wiaderko, (2) - wyłowiony klucz
int haveKey = 0; //Trzeba mieć klucz (1), żeby wejść do zamku
int clearSwamp = 0; //Quest ze świątyni odnośnie zabijania topielców (1) - Quest przyjęty
int swampKill = 0; //Zabite topielce
int killVampire = 0; //EndGame Quest
int forestFight = 0; //(1) - Potwory będą atakować

void Swamp(){
    if (clearSwamp == 1){
        while (swampKill <= 100){
            Floater();
            startBattle();
            swampKill ++;
        }
        clearSwamp = 2;
        printf("Ukończyłeś zadanie, wracasz do miasta");
        City();
    }
    else if (clearSwamp == 2){
        printf("Zabiłeś już wszystkie topielce. Wróć do świątyni po nagrodę.\n");
        City();
    }
    else{
        printf("Niczego więcej już tu nie ma. Wracasz do miasta.\n");
        City();
    }
}

void City(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';
    if (strcmp(choice, "idz na polnoc") == 0){
        printf("Wracasz do obozu\n");
        Camp();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Tam nic nie ma\n");
        City();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        if(clearSwamp == 0){
            printf("Nie możesz tam jeszcze iść");
            City();
        }
        else{
            if(swampKill == 1){
                printf("Jesteś pewien, że chcesz tam iść? Nie będziesz mógł wyjść dopóki nie pokonasz wszystkich potworów\n");
                fgets(choice,100,stdin);
                choice[strlen(choice)-1] = '\0';
                if(strcmp(choice, "tak") == 0){
                    printf("Idziesz na bagna\n");
                    Swamp();
                }
                else if(strcmp(choice, "nie") == 0){
                    printf("Wracasz do miasta\n");
                    City();
                }
                else{
                    printf("Niepoprawna komenda\n");
                    City();
                }
            }
            else{
                Swamp();
            }
        }
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Tam nic nie ma\n");
        City();
    }
    else if(strcmp(choice, "idz do swiatyni") == 0){
        if (clearSwamp == 0){
            printf("Bla... bla... bla... musisz oczyścić bagna z topielców (10). Przyjdź kiedy skończysz\n");
            clearSwamp = 1;
            City();
        }
        else if(clearSwamp == 1){
            printf("Zanim tam pójdziesz, musisz pokonać topielce\n");
            City();
        }
        else if(clearSwamp == 2){
            printf("W zamian za oczyszczenie bagna zostałeś pobogłosawiony. Twoje statystyki wzrosły\n");
            printf("Dostałeś kolejne zadanie od arcybiskupa. Na zachód od Obozu znajduje się Zamek w którym zamieszkuje potężny wampir\n");
            printf("Zostałeś poproszony o zabicie go\n");
            printf("Nie możesz odmówić\n");
            clearSwamp = 3;
            killVampire = 1;
            City();
        }
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Idziesz spać do świątyni\n");
        printf("Zregenerowałeś życie i mane\n");
        set_PlayerHealth(get_PlayerHealthMax(), get_PlayerHealthMax());
        set_PlayerMana(get_PlayerManaMax(), get_PlayerManaMax());
        City();
    }
    else if(strcmp(choice, "medytuj") == 0) {
        printf("Medytujesz...\n");
        playerMeditation();
        City();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        City();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na polnoc/wschod, idz do swiatyni, idz spac, statystyki, medytuj\n");
        City();
    }
    else{
        printf("Niepoprawna komenda\n");
        City();
    }
}

void Castle(){
    printf("Zamek... zła aura... Wampir...\n");
    Vampire();
    startBattle();
    printf("Gratulacje, ukończyłeś grę!\n");
    exit(0);
}

void Forest(){
    printf("Co chesz teraz zrobić?\n");
    int bleh = RInt(1, 3);
    if(get_PlayerLevel() < 5){
        if (bleh == 3 && forestFight == 1){
            Zombie();
            startBattle();
        }
    }
    else{
        int randomInt = RInt(1,8);
        if (randomInt == 3 && forestFight == 1){
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
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Nie możesz tutaj spać! Musisz wrócić do obozu\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na poludnie") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na polnoc") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na wschod") == 0){
        printf("Nie ma tam nic\n");
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "idz na zachod") == 0){
        printf("Wracasz do Obozu\n");
        Camp();
    }
    else if(strcmp(choice, "czekaj") == 0){
        printf("Czekasz\n");
        forestFight = 1;
        Forest();
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        forestFight = 0;
        Forest();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na zachod, statystyki, czekaj\n");
        forestFight = 0;
        Forest();
    }
    else{
        printf("Nie ma co tu zwiedzać\n");
        forestFight = 0;
        Forest();
    }
}

void Well(){
    printf("Co chesz teraz zrobić?\n");
    fgets(choice,100,stdin);
    choice[strlen(choice)-1] = '\0';

    if(strcmp(choice, "obejrzyj studnie") == 0){
        if (haveBucket == 0){
            printf("Znalazłeś stare wiaderko i linę\n");
            haveBucket = 1;
            Well();
        }
        else {
            printf("Niczego już tu nie ma\n");
            Well();
        }
    }
    else if(strcmp(choice, "zajrzyj do studni") == 0){
        if(haveBucket == 1){
            printf("Po kilkunastu próbach udaje Ci się wyłowić klucz ze studni\n");
            haveBucket = 2;
            haveKey = 1;
            Well();
        }
        else if( haveBucket == 2){
            printf("Niczego więcej już tam nie ma\n");
            Well();
        }
        else {
            printf("Widzisz coś świecącego na dnie\n");
            printf("ale żeby to wyłowić musisz znaleźć wiadro\n");
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
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Well();
    }
    else if(strcmp(choice, "idz spac") == 0){
        printf("Nie możesz tutaj spać!\n");
    }
    else if(strcmp(choice, "medytuj") == 0){
        printf("Nie mozesz sie tu skupic\n");
        Well();
    }
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na poludnie, statystyki, obejrzyj studnie, zajrzyj do studni\n");
        Well();
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
        if (get_PlayerLevel() < 5){
            printf("Strażnicy nie pozwalają Ci wejść do miasta\n");
            printf("Musisz stać się silniejszy\n");
            Camp();
        }
        else{
            if (clearSwamp == 0) {
                printf("Wchodząc do miasta zostajesz zaczepiony przez strażników\n");
                printf("Każą Ci się zgłosić do świątyni\n");
                City();
            }
            else{
                printf("Wchodzisz do miasta\n");
                City();
            }
        }
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
        if (killVampire ==  0){
            printf("Widzisz potężny zamek, emanujący straszliwą aurą. Wolisz się nie zbliżać do niego\n");
            printf("Zawracasz do obozu\n");
            Camp();
        }
        else if (killVampire == 1 && haveKey == 1){
            printf("Idziesz do zamku, czeka Cię ciężka walka. Na pewno chcesz tam iść?\n");
            fgets(choice,100,stdin);
            choice[strlen(choice)-1] = '\0';
            if(strcmp(choice, "tak") == 0){
                Castle();
            }
            else if(strcmp(choice, "nie") == 0){
                printf("Zawracasz do Obozu\n");
                Camp();
            }
        }
        else if(killVampire == 1 && haveKey == 0){
            printf("Próbujesz otworzyć bramę do zamku, ale Ci się nie udaje. Musisz znaleźć klucz\n");
            printf("Wracasz do Obozu\n");
            Camp();
        }
    }
    else if(strcmp(choice, "statystyki") == 0){
        get_PlayerStats();
        Camp();
    }
    else if(strcmp(choice, "medytuj") == 0){
        printf("Medytujesz...\n");
        playerMeditation();
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
    else if(strcmp(choice, "co robic") == 0){
        printf("idz na polnoc/poludnie/wschod/zachod, idz spac, statystyki, medytuj, koniec\n");
        Camp();
    }
    else{
        printf("Niepoprawna komenda\n");
        Camp();
    }
}

