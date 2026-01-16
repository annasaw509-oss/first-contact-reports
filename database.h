#ifndef DATABASE_H
#define DATABASE_H
#include<stdio.h>
typedef struct wynalazek{
    char nazwa[101];
    char typ[101];
    int niezawodnosc;
    int pot_energia;
    char status[20];
} wynalazek;
typedef struct Node{
    wynalazek x;
    struct Node* next;
}Node;
Node* dodaj_wynalazek(Node* head,wynalazek new_wynalazek);
void poprawne_dane();
Node* wczytaj(Node* head);
Node* znajdz_po_nazwie(Node* head);
void edytuj_wynalazek(Node* to_edit);
Node* usun_wynalazek(Node* head, char* nazwa);
void wyszukaj_zakres(Node* head, int min, int max);
int czy_mozna_usunac(Node* rozwazany);
Node* usun_wiele(Node* head, char* typ_usuwanego);
void wyswietl_wszystkie(Node* head);
void sortuj_alfabetycznie(Node* head);
void sortuj_niezawodnosc(Node* head);
#endif