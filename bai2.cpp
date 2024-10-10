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

int main() {
    int numer0, denom0, numer1, denom1;  // Khai báo các biến để lưu tử số và mẫu số của hai phân số

    // Nhập và rút gọn phân số thứ nhất
    do {
        cout << "Nhập phân số thứ nhất: \n";
        cout << "+ Tử số: "; cin >> numer0;
        cout << "+ Mẫu số: "; cin >> denom0;
        if (denom0 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom0 == 0);
    reduce(numer0, denom0);  // Gọi hàm để rút gọn phân số

    // Nhập và rút gọn phân số thứ hai
    do {
        cout << "Nhập phân số thứ hai: \n";
        cout << "+ Tử số: "; cin >> numer1;
        cout << "+ Mẫu số: "; cin >> denom1;
        if (denom1 == 0) cout << "Mẫu của phân số không thể khác 0 \n";
    } while (denom1 == 0);
    reduce(numer1, denom1);  // Gọi hàm để rút gọn phân số
 
    // Kiểm tra nếu hai phân số bằng nhau
    if (numer0 * denom1 == numer1 * denom0) {
        cout << "Hai phân số bằng nhau\n";  // Nếu hai phân số bằng nhau, in ra thông báo
        return 0;  // Kết thúc chương trình khi hai phân số bằng nhau
    }
    
    // So sánh và in ra phân số lớn hơn
    cout << "Phân số lớn hơn là: "; 

    if (numer0 * denom1 > numer1 * denom0) 
        out(numer0, denom0);  // In ra phân số thứ nhất nếu lớn hơn
    else 
        out(numer1, denom1);  // In ra phân số thứ hai nếu lớn hơn
}