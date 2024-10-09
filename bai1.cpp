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
    cout << "\n";
}

int main() {
    int numer, denom;

    do {
        cout << "Nhập phân số: \n";
        cout << "+ Tử số: "; cin >> numer;
        cout << "+ Mẫu số: "; cin >> denom;
        if (denom == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom == 0);
    
    reduce(numer, denom);
    out(numer, denom);
}
