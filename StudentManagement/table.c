#include "functions.h"
#include "otherHeaders.h"
#include "variable.h"

extern student s;

void thorline(int r, int c) // Triple Horizontal Line
{
    int i;

    for (i = 0; i < 3; i++)
    {
        gotoxy(r,c);
        printf("|");
        c++;
    }
}

void table(void)
{
     int i;

     gotoxy(0,6);
     for(i=0; i<=251; i++)
     {
         printf("-");
     }

     gotoxy(2,4);
     printf("No");
     thorline(5,3);

     gotoxy(23,4);
     printf("Name");
     thorline(46,3);

     gotoxy(49,4);
     printf("Roll");
     thorline(55,3);

     gotoxy(58,4);
     printf("Section");
     thorline(67,3);

     gotoxy(125,3);
     printf("Marks");
     thorline(242,3);

     gotoxy(68,4);
     for (i = 68; i < 242; i++)
     {
        printf("-");
     }


    int cold, cnew;

    i = 0;
    for (int c = 68; c < 242; c = c + 29)
    {
        cold = c;
        cnew  = cold + 29;
        gotoxy((cold+cnew)/2-6,5);
        printf("%s(%d)", s.subject[i].title, s.subject[i].code);

        i++;
        if ( i > 6)
        {
            break;
        }

        gotoxy(cnew,5);
        printf("|");
    }

     gotoxy(246,4);
     printf("avg");
     thorline(251,3);

     char ch = getche();
}
