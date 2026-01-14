#include<stdio.h>
#include"menu.h" 
#include"database.h"
#include"fileio.h" 
int main() {
    int wybor;
    wybor=menu();
    Node* head = NULL;
    obsluga_menu(wybor, head);

    return 0;
}