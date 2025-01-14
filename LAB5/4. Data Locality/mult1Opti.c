#include <stdio.h>
#include <stdlib.h>

#define N 512


int n;

int C[N][N];
int A[N][N];
int B[N][N];


void mult1(int C[][N], int B[][N], int A[][N], int n)
{

 int i,j,k;
  int ii,jj,kk;

   for ( i=0 ; i < n; i+=BS )
   {
     for ( k=0 ; k < n ; k+=BS )
     {
    	for ( j=0 ; j < n ; j+=BS )     
       {
         // BLOCKING
         for ( ii=i ; ii < i+BS; ii++ )
         {
            for ( kk=k ; kk < k+BS ; kk++ )
            {
              for ( jj=j ; jj < j+BS ; jj++ )
              {
                 C[ii][jj]+= A[ii][kk]*B[kk][jj];
              }
            }
         }
       }
     }
   }
}

void init(int A[][N], int n)
{

  int i,j;

  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      A[i][j] = i+j;

}

int main(int argc, char *argv[])
{


  if (argc > 1) n = atoi(argv[1]); else n = N;

  init( A, n);
  init( B, n);
  init( C, n);
  

  mult1(C,B,A,n); 

  write(1, C, sizeof(C));
  return 0;
}
