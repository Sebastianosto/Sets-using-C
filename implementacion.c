#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TDA_conjuntos.c"

void main(){
  //Declaracion de variables.
  conjunto *A, *B, *vacio, *resultado, *resultado2;
  int* vector;
  int aux1, aux2;

  //Inicializacion de los conjuntos. 
  A = crearConjunto();
  B = crearConjunto();
  resultado = crearConjunto();
  resultado2 = crearConjunto();
  vacio = crearConjunto(); //Sera nuestro conjunto vacio.

  system("cls");
  printf("ingrese la cantidad de Elementos de A: \n");
  scanf("%d", &aux1);
  system("cls");
  for (int i = 0; i < aux1; i++){
 	printf("Elemento %d:\n", i+1);
	scanf("%d",&aux2);
	agregarElemento(A, aux2);
  }
  system("cls");
  printf("ingrese la cantidad de Elementos de B: \n");
  scanf("%d", &aux1);
  system("cls");
  for (int i = 0; i < aux1; ++i){
 	printf("Elemento %d:\n", i+1);
	scanf("%d",&aux2);
	agregarElemento(B, aux2);
  }
  
  system("cls");
  printf("Conjunto A:\n");
  mostrarConjunto(A);
  printf("Conjunto B:\n");
  mostrarConjunto(B);

  resultado = complemento(conjuncion(A,B));
  resultado2 = disyuncion(complemento(A),complemento(B));

  system("cls");
  printf("Conjunto 1:\n");
  mostrarConjunto(resultado);

  printf("Conjunto 2:\n");
  mostrarConjunto(resultado2);



/*
  
  printf("Cardinalidad: %d\n",cardinalidad(hola));
  mostrarConjunto(hola);
  vector = conjunto_a_vector(hola);
  for (int i = 0; i < cardinalidad(hola); ++i){
    printf("%d  ",*(vector+i));
  }
  printf("\n");
  free(hola);

  */
}