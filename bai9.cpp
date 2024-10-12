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

/**
 * @brief Thêm sổ tiết kiệm mới vào danh sách.
 * 
 * @details
 * - Hàm này cho phép người dùng nhập thông tin chi tiết của một sổ tiết kiệm mới, bao gồm mã sổ, loại tiết kiệm, thông tin khách hàng và số tiền gửi.
 * - Quá trình nhập có các kiểm tra tính hợp lệ của mã sổ, loại tiết kiệm, tên khách hàng, CMND, ngày gửi và số tiền gửi.
 * - Sổ tiết kiệm hợp lệ sẽ được thêm vào danh sách.
 * 
 */
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

/**
 * @brief Hiển thị thông tin chi tiết của một sổ tiết kiệm.
 * 
 * @details 
 * - Hàm này in ra các thông tin của sổ tiết kiệm bao gồm mã sổ, loại tiết kiệm, họ tên khách hàng, số CMND, ngày mở sổ, lãi suất và số tiền hiện tại.
 **/
void xuat(const SoTietKiem& sotietiem) {
    cout << "\n-------------" << sotietiem.maSo << "----------------\n";
    cout << "Loại tiết kiệm: " << sotietiem.loaiTietKiem << endl;
    cout << "Họ và tên: " << sotietiem.hoTenKhachHang << endl;
    cout << "CMND: " << sotietiem.cmnd << endl;
    cout << "Ngày mở sổ: " << sotietiem.ngaygui.ngay << "/" << sotietiem.ngaygui.thang << "/" << sotietiem.ngaygui.nam << endl;
    cout << "Lãi suất: " << sotietiem.laiSuat << endl;
    cout << "Số tiền còn lại: " << sotietiem.soTienGui << endl; 
}

/**
 * @brief Hiển thị danh sách tất cả các sổ tiết kiệm.
 * 
 * @details 
 * - Hàm này lặp qua danh sách các sổ tiết kiệm (`arr`) và gọi hàm `xuat` để in thông tin của từng sổ tiết kiệm.
 **/
void xuatDS() {
    for (auto i : arr) {
        xuat(i);
    }
}

/**
 * @brief Cập nhật lãi suất cho một sổ tiết kiệm dựa trên mã sổ.
 * 
 * @details
 * - Hàm này cho phép người dùng nhập mã sổ tiết kiệm và lãi suất mới. Nếu tìm thấy sổ tiết kiệm có mã trùng khớp, lãi suất của sổ đó sẽ được cập nhật.
 **/
void capNhatLS() {
    double laisuat;
    string maSo;
    cout << "Nhập mã sổ cần đổi lãi suất: "; cin >> maSo;
    cout << "Nhập lãi suất: "; cin >> laisuat;

    for (auto &i : arr) {
        if (i.maSo == maSo) i.laiSuat = laisuat;
    }
}

/**
 * @brief Tính tiền lãi của sổ tiết kiệm dựa trên loại tiết kiệm và số tháng gửi.
 * 
 * @details
 * - Hàm này tính tiền lãi dựa trên hai loại tiết kiệm: "ngắn hạn" và "dài hạn". 
 *   - Nếu sổ tiết kiệm là "ngắn hạn" và số tháng gửi nhỏ hơn hoặc bằng 6 tháng, tiền lãi sẽ được tính theo lãi suất đã cho và số tháng gửi.
 *   - Nếu sổ tiết kiệm là "dài hạn" và số tháng gửi lớn hơn 6 tháng, tiền lãi cũng sẽ được tính theo lãi suất và số tháng gửi.
 * - Số tiền lãi trả về là một số nguyên lớn.
 **/
long long tinhTienLai(const SoTietKiem &stk) {
    if (stk.loaiTietKiem == "ngan han" && stk.soThangGui <= 6) {
        return stk.soTienGui * stk.laiSuat * stk.soThangGui / 12 * 1ll;
    } else if (stk.loaiTietKiem == "dai han" && stk.soThangGui > 6) {
        return stk.soTienGui * stk.laiSuat * stk.soThangGui / 12 * 1ll;
    }
    return 0;
}

/**
 * @brief Tính và in ra tiền lãi của sổ tiết kiệm dựa trên mã sổ.
 * 
 * @details
 * - Hàm này cho phép người dùng nhập mã sổ tiết kiệm và tính toán tiền lãi dựa trên thông tin sổ.
 **/
void tinhTienLaiSTK() {
    string maSo;
    cout << "Nhập mã sổ cần tính tiền lãi: "; cin >> maSo;
    for (auto i : arr) {
        if (i.maSo == maSo) cout << "Tiền lãi: " << tinhTienLai(i) << endl;
    }
}

/**
 * @brief Rút tiền từ sổ tiết kiệm dựa trên mã sổ và số tiền muốn rút.
 * 
 * @details
 * - Hàm này cho phép người dùng nhập mã sổ tiết kiệm và số tiền muốn rút.
 * - Nếu số tiền muốn rút lớn hơn số tiền trong sổ, in ra thông báo không đủ tiền để rút.
 * - Nếu số tiền rút hợp lệ, trừ số tiền rút vào số tiền trong sổ và in ra thông báo rút tiền thành công.
 **/
void rutTien() {
    string maSo;
    long long soTienRut;
    cout << "Nhập mã sổ cần rút tiền: "; cin >> maSo;
    cout << "Nhập số tiền cần rút: "; cin >> soTienRut;
    for (auto &i : arr) {
        if (i.maSo == maSo) {
            if (soTienRut > i.soTienGui) {
                cout << "Không đủ tiền để rút\n";
                return;
            }

            i.soTienGui -= soTienRut;
            cout << "Đã rút thành công\n";
        }
    }
}

/**
 * @brief Tìm và hiển thị thông tin sổ tiết kiệm dựa trên CMND của khách hàng.
 * 
 * @details
 * - Người dùng nhập CMND cần tìm, sau đó hàm sẽ duyệt qua danh sách sổ tiết kiệm (`arr`).
 * - Nếu tìm thấy sổ tiết kiệm có CMND khớp với dữ liệu nhập vào, hàm sẽ hiển thị thông tin chi tiết của sổ tiết kiệm đó.
 **/ 
void timSTKCMND() {
    string CMND;
    cout << "Nhập CMND của STK cần tìm: "; cin >> CMND;
    for (auto i : arr) {
        if (i.cmnd == CMND) xuat(i);
    }
}

/**
 * @brief Tìm và hiển thị thông tin sổ tiết kiệm trong khoảng thời gian gửi tiền được chỉ định.
 * 
 * @details
 * - Người dùng nhập ngày bắt đầu và ngày kết thúc của khoảng thời gian cần tìm.
 * - Hàm sẽ duyệt qua danh sách sổ tiết kiệm, kiểm tra ngày gửi của từng sổ.
 * - Nếu ngày gửi nằm trong khoảng thời gian được chỉ định (bao gồm cả ngày bắt đầu và ngày kết thúc), hàm sẽ in thông tin chi tiết của sổ tiết kiệm đó.
 **/
void timSTKngayGui() {
    NgayGui ngaybatdau, ngayketthuc;
    while (true) {
        cout << "Nhập ngày bắt đầu: (dd mm yyyy): "; cin >> ngaybatdau.ngay >> ngaybatdau.thang >> ngaybatdau.nam;
        if (!checkNG(ngaybatdau.ngay, ngaybatdau.thang, ngaybatdau.nam)) cout << "Ngày này không tồn tại!!!\n";
        else break;
    }

    while (true) {
        cout << "Nhập ngày kết thúc: (dd mm yyyy): "; cin >> ngayketthuc.ngay >> ngayketthuc.thang >> ngayketthuc.nam;
        if (!checkNG(ngayketthuc.ngay, ngayketthuc.thang, ngayketthuc.nam)) cout << "Ngày này không tồn tại!!!\n";
        else break;
    }

    for (auto i : arr) {
        if (i.ngaygui.ngay >= ngaybatdau.ngay && i.ngaygui.ngay <= ngayketthuc.ngay && i.ngaygui.thang >= ngaybatdau.thang && i.ngaygui.thang <= ngayketthuc.thang && i.ngaygui.nam >= ngaybatdau.nam && i.ngaygui.nam <= ngayketthuc.nam) xuat(i);
    }
}

/**
 * @brief Sắp xếp danh sách sổ tiết kiệm theo số tiền gửi giảm dần.
 * 
 * @details
 * - Sổ có số tiền gửi lớn hơn sẽ được sắp xếp lên trước.
 **/
void sapXepTheoSoTien() {
    sort(arr.begin(), arr.end(), [](const SoTietKiem &a, const SoTietKiem &b) {
        return a.soTienGui > b.soTienGui;
    });
}

/**
 * @brief Sắp xếp danh sách sổ tiết kiệm theo ngày mở sổ tăng dần.
 * 
 * @details
 * - Thứ tự sắp xếp: năm, tháng, sau đó đến ngày (tăng dần).
 **/
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
"7. Tìm kiếm sổ tiết kiệm trong một khoảng thời gian\n"
"8. Sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần\n"
"9. Sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần\n"
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
            tinhTienLaiSTK();
            break;
        case 5: 
            rutTien();
            break;
        case 6:
            timSTKCMND();
            break;
        case 7: 
            timSTKngayGui();
            break;
        case 8: 
            sapXepTheoSoTien();
            break;
        case 9:
            sapXepTheoNgayMoSo();
            break;


        default:
            cout << "Lựa chọn không hợp lệ!!! \n";
            break;
        }    
    } while (choic != 0);
}

