#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void problema2();
void problema4();
void problema6();
void problema8();
void problema10();
int cadenaAEntero(char cadena[]);

int main() {
    int opcion;
    while (true) {
        cout << "\n2. Problema 2\n4. Problema 4\n0. Salir\nSeleccione: ";
        cin >> opcion;


        if (opcion == 0) break;

        switch (opcion) {
        case 2:
            problema2();
            break;
        case 4:
            problema4();
            break;
        case 6:
            problema6();
            break;
        case 8:
            problema8();
            break;
        case 10:
            problema10();
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    }
    return 0;
}

void problema2() {
    srand(time(0));
    char letras[200];
    int conteo[26] = {0};
    for (int i = 0; i < 200; i++) {
        letras[i] = 'A' + (rand() % 26);
        cout << letras[i] << ((i + 1) % 20 == 0 ? "\n" : " ");
        conteo[letras[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (conteo[i] > 0) cout << (char)('A' + i) << ": " << conteo[i] << endl;
    }
}

int cadenaAEntero(char cadena[]) {
    int res = 0;
    for (int i = 0; cadena[i] != '\0'; i++) {
        res = res * 10 + (cadena[i] - '0');
    }
    return res;
}

void problema4() {
    char cadena[20];
    cout << "Ingrese numeros: ";
    cin >> cadena;
    int num = cadenaAEntero(cadena);
    cout << "Entero: " << num << " | Doble: " << num * 2 << endl;
}

void problema6() {
    char cadena[100];
    cout << "Ingrese una cadena: ";
    cin.ignore();
    cin.getline(cadena, 100);

    cout << "Original: " << cadena << endl;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 32;
        }
    }

    cout << "En mayuscula: " << cadena << endl;
}

void problema8() {
    char original[100], texto[100], numeros[100];
    int t = 0, n = 0;

    cout << "Ingrese cadena: ";
    cin.ignore();
    cin.getline(original, 100);

    for (int i = 0; original[i] != '\0'; i++) {
        if (original[i] >= '0' && original[i] <= '9') {
            numeros[n++] = original[i];
        } else {
            texto[t++] = original[i];
        }
    }
    texto[t] = '\0';
    numeros[n] = '\0';

    cout << "Texto: " << texto << endl;
    cout << "Numero: " << numeros << endl;
}

int romanToVal(char c);
void problema10();

int romanToVal(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

void problema10() {
    char romano[20];
    cout << "Ingrese numero romano (mayusculas): ";
    cin >> romano;

    int total = 0;
    for (int i = 0; romano[i] != '\0'; i++) {
        int s1 = romanToVal(romano[i]);
        if (romano[i+1] != '\0') {
            int s2 = romanToVal(romano[i+1]);
            if (s1 >= s2) {
                total += s1;
            } else {
                total -= s1;
            }
        } else {
            total += s1;
        }
    }
    cout << "El numero es: " << total << endl;
}
