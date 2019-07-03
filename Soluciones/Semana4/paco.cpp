#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <string>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=s; m>=n; m-=u)
#define FORb(m,s,n,u,k) for(int m=2; m<n&&k; m+=u)
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;
 
vector <int> tree[1000000];
int paradasDeCamion = 0;
bool visited[1000000];
int isValid;
void dfs(int cuantasVan, int anterior, int localizacionDeDistracciones[], int vertices, int distracciones){
    visited[anterior]=true;
    int cuantasDistracciones = 0;
    if((cuantasVan)>distracciones) return;
    isValid = 1;
    for(int i=0; i<tree[anterior].size(); i++){
        if(!visited[tree[anterior][i]]){
            if(localizacionDeDistracciones[tree[anterior][i]]==1) cuantasDistracciones=cuantasVan+1;
            if(localizacionDeDistracciones[tree[anterior][i]]==0) cuantasDistracciones=0;
            dfs(cuantasDistracciones, tree[anterior][i], localizacionDeDistracciones, vertices, distracciones);
            isValid=0;
        }
    }
    paradasDeCamion+=isValid;
}
 
int main(){
    sync;
    int vertices,distracciones;
    cin>>vertices>>distracciones;
    int localizacionDeDistracciones[vertices+1];
    int x,y;
    FOR(i,0,vertices,1) cin>>localizacionDeDistracciones[i+1];
    for(int i=0; i<vertices-1; i++){
        cin>>x>>y;
        tree[x].pb(y);
        tree[y].pb(x);
    }
    int cantidadDeGatos = localizacionDeDistracciones[1];//en el trabajo
    dfs(cantidadDeGatos,1,localizacionDeDistracciones,vertices,distracciones);
    cout<<paradasDeCamion<<endl;
    cout<<"Paco trabaja en Google"<<endl;
    return 0;
}