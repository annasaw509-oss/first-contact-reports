#include "fileio.h"
#include <string.h>
#include <stdio.h>
#include "database.h"
void odczyt(Node* head)
{
    wynalazek w;
    poprawne_dane();
    printf("podaj nazwe pliku do odczytu\n");
    char nazwa_pliku[101];
    fgets(nazwa_pliku,sizeof(nazwa_pliku),stdin);
    nazwa_pliku[strcspn(nazwa_pliku, "\n")] = '\0'; // Usuwa znak nowej linii z końca
    FILE* plik=fopen(nazwa_pliku,"r");
    if(plik==NULL)
    {
        printf("nie mozna otworzyc pliku o podanej nazwie\n");
        return 0;
    }
    else
    {
        while(fscanf(plik,"%101s %101s %d %d %20s",&w.nazwa,&w.typ,&w.niezawodnosc,&w.pot_energia,w.status)==5)
        {
            printf("Wynalazek: %s, Typ: %s, Niezawodnosc: %d, Energia potencjalna: %d, Status: %s\n",
                   w.nazwa, w.typ, w.niezawodnosc, w.pot_energia, w.status);
                   //przekazanie wynalazku w do funkcji dodaj_wynalazek
                   head=dodaj_wynalazek(head,w);
        }
    }
    fclose(plik);

}