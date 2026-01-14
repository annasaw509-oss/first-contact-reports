#include<stdio.h>
#include "database.h"
#include "menu.h"
#include "fileio.h"
int menu()
{
    int choice;
    printf("=====MENU=====\n");
    printf("1. Wprowadz wynalazek\n");
    printf("2. Wczytaj dane z pliku\n");
    printf("3. Edytuj wybrany wynalazek\n");
    printf("4. Usun wybrany wynalazek\n");
    printf("5. Usun wynalazki wedlug kryterium\n");
    printf("6. Wyszukaj wynalazki wedlug kryterium\n");
    printf("7. Posortuj wynalazki wedlug kryterium\n");
    printf("8. Wyswietl wszystkie wynalazki\n");
    printf("9. Zapisz dane do pliku\n");
    printf("0. Wygeneruj raport i zakoncz program\n");
    while(scanf("%d", &choice) != 1 || choice < 0 || choice > 9) {
        printf("Nieprawidlowy wybor. Sprobuj ponownie: ");
        while(getchar() != '\n');
    }
    return choice;
}
void obsluga_menu(int wybor,Node* head)
{
    switch(wybor) {
        case 1:
            printf("Wybrano opcje 1: Wprowadz wynalazek\n");
            wczytaj(head);
            break;
        case 2:
            printf("Wybrano opcje 2: Wczytaj dane z pliku\n");
            odczyt(head);
            break;
        case 3:
            printf("Wybrano opcje 3: Edytuj wybrany wynalazek\n");
            Node* znaleziony = znajdz_po_nazwie(head);
            if(znaleziony != NULL) {
                edytuj_wynalazek(znaleziony);
            }
            break;
        case 4:
            printf("Wybrano opcje 4: Usun wybrany wynalazek\n");
            break;
        case 5:
            printf("Wybrano opcje 5: Usun wynalazki wedlug kryterium\n");
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
                Node* znaleziony = znajdz_po_nazwie(head);
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
            break;
        case 8:
            printf("Wybrano opcje 8: Wyswietl wszystkie wynalazki\n");
            break;
        case 9:
            printf("Wybrano opcje 9: Zapisz dane do pliku\n");
            break;
        case 0:
            printf("Wybrano opcje 0: Wygeneruj raport i zakoncz program\n");
            break;
        default:
            printf("Nieprawidlowy wybor.\n");
    }
}
