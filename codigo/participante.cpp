#include <iostream>
using namespace std;
#define MAX 70

typedef struct
{
    char cod[9];
    char nombre[40];
    char facultad[MAX];
}carrera;

typedef struct 
{
    char cod[9];
    char nombre[25];
    char apellido[25];
    char año;
    char edad;
    char contacto;
    char departamento[MAX];
}participante;

participante parti[MAX];
int UltReg = 0;

carrera car[MAX];
int UltReg = 0;

// FUNCIONES CRUD

//CREATE
void addStudent(participante parti);
void addCarrera(carrera car);

//READ
void showStudent(int pos);
void showCareer(int pos);
void showStudents();
void showCareers();

int isStudent(char cod[]);
int isCareer(char cod[]);

void startStudent(int pos);
participante getStudent(int pos);

//UPDATE
void updateStudent(participante parti, int pos);
void updateCareer(carrera car, int pos);

//DELETE
void deleteStudent(int pos);
void deleteCareer(int pos);

