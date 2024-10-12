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

/**
 * @brief Kiểm tra tính hợp lệ của một ngày, tháng, năm cụ thể.
 * 
 * @details
 * - Ngày, tháng, và năm sẽ được kiểm tra theo các điều kiện:
 *   - Năm phải lớn hơn hoặc bằng 0.
 *   - Tháng phải nằm trong khoảng từ 1 đến 12.
 *   - Ngày phải nằm trong khoảng hợp lý theo số ngày của tháng.
 * 
 * @param day Ngày cần kiểm tra.
 * @param month Tháng cần kiểm tra.
 * @param year Năm cần kiểm tra.
 * 
 * @return `true` nếu ngày, tháng, năm hợp lệ; ngược lại, trả về `false`.
 */
bool checkNB(int day, int month, int year) {
    if (year < 0) return false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) days[1] = 29;

    if (month < 0 || month > 12) return false;
    if (day < 0 || day > days[month - 1]) return false;
    return true;
}

/**
 * @brief Kiểm tra tính hợp lệ của mã sổ tiết kiệm (mã CB).
 * 
 * @details
 * - Hàm này kiểm tra xem chuỗi mã sổ tiết kiệm có hợp lệ hay không theo các tiêu chí:
 *   - Độ dài của mã phải nhỏ hơn hoặc bằng 5 ký tự.
 *   - Mã chỉ được chứa các ký tự chữ cái (chữ thường hoặc chữ hoa) và chữ số.
 *   - Mã không được chứa các ký tự đặc biệt hay khoảng trắng.
 * 
 * @param macb Chuỗi mã sổ tiết kiệm cần kiểm tra.
 * 
 * @return `true` nếu mã hợp lệ; ngược lại, trả về `false`.
 **/
bool checkMaCB(string &macb) {
    if (macb.length() > 5) return false;
    for (char c : macb) {
        if (!isalpha(c) && !isdigit(c)) return false;
    }
    return true;
}

/**
 * @brief Kiểm tra tính hợp lệ của giờ và phút.
 * 
 * @param gio Giờ cần kiểm tra.
 * @param phut Phút cần kiểm tra.
 * 
 * @return `true` nếu giờ và phút hợp lệ; ngược lại, trả về `false`.
 **/
bool checkGB(int &gio, int &phut) {
    if (gio < 0 || gio > 24 || phut < 0 || phut > 60) return false;
    return true;
}

/**
 * @brief Kiểm tra tính hợp lệ của địa điểm.
 * 
 * @param diadiem Chuỗi ký tự chứa tên địa điểm cần kiểm tra.
 * 
 * @return `true` nếu địa điểm hợp lệ; ngược lại, trả về `false`.
 * */
bool checkLoca(string &diadiem) {
    if (diadiem.length() < 0 || diadiem.length() > 20) return false;
    for (char c : diadiem) {
        if (!isalpha(c) && !isspace(c)) return false;
    }
    return true;
}

/**
 * @brief Thêm chuyến bay vào danh sách.
 * 
 * @details
 * - Hàm này cho phép người dùng nhập thông tin về các chuyến bay cần thêm vào danh sách.
 * - Các thông tin cần nhập bao gồm: mã chuyến bay, ngày bay, giờ bay, nơi đi và nơi đến.
 * - Các kiểm tra được thực hiện để đảm bảo tính hợp lệ của các thông tin như mã chuyến bay, ngày, giờ và địa điểm.
 * - Nếu thông tin không hợp lệ, người dùng được yêu cầu nhập lại cho đến khi đúng.
 * - Mỗi chuyến bay được lưu vào danh sách `arr`, và mã chuyến bay được lưu vào `list_macb` để kiểm tra trùng lặp.
 */
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

/**
 * @brief In ra thông tin chi tiết của một chuyến bay.
 * 
 * @details
 * - Hàm này sẽ hiển thị các thông tin của chuyến bay bao gồm: mã chuyến bay, ngày bay, giờ bay, nơi đi và nơi đến.
 * - Các thông tin được in ra màn hình theo định dạng dễ đọc.
 **/
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

/**
 * @brief Sắp xếp và hiển thị thông tin các chuyến bay theo thứ tự quy định.
 * @sorting_criteria
 * - Tiêu chí sắp xếp được xác định trong hàm `cmp`, ví dụ có thể là theo mã chuyến bay, thời gian bay, hoặc các tiêu chí khác.
 */
void sapXepChuyenBay() {
    sort(arr.begin(), arr.end(), cmp);

    for (auto i : arr) {
        inThongTin(i);
    }
}

/**
 * @brief Tìm kiếm và hiển thị thông tin các chuyến bay dựa trên tiêu chí tìm kiếm do người dùng chọn.
 * 
 * @details
 * - Hàm này cho phép người dùng tìm kiếm chuyến bay bằng cách lựa chọn tiêu chí tìm kiếm như: mã chuyến bay, nơi đi, hoặc nơi đến.
 * - Các chuyến bay phù hợp với tiêu chí tìm kiếm sẽ được hiển thị đầy đủ thông tin.
 * - Chương trình cung cấp menu cho người dùng lựa chọn và yêu cầu nhập dữ liệu đầu vào tương ứng với tiêu chí đã chọn.
 * 
 * @menu
 * - 1: Tìm kiếm theo mã chuyến bay.
 * - 2: Tìm kiếm theo nơi đi.
 * - 3: Tìm kiếm theo nơi đến.
 * - 0: Thoát khỏi chức năng tìm kiếm.
 */
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

/**
 * @brief Tìm kiếm và hiển thị các chuyến bay dựa trên ngày bay và nơi khởi hành.
 * 
 * @details
 * - Hàm này yêu cầu người dùng nhập ngày bay và nơi đi, sau đó sẽ tìm kiếm các chuyến bay có cùng ngày bay và nơi đi với thông tin người dùng nhập.
 * - Nếu tìm thấy các chuyến bay phù hợp, thông tin chi tiết của các chuyến bay đó sẽ được in ra màn hình.
 */
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

/**
 * @brief Đếm số lượng chuyến bay từ một địa điểm đến một địa điểm khác.
 * 
 * @details
 * - Hàm này yêu cầu người dùng nhập vào nơi đi và nơi đến, sau đó sẽ đếm số lượng các chuyến bay có điểm khởi hành và điểm đến phù hợp với thông tin đã nhập.
 * - Kết quả sẽ được in ra là số lượng chuyến bay thỏa mãn điều kiện.
 */
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