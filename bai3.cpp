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

void sumFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1 + numer1 * denom0;
    int mauKQ = denom0 * denom1;
    reduce(tuKQ, mauKQ);
    cout << "Tổng của hai phân số: ";
    out(tuKQ,  mauKQ);
}

void minusFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1 - numer1 * denom0;
    int mauKQ = denom0 * denom1;
    reduce(tuKQ, mauKQ);
    cout << "Hiệu của hai phân số: ";
    out(tuKQ,  mauKQ);  
}

void mulFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * numer1;
    int mauKQ = denom0 * denom1;
    reduce(tuKQ, mauKQ);
    cout << "Tích của hai phân số: ";
    out(tuKQ,  mauKQ);  
}

void divFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1;
    int mauKQ = denom0 * numer1;
    reduce(tuKQ, mauKQ);
    cout << "Thương của hai phân số: ";
    out(tuKQ,  mauKQ);  
}

int main() {
    int numer0, denom0, numer1, denom1;

    do {
        cout << "Nhập phân số thứ nhất: \n";
        cout << "+ Tử số: "; cin >> numer0;
        cout << "+ Mẫu số: "; cin >> denom0;
        if (denom0 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom0 == 0);

    do {
        cout << "Nhập phân số thứ hai: \n";
        cout << "+ Tử số: "; cin >> numer1;
        cout << "+ Mẫu số: "; cin >> denom1;
        if (denom1 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom1 == 0);

    sumFr(numer0, denom0, numer1, denom1);
    minusFr(numer0, denom0, numer1, denom1);
    mulFr(numer0, denom0, numer1, denom1);
    divFr(numer0, denom0, numer1, denom1);

}
