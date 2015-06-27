#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Version
{
    int prim,sec,tert;
};

struct MobileApp
{
    int ID;
    char *name, *developer, *OS;
    float rating, size;
    struct Version version;
};

char fileName[]="wasea.txt";


struct MobileApp apps[30];


FILE* createFile(char fileName[20])
{
    FILE *f=fopen(fileName,"a");
    return f;
}
void writeInfo(FILE *f,int amount)
{
    int i,k;
    struct MobileApp app;
    app.name=malloc(20);
    app.developer=malloc(20);
    app.OS=malloc(20);
    for (i=0; i<amount; i++)
    {
        printf("\nEnregistrez l'application nr. %d\n",i+1);
        printf("\nDonnez l' ID:\n");
        scanf("%d",&app.ID);
        printf("\nDonnez le nom:\n");
        scanf("%s",app.name);
        printf("\nDonnez le developeur:\n");
        scanf("%s",app.developer);
        printf("\nChoisisez le nombre de systeme d'operation:\n");
        printf("\n     1. Android");
        printf("\n     2. iOS");
        printf("\n     3. Windows Phone\n");
        scanf("%d",&k);
        switch (k)
        {
        case 1:
            strcpy(app.OS, "Android");
            break;
        case 2:
            strcpy(app.OS, "iOS");
            break;
        case 3:
            strcpy(app.OS, "WinPhone");
            break;
        default:
            strcpy(app.OS, "Undefined");
            break;
        }
        printf("\nDonnez le rating:\n");
        scanf("%f",&app.rating);
        printf("\nDonnez la taille:\n");
        scanf("%f",&app.size);
        printf("\nDonnez la version, avec le format: prim sec tert:\n");
        scanf("%d%d%d",&app.version.prim,&app.version.sec,&app.version.tert);

        fprintf(f,"%d|%s|%s|%s|%f|%f|%d.%d.%d|\n",
                app.ID,app.name,app.developer,app.OS,app.rating,app.size, app.version.prim,app.version.sec,app.version.tert);
    }
    fclose(f);

}
int readInfo(char fileName[20])
{
    char allInfo[100],*token,*token2, str[20];
    int k=0;
    struct MobileApp app;
    FILE *f=fopen(fileName,"r");

    while (fscanf(f,"%s",allInfo)==1)
    {
        token = strtok(allInfo, "|");
        app.ID=atoi(token);

        token = strtok(NULL, "|");
        app.name=malloc(strlen(token) + 1);
        strcpy(app.name,token);

        token = strtok(NULL, "|");
        app.developer=malloc(strlen(token) + 1);
        strcpy(app.developer,token);

        token = strtok(NULL, "|");
        app.OS=malloc(strlen(token) + 1);
        strcpy(app.OS,token);

        token = strtok(NULL, "|");
        app.rating=atof(token);

        token = strtok(NULL, "|");
        app.size=atof(token);


        token = strtok(NULL, "|");

        token2=strtok(token, ".");
        app.version.prim=atoi(token2);

        token2=strtok(NULL, ".");
        app.version.sec=atoi(token2);

        token2=strtok(NULL, ".");
        app.version.tert=atoi(token2);

        apps[k]=app;
        k++;

    }
    fclose(f);
    return k;
}

void displayInfo(int k)
{
    int i;
    struct MobileApp app;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("-------------------------------------------------------------------------\n");
    for (i=0; i<k; i++)
    {
        app=apps[i];
        printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
               app.ID,app.name,app.developer,app.OS,app.rating,app.size,app.version.prim,app.version.sec,app.version.tert);
    }
}



int main()
{
    writeInfo(createFile(fileName),2);
    displayInfo(readInfo(fileName));
    return 0;
}
