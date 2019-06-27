#include <iostream>

using namespace std;

int main() {
    long long int n, a = 2;
    cin >> n;
    while(n % a != 0) {
        a++;
    }
    cout << a << " " << n / a << endl;
}
