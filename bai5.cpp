#include <iostream>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

void out(int &day, int &month, int &year) {
    cout << day << "/" << month << "/" << year << endl;
}

/**
 * @param day   Ngày hiện tại (giá trị nhập vào).
 * @param month Tháng hiện tại (giá trị nhập vào).
 * @param year  Năm hiện tại (giá trị nhập vào).
 * 
 * @brief Tính và hiển thị ngày kế tiếp dựa trên ngày, tháng, năm hiện tại. 
 * Hàm này kiểm tra xem ngày hiện tại có phải là ngày cuối cùng của tháng không.
 * - Nếu không phải, ngày sẽ tăng thêm 1.
 * - Nếu là ngày cuối cùng của tháng:
 *   - Nếu là tháng 12, ngày kế tiếp là 1/1 của năm tiếp theo.
 *   - Nếu không, ngày kế tiếp là ngày 1 của tháng sau trong cùng năm.
 * 
 * Đầu ra: In ngày kế tiếp (định dạng dd/mm/yyyy).
 */
void nextDay(int day, int month, int year) {
    if (day < days[month - 1]) day++;
    else {
        day = 1;
        if (month == 12) {
            month = 1;
            year++;
        }
        else month++;
    }

    cout << "Ngày kế tiếp là: "; out(day, month, year);
}

/**
 * @param day   Ngày hiện tại (giá trị nhập vào).
 * @param month Tháng hiện tại (giá trị nhập vào).
 * @param year  Năm hiện tại (giá trị nhập vào).
 * 
 * @brief Tính và hiển thị ngày trước đó dựa trên ngày, tháng, năm hiện tại.
 * - Nếu không phải ngày đầu tiên của tháng, giảm ngày xuống 1.
 * - Nếu là ngày đầu tiên của tháng:
 *   - Nếu là tháng 1, lùi về tháng 12 của năm trước, ngày là 31.
 *   - Nếu không, lùi về tháng trước đó, ngày là ngày cuối cùng của tháng trước.
 * 
 * Đầu ra: In ra ngày trước đó (định dạng dd/mm/yyyy).
 */
void previousDay(int day, int month, int year) {
    if (day > 1) day--;
    else {
        if (month == 1) {
            month = 12;
            year--;
        } else month--;
        day = days[month - 1];
    }

    cout << "Ngày trước đó là: "; out(day, month, year);
}

/**
 * @param day   Ngày hiện tại (giá trị nhập vào).
 * @param month Tháng hiện tại (giá trị nhập vào).
 * @param year  Năm hiện tại (giá trị nhập vào).
 * 
 * @brief Tính toán và hiển thị ngày thứ bao nhiêu trong năm dựa trên ngày, tháng hiện tại.
 * Hàm tính tổng số ngày từ tháng 1 đến tháng hiện tại và cộng thêm số ngày của tháng hiện tại.
 * 
 * Đầu ra: In ra thứ tự của ngày hiện tại trong năm.
 */
void daynth(int day, int month, int year) {
    int cnt = 0;
    for (int i = 0; i < month - 1; i++) {
        cnt += days[i];
    }
    cout << "Đây là ngày thứ " << cnt + day << " trong năm\n";
}

/**
 * @param day   Ngày hiện tại cần kiểm tra.
 * @param month Tháng hiện tại cần kiểm tra.
 * @param year  Năm hiện tại cần kiểm tra.
 * 
 * @brief Kiểm tra tính hợp lệ của ngày, tháng và năm.
 * - Đặt số ngày của tháng 2 mặc định là 28.
 * - Kiểm tra năm có phải là năm nhuận không:
 *   - Nếu là năm nhuận, tháng 2 có 29 ngày.
 * - Kiểm tra giá trị của tháng (1 <= month <= 12).
 * - Kiểm tra giá trị của ngày có nằm trong giới hạn của tháng tương ứng hay không.
 * 
 * Đầu ra: Trả về `true` nếu ngày tháng năm hợp lệ, `false` nếu không hợp lệ.
 */
bool legit(int day, int month, int year) {
    days[1] = 28;
    if (year < 0) return false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[1] = 29;

    if (month < 0 || month > 12) return false;
    if (day < 0 || day > days[month - 1]) return false;
    return true;
}

int main() {
    int day, month, year;
    
    do {
        cout << "Nhập ngày: "; cin >> day;
        cout << "Nhập tháng: "; cin >> month;
        cout << "Nhập năm: "; cin >> year;
        if (legit(day, month, year) == false) cout << "Ngày bạn nhập không hợp lệ!!\n";
    } while (legit(day, month, year) == false);

    nextDay(day, month, year);
    previousDay(day, month, year);
    daynth(day, month, year);
}