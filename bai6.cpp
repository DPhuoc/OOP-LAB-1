#include <iostream>
#include <vector>
using namespace std;

const long long MAXN = 1e6 + 10;
int arrA[MAXN], arrB[MAXN], n, m, f[MAXN];
vector <int> pos;

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> arrA[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> arrB[i];
    }


    // Tính mảng lùi KMP (mảng f) cho chuỗi con arrA
    f[1] = 0;  
    for (int i = 2, j = 0; i <= n; i++) {
        while (j > 0 && arrA[j + 1] != arrA[i]) j = f[j]; 
        if (arrA[j + 1] == arrA[i]) j++;  
        f[i] = j; 
    }


    // Tìm vị trí xuất hiện của arrA trong arrB bằng KMP
    for (int i = 1, j = 0; i <= m; i++) {
        while (j > 0 && arrA[j + 1] != arrB[i]) j = f[j]; 
        if (arrA[j + 1] == arrB[i]) j++;  
        if (j == n) {
            pos.push_back(i - n);
            j = f[j];  
        }
    }

    cout << pos.size() << endl;
    for (auto i : pos) {
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}