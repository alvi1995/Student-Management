#include "otherHeaders.h"
#include "variable.h"
#include "functions.h"

extern student s;

void edit_record(void)
{
    FILE *fp, *nentry;
    char ch;
    int i, c, cold, cnew;

    fp = fopen("sdatabase","ab+");


    if(fp == NULL)
    {
        printf("Error: Cannot Open File <sdatatbase>\n");
        return;
    }

    nentry = fopen("totalentry","rb");
    if(fread(&tentry, sizeof(tentry), 1 , nentry) != 1)
    {
        tentry = 0;
    }

    fclose(nentry);

    do
    {
        gotoxy(125,10);
        printf("Enter Roll No:");
        scanf("%d", &s.rno);

        while((getchar()) != '\n');

        gotoxy(125,12);
        printf("Enter Name:");
        gets(s.name);
        gotoxy(125,14);
        printf("Enter Section:");
        gets(s.section);

        gotoxy(125,16);
        printf("Enter Subject Marks-\n");

        gotoxy(68,20);
        printf("|");
        i = 0;
        for (c = 68; c < 242; c = c + 29)
        {
            cold = c;
            cnew  = cold + 29;
            gotoxy((cold+cnew)/2-6,20);
            printf("%s(%d)", s.subject[i].title, s.subject[i].code);

            i++;
            if ( i > 6)
            {
                break;
            }

            gotoxy(cnew,20);
            printf("|");
        }

        gotoxy(68,21);
        for(i = 68; i < 243; i++)
        {
            printf("-");
        }

        gotoxy(68,22);
        printf("|");
        i = 0;
        for (int c = 68; c < 242; c = c + 29)
        {
            cold = c;
            cnew  = cold + 29;
            gotoxy((cold+cnew)/2-2,22);
            scanf("%d", &s.subject[i].marks);

            i++;
            if ( i > 6)
            {
                break;
            }

            gotoxy(cnew,22);
            printf("|");
        }


        s.avg = 0;
        for(i = 0; i < 6; i++)
        {
            s.avg = s.avg + s.subject[i].marks;
        }

        fwrite(&s, sizeof(s), 1, fp);

        tentry++;

        gotoxy(120,24);
        printf("Do you want to add more(y/n):");
        ch = getche();

        system("cls");

    }while(ch != 'n');

    fclose(fp);

    nentry = fopen("totalentry", "wb+");

    if(nentry == NULL)
    {
        printf("<totalentry> file does not exit>");
        return;
    }
    fwrite(&tentry, sizeof(tentry), 1, nentry);

    fclose(nentry);

}

