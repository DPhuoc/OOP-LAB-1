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
    int numer, denom;

    do {
        // Yêu cầu người dùng nhập vào một phân số
        cout << "Nhập phân số: \n";
        
        // Nhập tử số từ người dùng
        cout << "+ Tử số: "; 
        cin >> numer;
        
        // Nhập mẫu số từ người dùng
        cout << "+ Mẫu số: "; 
        cin >> denom;
        
        // Kiểm tra nếu mẫu số bằng 0, in ra thông báo lỗi
        if (denom == 0) 
            cout << "Mẫu của phân số không thể khác 0 \n";
            
    // Lặp lại quá trình nhập cho đến khi mẫu số khác 0
    } while (denom == 0);
    
    // Gọi hàm reduce để rút gọn phân số
    reduce(numer, denom);

    // Gọi hàm out để in ra phân số sau khi rút gọn
    out(numer, denom);
}
