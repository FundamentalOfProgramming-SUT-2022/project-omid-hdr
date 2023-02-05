#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#include <dirent.h>
#define max 1000

FILE* omid;

FILE* tamp;

char clipboard[10000] = {0};

int line;
int number;
char harz[max];

void createfile()
{
    char daf[6] = "-file";
    char adr[max] = {0};
    char inp[max] = {0};
    char timp[max] = {0};
    char tmp[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    ////////////
    fgets(adr, max, stdin);
    int d = strlen(adr);
    if(cot)
    {
        if('"' != adr[d - 2])
        {
            printf("you forgot the second \"\n");
            return 0;
        }
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            mkdir(inp);
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r"))
        {
            printf("The File already exist!\n");
            return 0;
        }
        omid = fopen(inp, "w");
        fclose(omid);
        i = 0;
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        tmp[strlen(inp) - 4] = '\0';
        while (tmp[i] != '\0')
        {
            while(!(tmp[i] == '/' || tmp[i] == '\0'))
            {
                sprintf(timp,"%s%c", timp, tmp[i]);
                i++;
            }
            if(tmp[i] == '\0')
                break;
            mkdir(timp);
            timp[i] = tmp[i];
            i++;
        }
        omid = fopen(tmp, "w");
        fclose(omid);
    }
    else
    {
        while (adr[i] != '\n')
        {
            while(!(adr[i] == '/' || adr[i] == '\n'))
            {
                if(adr[i] == ' ')
                {
                    printf("You can't use space without \".\n");
                    return 0;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '\n')
                break;
            mkdir(inp);
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r"))
        {
            printf("The File already exist!\n");
            return 0;
        }
        omid = fopen(inp, "w");
        fclose(omid);
        ////////
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        i = 0;
        while (tmp[i] != '\0')
        {
            while(!(tmp[i] == '/' || tmp[i] == '\0'))
            {
                sprintf(timp,"%s%c", timp, tmp[i]);
                i++;
            }
            if(tmp[i] == '\0')
                break;
            mkdir(timp);
            timp[i] = tmp[i];
            i++;
        }
        omid = fopen(tmp, "w");
        close(omid);
    }
    printf("success\n");
    return 0;
}

////////

void insertstr()
{
    char daf[6] = "-file";
    char das[5] = "-str";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char str2[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dasin[5];
        fgets(dasin, 5, stdin);
        if (strcmp(dasin, das))
        {
            printf("invalid command!need \"-str\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }


        str[0] = getchar();
        if (str[0] == '"')
        {
            int q = 0;
            while(1)
            {
                str[q] = getchar();
                if(str[q] == '\\')
                {
                    q++;
                    str[q] = getchar();
                    if(str[q] == '"')
                    {
                        str[q - 1] = '"';
                        q--;
                    }
                }
                else if(str[q] == '"')
                {
                    str[q] = '\0';
                    break;
                }
                q++;
            }
        }
        else
        {
            scanf("%s", str2);
            strcat(str, str2);
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '\\')
            {
                if(str[i + 1] == 'n')
                {
                    str[i] = '\n';
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
                else if (str[i + 1] == '\\')
                {
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
            }
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dapin[5];
        fgets(dapin, 5, stdin);
        if (strcmp(dapin, dap))
        {
            printf("invalid command!need \"-pos\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        scanf("%d:%d", &line, &number);
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        /////
        tamp = fopen(tmp, "w");
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        fputs(str, tamp);
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        fclose(omid);
        fclose(tamp);
        omid = fopen(inp, "r+");
        tamp = fopen(tmp, "r+");
        char all[1000] = {0};
        g = fgetc(tamp);
        int v = 0;
        while (g != EOF)
        {
            all[v] = g;
            g = fgetc(tamp);
            v++;
        }
        all[v] = '\0';
        char all2[1000] = {0};
        g = fgetc(omid);
        v = 0;
        while (g != EOF)
        {
            all2[v] = g;
            g = fgetc(omid);
            v++;
        }
        all2[v] = '\0';
        getchar();
        fclose(omid);
        omid = fopen(inp, "w");
        fputs(all, omid);
        fclose(tamp);
        tamp = fopen(tmp, "w");
        fputs(all2, tamp);
        fclose(omid);
        fclose(tamp);
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");

        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dasin[5];
        fgets(dasin, 5, stdin);
        if (strcmp(dasin, das))
        {
            printf("invalid command!need \"-str\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        str[0] = getchar();
        if (str[0] == '"')
        {
            int q = 0;
            while(1)
            {
                str[q] = getchar();
                if(str[q] == '\\')
                {
                    q++;
                    str[q] = getchar();
                    if(str[q] == '"')
                    {
                        str[q - 1] = '"';
                        q--;
                    }
                }
                else if(str[q] == '"')
                {
                    str[q] = '\0';
                    break;
                }
                q++;
            }
        }
        else
        {
            scanf("%s", str2);
            strcat(str, str2);
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '\\')
            {
                if(str[i + 1] == 'n')
                {
                    str[i] = '\n';
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
                else if (str[i + 1] == '\\')
                {
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
            }
        }

        //////

        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dapin[5];
        fgets(dapin, 5, stdin);
        if (strcmp(dapin, dap))
        {
            printf("invalid command!need \"-pos\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        scanf("%d:%d", &line, &number);
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        tamp = fopen(tmp, "w");
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        fputs(str, tamp);
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        getchar();
        fclose(omid);
        fclose(tamp);
        omid = fopen(inp, "r+");
        tamp = fopen(tmp, "r+");
        char all[1000] = {0};
        g = fgetc(tamp);
        int v = 0;
        while (g != EOF)
        {
            all[v] = g;
            g = fgetc(tamp);
            v++;
        }
        all[v] = '\0';
        char all2[1000] = {0};
        g = fgetc(omid);
        v = 0;
        while (g != EOF)
        {
            all2[v] = g;
            g = fgetc(omid);
            v++;
        }
        all2[v] = '\0';
        fclose(omid);
        omid = fopen(inp, "w");
        fputs(all, omid);
        fclose(tamp);
        tamp = fopen(tmp, "w");
        fputs(all2, tamp);
        fclose(omid);
        fclose(tamp);
    }
    printf("success\n");
    return 0;
}

//////////

void cat()
{
    char daf[6] = "-file";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need spase.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }

    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "r+");
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "r+");
    }
    while(fgets(Line, max, omid) != NULL)
        printf("%s", Line);
    printf("\nsuccess\n");
    return 0;
}

/////////

void Remove()
{
    char daf[6] = "-file";
    char das[6] = "-size";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char str2[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }

    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dapin[5];
    fgets(dapin, 5, stdin);
    if (strcmp(dapin, dap))
    {
        printf("invalid command!need \"-pos\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    scanf("%d:%d", &line, &number);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dasin[6];
    fgets(dasin, 6, stdin);
    if (strcmp(dasin, das))
    {
        printf("invalid command!need \"-size\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int tool;
    scanf("%d", &tool);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != '-')
    {
        printf("invalid command!need \"-\".\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char flag = getchar();
    for(int k = 5; k < strlen(inp); k++)
        tmp[k - 5] = inp[k];
    tmp[strlen(inp) - 4] = '\0';
    /////////////////////
    tamp = fopen(tmp, "w");

    //////
    if(flag == 'b')
    {
        if (tool < number)
        {
            for (int j = 0; j < line - 1; j++)
            {
                fgets(Line, max, omid);
                fputs(Line, tamp);
            }
            char g;

            for (int z = 0; z < number - tool; z++)
            {
                g = fgetc(omid);
                fputc(g, tamp);
            }
            for (int z = 0; z < tool; z++)
            {
                g = fgetc(omid);
            }
            g = fgetc(omid);
            while (g != EOF)
            {
                fputc(g, tamp);
                g = fgetc(omid);
            }
            fclose(omid);
            fclose(tamp);
        }
        else
        {
            for (int j = 0; j < line - 2; j++)
            {
                fgets(Line, max, omid);
                fputs(Line, tamp);
            }
            fgets(Line, max, omid);
            int d = strlen(Line);
            fclose(omid);
            omid = fopen(inp, "a+");
            for (int k = 0; k < line - 2; k++)
                fgets(Line, max, omid);
            char g;
            for ( int z = 0; z < d + number - tool; z++)
            {
                g = fgetc(omid);
                fputc(g, tamp);
            }
            for (int z = 0; z < tool; z++)
            {
                g = fgetc(omid);
            }
            g = fgetc(omid);
            while (g != EOF)
            {
                fputc(g, tamp);
                g = fgetc(omid);
            }
            fclose(omid);
            fclose(tamp);
        }
    }
    else if(flag == 'f')
    {
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        for (int z = 0; z < tool; z++)
        {
            g = fgetc(omid);
        }
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        fclose(omid);
        fclose(tamp);
    }
    else
    {
        printf("wrong flag!\n");
        fclose(omid);
        fclose(tamp);
        return 0;
    }
    omid = fopen(inp, "r+");
    tamp = fopen(tmp, "r+");
    char all[1000] = {0};
    char g = fgetc(tamp);
    int v = 0;
    while (g != EOF)
    {
        all[v] = g;
        g = fgetc(tamp);
        v++;
    }
    all[v] = '\0';
    char all2[1000] = {0};
    g = fgetc(omid);
    v = 0;
    while (g != EOF)
    {
        all2[v] = g;
        g = fgetc(omid);
        v++;
    }
    all2[v] = '\0';
    fclose(omid);
    omid = fopen(inp, "w");
    fputs(all, omid);
    fclose(tamp);
    tamp = fopen(tmp, "w");
    fputs(all2, tamp);
    fclose(omid);
    fclose(tamp);

    printf("success\n");
    return 0;
}

void Copy()
{
    memset(clipboard, '\0', 1000);
    char daf[6] = "-file";
    char das[6] = "-size";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char str2[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }

    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dapin[5];
    fgets(dapin, 5, stdin);
    if (strcmp(dapin, dap))
    {
        printf("invalid command!need \"-pos\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    scanf("%d:%d", &line, &number);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dasin[6];
    fgets(dasin, 6, stdin);
    if (strcmp(dasin, das))
    {
        printf("invalid command!need \"-size\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int tool;
    scanf("%d", &tool);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != '-')
    {
        printf("invalid command!need \"-\".\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char flag = getchar();
    /////////////////////
    if(flag == 'b')
    {
        if (tool < number)
        {
            for (int j = 0; j < line - 1; j++)
            {
                fgets(Line, max, omid);
            }
            char g;

            for (int z = 0; z < number - tool; z++)
            {
                g = fgetc(omid);
            }
            for (int z = 0; z < tool; z++)
            {
                clipboard[z] = fgetc(omid);
            }
            clipboard[tool] = '\0';
            fclose(omid);
        }
        else
        {
            for (int j = 0; j < line - 2; j++)
            {
                fgets(Line, max, omid);
            }
            fgets(Line, max, omid);
            int d = strlen(Line);
            fclose(omid);
            omid = fopen(inp, "a+");
            for (int k = 0; k < line - 2; k++)
                fgets(Line, max, omid);
            char g;
            for ( int z = 0; z < d + number - tool; z++)
            {
                g = fgetc(omid);
            }
            for (int z = 0; z < tool; z++)
            {
                clipboard[z] = fgetc(omid);
            }
            clipboard[tool] = '\0';
            fclose(omid);
        }
    }
    else if(flag == 'f')
    {
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
        }
        for (int z = 0; z < tool; z++)
        {
            clipboard[z] = fgetc(omid);
        }
        clipboard[tool] = '\0';
        fclose(omid);
    }
    else
    {
        printf("wrong flag!\n");
        fclose(omid);
        return 0;
    }
    printf("success.\n");
    return 0;
}

void Cut()
{
    memset(clipboard, '\0', 1000);
    char daf[6] = "-file";
    char das[6] = "-size";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char str2[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dapin[5];
    fgets(dapin, 5, stdin);
    if (strcmp(dapin, dap))
    {
        printf("invalid command!need \"-pos\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    scanf("%d:%d", &line, &number);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dasin[6];
    fgets(dasin, 6, stdin);
    if (strcmp(dasin, das))
    {
        printf("invalid command!need \"-size\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int tool;
    scanf("%d", &tool);
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != '-')
    {
        printf("invalid command!need \"-\".\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char flag = getchar();
    for(int k = 5; k < strlen(inp); k++)
        tmp[k - 5] = inp[k];
    tmp[strlen(inp) - 4] = '\0';
    /////////////////////
    tamp = fopen(tmp, "w");

    //////

    if(flag == 'b')
    {
        if (tool < number)
        {
            for (int j = 0; j < line - 1; j++)
            {
                fgets(Line, max, omid);
                fputs(Line, tamp);
            }
            char g;

            for (int z = 0; z < number - tool; z++)
            {
                g = fgetc(omid);
                fputc(g, tamp);
            }
            for (int z = 0; z < tool; z++)
            {
                clipboard[z] = fgetc(omid);
            }
            clipboard[tool] = '\0';
            g = fgetc(omid);
            while (g != EOF)
            {
                fputc(g, tamp);
                g = fgetc(omid);
            }
            fclose(omid);
            fclose(tamp);
        }
        else
        {
            for (int j = 0; j < line - 2; j++)
            {
                fgets(Line, max, omid);
                fputs(Line, tamp);
            }
            fgets(Line, max, omid);
            int d = strlen(Line);
            fclose(omid);
            omid = fopen(inp, "a+");
            for (int k = 0; k < line - 2; k++)
                fgets(Line, max, omid);
            char g;
            for ( int z = 0; z < d + number - tool; z++)
            {
                g = fgetc(omid);
                fputc(g, tamp);
            }
            for (int z = 0; z < tool; z++)
            {
                clipboard[z] = fgetc(omid);
            }
            clipboard[tool] = '\0';
            g = fgetc(omid);
            while (g != EOF)
            {
                fputc(g, tamp);
                g = fgetc(omid);
            }
            fclose(omid);
            fclose(tamp);
        }
    }
    else if(flag == 'f')
    {
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        for (int z = 0; z < tool; z++)
        {
            clipboard[z] = fgetc(omid);
        }
        clipboard[tool] = '\0';
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        fclose(omid);
        fclose(tamp);
    }
    else
    {
        printf("wrong flag!\n");
        fclose(omid);
        fclose(tamp);
        return 0;
    }
    omid = fopen(inp, "r+");
    tamp = fopen(tmp, "r+");
    char all[1000] = {0};
    char g = fgetc(tamp);
    int v = 0;
    while (g != EOF)
    {
        all[v] = g;
        g = fgetc(tamp);
        v++;
    }
    all[v] = '\0';
    char all2[1000] = {0};
    g = fgetc(omid);
    v = 0;
    while (g != EOF)
    {
        all2[v] = g;
        g = fgetc(omid);
        v++;
    }
    all2[v] = '\0';
    fclose(omid);
    omid = fopen(inp, "w");
    fputs(all, omid);
    fclose(tamp);
    tamp = fopen(tmp, "w");
    fputs(all2, tamp);
    fclose(omid);
    fclose(tamp);
    printf("success\n");
    return 0;
}

void paste()
{
    char daf[6] = "-file";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }


    if(cot)
    {
        scanf("%s[^\"]", adr);
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dapin[5];
        fgets(dapin, 5, stdin);
        if (strcmp(dapin, dap))
        {
            printf("invalid command!need \"-pos\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        scanf("%d:%d", &line, &number);
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        tmp[strlen(inp) - 4] = '\0';
        /////
        tamp = fopen(tmp, "w");
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        fputs(str, tamp);
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        fclose(omid);
        fclose(tamp);
        omid = fopen(inp, "a+");
        tamp = fopen(tmp, "a+");
        char all[1000] = {0};
        g = fgetc(tamp);
        int v = 0;
        while (g != EOF)
        {
            all[v] = g;
            g = fgetc(tamp);
            v++;
        }
        all[v] = '\0';
        char all2[1000] = {0};
        g = fgetc(omid);
        v = 0;
        while (g != EOF)
        {
            all2[v] = g;
            g = fgetc(omid);
            v++;
        }
        all2[v] = '\0';
        getchar();
        fclose(omid);
        omid = fopen(inp, "w");
        fputs(all, omid);
        fclose(tamp);
        tamp = fopen(tmp, "w");
        fputs(all2, tamp);
        fclose(omid);
        fclose(tamp);
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");

        if (getchar() != ' ')
        {
            printf("invalid command!need space2.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        strcpy(str, clipboard);
        char dapin[5];
        fgets(dapin, 5, stdin);
        if (strcmp(dapin, dap))
        {
            printf("invalid command!need \"-pos\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space3.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        scanf("%d:%d", &line, &number);
        for(int k = 5; k < strlen(inp); k++)
            tmp[k - 5] = inp[k];
        tamp = fopen(tmp, "w");
        for (int j = 0; j < line - 1; j++)
        {
            fgets(Line, max, omid);
            fputs(Line, tamp);
        }
        char g;
        for (int z = 0; z < number; z++)
        {
            g = fgetc(omid);
            fputc(g, tamp);
        }
        fputs(str, tamp);
        g = fgetc(omid);
        while (g != EOF)
        {
            fputc(g, tamp);
            g = fgetc(omid);
        }
        getchar();
        fclose(omid);
        fclose(tamp);
        omid = fopen(inp, "a+");
        tamp = fopen(tmp, "a+");
        char all[1000] = {0};
        g = fgetc(tamp);
        int v = 0;
        while (g != EOF)
        {
            all[v] = g;
            g = fgetc(tamp);
            v++;
        }
        all[v] = '\0';
        char all2[1000] = {0};
        g = fgetc(omid);
        v = 0;
        while (g != EOF)
        {
            all2[v] = g;
            g = fgetc(omid);
            v++;
        }
        all2[v] = '\0';
        fclose(omid);
        omid = fopen(inp, "w");
        fputs(all, omid);
        fclose(tamp);
        tamp = fopen(tmp, "w");
        fputs(all2, tamp);
        fclose(omid);
        fclose(tamp);
    }
    printf("success\n");
    return 0;
}

void undo()
{
    char daf[6] = "-file";;
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }

    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
    }
    for(int k = 5; k < strlen(inp); k++)
        tmp[k - 5] = inp[k];
    tmp[strlen(inp) - 4] = '\0';
    char g;
    tamp = fopen(tmp, "r+");
    char all[1000] = {0};
    g = fgetc(tamp);
    int v = 0;
    while (g != EOF)
    {
        all[v] = g;
        g = fgetc(tamp);
        v++;
    }
    all[v] = '\0';
    char all2[1000] = {0};
    g = fgetc(omid);
    v = 0;
    while (g != EOF)
    {
        all2[v] = g;
        g = fgetc(omid);
        v++;
    }
    all2[v] = '\0';
    fclose(omid);
    omid = fopen(inp, "w");
    fputs(all, omid);
    fclose(tamp);
    tamp = fopen(tmp, "w");
    fputs(all2, tamp);
    fclose(omid);
    fclose(tamp);
    printf("success.\n");
    return 0;
}

void findd()
{
    char daf[6] = "-file";
    char das[5] = "-str";
    char dap[5] = "-pos";
    char adr[max] = {0};
    char tmp[max] = {0};
    char inp[max] = {0};
    char str[max] = {0};
    char str2[max] = {0};
    char Line[max] = {0};
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    char dafin[6];
    fgets(dafin, 6, stdin);
    if (strcmp(dafin, daf))
    {
        printf("invalid command!need \"-file\"\n");
        fgets(harz, max, stdin);
        return 0;
    }
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dasin[5];
        fgets(dasin, 5, stdin);
        if (strcmp(dasin, das))
        {
            printf("invalid command!need \"-str\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }


        str[0] = getchar();
        if (str[0] == '"')
        {
            int q = 0;
            while(1)
            {
                str[q] = getchar();
                if(str[q] == '\\')
                {
                    q++;
                    str[q] = getchar();
                    if(str[q] == '"')
                    {
                        str[q - 1] = '"';
                        q--;
                    }
                }
                else if(str[q] == '"')
                {
                    str[q] = '\0';
                    break;
                }
                q++;
            }
        }
        else
        {
            scanf("%s", str2);
            strcat(str, str2);
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '\\')
            {
                if(str[i + 1] == 'n')
                {
                    str[i] = '\n';
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
                else if (str[i + 1] == '\\')
                {
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
            }
        }
    }
    else
    {
        scanf("%s", adr);
        int p = strlen(adr);
        while (i < p)
        {
            while(adr[i] != '/')
            {
                if(i == p)
                {
                    inp[i] = '\0';
                    break;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            sprintf(inp,"%s%c", inp, adr[i]);
            i++;
        }

        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        omid = fopen(inp, "a+");

        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        char dasin[5];
        fgets(dasin, 5, stdin);
        if (strcmp(dasin, das))
        {
            printf("invalid command!need \"-str\"\n");
            fgets(harz, max, stdin);
            return 0;
        }
        if (getchar() != ' ')
        {
            printf("invalid command!need space.\n");
            fgets(harz, max, stdin);
            return 0;
        }
        str[0] = getchar();
        if (str[0] == '"')
        {
            int q = 0;
            while(1)
            {
                str[q] = getchar();
                if(str[q] == '\\')
                {
                    q++;
                    str[q] = getchar();
                    if(str[q] == '"')
                    {
                        str[q - 1] = '"';
                        q--;
                    }
                }
                else if(str[q] == '"')
                {
                    str[q] = '\0';
                    break;
                }
                q++;
            }
        }
        else
        {
            scanf("%s", str2);
            strcat(str, str2);
        }
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '\\')
            {
                if(str[i + 1] == 'n')
                {
                    str[i] = '\n';
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
                else if (str[i + 1] == '\\')
                {
                    i++;
                    while(str[i + 1] != '\0')
                    {
                        str[i] = str[i + 1];
                        i++;
                    }
                    str[i] = '\0';
                    break;
                }
            }
        }
    }
    //find(str);
    //printf("success\n");
    printf("narasidam!");
    return 0;
}


void getaddres()
{
    char adr[max];
    char inp[max];
    int i = 0;
    int cot = 0;
    ////////////
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
        else
        {
            scanf("%s", inp);
        }
        omid = fopen(inp, "r+");
        //naresidam ghashangh konam...
    }
}

void Indent(char car[])
{
    for (int i = 0; car[i] != '\0'; i++)
    {
        if ((car[i] == ' ' || car[i] == '\n') && (car[i - 1] == '{' || car[i - 1] == '}'))
        {
            memmove(&car[i], &car[i + 1], strlen(car) - i);
            i--;
        }
        else if ((car[i] == ' ' || car[i] == '\n') && (car[i + 1] == '{' || car[i + 1] == '}'))
        {
            memmove(&car[i], &car[i + 1], strlen(car) - i);
            i -= 2;
        }
    }
    int cc = 0;
    for (int i = 0; car[i] != '\0'; i++)
    {
        if (car[i] == '{')
        {
            if (i != 0 && car[i - 1] != '\n' && car[i - 1] != ' ')
            {
                memmove(&car[i + 1], &car[i], strlen(car) - i + 1);
                car[i] = ' ';
                i++;
            }
            cc++;
            if (car[i + 1] == '}')
            {
                memmove(&car[4 * (cc - 1) + i + 2], &car[i + 1], strlen(car) - i);
                car[i + 1] = '\n';
                i++;
                for (int j = 0; j < 4 * (cc - 1); j++)
                {
                    car[i + 1] = ' ';
                    i++;
                }
            }
            else
            {
                memmove(&car[4 * cc + i + 2], &car[i + 1], strlen(car) - i);
                car[i + 1] = '\n';
                i++;
                for (int j = 0; j < 4 * cc; j++)
                {
                    car[i + 1] = ' ';
                    i++;
                }
            }
        }
        else if (car[i] == '}')
        {
            if (car[i - 1] != '\n' && car[i - 1] != ' ')
            {
                memmove(&car[4 * (cc - 1) + i + 1], &car[i], strlen(car) - i + 1);
                car[i] = '\n';
                i++;
                for (int j = 0; j < 4 * (cc - 1); j++)
                {
                    car[i] = ' ';
                    i++;
                }
            }
            cc--;
            if (car[i + 1] == '}')
            {
                memmove(&car[4 * (cc - 1) + i + 2], &car[i + 1], strlen(car) - i);
                car[i + 1] = '\n';
                i++;
                for (int j = 0; j < 4 * (cc - 1); j++)
                {
                    car[i + 1] = ' ';
                    i++;
                }
            }
            else if (car[i + 1] == ' ' || car[i + 1] == '\n' || car[i + 1] == '\0')
            {
            }
            else
            {
                memmove(&car[4 * cc + i + 2], &car[i + 1], strlen(car) - i);
                car[i + 1] = '\n';
                i++;
                for (int j = 0; j < 4 * cc; j++)
                {
                    car[i + 1] = ' ';
                    i++;
                }
            }
        }
    }
}

void indent(char in[])  //help!
{
    if (in[0] == '"')
    {
        in[strlen(in) - 1] = '\0';
        memmove(&in[0], &in[2], strlen(in) - 1);
    }
    else if (in[0] == '/')
    {
        memmove(&in[0], &in[1], strlen(in));
    }
    if (fopen(in, "r") == 0)
    {
        printf("The file don't exit!\n");//////////
        return;
    }
    FILE *file;
    file = fopen(in, "r+");
    char c;
    int i = 0;
    char car[10000];
    while (1)
    {
        c = fgetc(file);
        if (c == EOF)
            break;
        car[i] = c;
        i++;
        car[i] = '\0';
    }
    fclose(file);
    Indent(car);
    file = fopen(in, "w");
    fprintf(file, "%s", car);
    fclose(file);
}

void compare() //help!
{
    char adr[max] = {0};
    char adr2[max] = {0};
    char tmp[max] = {0};
    char tmp2[max] = {0};
    char inp[max] = {0};
    char inp2[max] = {0};
    char Line[max] = {0};
    getchar();
    int cot = 0;
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        scanf("%[^\"]s", adr);
        sprintf(adr, "%s\"", adr);
        getchar();
        int i = 0;
        while (adr[i] != '"')
        {
            while(!(adr[i] == '/' || adr[i] == '"'))
            {
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '"')
                break;
            if(mkdir(inp) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp);
                return 0;
            }
            inp[i] = adr[i];
            i++;
        }
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
    }
    else
    {
        scanf("%s", inp);
        if(fopen(inp, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }

    }
    omid = fopen(inp, "a+");
    ///////////////
    cot = 0;
    getchar();
    if (getchar() == '"')
    {
        cot++;
        getchar();
    }
    if(cot)
    {
        int i = 0;
        scanf("%[^\"]s", adr2);
        sprintf(adr2, "%s\"", adr2);
        getchar();
        while (adr2[i] != '"')
        {
            while(!(adr2[i] == '/' || adr2[i] == '"'))
            {
                sprintf(inp2,"%s%c", inp2, adr2[i]);
                i++;
            }
            if(adr2[i] == '"')
                break;
            if(mkdir(inp2) == 0)
            {
                printf("incorrect direction!\n");
                fgets(harz, max, stdin);
                rmdir(inp2);
                return 0;
            }
            inp2[i] = adr2[i];
            i++;
        }
        if(fopen(inp2, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }
    }
    else
    {
        scanf("%s", inp2);
        if(fopen(inp2, "r") == 0)
        {
            printf("The File don't exist!\n");
            fgets(harz, max, stdin);
            return 0;
        }

    }
    tamp = fopen(inp2, "a+");
    ////

    int khat = 1;
    char s1[max];
    char s2[max];
    int omid_l = 1;
    int tamp_l = 1;
    while (fgets(s1, max, omid) != NULL)
    {
        omid_l++;
    }
    fseek(omid, 0, SEEK_SET);
    while (fgets(s2, max, tamp) != NULL)
    {
        tamp_l++;
    }
    fseek(tamp, 0, SEEK_SET);
    ///
    while (fgets(s1, max, omid) != NULL && fgets(s2, max, tamp) != NULL)
    {
        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;
        if (strcmp(s1, s2) != 0)
        {
            printf("   === #%d ===\n", khat);
            printf("%s\n", s1);
            printf("%s\n", s2);
        }
        khat++;
    }
    if (fgets(s1, max, omid) == NULL && fgets(s2, max, tamp) != NULL)
    {
        printf("\nFile 2 is bigger\n");
        printf("   >>> #%d - #%d >>>\n", khat, tamp_l);
        fseek(tamp, 0, SEEK_SET);
        for (int i = 0; i < khat - 1; i++)
        {
            fgets(s2, max, tamp);
        }
        while (fgets(s2, max, tamp) != NULL)
        {
            printf("%s", s2);
        }
    }
    else if (fgets(s2, max, tamp) == NULL && fgets(s1, max, omid) != NULL)
    {
        printf("\nFile 1 is bigger\n");
        printf("   >>> #%d - #%d >>>\n", khat, omid_l);
        fseek(omid, 0, SEEK_SET);
        for (int i = 0; i < khat - 1; i++)
        {
            fgets(s1, max, omid);
        }
        while (fgets(s1, max, omid) != NULL)
        {
            printf("%s", s1);
        }
    }
    fclose(omid);
    fclose(tamp);
}


int depth ;
void tree() //help from sites!
{
    if (getchar() != ' ')
    {
        printf("invalid command!need space.\n");
        fgets(harz, max, stdin);
        return 0;
    }
    scanf("%d", &depth);
    if(depth == -1)
    {
        depth = 1000;
        char in[100]= {"D:\\project\\root"};
        listFilesRecursively(in);
    }
    else if(depth > -1)
    {
        char in[100]= {"D:\\project\\root"};
        listFilesRecursively(in);
    }
    else
    {
        printf("wrong depth\n");
    }
}
void listFilesRecursively(char *basein)
{
    char in[1000];
    struct dirent *dp;
    DIR *dir = opendir(basein);
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            int z = 0;
            strcpy(in, basein);
            strcat(in, "\\");
            strcat(in, dp->d_name);

            for(int q = 0 ; in[q] != '\0' ; q++)
            {
                if(in[q] == '\\')
                {
                    z++;
                }
            }
            for(int x = 0 ; x < z - 3 ; x++)
            {
                printf("--");
            }
            printf("%s\n", dp->d_name);
            if(z - 2 <= depth)
                listFilesRecursively(in);
        }
    }
    closedir(dir);
}

void grep(char * str, int flag, int ss)
{
    char z = getchar();
    int mc = 0;
    while (z != '\n')
    {
        int a_m = 0;
        char input[max];
        char c = getchar();
        int cot = 0;
        if (c == '"')
        {
            getchar();
            cot = 1;
        }
        z = getchar();
        int i;
        for (i = 0 ; z != '\n' ; i++)
        {
            *(input + i) = z;
            z = getchar();
            if (z == ' ' && cot == 0)
            {
                i++;
                break;
            }
            if (z == '"' && cot == 1)
            {
                i++;
                break;
            }
        }
        *(input + i) = '\0';
        if (z == '"')
        {
            z = getchar();
        }

        FILE * file = fopen(input, "r");
        if (file == NULL)
        {
            printf("This File Doesn't Exist\n");
            return;
        }
        int pos = 0, tool;
        fseek(file, 0, SEEK_END);
        tool = ftell(file);
        char e = 'a';
        for (pos = 0; pos < tool && e != EOF ; pos++)
        {
            int match = 0;
            if (e == '\n')
            {
                fseek(file, pos + 2, SEEK_SET);
            }
            else
                fseek(file, pos, SEEK_SET);
            for (int j = 0 ; j < ss && e != EOF ; j++)
            {
                e = fgetc(file);
                if (*(str + j) == e)
                {
                    match++;
                }
                else
                    break;
            }
            if (match == ss)
            {
                mc++;
                while (e != '\n' && e != EOF)
                {
                    fseek(file, -2, SEEK_CUR);
                    e = fgetc(file);
                }
                if (e == EOF)
                {
                    fseek(file, 0, SEEK_SET);
                }
                char input_line[max];
                fgets(input_line, max, file);
                e = fgetc(file);
                if (flag == 0)
                {
                    printf("%s: %s", input, input_line);
                    if (ftell(file) == tool)
                    {
                        printf("\n");
                    }
                }
                if (flag == 2 && a_m == 0)
                {
                    printf("%s\n", input);
                }
                a_m = 1;
            }
        }
        fclose(file);
    }
    if (flag == 1)
    {
        printf("%d\n", mc);
    }

}

void gin(int flag) //help!
{
    char str[max];
    int size = 0;
    char c = getchar();
    int cot = 0;
    int i;
    if (c == '"')
    {
        i = 0;
        cot = 1;
    }
    else
    {
        *(str) = c;
        size++;
        i = 1;
    }
    char z = getchar();
    if (z == ' ' && cot == 0)
    {
        str[1] = '\0';
    }
    else
    {
        for (; z != '\n' ; i++)
        {
            *(str + i) = z;
            size++;
            z = getchar();
            if (z == ' ' && cot == 0)
            {
                i++;
                break;
            }
            if (z == '"' && cot == 1)
            {
                i++;
                break;
            }
        }
        *(str + i) = '\0';
        if (z == '"')
        {
            getchar();
        }
    }
    char ic[max];
    scanf("%s", ic);
    if (strcmp(ic, "-files") == 0)
    {
        grep(str, flag, size);
    }
    else
    {
        printf("Invalid Command\n");
        return;
    }

}

void flag_grep()
{
    char flag[max];
    scanf("%s", flag);
    if (strcmp(flag, "-str") == 0)
    {
        getchar();
        gin(0);
    }
    else if (strcmp(flag, "-C") == 0)
    {
        getchar();
        scanf("%s", flag);
        if (strcmp(flag, "-str") == 0)
        {
            getchar();
            gin(1);
        }
        else
        {
            printf("Invalid Command\n");
            return;
        }
    }
    else if (strcmp(flag, "-I") == 0)
    {
        getchar();
        scanf("%s", flag);
        if (strcmp(flag, "-str") == 0)
        {
            getchar();
            gin(2);
        }
        else
        {
            printf("Invalid Command\n");
            return;
        }
    }
    else
    {
        printf("Invalid Command\n");
        return;
    }
}

void replacee()
{
    printf("naresidam!!");
    return 0;
}

int main()
{
    while(1)
    {
        char command[max];
        scanf("%s", command);
        if(!strcmp(command, "createfile"))
            createfile();
        else if(!strcmp(command, "insertstr"))
            insertstr();
        else if(!strcmp(command, "cat"))
            cat();
        else if(!strcmp(command, "removestr"))
            Remove();
        else if(!strcmp(command, "copystr"))
            Copy();
        else if(!strcmp(command, "cutstr"))
            Cut();
        else if(!strcmp(command, "undo"))
            undo();
        else if(!strcmp(command, "pastestr"))
            paste();
        else if(!strcmp(command, "tree"))
            tree();
        else if(!strcmp(command, "auto-indent"))
        {
            getchar();
            char in[1000];
            gets(in);
            indent(in);
        }
        else if(!strcmp(command, "compare"))
            compare();
        else if(!strcmp(command, "find"))
            findd();
        else if(!strcmp(command, "replace"))
            replacee();
        else if (!strcmp(command, "grep"))
        {
            getchar();
            flag_grep();
        }
        else if(!strcmp(command, "end"))
            return 0;
        else
        {
            fgets(harz, max, stdin);
            printf("invalid command\n");
        }
    }
}
