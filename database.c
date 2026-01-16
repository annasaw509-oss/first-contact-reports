#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "database.h"
Node* dodaj_wynalazek(Node* head,wynalazek new_wynalazek)
{
    Node* n=calloc(1,sizeof(Node));
    if(n==NULL)
    {
        printf("blad alokacji pamieci\n");
        return head;
    }
    n->x=new_wynalazek;
    if(head==NULL)
    {
            n->next=head;
            printf("Wynalazek dodany pomyslnie\n");   
            return n;
    }
    n->next=head;
    head=n;
    if(head!=NULL)
    {
        printf("Wynalazek dodany pomyslnie\n");
    }
    else
    {
        printf("Blad przy dodawaniu wynalazku\n");
    }
    return head;//dodanie wynalazku bez sortowania
}
void poprawne_dane()
{
    printf("Przykladowa zawartosc pliku dla jednego obiektu:\n");
    printf("wynalazek1 ");
    printf("mechaniczny ");
    printf("85 ");
    printf("150 ");
    printf("prototyp\n");
}
Node* wczytaj(Node* head)
{
    wynalazek w;
    printf("wprowadz nazwe wynalazku\n");
    while(scanf("%101s",w.nazwa)!=1)
    {
        printf("nieprawidlowe dane, sprobuj ponownie\n");
        while(getchar()!='\n');
    }
    printf("wprowadz typ wynalazku\n");
    while(scanf("%101s",w.typ)!=1)
    {
        printf("nieprawidlowe dane, sprobuj ponownie\n");
        while(getchar()!='\n');
    }
    printf("wprowadz niezawodnosc wynalazku (0-100)\n");
    while(scanf("%d",&w.niezawodnosc)!=1||w.niezawodnosc<0||w.niezawodnosc>100)
    {
        printf("nieprawidlowe dane, sprobuj ponownie\n");
        while(getchar()!='\n');
    }
    printf("wprowadz potencjalna energie wynalazku\n");
    while(scanf("%d",&w.pot_energia)!=1)
    {
        printf("nieprawidlowe dane, sprobuj ponownie\n");
        while(getchar()!='\n');
    }
    printf("wprowadz status wynalazku (prototyp, testowany, dopuszczony, zakazany, niestabilny)\n");
    while(scanf("%20s",w.status)!=1|| (strcmp(w.status,"prototyp")!=0&&strcmp(w.status,"testowany")!=0&&
          strcmp(w.status,"dopuszczony")!=0&&strcmp(w.status,"zakazany")!=0&&strcmp(w.status,"niestabilny")!=0))
    {
        printf("nieprawidlowe dane, sprobuj ponownie\n");
        while(getchar()!='\n');
    }
    //przekazanie wynalazku w do funkcji dodaj_wynalazek
    head=dodaj_wynalazek(head,w);
    return head;
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
                while(scanf("%101s",to_edit->x.nazwa)!=1)
                {
                    printf("nieprawidlowe dane, sprobuj ponownie\n");
                    while(getchar()!='\n');
                }
                break;
            case 2:
                printf("wprowadz nowy typ wynalazku\n");
                while(scanf("%101s",to_edit->x.typ)!=1)
                {
                    printf("nieprawidlowe dane, sprobuj ponownie\n");
                    while(getchar()!='\n');
                }
                break;
            case 3:
                printf("wprowadz nowa niezawodnosc wynalazku (0-100)\n");
                while(scanf("%d",&to_edit->x.niezawodnosc)!=1||to_edit->x.niezawodnosc<0||to_edit->x.niezawodnosc>100)
                {
                    printf("nieprawidlowe dane, sprobuj ponownie\n");
                    while(getchar()!='\n');
                }
                break;
            case 4:
                printf("wprowadz nowa potencjalna energie wynalazku\n");
                while(scanf("%d",&to_edit->x.pot_energia)!=1)
                {
                    printf("nieprawidlowe dane, sprobuj ponownie\n");
                    while(getchar()!='\n');
                }
                break;
            case 5:
                printf("wprowadz nowy status wynalazku (prototyp, testowany, dopuszczony, zakazany, niestabilny)\n");
                while(scanf("%20s",to_edit->x.status)!=1|| (strcmp(to_edit->x.status,"prototyp")!=0&&strcmp(to_edit->x.status,"testowany")!=0&&
                      strcmp(to_edit->x.status,"dopuszczony")!=0&&strcmp(to_edit->x.status,"zakazany")!=0&&strcmp(to_edit->x.status,"niestabilny")!=0))
                {
                    printf("nieprawidlowe dane, sprobuj ponownie\n");
                    while(getchar()!='\n');
                }
                break;
            case 0:
                printf("edycja zakonczona\n");
                break;
            default:
                printf("nieprawidlowy wybor\n");
        }
    }
}
int czy_mozna_usunac(Node* rozwazany)
{ 
    if(strcmp(rozwazany->x.status,"zakazany")==0||strcmp(rozwazany->x.status,"niestabilny")==0)
    {
        printf("Nie mozna usunac wynalazku o statusie zakazany lub niestabilny\n");
        return 0;
    }
    else
    {
        return 1;
    }
}
Node* usun_wynalazek(Node* head, char* nazwa_usuwanego)
{
    if (head == NULL)
    {return head;}
    if(strcmp(head->x.nazwa,nazwa_usuwanego)==0&&czy_mozna_usunac(head)==1)
    {
        Node* next = head->next;
        free(head);
        return next;
    }
    Node* obecny = head;
    while(obecny->next!=NULL&&strcmp((obecny->next)->x.nazwa,nazwa_usuwanego)!=0)
    {obecny=obecny->next;}
    if(obecny->next!=NULL&&czy_mozna_usunac(obecny->next)==1)
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
Node* usun_wiele(Node* head, char* typ_usuwanego)
{
    int licz=0;
    if(head==NULL)
    {
        printf("usunieto %d obiektow\n",licz);
        return head;
    }
    while(head!=0&&strcmp(head->x.typ,typ_usuwanego)==0&&czy_mozna_usunac(head)==1)
    {
        Node* next=head->next;
        free(head);
        head=next;
        licz++;
    }
    Node* obecny=head;
    while(obecny->next!=NULL)
    {
        if(strcmp((obecny->next)->x.typ,typ_usuwanego)==0&&czy_mozna_usunac(obecny->next)==1)
        {
            Node* do_usuniecia=obecny->next;
            obecny->next=do_usuniecia->next;
            free(do_usuniecia);
            licz++;
        }
        else
        {
            obecny=obecny->next;
        }
    }
    printf("usunieto %d obiektow\n",licz);
    return head;
}
void wyswietl_wszystkie(Node* head)
{
    Node* obecny=head;
    if(obecny==NULL)
    {
        printf("brak wynalazkow w bazie danych\n");
        return;
    }
    while(obecny!=NULL)
    {
        printf("Wynalazek: %s, Typ: %s, Niezawodnosc: %d, Energia potencjalna: %d, Status: %s\n",
               obecny->x.nazwa, obecny->x.typ, obecny->x.niezawodnosc,
               obecny->x.pot_energia, obecny->x.status);
        obecny=obecny->next;
    }
}
void sortuj_alfabetycznie(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    int zamiany;
    Node* zamieniany;
    do
    {
        zamiany=0;
        zamieniany=head;
        while(zamieniany->next!=NULL)
        {
            if(strcmp(zamieniany->x.nazwa,zamieniany->next->x.nazwa)>0)
            {
                wynalazek pom=zamieniany->x;
                zamieniany->x=zamieniany->next->x;
                zamieniany->next->x=pom;
                zamiany++;
            }
            zamieniany=zamieniany->next;
        }

    } while (zamiany!=0);
    
}
void sortuj_niezawodnosc(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    int zamiany;
    Node* zamieniany;
    do
    {
        zamiany=0;
        zamieniany=head;
        while(zamieniany->next!=NULL)
        {
            if(zamieniany->x.niezawodnosc>zamieniany->next->x.niezawodnosc)
            {
                wynalazek pom=zamieniany->x;
                zamieniany->x=zamieniany->next->x;
                zamieniany->next->x=pom;
                zamiany++;
            }
            zamieniany=zamieniany->next;
        }

    } while (zamiany!=0);
    
}
void raport(Node* head)
{
    int total=0;
    int prototypy=0;
    int testowane=0;
    int dopuszczone=0;
    int zakazane=0;
    int niestabilne=0;
    Node* obecny=head;
    while(obecny!=NULL)
    {
        total++;
        if(strcmp(obecny->x.status,"prototyp")==0)
        {
            prototypy++;
        }
        else if(strcmp(obecny->x.status,"testowany")==0)
        {
            testowane++;
        }
        else if(strcmp(obecny->x.status,"dopuszczony")==0)
        {
            dopuszczone++;
        }
        else if(strcmp(obecny->x.status,"zakazany")==0)
        {
            zakazane++;
        }
        else if(strcmp(obecny->x.status,"niestabilny")==0)
        {
            niestabilne++;
        }
        obecny=obecny->next;
    }
    printf("Raport wynalazkow:\n");
    printf("Laczna liczba wynalazkow: %d\n",total);
    printf("Prototypy: %d\n",prototypy);
    printf("Testowane: %d\n",testowane);
    printf("Dopuszczone: %d\n",dopuszczone);
    printf("Zakazane: %d\n",zakazane);
    printf("Niestabilne: %d\n",niestabilne);
}