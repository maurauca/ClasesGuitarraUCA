#include <iostream>
using namespace std;
#define MAX 70

typedef struct
{
    char cod[9];
    char nombre[25];
    char departamento[MAX];
} ciudad;

typedef struct
{
    char cod[9];
    char nombre[40];
    char facultad[MAX];
}carrera;

typedef struct 
{
    char nombre[25];
    char apellido[25];
    char año;
    char edad;
    char contacto;
}participante;
