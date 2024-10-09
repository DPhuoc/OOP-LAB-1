#include <iostream>
#include <algorithm>
using namespace std;

const long long MAXN = 1e6 + 10;

struct hocsinh {
    string hoten;
    double toan, van, anh, diemtb;
    string xeploai;
};

hocsinh arr[MAXN];
long long n;

bool ten_hop_le(const string& ten) {
    if (ten.length() < 1 || ten.length() > 50) {
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

bool diem_hop_le(const int& toan, const int& van, const int& anh) {
    if (toan < 0 || toan > 10 || van < 0 || van > 10 || anh < 0 || anh > 10) return false;
    return true;
}

string phanLoai(double diemtb) {
    if (diemtb >= 9.0)
        return "Xuất sắc";
    else if (diemtb >= 8.0)
        return "Giỏi";
    else if (diemtb >= 6.5)
        return "Khá";
    else if (diemtb >= 5.0)
        return "Trung bình";
    else
        return "Yếu";
}

bool cmp(const hocsinh &a, const hocsinh &b) {
    return a.diemtb > b.diemtb; 
}

void NhapHocSinh() {
    cout << "Số lượng học sinh: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nhập thông tin học sinh thứ " << i + 1 << ":\n";
        cin.ignore();
        do {
            cout << "Họ và tên: "; getline(cin, arr[i].hoten);
            if (!ten_hop_le(arr[i].hoten)) cout << "Tên không hợp lệ, vui lòng nhập lại \n";
        } while (!ten_hop_le(arr[i].hoten));

        do {
            cout << "Điểm Toán: "; cin >> arr[i].toan;
            cout << "Điểm Văn: "; cin >> arr[i].van;
            cout << "Điểm Ngoại ngữ: "; cin >> arr[i].anh;
            if (!diem_hop_le(arr[i].toan, arr[i].van, arr[i].anh)) cout << "Điểm không hợp lệ, vui lòng nhập lại \n";
        } while (!diem_hop_le(arr[i].toan, arr[i].van, arr[i].anh));
        
        arr[i].diemtb = (2 * arr[i].toan + arr[i].van + arr[i].anh) / 4;
        arr[i].xeploai = phanLoai(arr[i].diemtb);
    }

    sort(arr, arr + n, cmp);
}

void InThongTin(hocsinh &a) {
    cout << "Họ và tên học sinh: " << a.hoten << endl;
    cout << "Điểm Toán: " << a.toan << endl;
    cout << "Điểm Văn: " << a.van << endl;
    cout << "Điểm Ngoại ngữ: " << a.anh << endl;
    cout << "Điểm trung bình: " << a.diemtb << endl;
    cout << "Xếp loại: " << a.xeploai << endl;
    cout << "\n";
}

void TimKiemHocSinh() {
    string findStr;
    cin.ignore();
    cout << "Nhập tên học sinh cần tìm: "; getline(cin, findStr);

    for (int i = 0; i < n; i++) {
        if (arr[i].hoten.find(findStr) != std::string::npos) {
            InThongTin(arr[i]);
        }
    }
}

void HocSinhDiemCao() {
    cout << "Học sinh có điểm trung bình cao nhất là: " << arr[0].hoten << endl;
}

void HocSinhDiemThap() {
    cout << "Các học sinh có điểm trung bình thấp nhất: " << endl;
    for (int i = n - 1; i >= 0; i--) {
        cout << "+ " << arr[i].hoten << endl;
        if (i - 1 < 0 || arr[i].diemtb != arr[i - 1].diemtb) break;
    }
}

string menu = 
"\n======== MENU ========\n"
"1. Nhập thông tin học sinh\n"
"2. Xem học sinh có điểm cao nhất\n"
"3. Tìm kiếm học sinh\n"
"4. Danh sách học sinh có điểm thấp nhất\n"
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
            NhapHocSinh();
            break;
        case 2:
            HocSinhDiemCao();
            break;
        case 3:
            TimKiemHocSinh();
            break;
        case 4:
            HocSinhDiemThap();
            break;

        default:
            cout << "Lựa chọn không hợp lệ!!! \n";
            break;
        }    
    } while (choic != 0);
}