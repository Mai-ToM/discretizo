
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int main() {
   	srand(time(NULL));
 	clock_t t_ini, t_fin;
    double secs; 
    int i;
    t_ini = clock();  
    int valorUsuario;  
    int edadesA, edadesB,edadesC,edadesD;
    t_ini = clock();  
    printf("Introduzca un numero entero: ");
    scanf("%d", &valorUsuario);
    int V;
    if (valorUsuario>0){
        V =valorUsuario;
    }else{V =2000000;}
    int A[V];

    for( i=0; i<=V; i++){
    A[i]=rand()%(101-1);
    }
    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
 	printf("Total tiempo llenado del vector: %.2f\n", secs);

    t_ini = clock();  
 	//Divisiòn de las edades
    #pragma omp parallel for  schedule(static) reduction(+: edadesA,edadesB,edadesC, edadesD)
 	for( i=0; i<V; i++){
    	if(A[i]>=0&&A[i]<=14){
    		edadesA=edadesA+1;
    	}else if (A[i]>=15&&A[i]<=24)
    	{
    		edadesB=edadesB+1;
    	}else if (A[i]>=25&&A[i]<=64)
    	{
    		edadesC=edadesC+1;
    	}else{
    		edadesD=edadesD+1;
    	}

    }
     
    t_fin = clock();
    secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
    printf("Total de tiempo en las operaciones: %.2f\n", secs);
    printf("A: %d\n", edadesA);
    printf("B: %d\n", edadesB);
    printf("C: %d\n", edadesC);
    printf("D: %d\n", edadesD);
    printf("Total: %d\n", edadesD+edadesA+edadesC+edadesB);
    printf("Tamaño del vector: %d\n", valorUsuario);

    return 0;
}