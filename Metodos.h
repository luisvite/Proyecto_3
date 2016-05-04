#ifndef METODOS_H_INCLUDED
#define METODOS_H_INCLUDED

typedef struct
{
    int clave;      //Clave de la muestra
    char nombre[30];//Nombre de la muestra
    char depto[30];   //Departamento al que pertenece la muestra
}Muestra;

typedef struct
{
    Muestra *arreglo;
    int header;
    int tail;
    int max;
}ColaLineal;

typedef struct
{
    Muestra *arreglo;
    int header;
    int tail;
    int max;
}ColaCircular;

typedef struct
{
    Muestra *arreglo;
    int tope;
    int max;
}Pila;

//Menu
int Menu (char texto[], int n);

//Metodos para la cola lineal
void InsertarCL(ColaLineal *cl);
Muestra BorrarCL(ColaLineal *cl);
int ValidaEspacioCL(ColaLineal *cl);
int ValidaVacioCL(ColaLineal *cl);

//Metodos para la cola circular
void InsertarCC(ColaCircular *cc,Muestra m);
Muestra BorrarCC(ColaCircular *cc);
int ValidaEspacioCC(ColaCircular *cc);
int ValidaVacioCC(ColaCircular *cc);

//Metodos para la pila estatica
void Push(Pila *p, Muestra m);
Muestra Pop(Pila *p);
int ValidaEspacioP(Pila *p);
int ValidaVacioP(Pila *p);


#endif // METODOS_H_INCLUDED
