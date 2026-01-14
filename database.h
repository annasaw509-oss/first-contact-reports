#include<stdio.h>
typedef struct {
    char nazwa[101];
    char typ[101];
    int niezawodnosc;
    int pot_energia;
    enum { prototyp, testowany, dopuszczony, zakazany, niestabilny}status;
} wynalazek;
typedef struct Node{
    wynalazek x;
    struct Node* next;
}Node;
Node* dodaj_wynalazek(Node* head,wynalazek new_wynalazek);
void poprawne_dane();
void wczytaj(Node* head);
Node* znajdz_po_nazwie(Node* head);
void edytuj_wynalazek(Node* to_edit);
Node* usun_wynalazek(Node* head, char* nazwa);
void wyszukaj_zakres(Node* head, int min, int max);