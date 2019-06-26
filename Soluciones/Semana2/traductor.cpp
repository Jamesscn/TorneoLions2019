#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int tamano;
    cin >> tamano;
    map<string, string> diccionario;
    for(int i = 0; i < tamano; i++) {
        string original, traduccion;
        cin >> original >> traduccion;
        diccionario[original] = traduccion;
    }
    string frase;
    getline(cin, frase);
    getline(cin, frase);
    vector<string> palabras;
    string actual = "";
    for(int i = 0; i < frase.length(); i++) {
        if(frase[i] != ' ') {
            actual += frase[i];
        } else {
            palabras.push_back(actual);
            actual = "";
        }
    }
    palabras.push_back(actual);
    for(int i = 0; i < palabras.size(); i++) {
        cout << diccionario[palabras[i]] << " ";
    }
    cout << endl;
}