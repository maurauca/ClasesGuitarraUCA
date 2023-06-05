#include <iostream>
#include "cursor.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 70

//ESTRUCTURAS DE DATOS PARTICIPANTE
typedef struct
{
    char año[2];
    char cod[9];
    char nombre[40];
    char facultad[MAX];
} carrera;

typedef struct
{
    char cod[9];
    char nombre[25];
    char apellido[25];
    char edad[2];
    char contacto[8];
    char departamento[MAX];
} participante;

participante parti[MAX];
int UltReg = 0;

carrera carre[MAX];
int UltReg = 0;

// FUNCIONES CRUD

// CREATE
void addStudent(participante par);
void addCarrera(carrera car);

// READ
void showStudent(int pos);
void showCareer(int pos);
void showStudents();
void showCareers();

int isStudent(char cod[]);
int isCareer(char cod[]);

void startStudent(int pos);
void startCareer(int pos);
participante getStudent(int pos);

// UPDATE
void updateStudent(participante par, int pos);
void updateCareer(carrera car, int pos);

// DELETE
void deleteStudent(int pos);
void deleteCareer(int pos);

// FICHEROS
FILE *registroParticipante;
void saveStudent();
void readStudent();
int calcUltReg(FILE *archivo);

void saveClientes()
{
    registroParticipante = fopen("datosParticipante.bin", "wb");
    fwrite(parti, sizeof(participante), UltReg, registroParticipante);
    fclose(registroParticipante);
}

void readClientes()
{
    registroParticipante = fopen("datosParticipante.bin", "rb");
    if (registroParticipante == NULL)
    {
        return;
    }
    UltReg = calcUltReg(registroParticipante);
    fread(parti, sizeof(participante), MAX, registroParticipante);
    fclose(registroParticipante);
}

int calcUltReg(FILE *archivo)
{
    int size, num;
    fseek(archivo, 0, SEEK_END);
    size = ftell(archivo);
    rewind(archivo);
    num = size / sizeof(participante);
    return num;
}



void addStudent(participante par)
{
    parti[UltReg] = par;
    UltReg++;
}
void addCareer(carrera car)
{
    carre[UltReg] = car;
    UltReg++;
}

void showStudent(int pos)
{
    cout << "Ingrese el codigo del estudiante: " << parti[pos].cod << endl;
    cout << "Ingrese nombre: " << parti[pos].nombre << endl;
    cout << "Ingrese apellido: " << parti[pos].apellido << endl;
    cout << "Ingrese edad: " << parti[pos].edad << endl;
    cout << "Ingrese numero telefonico para contacto: " << parti[pos].contacto << endl;
    cout << "Ingrese departamento: " << parti[pos].departamento << endl;
}

void showCareer(int pos)
{
    cout << "Ingrese el codigo del estudiante: " << carre[pos].cod << endl;
    cout << "Ingrese el año que esta cursando" << carre[pos].año << endl;
    cout << "Ingrese el nombre de su facultad" << carre[pos].facultad << endl;
    cout << "Ingrese el nombre de su carrera" << carre[pos].nombre << endl;
}

int isStudent(char cod[9])
{
    int pos = 0;
    for (int i = 0; i < UltReg; i++)
    {
        if (strcmp(cod, parti[i].cod) == 0)
        {
            pos = i;
            break;
        }
    }
}

int isCareer(char cod[9])
{
    int pos = 0;
    for (int i = 0; i < UltReg; i++)
    {
        if (strcmp(cod, carre[i].cod))
        {
            pos = i;
            break;
        }
    }
}

participante getStudent(int pos)
{
    return parti[pos];
}

void updateStudent(participante par, int pos)
{
    parti[pos] = par;
}

void updateCareer(carrera car, int pos)
{
    carre[pos] = car;
}

void deleteStudent(int pos)
{
    if (pos == UltReg)
    {
        cout << "No tenemos un registro de este participante." << endl;
        return;
    }
    for (int i = 0; i < UltReg; i++)
    {
        parti[i] = parti[i + 1];
    }
    UltReg--;
    startStudent(UltReg);
}

void deleteCareer(int pos)
{
    if (pos == UltReg)
    {
        cout << "No tenemos un registro de estos datos." << endl;
        for (int i = 0; i < UltReg; i++)
        {
            carre[i] = carre[i + 1];
        }
        UltReg--;
        startCareer;
    }
}

void showStudents()
{
    system("cls");
    if (UltReg == 0)
    {
        cout << "No existe un registro de este participante." << endl;
        return;
    }
    for (int i = 0; i < UltReg; i++)
    {
        cout << "+++++++++++++++++++++++++++++++++++" << endl;
        showStudent(i);
    }
    cout << "Ultimo registro de estudiante... " << endl;
}

void showCareer()
{
    system("cls");
    if (UltReg == 0)
    {
        cout << "No existe un registro de esta carrera en el club." << endl;
        return;
    }
    for (int i = 0; i < UltReg; i++)
    {
        cout << "+++++++++++++++++++++++++++++++++++" << endl;
        showCareer(i);
    }
    cout << "Ultimo registro de carrera... " << endl;
}

void startStudent(int pos)
{
    strcpy(parti[pos].cod, "");
    strcpy(parti[pos].nombre, "");
    strcpy(parti[pos].apellido, "");
    strcpy(parti[pos].edad, "");
    strcpy(parti[pos].contacto, "");
    strcpy(parti[pos].departamento, "");
}    

void startCareer(int pos)
{
    strcpy(carre[pos].cod, "");
    strcpy(carre[pos].año, "");
    strcpy(carre[pos].nombre, "");
    strcpy(carre[pos].facultad, "");
}

int menu()
{
    int op;
    cout << "-----------------------------------------" << endl;
    cout << "'       UNIVERSIDAD CENTROAMERICANA     '" << endl;
    cout << "'                   UCA                 '" << endl;
    cout << "'         CLUB DE GUITARRA 2023         '" << endl;
    cout << "'---------------------------------------'" << endl;
    cout << "Cantidad de estudiantes inscritos: " << endl;
    cout << "1. Inscribir nuevo participante" << endl;
    cout << "2. Editar registro de participante" << endl;
    cout << "3. Eliminar participante" << endl;
    cout << "4. Buscar datos de inscripción de participante" << endl;
    cout << "5. Mostrar todas los participantes" << endl;
    cout << "6. Salir del programa." << endl;
    cin >> op;
    return op;
}

void start()
{
    int op, pos, answ;
    char cod[9];
    participante par;
    readStudent();
    do
    {
        system ("cls||clear");
        op = menu();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy(10, 5);
            cout << "Id del estudiante:";
            gotoxy(10, 6);
            cout << "Ingrese el nombre del estudiante: ";
            gotoxy(10, 7);
            cout << "Ingrese el apellido del estudiante: ";
            gotoxy(10, 8);
            cout << "Ingrese la edad del estudiante: ";
            gotoxy(10, 9);
            cout << "Ingrese el numero de contacto que proporciono el estudiante: ";
            gotoxy(10, 10);
            cout << "Ingrese el departamento de residencia del estudiante: ";
            gotoxy(10, 11);
            scanf(" %[^\n]", par.cod);
            gotoxy(18, 6);
            scanf(" %[^\n]", par.nombre);
            gotoxy(20, 7);
            scanf(" %[^\n]", par.apellido);
            gotoxy(16, 8);
            scanf(" %[^\n]", par.edad);
            gotoxy(17, 9);
            scanf(" %[^\n]", par.contacto);
            gotoxy(42, 10);
            scanf(" %[^\n]", par.departamento);
            addStudent(par);
            system("pause");
            break;
        
        case 2:

        default:
            break;
        }
    } while (op !=6);

}