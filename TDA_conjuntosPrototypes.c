#include <stdio.h>
#define UNIVERSE 20 //Se define la cantidad maxima de elementos.

//Se implementa el tda conjunto mediante estructuras.
typedef struct{
	int cardinalidad;
	int elementos[UNIVERSE];
}conjunto;


//Genera un conjunto vacio.
conjunto* crearConjunto();

//Funcion auxiliar para efectuar otras funciones.
int posicion(conjunto * set, int elem);

//Devuelve la cardinalidad del conjunto pasado como argumento.
int cardinalidad(conjunto* set);

//Devuelve 1 si el elemento pertenece al conjunto, 0 si no pertenece.
int pertenece(conjunto * set, int elem);

//Agrega un elemento al conjunto siempre que no se exceda el limite de elementos.
void agregarElemento(conjunto*set, int elem);

//Devuelve la cardinalidad mas grande entre dos conjuntos.
int maxCardinalidad(int num1, int num2);

//Elimina un elemento del conjunto, siempre que el elemento pertenezca inicialmente al conjunto.
void eliminarElemento(conjunto* set, int elem);

//Muestra los elementos del conjunto en pantalla.
void mostrarConjunto(conjunto* set);

//Devuelve 1 si el primer conjunto es subconjunto del segundo, 0 en caso contrario.
int esSubconjunto(conjunto* set_1, conjunto* set_2);

//Devuelve un conjunto con los elementos que aparecen tanto en el primet conjunto, como en el segundo.
conjunto* conjuncion(conjunto* set_1, conjunto* set_2);

//Crea el conjunto universo.
conjunto* conjuntoUniverso();

//Devuelve un conjunto con los elementos tanto del primer conjunto, como del segundo.
conjunto* disyuncion(conjunto* set_1, conjunto* set_2);

//Devuelve un conjunto con los elementos que aparecen en el primer conjunto, y no aparecen en el segundo.
conjunto* diferencia(conjunto* set_1, conjunto* set_2);

//Devuelve un conjunto con los elementos que esten en la disyuncion de los conjuntos, y no en la conjuncion.
conjunto* diferenciaSimetrica(conjunto* set_1, conjunto* set_2);

//Devuelve un conjunto con los elementos que no estan en el conjunto del argumento.
conjunto* complemento(conjunto* set);

//Devuelve un vector dinamico con los elementos del conjunto.
int* conjunto_a_vector(conjunto* set);