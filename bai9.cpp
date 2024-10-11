#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <set>
#include <algorithm>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

struct NgayGui {
    int ngay, thang, nam;
};

struct SoTietKiem {
    string maSo;             
    string loaiTietKiem;     
    string hoTenKhachHang;   
    string cmnd;                
    NgayGui ngaygui;   
    long long soTienGui;       
    double laiSuat;
    long long soThangGui;
};

vector <SoTietKiem> arr;
set <string> list_maSo;

bool checkMaSo(string &maSo) {
    if (maSo.length() > 5) return false;
    for (char c : maSo) {
        if (!isalpha(c) && !isdigit(c)) return false;
    }
    return true;
}

bool checkLoaiTK(string &loaiTietKiem) {
    if (loaiTietKiem.length() > 10) return false;
    for (char c : loaiTietKiem) {
        if (!isalpha(c) && !isdigit(c) && !isspace(c)) return false;
    }
    return true;
}

bool checkTen(string &ten) {
    if (ten.length() < 1 || ten.length() > 30) {
        return false;
    }

    for (char c : ten) {
        if (!isalpha(c) && !isspace(c)) return false;
    }

    if (!isupper(ten[0])) return false;

    for (int i = 1; i < ten.length(); i++) {
        if ((isupper(ten[i]) && ten[i - 1] != ' ') || (islower(ten[i]) && ten[i - 1] == ' ')) return false;
    }

    return true;
}

bool checkCMND(string &CMND) {
    if (CMND.length() != 9 && CMND.length() != 12) return false;
    for (char c : CMND) {
        if (!isdigit(c)) return false;
    }
    return true;
}

bool checkNG(int day, int month, int year) {
    if (year < 0) return false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[1] = 29;

    if (month < 0 || month > 12) return false;
    if (day < 0 || day > days[month - 1]) return false;
    return true;
}

void themSTK() {
    string maSo, loaiTietKiem, hoTenKhachHang, CMND;
    NgayGui ngaygui;
    long long soTienGui;

    while (true) {
        cout << "Nhập mã sổ: "; cin >> maSo;
        if (!checkMaSo(maSo) || list_maSo.find(maSo) != list_maSo.end()) cout << "Mã sổ tiết kiệm không hợp lệ!!\n";
        else break;
    }    

    cin.ignore();


    while (true) {
        cout << "Nhập loại tiết kiệm: "; 
        getline(cin, loaiTietKiem);
        if (!checkLoaiTK(maSo)) cout << "Loại tiết kiệm không hợp lệ!!\n";
        else break;
    }    

    while (true) {
        cout << "Nhập họ và tên: "; getline(cin, hoTenKhachHang);
        if (!checkTen(hoTenKhachHang)) cout << "Họ và tên không hợp lệ!!\n";
        else break;
    }  


    while (true) {
        cout << "Nhập CMND: "; getline(cin, CMND);
        if (!checkCMND(CMND)) cout << "CMND không hợp lệ!!\n";
        else break;
    }

    while (true) {
        cout << "Nhập ngày gửi (dd mm yyyy): "; cin >> ngaygui.ngay >> ngaygui.thang >> ngaygui.nam;
        if (!checkNG(ngaygui.ngay, ngaygui.thang, ngaygui.nam)) cout << "Ngày này không tồn tại!!!\n";
        else break;
    }

    while (true) {
        cout << "Nhập số tiền cần gửi: "; cin >> soTienGui;
        if (soTienGui < 0) cout << "Số tiền gửi không hợp lệ\n";
        else break;
    }

    arr.push_back(SoTietKiem({maSo, loaiTietKiem, hoTenKhachHang, CMND, ngaygui, soTienGui, 0.7, (2024 - ngaygui.nam) * 12 + 10 - ngaygui.thang}));
}

void xuat(const SoTietKiem& sotietiem) {
    cout << "\n-------------" << sotietiem.maSo << "----------------\n";
    cout << "Loại tiết kiệm: " << sotietiem.loaiTietKiem << endl;
    cout << "Họ và tên: " << sotietiem.hoTenKhachHang << endl;
    cout << "CMND: " << sotietiem.cmnd << endl;
    cout << "Ngày mở sổ: " << sotietiem.ngaygui.ngay << "/" << sotietiem.ngaygui.thang << "/" << sotietiem.ngaygui.nam << endl;
    cout << "Số tiền còn lại: " << sotietiem.soTienGui << endl; 
}

void xuatDS() {
    for (auto i : arr) {
        xuat(i);
    }
}

void capNhatLS() {

}

double tinhTienLai(const SoTietKiem &stk, double laiSuat, int soThangGui) {
    if (stk.loaiTietKiem == "ngan han" && soThangGui <= 6) {
        return stk.soTienGui * laiSuat * soThangGui / 12;
    } else if (stk.loaiTietKiem == "dai han" && soThangGui > 6) {
        return stk.soTienGui * laiSuat * soThangGui / 12;
    }
    return 0;
}

void sapXepTheoSoTien() {
    sort(arr.begin(), arr.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
        return a.soTienGui > b.soTienGui;
    });
}

void sapXepTheoNgayMoSo() {
    sort(arr.begin(), arr.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
        if (a.ngaygui.nam != b.ngaygui.nam) return a.ngaygui.nam < b.ngaygui.nam;
        if (a.ngaygui.thang != b.ngaygui.thang) return a.ngaygui.thang < b.ngaygui.thang;
        return a.ngaygui.ngay < b.ngaygui.ngay;
    });
}

string menu = 
"\n======== MENU ========\n"
"1. Thêm thông tin sổ tiết kiệm\n"
"2. Xuất danh sách sổ tiết kiệm\n"
"3. Cập nhật lãi suất\n"
"4. Tính toán tiền lãi\n"
"5. Rút tiền\n"
"6. Tìm kiếm sổ tiết kiệm theo CMND\n"
"7. Sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần\n"
"8. Sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần\n"
"0. Thoát\n"
"======================\n"
"Nhập lựa chọn của bạn: ";

int main() {
    int choic;
    do {
        cout << menu; cin >> choic;
        switch (choic) {
        
        case 0:
            return 0;
        case 1:
            themSTK();
            break;
        case 2:
            xuatDS();
            break;
        case 3:
            capNhatLS();
            break;
        case 4:
            break;
        case 5: 
            break;
        case 6:
            break;
        case 7: 
            sapXepTheoSoTien();
            break;
        case 8: 
            sapXepTheoNgayMoSo();
            break;


        default:
            cout << "Lựa chọn không hợp lệ!!! \n";
            break;
        }    
    } while (choic != 0);
}

