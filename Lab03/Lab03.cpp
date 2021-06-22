#include <ctime>
#include <iostream>
#include <cstdio>

#define SIZE 10

using namespace std;

int contador_brute = 0;
int contador_smart = 0;

// initiate the matrix
void int_matrix(int m[][SIZE]) {
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            m[i][j] = counter++;
        }
    }
}

// search is O(n2)
bool brute_search(int m[][SIZE], int key) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            contador_brute++;
            if (m[i][j] == key) return true;
        }
    }
    return false;

}

// search is O(n)
bool smart_search(int m[][SIZE], int key) {
    int row = SIZE - 1;
    int col = 0;

    while (row >= 0 && col < SIZE) {
        contador_smart++;
        if (m[row][col] == key) return true;
        else if (m[row][col] > key) row = row--;
        else if (m[row][col] < key) col = col++;
    }

    return false;
}

int main()
{
    int num;
    int matrix[SIZE][SIZE];

    // initializes matrix
    int_matrix(matrix);

    // enter the key
    printf("Entre com um numero a ser buscado: ");
    cin >> num;
    printf("\n");

    // search
    if (brute_search(matrix, num)) {
        cout << "Brute: Encontrei o numero " << num << ", apos " << contador_brute << " comparacoes." << endl;
    }
    else {
        cout << "Brute: Nao foi possivel encontrar o numero, apos " << contador_brute << " comparacoes." << endl;
    }

    if (smart_search(matrix, num)) {
        cout << "Smart: Encontrei o numero " << num << ", apos " << contador_smart << " comparacoes." << endl;
    }
    else {
        cout << "Smart: Nao foi possivel encontrar o numero, apos " << contador_smart << " comparacoes." << endl;
    }

    return 0;
}

