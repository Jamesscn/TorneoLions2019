#include <iostream>
#include <map>

using namespace std;

map<string, int> nutricion;

void ordenar(string* nombres, string* comidas, int* horas, int n) {
    if(n < 2) {
        return;
    }
    int mitadA = n / 2;
    int mitadB = n - mitadA;
    string nombresA[mitadA];
    string nombresB[mitadB];
    string comidasA[mitadA];
    string comidasB[mitadB];
    int horasA[mitadA];
    int horasB[mitadB];
    for(int i = 0; i < mitadA; i++) {
        nombresA[i] = nombres[i];
        comidasA[i] = comidas[i];
        horasA[i] = horas[i];
    }
    for(int i = 0; i < mitadB; i++) {
        nombresB[i] = nombres[i + mitadA];
        comidasB[i] = comidas[i + mitadA];
        horasB[i] = horas[i + mitadA];
    }
    ordenar(nombresA, comidasA, horasA, mitadA);
    ordenar(nombresB, comidasB, horasB, mitadB);
    int indiceA = 0;
    int indiceB = 0;
    while(indiceA < mitadA && indiceB < mitadB) {
        if(nutricion[comidasA[indiceA]] > nutricion[comidasB[indiceB]]) {
            nombres[indiceA + indiceB] = nombresA[indiceA];
            comidas[indiceA + indiceB] = comidasA[indiceA];
            horas[indiceA + indiceB] = horasA[indiceA];
            indiceA++;
        } else if (nutricion[comidasA[indiceA]] == nutricion[comidasB[indiceB]]) {
            if(horasA[indiceA] > horasB[indiceB]) {
                nombres[indiceA + indiceB] = nombresA[indiceA];
                comidas[indiceA + indiceB] = comidasA[indiceA];
                horas[indiceA + indiceB] = horasA[indiceA];
                indiceA++;
            } else {
                nombres[indiceA + indiceB] = nombresB[indiceB];
                comidas[indiceA + indiceB] = comidasB[indiceB];
                horas[indiceA + indiceB] = horasB[indiceB];
                indiceB++;
            }
        } else {
            nombres[indiceA + indiceB] = nombresB[indiceB];
            comidas[indiceA + indiceB] = comidasB[indiceB];
            horas[indiceA + indiceB] = horasB[indiceB];
            indiceB++;
        }
    }
    while(indiceA < mitadA) {
        nombres[indiceA + indiceB] = nombresA[indiceA];
        comidas[indiceA + indiceB] = comidasA[indiceA];
        horas[indiceA + indiceB] = horasA[indiceA];
        indiceA++;
    }
    while(indiceB < mitadB) {
        nombres[indiceA + indiceB] = nombresB[indiceB];
        comidas[indiceA + indiceB] = comidasB[indiceB];
        horas[indiceA + indiceB] = horasB[indiceB];
        indiceB++;
    }
}

int main() {
    int alumnos;
    cin >> alumnos;
    string nombres[alumnos];
    string comidas[alumnos];
    int horas[alumnos];
    for(int i = 0; i < alumnos; i++) {
        cin >> nombres[i] >> comidas[i] >> horas[i];
    }
    nutricion["Pizza"] = 0;
    nutricion["Tacos"] = 1;
    nutricion["Torta"] = 2;
    nutricion["Ensalada"] = 3;
    ordenar(nombres, comidas, horas, alumnos);
    for(int i = 0; i < alumnos; i++) {
        cout << nombres[i] << endl;
    }
}