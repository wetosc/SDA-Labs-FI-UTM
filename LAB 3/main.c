#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct gateau
{
    char *nom;
    float sucre, poids;
} a,min;

void sorting(FILE *f)
{

//f=fopen("gateau.txt","rb+");
    int i,j,n=0,pos;
    while (!feof(f))
    {
        fread(&a,sizeof(a),1,f);
        n++;
//             printf("lalala");
    }
//printf("\nn= %d\n",n);
    for (i=0; i<n-1; i++)
    {
        fseek(f,sizeof(a)*i,SEEK_SET);
        fread(&a,sizeof(a),1,f);
        min=a;
        pos=i;
        for (j=i+1; j<n; j++)
        {
            fseek(f,sizeof(a)*j,SEEK_SET);
            fread(&a,sizeof(a),1,f);
            if (a.sucre<min.sucre)
            {
                min=a;
                pos=j;
            }
        }
        fseek(f,sizeof(a)*i,SEEK_SET);
        fread(&a,sizeof(a),1,f);
        fseek(f,sizeof(a)*pos,SEEK_SET);
        fwrite(&a,sizeof(a),1,f);
        fseek(f,sizeof(a)*i,SEEK_SET);
        fwrite(&min,sizeof(min),1,f);
    }
}






int main()
{
    printf("\n Nom  -- Poids  -- Sucre ",a.nom, a.poids, a.sucre);
    int i;
    FILE *f=fopen("gateau.txt","wb");
    srand(time(NULL));
    for (i=0; i<10; i++)
    {
        a.sucre=(rand()%10+0.1f)/2.0f;
        a.poids=(rand()%10+0.1f)/2.0f;
        a.nom="Gateau";
        printf("\n %s -- %.1f  -- %.1f ",a.nom, a.poids, a.sucre);
        fwrite(&a,sizeof(a),1,f);
    }
    fclose(f);

    f=fopen("gateau.txt","rb+");
    sorting(f);
    fclose(f);

    f=fopen("gateau.txt","rb");
    printf("\n");
    for (i=0; i<10; i++)
    {
        fread(&a,sizeof(a),1,f);
        printf("\n %s -- %.1f  -- %.1f ",a.nom, a.poids, a.sucre);
    }
    fclose(f);




    return 0;
}
