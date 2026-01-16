#include<stdio.h>
#include "database.h"
#include "menu.h"
#include "fileio.h"
int menu()
{
    int choice=-1;
    printf("=====MENU=====\n");
    printf("1. Wprowadz wynalazek\n");
    printf("2. Wczytaj dane z pliku\n");
    printf("3. Edytuj wybrany wynalazek\n");
    printf("4. Usun wybrany wynalazek\n");
    printf("5. Usun wynalazki wedlug typu\n");
    printf("6. Wyszukaj wynalazki wedlug kryterium\n");
    printf("7. Posortuj wynalazki wedlug kryterium\n");
    printf("8. Wyswietl wszystkie wynalazki\n");
    printf("9. Zapisz dane do pliku\n");
    printf("0. Zakoncz program\n");
    while(scanf("%d", &choice) != 1 || choice < 0 || choice > 9) {
        printf("Nieprawidlowy wybor. Sprobuj ponownie: ");
        while(getchar() != '\n');
    }
    return choice;
}
Node* obsluga_menu(int wybor,Node* head)
{
    Node* znaleziony;
    switch(wybor) {
        case 1:
            printf("Wybrano opcje 1: Wprowadz wynalazek\n");
            head = wczytaj(head);
            break;
        case 2:
            printf("Wybrano opcje 2: Wczytaj dane z pliku\n");
            head = odczyt(head);
            break;
        case 3:
            printf("Wybrano opcje 3: Edytuj wybrany wynalazek\n");
            znaleziony = znajdz_po_nazwie(head);
            if(znaleziony != NULL) {
                edytuj_wynalazek(znaleziony);
            }
            break;
        case 4:
            printf("Wybrano opcje 4: Usun wybrany wynalazek\n");
            znaleziony = znajdz_po_nazwie(head);
            if(znaleziony != NULL) {
                head = usun_wynalazek(head, znaleziony->x.nazwa);
            }
            break;
        case 5:
            printf("Wybrano opcje 5: Usun wynalazki wedlug typu\n");
            printf("wprowadz typ wynalazkow do usuniecia\n");
            char typ_usuwanego[101];
            scanf("%101s",typ_usuwanego);
            head = usun_wiele(head, typ_usuwanego);
            break;
        case 6:
            printf("Wybrano opcje 6: Wyszukaj wynalazki wedlug kryterium\n");
            printf("1. Wyszukaj po nazwie\n2. wyszukaj wedlog wartosci niezawodnosci\n");
            int choice6;
            while(scanf("%d", &choice6) != 1 || (choice6 != 1 && choice6 != 2)) {
                printf("Nieprawidlowy wybor. Sprobuj ponownie: ");
                while(getchar() != '\n');
            }
            if(choice6 == 1) {
                printf("Wybrano wyszukiwanie po nazwie\n");
                znaleziony = znajdz_po_nazwie(head);
                if(znaleziony != NULL) {
                    printf("Znaleziono wynalazek: %s, Typ: %s, Niezawodnosc: %d, Energia potencjalna: %d, Status: %s\n",
                           znaleziony->x.nazwa, znaleziony->x.typ, znaleziony->x.niezawodnosc,
                           znaleziony->x.pot_energia, znaleziony->x.status);
                }
            } else {
                printf("Wybrano wyszukiwanie wedlog wartosci niezawodnosci\n");
                printf("wczytaj interesujacy cie zakres niezawodnosci\n");
                int min;
                int max;
                printf("min: ");
                scanf("%d",&min);
                printf("max: ");
                scanf("%d",&max);
                wyszukaj_zakres(head,min,max);
            }
            break;
        case 7:
            printf("Wybrano opcje 7: Posortuj wynalazki wedlug kryterium\n");
            printf("1. Sortuj alfabetycznie\n2. Sortuj wedlug niezawodnosci\n");
            int choice7;
            while(scanf("%d", &choice7) != 1 || (choice7 != 1 && choice7 != 2)) {
                printf("Nieprawidlowy wybor. Sprobuj ponownie: ");
                while(getchar() != '\n');
            }
            if(choice7 == 1) {
                printf("Wybrano sortowanie alfabetyczne...\n");
                sortuj_alfabetycznie(head);
            } else {
                printf("Wybrano sortowanie wedlug niezawodnosci...\n");
                sortuj_niezawodnosc(head);
            }
            printf("Sortowanie zakonczone.\n");
            break;
        case 8:
            printf("Wybrano opcje 8: Wyswietl wszystkie wynalazki\n");
            wyswietl_wszystkie(head);
            break;
        case 9:
            printf("Wybrano opcje 9: Zapisz dane do pliku\n");
            zapis(head);
            break;
        case 0:
            printf("Wybrano opcje 0: Zakończ program\n");
            break;
        default:
            printf("Nieprawidlowy wybor.\n");
    }
    return head;
}
