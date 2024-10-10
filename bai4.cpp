#include <iostream>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;

double gt[40];  

/**
 * @brief Tính xấp xỉ giá trị của hàm sin(x) bằng chuỗi Taylor.
 * 
 * Hàm này tính giá trị gần đúng của sin(x) bằng cách sử dụng chuỗi Taylor quanh gốc 0:
 * sin(x) = x - x^3/3! + x^5/5! - x^7/7! + ...
 * 
 * Chuỗi được tính cho đến khi giá trị tuyệt đối của các hạng tử trong chuỗi nhỏ hơn 
 * giá trị `precision` đã xác định, nghĩa là phép tính đã đạt độ chính xác mong muốn.
 * 
 * Đầu vào:
 * @param x Giá trị cần tính hàm sin (góc tính bằng radian).
 * 
 * Đầu ra:
 * @return Giá trị gần đúng của sin(x).
 */
double sinX(double x) {
    // Giới hạn giá trị x trong khoảng [0, 2π] để tăng hiệu quả tính toán
    x = fmod(x, 2 * M_PI);

    double term = x;  // Khởi tạo hạng tử đầu tiên của chuỗi Taylor (x)
    double sinValue = x;  // Giá trị sin ban đầu bằng hạng tử đầu tiên
    int n = 0;  // Chỉ số n trong chuỗi Taylor
    double precision = 0.00001;  // Độ chính xác yêu cầu

    // Tính chuỗi Taylor cho đến khi độ lớn của hạng tử < precision
    while (fabs(term) >= precision) {
        n++;  // Tăng chỉ số n
        // Tính hạng tử tiếp theo trong chuỗi Taylor: (-1)^n * x^(2n+1) / (2n+1)!
        term = pow(-1, n) * pow(x, 2 * n + 1) / gt[2 * n + 1];  
        sinValue += term;  // Cộng hạng tử vào giá trị sin tổng
    }
    return sinValue;  // Trả về giá trị sin(x) xấp xỉ
}

int main() {
    // Khởi tạo mảng giai thừa từ 0! đến 25!
    gt[0] = 1;
    for (int i = 1; i <= 25; i++) {  
        gt[i] = gt[i - 1] * i;  // gt[i] = i!
    }

    // Nhập giá trị góc x (đơn vị radian) từ người dùng
    double x;
    cout << "Nhập giá trị X (radian): "; 
    cin >> x;

    // Định dạng kết quả với 6 chữ số thập phân
    cout << fixed << setprecision(6);

    // Tính và hiển thị giá trị của sin(x)
    cout << "Giá trị của sin(" << x << ") là: " << sinX(x) << endl;

    return 0;
}