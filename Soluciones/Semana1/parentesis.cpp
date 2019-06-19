#include <iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    int respuestaA = 0, respuestaB = 0;
    int cuenta = 0;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            cuenta++;
        } else if (str[i] == ')') {
            cuenta--;
        }
        if(cuenta < 0) {
            respuestaB++;
            cuenta = 0;
        }
    }
    respuestaA = cuenta;
    cout << respuestaA << " " << respuestaB << endl;  
}