#include <iostream>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

void out(int &day, int &month, int &year) {
    cout << day << "/" << month << "/" << year << endl;
}

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

void daynth(int day, int month, int year) {
    int cnt = 0;
    for (int i = 0; i < month - 1; i++) {
        cnt += days[i];
    }
    cout << "Đây là ngày thứ " << cnt + day << " trong năm\n";
}

bool legit(int day, int month, int year) {
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