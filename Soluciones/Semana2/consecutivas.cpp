#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int cantidad, suma;
        cin >> cantidad >> suma;
        int pivote;
        if(cantidad % 2 == 0) {
            if(suma % cantidad == cantidad / 2) {
                pivote = (suma + cantidad / 2) / cantidad;
            } else {
                cout << "NO EXISTE" << endl;
                continue;
            }
        } else {
            if(suma % cantidad == 0) {
                pivote = suma / cantidad;
            } else {
                cout << "NO EXISTE" << endl;
                continue;
            }
        }
        for(int j = 0; j < cantidad; j++) {
            cout << pivote - cantidad / 2 + j << " ";
        }
        cout << endl;
    }
}