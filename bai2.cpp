#include <iostream>
#include <algorithm>
using namespace std;

void reduce(int &numer, int &denom) {
    int tmp = __gcd(numer, denom);
    numer /= tmp;
    denom /= tmp;

    if (denom < 0) {
        denom = -denom;
        numer = -numer;
    }
}

void out(int &numer, int &denom) {
    cout << numer;
    if (numer != 0 && denom != 1) {
        cout << " / " << denom;
    }
    cout << endl;
}

int main() {
    int numer0, denom0, numer1, denom1;

    do {
        cout << "Nhập phân số thứ nhất: \n";
        cout << "+ Tử số: "; cin >> numer0;
        cout << "+ Mẫu số: "; cin >> denom0;
        if (denom0 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom0 == 0);
    reduce(numer0, denom0);

    do {
        cout << "Nhập phân số thứ hai: \n";
        cout << "+ Tử số: "; cin >> numer1;
        cout << "+ Mẫu số: "; cin >> denom1;
        if (denom1 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom1 == 0);
    reduce(numer1, denom1);

    cout << "Phân số lớn hơn là: "; 

    if (numer0 * denom1 > numer1 * denom0) out(numer0, denom0);
    else out(numer1, denom1);
    
}
