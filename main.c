//Anna Sawczuk ps6 temat 7
#include<stdio.h>
#include"menu.h" 
#include"database.h"
#include"fileio.h" 
int main() {
    int wybor=-1;
    Node* head = NULL;
    while(wybor!=0)
    {
        wybor=menu();
        head=obsluga_menu(wybor, head);
    }
    return 0;
}