#include <iostream>

using namespace std;

unsigned long long int max(unsigned long long int a, unsigned long long int b) {
    if(a > b) {
        return a;
    }
    return b;
}

int main() {                                                                                                                                             
    int n, m;
    cin >> n >> m;
    unsigned long long int rancho[n][m];                                                                                                            
    for (int i = 0; i < n; i++) {                                                                                                                         
        for (int j = 0; j < m; j++) {  
            unsigned long long int suma = 0;                                                                                                                   
            if(i > 0) {
                suma += rancho[i - 1][j];
            }
            if(j > 0) {
                suma += rancho[i][j - 1];
            }
            rancho[i][j] = max(1, suma);                                                                  
        }                                                                                                                                                
    }
    cout << rancho[n - 1][m - 1] << endl;                                                                                                                                                                                                                                                                                                                                                  
} 