#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Rút gọn phân số bằng cách chia tử số và mẫu số cho ước chung lớn nhất (GCD).
 * 
 * @param numer Tham chiếu tới tử số của phân số. (Cần được rút gọn)
 * @param denom Tham chiếu tới mẫu số của phân số. (Cần được rút gọn)
 * 
 * @return Không có giá trị trả về, nhưng tham chiếu tới các tham số 
 *         numer và denom sẽ được cập nhật với giá trị đã rút gọn.
 */
void reduce(int &numer, int &denom) {
    // Tính ước chung lớn nhất của tử số và mẫu số
    int tmp = __gcd(numer, denom);

    // Chia tử số và mẫu số cho GCD để rút gọn phân số
    numer /= tmp;
    denom /= tmp;

    // Đảm bảo mẫu số luôn dương
    if (denom < 0) {
        denom = -denom; // Chuyển mẫu số thành dương
        numer = -numer; // Đổi dấu tử số
    }
}

/**
 * @brief In ra phân số dưới dạng tử số và mẫu số.
 * 
 * @param numer Tham chiếu tới tử số của phân số. 
 *              Đây là giá trị sẽ được in ra đầu tiên.
 * @param denom Tham chiếu tới mẫu số của phân số.
 *              Mẫu số sẽ được in ra nếu tử số khác 0 và mẫu số khác 1.
 * 
 * @return Không có giá trị trả về, nhưng hàm sẽ in ra kết quả lên màn hình.
 */
void out(int &numer, int &denom) {
    cout << numer; // In ra tử số
    if (numer != 0 && denom != 1) {
        cout << " / " << denom; // In ra mẫu số nếu tử số khác 0 và mẫu số không bằng 1
    }
    cout << "\n"; // Xuống dòng
}

/**
 * @brief Tính tổng của hai phân số và in ra kết quả.
 * 
 * Hàm này thực hiện phép tính tổng của hai phân số bằng công thức:
 * (numer0/denom0) + (numer1/denom1) = (numer0 * denom1 + numer1 * denom0) / (denom0 * denom1).
 * Sau đó, phân số kết quả được rút gọn và in ra.
 * 
 * @param numer0 Tử số của phân số thứ nhất.
 * @param denom0 Mẫu số của phân số thứ nhất.
 * @param numer1 Tử số của phân số thứ hai.
 * @param denom1 Mẫu số của phân số thứ hai.
 */
void sumFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1 + numer1 * denom0;  // Tử số kết quả
    int mauKQ = denom0 * denom1;  // Mẫu số kết quả
    reduce(tuKQ, mauKQ);  // Rút gọn phân số kết quả
    cout << "Tổng của hai phân số: ";
    out(tuKQ,  mauKQ);  // In kết quả
}

/**
 * @brief Tính hiệu của hai phân số và in ra kết quả.
 * 
 * Hàm này thực hiện phép tính hiệu của hai phân số bằng công thức:
 * (numer0/denom0) - (numer1/denom1) = (numer0 * denom1 - numer1 * denom0) / (denom0 * denom1).
 * Sau đó, phân số kết quả được rút gọn và in ra.
 * 
 * @param numer0 Tử số của phân số thứ nhất.
 * @param denom0 Mẫu số của phân số thứ nhất.
 * @param numer1 Tử số của phân số thứ hai.
 * @param denom1 Mẫu số của phân số thứ hai.
 */
void minusFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1 - numer1 * denom0;  // Tử số kết quả
    int mauKQ = denom0 * denom1;  // Mẫu số kết quả
    reduce(tuKQ, mauKQ);  // Rút gọn phân số kết quả
    cout << "Hiệu của hai phân số: ";
    out(tuKQ,  mauKQ);  // In kết quả
}

/**
 * @brief Tính tích của hai phân số và in ra kết quả.
 * 
 * Hàm này thực hiện phép tính tích của hai phân số bằng công thức:
 * (numer0/denom0) * (numer1/denom1) = (numer0 * numer1) / (denom0 * denom1).
 * Sau đó, phân số kết quả được rút gọn và in ra.
 * 
 * @param numer0 Tử số của phân số thứ nhất.
 * @param denom0 Mẫu số của phân số thứ nhất.
 * @param numer1 Tử số của phân số thứ hai.
 * @param denom1 Mẫu số của phân số thứ hai.
 */
void mulFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * numer1;  // Tử số kết quả
    int mauKQ = denom0 * denom1;  // Mẫu số kết quả
    reduce(tuKQ, mauKQ);  // Rút gọn phân số kết quả
    cout << "Tích của hai phân số: ";
    out(tuKQ,  mauKQ);  // In kết quả
}

/**
 * @brief Tính thương của hai phân số và in ra kết quả.
 * 
 * Hàm này thực hiện phép tính thương của hai phân số bằng công thức:
 * (numer0/denom0) / (numer1/denom1) = (numer0 * denom1) / (denom0 * numer1).
 * Sau đó, phân số kết quả được rút gọn và in ra.
 * 
 * @param numer0 Tử số của phân số thứ nhất.
 * @param denom0 Mẫu số của phân số thứ nhất.
 * @param numer1 Tử số của phân số thứ hai.
 * @param denom1 Mẫu số của phân số thứ hai.
 */
void divFr(int numer0, int denom0, int numer1, int denom1) {
    int tuKQ = numer0 * denom1;  // Tử số kết quả
    int mauKQ = denom0 * numer1;  // Mẫu số kết quả
    reduce(tuKQ, mauKQ);  // Rút gọn phân số kết quả
    cout << "Thương của hai phân số: ";
    out(tuKQ,  mauKQ);  // In kết quả
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
