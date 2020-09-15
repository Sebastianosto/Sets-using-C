#include <stdio.h>
#include <stdlib.h>
#include "TDA_conjuntosPrototypes.c"

conjunto* crearConjunto(){
  conjunto * set;
  set = (conjunto*)malloc(sizeof(conjunto));
  set->cardinalidad = 0;
  return set;
}


int posicion(conjunto * set, int elem){
  int left, right, middle;
  left = 0;
  right = set->cardinalidad-1;
  while (left <= right) {
    middle = (int)((left + right) / 2);
    if (set->elementos[middle] == elem) {
      return middle;
    }else{
      if (set->elementos[middle] > elem) {
        right = middle - 1;
      }else{
        left = middle +1;
      }
    }
  }
  return -1;
}

int cardinalidad(conjunto* set){
  return set->cardinalidad;
}

int pertenece(conjunto * set, int elem){
  int index;
  index = posicion(set, elem);
  if(index == -1){
    return 0;
  }else{
    return 1;
  }
}
void agregarElemento(conjunto*set, int elem){
  if(!pertenece(set, elem)){
    if(set->cardinalidad < UNIVERSE){
      int k = 0;
      while (k < set->cardinalidad && elem > set->elementos[k]) {
        k++;
      }
      if (k >= set->cardinalidad) {
        set->elementos[k]= elem;
      }else{
        for (int i = set->cardinalidad-1; i >= k ; i--) {
          set->elementos[i+1] =set->elementos[i];
        }
        set->elementos[k] = elem;
      }
      set->cardinalidad += 1;
    }
  }
}

int maxCardinalidad(int num1, int num2){
  if (num1 > num2){
    return num1;
  }else{
    return num2;
  }
}



void eliminarElemento(conjunto* set, int elem){
  if (pertenece(set, elem)) {
    int k;
    k = posicion(set, elem);
    for (int i = k; i < set->cardinalidad -1; i++) {
      set->elementos[i] = set->elementos[i+1];
    }
    set->cardinalidad -= 1;
  }
}

void mostrarConjunto(conjunto * set){
  printf("Elementos: ");
  for (int i = 0; i < set->cardinalidad; i++) {
    printf("%d ", set->elementos[i]);
  }
  printf("\n");
}

int esSubconjunto(conjunto* set_1, conjunto* set_2){
  for (int i = 0; i < set_1->cardinalidad; i++){
    if(!pertenece(set_2, set_1->elementos[i])){
      return 0;
    }
  }
  return 1;
}

conjunto* conjuncion(conjunto* set_1, conjunto* set_2){
  conjunto* conjuntoResult;
  conjuntoResult = crearConjunto(conjuntoResult);
  for (int i = 0; i < set_1->cardinalidad; ++i){
    if (pertenece(set_2, set_1->elementos[i])){
      agregarElemento(conjuntoResult, set_1->elementos[i]);
    }
  }
  return conjuntoResult;

}

conjunto* conjuntoUniverso(){
  conjunto* u;
  u = crearConjunto();
  for (int i = 0; i < UNIVERSE; ++i){
    agregarElemento(u, i);
  }
  return u;
}

conjunto* disyuncion(conjunto* set_1, conjunto* set_2){
  conjunto* d;
  d = crearConjunto();
  int mayor = maxCardinalidad(set_1->cardinalidad, set_2->cardinalidad);
  for (int i = 0; i < mayor; ++i){
    if(pertenece(set_1,set_1->elementos[i] )){ 
     agregarElemento(d, set_1->elementos[i]);
    }
    if (pertenece(set_2,set_2->elementos[i] )){
     agregarElemento(d, set_2->elementos[i]);
    }
  }
  return d;
}

conjunto* diferencia(conjunto* set_1, conjunto* set_2){
  conjunto* resta;
  resta = crearConjunto();
  int mayor = maxCardinalidad(set_1->cardinalidad, set_2->cardinalidad);
  for (int i = 0; i < mayor; ++i){
    if(pertenece(set_1, set_1->elementos[i]) && !pertenece(set_2, set_1->elementos[i])){
      agregarElemento(resta,set_1->elementos[i]);
    }
  }
  return resta;
}

conjunto* diferenciaSimetrica(conjunto* set_1, conjunto* set_2){
  conjunto* resta;
  resta = crearConjunto();
  resta = disyuncion(diferencia(set_1, set_2), diferencia(set_2, set_1));
  return resta;
}

conjunto* complemento(conjunto* set){
  conjunto* c;
  c = crearConjunto();
  for (int i = 0; i < UNIVERSE; ++i){
    if(!pertenece(set, i)){
      agregarElemento(c, i);
    }
  }
  return c;
}

int* conjunto_a_vector(conjunto* set){
  int* vector;
  vector = (int*)malloc(set->cardinalidad*sizeof(int));
  for (int i = 0; i < set->cardinalidad; ++i){
    *(vector+i) = set->elementos[i];
  }
  return vector;
}