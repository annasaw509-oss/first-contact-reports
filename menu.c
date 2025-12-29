#include<stdio.h>
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
void obsluga_menu(int wybor)
{
    switch(wybor) {
        case 1:
            printf("Wybrano opcje 1: Wprowadz wynalazek\n");
            
            break;
        case 2:
            printf("Wybrano opcje 2: Wczytaj dane z pliku\n");
            break;
        case 3:
            printf("Wybrano opcje 3: Edytuj wybrany wynalazek\n");
            break;
        case 4:
            printf("Wybrano opcje 4: Usun wybrany wynalazek\n");
            break;
        case 5:
            printf("Wybrano opcje 5: Usun wynalazki wedlug kryterium\n");
            break;
        case 6:
            printf("Wybrano opcje 6: Wyszukaj wynalazki wedlug kryterium\n");
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