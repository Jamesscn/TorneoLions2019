#include <iostream>

using namespace std;

int main() {
    int accumulative[1000001];
    int sum = 0;
    for(int i = 0; i < 1000001; i++) {
        int num = i;
        while(num > 0) {
            sum += num % 2;
            num /= 2;
        }
        accumulative[i] = sum;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int min, max;
        cin >> min >> max;
        cout << accumulative[max] - accumulative[min] << endl;
    }
}