#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int main() {
    int amistades;
    cin >> amistades;
    vector<set<string>> grupos;
    map<string, vector<string>> relaciones;
    map<string, bool> visitado;
    set<string> personas;
    for(int i = 0; i < amistades; i++) {
        string a, b;
        cin >> a >> b;
        relaciones[a].push_back(b);
        relaciones[b].push_back(a);
        visitado[a] = false;
        visitado[b] = false;
        personas.insert(a);
        personas.insert(b);
    }
    int indiceGrupo = 0;
    for(set<string>::iterator it = personas.begin(); it != personas.end(); it++) {
        string persona = *it;
        if(visitado[persona]) {
            continue;
        }
        set<string> grupo;
        queue<string> recorrido;
        recorrido.push(persona);
        while(recorrido.size() > 0) {
            string actual = recorrido.front();
            recorrido.pop();
            visitado[actual] = true;
            grupo.insert(actual);
            for(int i = 0; i < relaciones[actual].size(); i++) {
                if(!visitado[relaciones[actual][i]]) {
                    recorrido.push(relaciones[actual][i]);
                }
            }
        }
        grupos.push_back(grupo);
        indiceGrupo++;
    }
    for(int i = 0; i < indiceGrupo; i++) {
        for(set<string>::iterator it = grupos[i].begin(); it != grupos[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}