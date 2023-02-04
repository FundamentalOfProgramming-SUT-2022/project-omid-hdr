#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

char harz[max];

char clipboard[10000] = {0};

int line;
int number;

void createfile()
{
    char daf[8] = "-file";
    char adr[max] = {0};
    char inp[max] = {0};
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
        FILE* omid = fopen(inp, "w");
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
        FILE* omid = fopen(inp, "w");
        fclose(omid);
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
    ////////////
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
        FILE* omid = fopen(inp, "a+");
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
        if (str[0] == '"') {
            char u;
            for (int q = 0; q < 100; q++) {
                u = getchar();
                if (u == '"') {
                    str[q] == '\0';
                    break;
                }
                str[q] = u;
            }
        }
        else {
            scanf("%s", str2);
            strcat(str, str2);
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
        FILE* tmp = fopen("tmp.txt", "w");
        for (int j = 0;j < line - 1; j++) {
            fgets(Line, max, omid);
            printf(".%s.", Line);
            fputs(Line, tmp);
        }
        char g;
        for (int z = 0; z < number; z++) {
            g = fgetc(omid);
            fputc(g, tmp);
            printf("*%c*", g);
        }
        fputs(str, tmp);
        g = fgetc(omid);
        while (g != EOF) {
            fputc(g, tmp);
            g = fgetc(omid);
        }
        getchar();
        fclose(omid);
        fclose(tmp);
    }
    else
    {
        while (adr[i] != '\n')
        {
            while(!(adr[i] == '/' || adr[i] == '\n'))
            {
                if(adr[i] == ' ')
                {
                    printf("You can't use spase without \".\n");
                    fgets(harz, max, stdin);
                    return 0;
                }
                sprintf(inp,"%s%c", inp, adr[i]);
                i++;
            }
            if(adr[i] == '\n')
                break;
            if(mkdir(inp))
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
        FILE* omid = fopen(inp, "a");

        ///////
        //insertstr -file "/root/omid.txt" -str "ha   gh" -pos 5:0

        fclose(omid);
    }
    printf("success\n");
    return 0;
}

//////////

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
        else if(!strcmp(command, "end"))
            return 0;
        else
        {
            fgets(harz, max, stdin);
            printf("invalid command\n");
        }
    }
}
