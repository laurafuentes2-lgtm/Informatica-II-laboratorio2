#include "main.h"

int main() {
    int opcion;
    while (true) {
        cout << "\n--- MENU DE EJERCICIOS (PARES) ---" << endl;
        cout << "Seleccione un problema (2, 4, 6, 8, 10, 12) o 0 para salir: ";
        cin >> opcion;

        if (opcion == 0) break;

        switch (opcion) {
        case 2:  problema2();  break;
        case 4:  problema4();  break;
        case 6:  problema6();  break;
        case 8:  problema8();  break;
        case 10: problema10(); break;
        case 12: problema12(); break;
        case 14: problema14(); break;
        case 16: problema16(); break;
        case 18: problema18(); break;
        default: cout << "Opcion no valida." << endl; break;
        }
    }
    return 0;
}

// --- PROBLEMA 2: Generador Aleatorio ---
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

// --- PROBLEMA 4: Cadena a Entero ---
int cadenaAEntero(char cadena[]) {
    int res = 0;
    for (int i = 0; cadena[i] != '\0'; i++) res = res * 10 + (cadena[i] - '0');
    return res;
}
void problema4() {
    char cadena[20];
    cout << "Ingrese una cadena de numeros: ";
    cin >> cadena;
    int num = cadenaAEntero(cadena);
    cout << "El numero entero es: " << num << endl;
}

// --- PROBLEMA 6: Mayusculas ---
void problema6() {
    char cadena[100];
    cout << "Ingrese una frase: ";
    cin.ignore();
    cin.getline(cadena, 100);
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') cadena[i] -= 32;
    }
    cout << "En mayusculas: " << cadena << endl;
}

// --- PROBLEMA 8: Separar Texto y Numeros ---
void problema8() {
    char original[100], texto[100], numeros[100];
    int t = 0, n = 0;
    cout << "Ingrese una cadena mezcla: ";
    cin.ignore();
    cin.getline(original, 100);
    for (int i = 0; original[i] != '\0'; i++) {
        if (original[i] >= '0' && original[i] <= '9') numeros[n++] = original[i];
        else texto[t++] = original[i];
    }
    texto[t] = '\0'; numeros[n] = '\0';
    cout << "Original: " << original << endl;
    cout << "Texto: " << texto << endl;
    cout << "Numeros: " << numeros << endl;
}

// --- PROBLEMA 10: Romanos a Arabigos ---
int romanToVal(char c) {
    if (c == 'I') return 1; if (c == 'V') return 5;
    if (c == 'X') return 10; if (c == 'L') return 50;
    if (c == 'C') return 100; if (c == 'D') return 500;
    if (c == 'M') return 1000; return 0;
}
void problema10() {
    char romano[20];
    cout << "Ingrese numero romano (MAYUSCULAS): ";
    cin >> romano;
    int total = 0;
    for (int i = 0; romano[i] != '\0'; i++) {
        int s1 = romanToVal(romano[i]);
        if (romano[i+1] != '\0') {
            int s2 = romanToVal(romano[i+1]);
            if (s1 >= s2) total += s1; else total -= s1;
        } else total += s1;
    }
    cout << "El valor es: " << total << endl;
}

// --- PROBLEMA 12: Cuadrado Magico (CON PUNTEROS) ---
void problema12() {
    int n;
    cout << "Ingrese el tamano de la matriz cuadrada: ";
    cin >> n;

    // Uso de puntero y memria dinamica
    int *matriz = new int[n * n];

    cout << "Ingrese los elementos fila por fila:" << endl;
    for (int i = 0; i < n * n; i++) {
        cin >> *(matriz + i); // Acceso por puntero
    }

    // Calculamos la suma de la primera fila como referencia
    int sumaReferencia = 0;
    for (int j = 0; j < n; j++) sumaReferencia += *(matriz + j);

    bool esMagico = true;

    // Verificar filas
    for (int i = 0; i < n; i++) {
        int sumaFila = 0;
        for (int j = 0; j < n; j++) sumaFila += *(matriz + i * n + j);
        if (sumaFila != sumaReferencia) esMagico = false;
    }

    // Verificar columnas
    for (int j = 0; j < n; j++) {
        int sumaCol = 0;
        for (int i = 0; i < n; i++) sumaCol += *(matriz + i * n + j);
        if (sumaCol != sumaReferencia) esMagico = false;
    }

    if (esMagico) cout << "ES un cuadrado magico." << endl;
    else cout << "NO es un cuadrado magico." << endl;

    // liberar la memoria
    delete[] matriz;
}

void problema14(){
    int matriz [5][5];
    int *p = &matriz[0][0]; // iniciamo la matriz
    for (int i = 0; i < 25 ; i++){
        *(p + i) = i + 1;
    }
    //mostramos la matriz originial
    cout << "Matriz Original:"<< endl;
    for (int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout <<matriz[i][j] << "\t";
        }
        cout << endl;
    }
    //rotacion 90 grados (la primera fila se combierte en la ultim fila)
    cout << "\nRotada 90 grados:" <<endl;
    for(int j = 0; j<5; j++){
        for (int i=4; i>=0; i--){
            cout <<matriz[i][j] << "\t";
        }
        cout << endl;
    }
    //rotacion 180 grados (leemos la matriz al reves)
    cout<< "\nRotada 180 grados:" <<endl;
    for (int i=4; i>=0; i--){
        for (int j=4; j>=0; j--){
            cout <<matriz[i][j]<< "\t";
        }
        cout <<endl;
    }
    // 5. Rotacion 270 grados
    cout << "\nRotada 270 grados:" << endl;
    for (int j = 4; j >= 0; j--) {
        for (int i = 0; i < 5; i++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

}

void problema16(){
    int n;
    cout <<"Ingrese  el tamaño de la cuadricula: ";
    cin >> n;
    //usamos double porque el numero de caminios es muy grande
    double caminos = 1;
    //calculamos las combinaciones
    for( int i=1; i<=n; i++){
        caminos = caminos * (n+i)/i;
    }
    //usamos fixed para que no salga en notacion cientifica
    cout.precision(0);
    cout << "Para una malla de " <<n<< "x" <<n<< "hay" <<fixed<< caminos<< "caminos" << endl;
}

void problema18(){
    int n;
    cout << "Ingrese el numero de fila de pascal: ";
    cin >> n;

    long long *fila = new long long[n+1];
    //calculamos los coeficientes binominales
    *(fila +0)=1; //primer elemento siempre 1
    for (int k =1; k<=n; k++){
        *(fila+k) = *(fila+k-1) * (n-k+1)/k;
    }
    cout <<"Los coeficientes de l fila " <<n<< "son: " <<endl;
    for (int i=0; i<=n; i++){
        cout << *(fila+i)<< " ";
    }
    //liberamosla memoria
    delete [] fila;
}
