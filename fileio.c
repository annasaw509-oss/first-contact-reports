#include "fileio.h"
#include <string.h>
#include <stdio.h>
#include "database.h"
Node* odczyt(Node* head)
{
    wynalazek w;
    poprawne_dane();
    printf("podaj nazwe pliku do odczytu\n");
    int sprawdz=0;
    char nazwa_pliku[101];
    while(getchar()!='\n');
    fgets(nazwa_pliku,101,stdin);
    nazwa_pliku[strcspn(nazwa_pliku, "\n")] = '\0'; // Usuwa znak nowej linii z końca
    FILE* plik=fopen(nazwa_pliku,"r");
    if(plik==NULL)
    {
        printf("nie mozna otworzyc pliku o podanej nazwie\n");
    }
    else
    {
        while(fscanf(plik,"%s %s %d %d %s",w.nazwa,w.typ,&w.niezawodnosc,&w.pot_energia,w.status)==5)
        {
            sprawdz++;
            printf("Wynalazek: %s, Typ: %s, Niezawodnosc: %d, Energia potencjalna: %d, Status: %s\n",
                   w.nazwa, w.typ, w.niezawodnosc, w.pot_energia, w.status);
                   head=dodaj_wynalazek(head,w);
        }
        if(sprawdz==0)
        {
            printf("plik jest pusty lub niepoprawny format danych\n");
        }
    }
    fclose(plik);
    return head;
}
void zapis(Node* head)
{
    printf("podaj nazwe pliku do zapisu\n");
    while(getchar()!='\n');
    char nazwa_pliku[101];
    fgets(nazwa_pliku,sizeof(nazwa_pliku),stdin);
    nazwa_pliku[strcspn(nazwa_pliku, "\n")] = '\0'; // Usuwa znak nowej linii z końca
    FILE* plik=fopen(nazwa_pliku,"w");
    if(plik==NULL)
    {
        printf("nie mozna otworzyc pliku o podanej nazwie\n");
    }
    else
    {
        Node* obecny=head;
        while(obecny!=NULL)
        {
            fprintf(plik,"%s\n%s\n%d\n%d\n%s\n\n",obecny->x.nazwa,obecny->x.typ,obecny->x.niezawodnosc,
                    obecny->x.pot_energia,obecny->x.status);
            obecny=obecny->next;
        }
    }
    fclose(plik);
}