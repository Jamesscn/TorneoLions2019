#include<iostream>
using namespace std;
int a = 0,x,y = 0,z = 0, k = 0;
int main(){
    int n;
	cin>>n;
	while(n--){
        int x;
	    cin>>x;
        y+=(x>=a?1:-y+1);
        z=(y>=z?y:z);
		a=x;
	}
	cout<<z;
}