#include<stdio.h>
#include "database.h"
Node* dodaj_wynalazek(Node* head,wynalazek new_wynalazek)
{
    Node* n=calloc(1,sizeof(Node));
    n->x=new_wynalazek;
    if(head==NULL)
    {
            n->next=head;   
            return n;
    }
    n->next=head;
    head=n;
    return head;//dodanie wynalazku bez sortowania
}
void poprawne_dane()
{
    printf("Przykładowa zawartość pliku dla jednego obiektu:\n");
    printf("wynalazek1\n");
    printf("mechaniczny\n");
    printf("85\n");
    printf("150\n");
    printf("prototyp\n");
}
void wczytaj(Node* head)
{
    wynalazek w;
    printf("wprowadz nazwe wynalazku\n");
    scanf("%101s",w.nazwa);
    printf("wprowadz typ wynalazku\n");
    scanf("%101s",w.typ);
    printf("wprowadz niezawodnosc wynalazku (0-100)\n");
    scanf("%d",&w.niezawodnosc);
    printf("wprowadz potencjalna energie wynalazku\n");
    scanf("%d",&w.pot_energia);
    printf("wprowadz status wynalazku (prototyp, testowany, dopuszczony, zakazany, niestabilny)\n");
    scanf("%20s",w.status);
    //przekazanie wynalazku w do funkcji dodaj_wynalazek
    head=dodaj_wynalazek(head,w);
}
Node* znajdz_po_nazwie(Node* head)
{
    char szukany[101];
    printf("wprowadz nazwe szukanego wynalazku\n");
    scanf("%101s",szukany);
    Node* obecny=head;
    while(obecny!=NULL)
    {
        if(strcmp(obecny->x.nazwa,szukany)==0)
        {
            return obecny;
        }
        else
        {
            obecny=obecny->next;
        }
    }
    printf("nie znaleziono wynalazku o podanej nazwie\n");
    return NULL;
}
void edytuj_wynalazek(Node* to_edit)
{
    int wybor=-1;
    while(wybor!=0)
    {
        printf("ktore pole chcesz edytowac?\n");
        printf("1-nazwa\n2-typ\n3-niezawodnosc\n4-potencjalna energia\n5-status\n0-zakoncz edycje\n");
        scanf("%d",&wybor);
        switch(wybor)
        {
            case 1:
                printf("wprowadz nowa nazwe wynalazku\n");
                scanf("%101s",to_edit->x.nazwa);
                break;
            case 2:
                printf("wprowadz nowy typ wynalazku\n");
                scanf("%101s",to_edit->x.typ);
                break;
            case 3:
                printf("wprowadz nowa niezawodnosc wynalazku (0-100)\n");
                scanf("%d",&to_edit->x.niezawodnosc);
                break;
            case 4:
                printf("wprowadz nowa potencjalna energie wynalazku\n");
                scanf("%d",&to_edit->x.pot_energia);
                break;
            case 5:
                printf("wprowadz nowy status wynalazku (prototyp, testowany, dopuszczony, zakazany, niestabilny)\n");
                scanf("%20s",to_edit->x.status);
                break;
            case 0:
                printf("edycja zakonczona\n");
                break;
            default:
                printf("nieprawidlowy wybor\n");
        }
    }
}
Node* usun_wynalazek(Node* head, char* nazwa_usuwanego)
{
    if (head == NULL)
    {return head;}
    if(strcmp(head->x.nazwa,nazwa_usuwanego)==0)
    {
        Node* next = head->next;
        free(head);
        return next;
    }
    Node* obecny = head;
    while(obecny->next!=NULL&&strcmp((obecny->next)->x.nazwa,nazwa_usuwanego)!=0)
    {obecny=obecny->next;}
    if(obecny->next!=NULL)
    {
        Node* do_usuniecia=obecny->next;
        obecny->next=do_usuniecia->next;
        free(do_usuniecia);
    }
    return head;
}
void wyszukaj_zakres(Node* head, int min, int max)
{
    Node* obecny=head;
    int znalezione=0;
    while(obecny!=NULL)
    {
        if(obecny->x.niezawodnosc>=min&&obecny->x.niezawodnosc<=max)
        {
            printf("Znaleziono wynalazek: %s, Typ: %s, Niezawodnosc: %d, Energia potencjalna: %d, Status: %s\n",
                   obecny->x.nazwa, obecny->x.typ, obecny->x.niezawodnosc,
                   obecny->x.pot_energia, obecny->x.status);
            znalezione=1;
        }
        obecny=obecny->next;
    }
    if(znalezione==0)
    {
        printf("Nie znaleziono wynalazkow w podanym zakresie niezawodnosci\n");
    }
}