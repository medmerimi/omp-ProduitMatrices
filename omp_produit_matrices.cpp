//MERIMI Mohammed 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

#define n 40
#define m 2
#define k 3
#define NUMTHREADS 3

int A[n][m],B[m][k],C[n][k];
double debut,fin;
int i,j;

int main (){
	 //sequentiel 
    int l;
    debut=clock();
    printf("matrice A : \n");
    for(i=0;i<n;i++){
    	printf("\n");	
    	for(j=0;j<m;j++){
    		A[i][j]=rand()%3;
    		printf("%d \t",A[i][j]);
		}
    	
	}
	printf("\n");
	
	printf("matrice B : \n");
	for(i=0;i<n;i++){
		printf("\n");	
		for(j=0;j<m;j++){
			B[i][j]=rand()%3;
			printf("%d \t",B[i][j]);
		}
	}
	
	printf("\n");
	
	#pragma omp parallel num_threads(2)  
	{
	#pragma omp for 
	{
    for(i=0;i<n;i++){
    	printf("\n");	
    	for(j=0;j<m;j++){
    		C[i][j]=0;
    		for(l=0;l<k;l++){
    		    C[i][j]=C[i][j]+A[i][l]*B[l][j]	;
			}
		}
	}
    }
    }
    printf("\n");
	printf("partie sequentiel");
	printf("\n");
	printf("matrice C :\n");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<k;j++){
			printf("%d \t",C[i][j]);

		}
	}
	fin=clock();
	printf("\n");
    printf("temps execution sequetiel=%f\n",  (double)(fin-debut)/CLOCKS_PER_SEC); 
	
	
	return 0 ;
}
