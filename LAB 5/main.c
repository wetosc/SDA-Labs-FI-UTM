#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int A[20][20];
int x[20];
int n=5,s=4;

void citire(FILE *fin)
{
    int i,j;
    fscanf(fin,"%d ",&n);
    fscanf(fin,"%d ",&s);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(fin,"%d ",&A[i][j]);
    fclose(fin);
}

void tipar()
{
    int i;
    printf("\n");
    for(i=1; i<=n; i++)
        printf("%d",x[i]+1);
}

int validare()
{
    int i,k;
    for (k=1; k<=n; k++)
        for (i=k; i<=n; i++)
            if (x[k]==x[i] && A[k][i]==1) return 0;
    return 1;
}

void convert(int from, int to[])
{
    int temp=from,i=0;
    while (temp>0)
    {
        to[n-i]=temp%s;
        temp=temp/s;
        i++;
    }
}

int main()
{
    FILE *f=fopen("harta.txt","r");
    citire(f);
    printf("\n Solutii: \n");
    int i;
    for (i=0; i<pow(s,n)-1; i++)
    {
        convert(i,x);
        if (validare()==1) tipar();
    }
    return 0;
}
