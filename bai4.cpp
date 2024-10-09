#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;

double gt[40];  

double sinX(double x) {
    x = fmod(x, 2 * M_PI);

    double term = x;
    double sinValue = x;
    int n = 0;
    double precision = 0.00001;

    while (fabs(term) >= precision) {
        n++;
        term = pow(-1, n) * pow(x, 2 * n + 1) / gt[2 * n + 1];  
        sinValue += term;
    }
    return sinValue; 
}

int main() {
    gt[0] = 1;
    for (int i = 1; i <= 25; i++) {  
        gt[i] = gt[i - 1] * i;
    }

    double x;
    cout << "Nhập giá trị X (radiant): "; 
    cin >> x;

    cout << fixed << setprecision(6);
    cout << "Giá trị của sin(" << x << ") là: " << sinX(x) << endl;

    return 0;
}