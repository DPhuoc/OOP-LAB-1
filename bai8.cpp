#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};

struct NgayBay {
    int ngay, thang, nam;
};

struct GioBay {
    int gio, phut;
};

struct ChuyenBay {
    string macb;
    NgayBay ngaybay;
    GioBay giobay;
    string noidi, noiden;
};

vector <ChuyenBay> arr;
set <string> list_macb;

bool checkNB(int day, int month, int year) {
    if (year < 0) return false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[1] = 29;

    if (month < 0 || month > 12) return false;
    if (day < 0 || day > days[month - 1]) return false;
    return true;
}

bool checkMaCB(string &macb) {
    if (macb.length() != 5) return false;
    for (char c : macb) {
        if (!isalpha(c) && !isdigit(c)) return false;
    }
    return true;
}

bool checkGB(int &gio, int &phut) {
    if (gio < 0 || gio > 24 || phut < 0 || phut > 60) return false;
    return true;
}

bool checkLoca(string &diadiem) {
    if (diadiem.length() < 0 || diadiem.length() > 20) return false;

    for (char c : diadiem) {
        if (!isalpha(c) && !isspace(c)) return false;
    }

    return true;
}

void ThemChuyenBay() {
    int n;
    cout << "Số lượng chuyến bay cần thêm: "; cin >> n;

    while (n--) {
        string macb;
        NgayBay ngaybay;
        GioBay giobay;
        string noidi, noiden;

        cin.ignore();
        while (true) {
            cout << "Nhập mã chuyến bay: "; getline(cin, macb);
            if (!checkMaCB(macb) || list_macb.find(macb) != list_macb.end()) cout << "Mã chuyến bay không hợp lệ!!\n";
            else break;
        }

        while (true) {
            cout << "Nhập ngày bay (dd mm yyyy): "; cin >> ngaybay.ngay >> ngaybay.thang >> ngaybay.nam;
            if (!checkNB(ngaybay.ngay, ngaybay.thang, ngaybay.nam)) cout << "Ngày này không tồn tại!!!\n";
            else break;
        }

        while (true) {
            cout << "Nhập giờ bay (hh mm): "; cin >> giobay.gio >> giobay.phut;
            if (!checkGB(giobay.gio, giobay.phut)) cout << "Giờ này không tồn tại!!\n";
            else break;
        }

        cin.ignore();
        while (true) {
            cout << "Nhập nơi đi: "; getline(cin, noidi);
            cout << "Nhập nơi đến: "; getline(cin, noiden);
            if (!checkLoca(noidi) || !checkLoca(noiden)) cout << "Địa điểm không hợp lệ!!\n";
            else break;
        }

        arr.push_back(ChuyenBay({macb, ngaybay, giobay, noidi, noiden}));
        list_macb.insert(macb);
    }
}

void inThongTin(const ChuyenBay& a) {
    cout << "---------------" << a.macb << "------------------\n";
    cout << "Ngày bay: " << a.ngaybay.ngay << "/" << a.ngaybay.thang << "/" << a.ngaybay.nam << endl;
    cout << "Giờ bay: " << a.giobay.gio << ":" << a.giobay.phut << endl;
    cout << "Bay từ: " << a.noidi << endl;
    cout << "Đến: " << a.noiden << endl;
}

bool cmp(const ChuyenBay& a, const ChuyenBay& b) {
    if (a.ngaybay.nam != b.ngaybay.nam)
        return a.ngaybay.nam < b.ngaybay.nam;

    if (a.ngaybay.thang != b.ngaybay.thang)
        return a.ngaybay.thang < b.ngaybay.thang;

    if (a.ngaybay.ngay != b.ngaybay.ngay)
        return a.ngaybay.ngay < b.ngaybay.ngay;

    if (a.giobay.gio != b.giobay.gio)
        return a.giobay.gio < b.giobay.gio;

    return a.giobay.phut < b.giobay.phut;
}

void sapXepChuyenBay() {
    sort(arr.begin(), arr.end(), cmp);

    for (auto i : arr) {
        inThongTin(i);
    }
}

void timKiemChuyenBay() {
    string menu = 
    "\n======== MENU ========\n"
    "1. Mã chuyến bay\n"
    "2. Nơi đi\n"
    "3. Nơi đến\n"
    "0. Thoát\n"
    "======================\n"
    "Nhập lựa chọn của bạn: ";

    int choic;
    string target;

     do {
        cout << menu;  cin >> choic;
        cin.ignore();
        switch (choic) {

        case 0:
            return;
        case 1:
            cout << "Nhập mã chuyến bay: "; cin >> target;
            for (auto i : arr) {
                if (i.macb.find(target) != std::string::npos) inThongTin(i);
            }
            break;
        case 2:
            cout << "Nhập nơi đi: "; getline(cin, target);
            for (auto i : arr) {
                if (i.noidi.find(target) != std::string::npos) inThongTin(i);
            }
            break;
        case 3:
            cout << "Nhập nơi đến: "; getline(cin, target);
            for (auto i : arr) {
                if (i.noiden.find(target) != std::string::npos) inThongTin(i);
            }
            break;
        
        default:
            cout << "Lựa chọn không hợp lệ!!! \n";
            break;
        }    
    } while (choic != 0);
}

void findAll() {
    NgayBay ngaybay;
    string noidi;

    cout << "Nhập ngày bay (dd mm yyyy): "; cin >> ngaybay.ngay >> ngaybay.thang >> ngaybay.nam;
    cin.ignore();
    cout << "Nhập nơi đi: "; getline(cin, noidi);

    for (auto i : arr) {
        if (i.noidi.find(noidi) != std::string::npos && ngaybay.ngay == i.ngaybay.ngay && ngaybay.thang == i.ngaybay.thang && ngaybay.nam == i.ngaybay.nam) inThongTin(i);
    }
}

void DemChuyenBay() {
    string noidi, noiden;
    cin.ignore();
    cout << "Nhập nơi đi: "; getline(cin, noidi);
    cout << "Nhập nơi đến: "; getline(cin, noiden);

    int cnt = 0;
    for (auto i : arr) {
        if (i.noidi.find(noidi) != std::string::npos && i.noiden.find(noiden) != std::string::npos) cnt++;
    }

    cout << "Có tổng cộng " << cnt << " chuyến bay từ " << noidi << " đến " << noiden << endl;
}

string menu = 
"\n======== MENU ========\n"
"1. Thêm thông tin chuyến bay\n"
"2. Tìm kiếm chuyến bay\n"
"3. Sắp xếp chuyến bay\n"
"4. Danh sách tất cả chuyến bay\n"
"5. Đếm số lượng chuyến bay\n"
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
            ThemChuyenBay();
            break;
        case 2:
            timKiemChuyenBay();
            break;
        case 3:
            sapXepChuyenBay();
            break;
        case 4:
            findAll();
            break;
        case 5: 
            DemChuyenBay();
            break;

        default:
            cout << "Lựa chọn không hợp lệ!!! \n";
            break;
        }    
    } while (choic != 0);
}