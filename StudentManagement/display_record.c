#include "otherHeaders.h"
#include "variable.h"
#include "functions.h"

extern student s;

void display_record(void)
{
    int r;
    FILE *fp, *nentry;

    nentry = fopen("totalentry","rb");
    if(nentry == NULL)
    {
        printf("Cannot Open File <totalentry>");
        return;
    }

    if(fread(&tentry, sizeof(tentry), 1 , nentry) != 1)
    {
        printf("No data exist.Add some data");
        char ch = getche();
        return;
    }
    fclose(nentry);

    fp = fopen("sdatabase", "rb");

    if(fp == NULL)
    {
        printf("Error: Cannot Open File <sdatatbase> or <sdatabase> does not exist");
        return;
    }

    table();
    r = tentry;
    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        r = tentry - r + 1;
        gotoxy(2,7 + r - 1);
        printf("%d", r);
        r--;
    }

    fclose(fp);
}
