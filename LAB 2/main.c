#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

const int arr_size = 100000000;

time_t time1,time2;
int a[100000000],n;

void random(){
    int i; srand(time(NULL));
    for (i=0;i<n;i++)a[i]= (rand()%100)-50;
}
int cmpfunc (const void * a, const void * b){
   return ( *(int*)a - *(int*)b );}
int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void bubble_sort(){
  int c, d, t;
  for (c = 0 ; c < ( n - 1 ); c++){
        for (d = 0 ; d < n - c - 1; d++){
            if (a[d] > a[d+1]){
        t         = a[d];
        a[d]   = a[d+1];
        a[d+1] = t;
      }
    }
  }
}
void insertion_sort(){
  int c, d, t;
for (c = 1 ; c <= n - 1; c++) {
    d = c;
    while ( d > 0 && a[d] < a[d-1]) {
      t          = a[d];
      a[d]   = a[d-1];
      a[d-1] = t;

      d--;
    }
  }
}
void selection_sort(){
  int c, d, t,position;
 for ( c = 0 ; c < ( n - 1 ) ; c++ )
   {
      position = c;

      for ( d = c + 1 ; d < n ; d++ )
      {
         if ( a[position] > a[d] )
            position = d;
      }
      if ( position != c )
      {
         t = a[c];
         a[c] = a[position];
         a[position] = t;
      }
   }
}
void shell_sort(){
    int i,k,j,tmp;
for(i=n/2; i>0; i=i/2)
 {
   for(j=i; j<n; j++)
   {
     for(k=j-i; k>=0; k=k-i)
     {
        if(a[k+i]>=a[k])
            break;
        else
        {
            tmp=a[k];
            a[k]=a[k+i];
            a[k+i]=tmp;
        }
     }
   }
 }
}
void quickSort( int a[], int l, int r){
   int j;

   if( l < r )
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }

}






int main() {
n=1000000;
printf("\n N= %d\n\n",n);

random();
time1=clock();
qsort(a, n, sizeof(int), cmpfunc);
time2=clock();
printf("\n qsort, standart:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);

random();
time1=clock();
shell_sort();
time2=clock();
printf("\n Shell sort:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);

// Medium Sort
n=100000;
printf("\n\n N= %d\n\n",n);

random();
time1=clock();
quickSort(a,0,n-1);
time2=clock();
printf("\n QuickSort:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);

// Slooooooooooooooow Sort
n=30000;
printf("\n\n N= %d\n\n",n);

random();
time1=clock();
bubble_sort();
time2=clock();
printf("\n Bubble sort:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);

random();
time1=clock();
insertion_sort();
time2=clock();
printf("\n Insertion sort:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);

random();
time1=clock();
selection_sort();
time2=clock();
printf("\n Selection sort:\n Time: %f   s\n",(double)(time2-time1)/CLOCKS_PER_SEC);



printf("\n");
return 0;
}
