#include <iostream>

using namespace std;

int main() {
    long long int n;
    long long int a = 2;
    cin >> n;
    while(n % a != 0) {
        a++;
    }
    cout << a << " " << n / a << endl;
}