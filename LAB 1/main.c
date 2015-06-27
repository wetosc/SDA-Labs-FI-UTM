#include <stdio.h>
#include <conio.h>

int a[50][50],m,n,arr3[50];

void random(){
    int i,j;
    srand(time(NULL));
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            a[i][j]= (rand()%100)-50;
}
void afficher(int x[50][50],int n, int m){
    printf("\n");
    int i,j;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) printf(" %3d",x[i][j]);
        printf("\n");
    }
      printf("\n");
}

void maxPos1(int x[50][50], int n, int m, int result[50]){
int i,j,l;
for (j=0;j<m;j++) {result[j]=0; l=x[0][j];
    for (i=1;i<n;i++) if (x[i][j]>l) {l=x[i][j];result[j]=i;}
}
}

int *maxPos2(int x[50][50], int n, int m){
int i,j,l,*result;
result=malloc(sizeof(int)*50);

for (j=0;j<m;j++) {result[j]=0; l=x[0][j];
    for (i=1;i<n;i++) if (x[i][j]>l) {l=x[i][j];result[j]=i;}
}
return result;
}

void maxPos3(){
int i,j,l;
for (j=0;j<m;j++) {arr3[j]=0; l=a[0][j];
    for (i=1;i<n;i++) if (a[i][j]>l) {l=a[i][j];arr3[j]=i;}
}
}

int main() {
int i=0,arr1[50], *arr2;
printf("Donnez les dimesions de la matrice\n");
scanf("%d%d",&n,&m);
random();
afficher(a,n,m);

printf("\nLe nombre des elements qui se trouvent\n    en haut de l'element MAX de chaque colonne est:\n");

// Par parametres valeurs;
maxPos1(a,n,m,arr1);
printf("\nLa methode des parametres:\n");
for (i=0;i<m;i++) printf(" %d ",arr1[i]);
// Par adresses:
arr2=maxPos2(a,n,m);
printf("\nLa methode des adresses:\n");
for (i=0;i<m;i++) printf(" %d ",arr2[i]);
// Par variables globales:
maxPos3();
printf("\nLa methode des variables globales:\n");
for (i=0;i<m;i++) printf(" %d ",arr3[i]);

printf("\n");
return 0;
}
