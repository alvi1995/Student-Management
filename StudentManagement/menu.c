#include "otherHeaders.h"
//#include "variable.h"
#include "functions.h"


void menu(void)
{
    int choice;

    do
    {
        gotoxy(125,10);
        printf("Menu-\n");
        gotoxy(125,12);
        printf("1. Edit Student Record\n");
        gotoxy(125,14);
        printf("2. List Student Record\n");
        gotoxy(125,16);
        printf("3. Search Student Record\n");
        gotoxy(125,18);
        printf("4. Delete Student Record\n");
        gotoxy(125,20);
        printf("5. Update Student Record\n");
        gotoxy(125,22);
        printf("6. Sort Student Record\n");
        gotoxy(125,24);
        printf("7. Exit\n");

        gotoxy(125,26);
        printf("Command:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            system("cls");
            edit_record();
            break;
        case 2:
            system("cls");
            display_record();
            break;
        }

        system("cls");

    }while(choice != 7);
}
