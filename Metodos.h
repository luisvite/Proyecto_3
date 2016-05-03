#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

typedef struct
{
    int clave;      //Clave de la muestra
    char nombre[30];//Nombre de la muestra
    char depto[];   //Departamento al que pertenece la muestra
}Muestra;

typedef struct
{
    int *arreglo;
    int header;
    int tail;
    int max;
}ColaLineal;

typedef struct
{
    int *arreglo;
    int header;
    int tail;
    int max;
}ColaCircular;

typedef struct
{
    int *arreglo;
    int tope;
    int max;
}Pila;



#endif // METODOS_H_INCLUDED
