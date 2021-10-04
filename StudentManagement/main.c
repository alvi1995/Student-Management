#include "otherHeaders.h"
#include "variable.h"
#include "functions.h"


student s;

int main()
{
    int i;

    char subjtitle[][60] = { //subject title
    "Math",
    "Physics",
    "Mechanics",
    "Chemistry",
    "English",
    "Fuck"
    };

    int subjcode[] = { // subject code
        1000,
        1001,
        1002,
        1003,
        1004,
        1005
    };

    for (i = 0; i < 6; i++)
    {
        strcpy(s.subject[i].title,subjtitle[i]);
        s.subject[i].code = subjcode[i];
    }

    title();

    system("cls");

    menu();

    system("cls");

    printf("Program Exited Successfully..");

    return 0;
}
