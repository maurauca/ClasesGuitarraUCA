#include <iostream>
#include "cursor.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 70

// ESTRUCTURAS DE DATOS PARTICIPANTE
typedef struct
{
    char facultad[MAX];
    char nombre[40];
    int año;
} carrera;

typedef struct
{
    char cod[10];
    char nombre[25];
    char apellido[25];
    char edad[2];
    char contacto[8];
    char departamento[MAX];
    carrera car;
} participante;

carrera carre[MAX];
participante parti[MAX];
int UltReg = 0;

char idCarrera[9];
carrera carreraSel;
int posCarrera;

// FUNCIONES CRUD

// CREATE
void addStudent(participante par);
void addCareer(carrera car);

// READ
void showStudent(int pos);
void showCareer(int pos);
void showStudents();
void showCareers();

int isStudent(char cod[]);

void startStudent(int pos);
void startCareer(int pos);
participante getStudent(int pos);
carrera getCarrera(int pos);

// UPDATE
void updateStudent(participante par, int pos);
void updateCareer(carrera car, int pos);

// DELETE
void deleteStudent(int pos);
void deleteCareer(int pos);

// FICHEROS
FILE *registroParticipante;
void saveStudents();
void readStudent();
int calcUltReg(FILE *archivo);

void saveStudents()
{
    registroParticipante = fopen("datosParticipante.bin", "wb");
    fwrite(parti, sizeof(participante), UltReg, registroParticipante);
    fclose(registroParticipante);
}

void readStudent()
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
    gotoxy(10,2);
    cout << "------------ Datos estudiante ------------" << endl;
    gotoxy(10,3);
    cout << "Codigo: " << parti[pos].cod << endl;
    gotoxy(10,4);
    cout << "Nombres: " << parti[pos].nombre << endl;
    gotoxy(10,5);
    cout << "Apellidos: " << parti[pos].apellido << endl;
    gotoxy(10,6);
    cout << "Edad: " << parti[pos].edad << endl;
    gotoxy(10,7);
    cout << "Numero de contacto: " << parti[pos].contacto << endl;
    gotoxy(10,8);
    cout << "Departamento: " << parti[pos].departamento << endl;
    cout << "Carrera: " << parti[pos].car.nombre << endl;

}

void showCareer(int pos)
{
    cout << "Año que cursa: " << carre[pos].año << endl;
    cout << "Facultad: " << carre[pos].facultad << endl;
    cout << "Carrera: " << carre[pos].nombre << endl;
}

int isStudent(char cod[9])
{
    int pos = -1;
    for (int i = 0; i < UltReg; i++)
    {
        if (strcmp(cod, parti[i].cod) == 0)
        {
            pos = i;
            break;
        }
    }
    return pos;
}


participante getStudent(int pos)
{
    return parti[pos];
}

carrera getCarrera(int pos)
{
    return carre[pos];
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
        startCareer(UltReg);
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

void showCareers()
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
    strcpy(carre[pos].facultad, "");
    strcpy(carre[pos].nombre, "");
    carre[pos].año = 0;

}

int menu()
{
    int op;
    cout << "-----------------------------------------" << endl;
    cout << "'       UNIVERSIDAD CENTROAMERICANA     '" << endl;
    cout << "'                   UCA                 '" << endl;
    cout << "'         CLUB DE GUITARRA 2023         '" << endl;
    cout << "'---------------------------------------'" << endl;
    cout << "Cantidad de estudiantes inscritos: " << UltReg <<endl;
    cout << "1. Inscribir nuevo participante" << endl;
    cout << "2. Editar registro de participante" << endl;
    cout << "3. Eliminar participante" << endl;
    cout << "4. Buscar datos de inscripcion de participante" << endl;
    cout << "5. Mostrar todas los participantes" << endl;
    cout << "6. Salir del programa." << endl;
    cout << "7. Agregar carrera." << endl;
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
        system("cls||clear");
        op = menu();
        switch (op)
        {
        case 1:
            system("cls || clear");
            gotoxy(10, 5);
            cout << "Id del estudiante:";
            gotoxy(10, 6);
            cout << "Ingrese los nombres del estudiante: ";
            gotoxy(10, 7);
            cout << "Ingrese los apellidos del estudiante: ";
            gotoxy(10, 8);
            cout << "Ingrese la edad del estudiante: ";
            gotoxy(10, 9);
            cout << "Ingrese el numero de contacto que proporciono el estudiante: ";
            gotoxy(10, 10);
            cout << "Ingrese el departamento de residencia del estudiante: ";
            gotoxy(10, 11);
            cout << "Escribe el codigo de la carrera: " << endl;
            gotoxy(10, 12);
            cout << "Ingrese la facultad de la Universidad: " << endl;
            gotoxy(10,13);
            cout << "Ingrese el nombre de la carrera: " << endl;
            gotoxy(10,14);
            cout << "Ingrese el ano que esta cursando este participante: " << endl;
            gotoxy(29, 5);
            scanf(" %[^\n]", par.cod);
            gotoxy(46, 6);
            scanf(" %[^\n]", par.nombre);
            gotoxy(48, 7);
            scanf(" %[^\n]", par.apellido);
            gotoxy(42, 8);
            scanf(" %[^\n]", par.edad);
            gotoxy(71, 9);
            scanf(" %[^\n]", par.contacto);
            gotoxy(64, 10);
            scanf(" %[^\n]", par.departamento);
            gotoxy(43,11);
            scanf(" %[^\n]", idCarrera);
            gotoxy(49,12);
            scanf(" %[^\n]", par.car.facultad);
            gotoxy(43,13);
            scanf(" %[^\n]", par.car.nombre);
            gotoxy(62,14);
            scanf(" %[^\n]", par.car.año);
            addStudent(par);
            cout << "Participante anadido con exito." << endl;
            system("pause");
            break;

        case 2:
            system("cls||clear");
            gotoxy(10,1);
            cout << "Escribe el codigo del participante a buscar: " << endl;
            gotoxy(55,1);
            scanf(" %[^\n]", cod);
            pos = isStudent(cod);
            showStudent(pos);
            gotoxy(10,10);
            cout << "------------ Datos a editar ------------" << endl;
            gotoxy(10, 11);
            cout << "Id del estudiante:";
            gotoxy(10, 12);
            cout << "Ingrese el nombre del estudiante: ";
            gotoxy(10, 13);
            cout << "Ingrese el apellido del estudiante: ";
            gotoxy(10, 14);
            cout << "Ingrese la edad del estudiante: ";
            gotoxy(10, 15);
            cout << "Ingrese el numero de contacto que proporciono el estudiante: ";
            gotoxy(10, 16);
            cout << "Ingrese el departamento de residencia del estudiante: ";
            gotoxy(10, 17);
            cout << "Ingrese el codigo de la carrera: " << endl; 
            gotoxy(10, 18);
            cout << "Ingrese la facultad: " << endl; 
            gotoxy(10, 19);
            cout << "Ingrese el nombre de la carrera: " << endl; 
            gotoxy(10, 20);
            cout << "Ingrese el año cursante: " << endl; 
            gotoxy(29, 11);
            scanf(" %[^\n]", par.cod);
            gotoxy(44, 12);
            scanf(" %[^\n]", par.nombre);
            gotoxy(46, 13);
            scanf(" %[^\n]", par.apellido);
            gotoxy(42, 14);
            scanf(" %[^\n]", par.edad);
            gotoxy(71, 15);
            scanf(" %[^\n]", par.contacto);
            gotoxy(64, 16);
            scanf(" %[^\n]", par.departamento);
            updateStudent(par, pos);
            gotoxy(10,17);
            cout << "Registro de inscripcion actualizado... " << endl;
            system("pause");
            break;

        case 3:
            system("cls||clear");
            if (UltReg == 0)
            {
                cout << "No hay registro que eliminar..." << endl;
            }
            cout << "Escribe el Id del participante: ";
            cin >> cod;
            pos = isStudent(cod);
            par = getStudent(pos);
            cout << "Estas seguro de eliminar la inscripcion del siguiente estudiante: " << par.nombre << " " << par.apellido << "?\n";
            cout << "Escribe 1 para SI o 2 para NO: ";
            cin >> answ;
            if (answ == 1)
            {
                deleteStudent(pos);
                cout << "Registro Eliminado... \n";
            }
            else
            {
                cout << "Operacion cancelada.... \n";
            }
            system("pause");
            break;

        case 4:
            system("cls||clear");
            cout << "Escribe el codigo del estudiante a buscar: ";
            scanf(" %[^\n]", cod);
            pos = isStudent(cod);
            showStudent(pos);
            system("pause");
            break;

        case 5:
            system("cls||clear");
            showStudents();
            system("pause");
            break;

        case 6:
            break;
        default:
            system("cls||clear");
            cout << "Opcion invalida" << endl;
            system("pause");
            break;
        }
    } while (op != 6);
    saveStudents();
}