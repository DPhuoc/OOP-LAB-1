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

/**
 * @brief Kiểm tra tính hợp lệ của một tên học sinh.
 * 
 * @param ten Chuỗi ký tự chứa tên học sinh.
 * 
 * @return true Nếu tên hợp lệ (thỏa mãn tất cả các tiêu chí).
 * @return false Nếu tên không hợp lệ (vi phạm bất kỳ tiêu chí nào).
 * 
 * @details
 * Hàm này kiểm tra các tiêu chí sau để xác định tính hợp lệ của tên:
 * 1. Độ dài của tên phải từ 1 đến 50 ký tự.
 * 2. Tên chỉ được chứa các ký tự chữ cái và khoảng trắng (không được chứa ký tự đặc biệt hoặc số).
 * 3. Ký tự đầu tiên phải là chữ cái viết hoa.
 * 4. Sau khoảng trắng, chữ cái tiếp theo phải là chữ viết hoa.
 * 5. Các ký tự khác (ngoài chữ cái đầu sau khoảng trắng) phải là chữ viết thường.
 * 
 * Mục đích của hàm là đảm bảo rằng tên học sinh được nhập vào đúng theo chuẩn quy định.
 */
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

/**
 * @brief Kiểm tra tính hợp lệ của điểm số cho ba môn học: Toán, Văn, Anh.
 * 
 * @param toan Điểm môn Toán (kiểu nguyên).
 * @param van Điểm môn Văn (kiểu nguyên).
 * @param anh Điểm môn Anh (kiểu nguyên).
 * 
 * @return true Nếu tất cả điểm số hợp lệ (nằm trong khoảng từ 0 đến 10).
 * @return false Nếu bất kỳ điểm nào không hợp lệ (ngoài khoảng từ 0 đến 10).
 * 
 */
bool diem_hop_le(const int& toan, const int& van, const int& anh) {
    if (toan < 0 || toan > 10 || van < 0 || van > 10 || anh < 0 || anh > 10) return false;
    return true;
}

/**
 * @brief Phân loại học sinh dựa trên điểm trung bình.
 * 
 * @param diemtb Điểm trung bình của học sinh (kiểu số thực).
 * 
 * @return string Kết quả phân loại học sinh dưới dạng chuỗi:
 * - "Xuất sắc" nếu điểm trung bình >= 9.0.
 * - "Giỏi" nếu điểm trung bình >= 8.0 và < 9.0.
 * - "Khá" nếu điểm trung bình >= 6.5 và < 8.0.
 * - "Trung bình" nếu điểm trung bình >= 5.0 và < 6.5.
 * - "Yếu" nếu điểm trung bình < 5.0.
 * 
 */
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

/**
 * @brief Nhập thông tin cho danh sách học sinh, tính điểm trung bình và phân loại.
 * 
 * @details
 * - Hàm này yêu cầu người dùng nhập số lượng học sinh và thông tin của từng học sinh bao gồm:
 *   - Họ và tên: Phải hợp lệ (tối đa 50 ký tự, không chứa số và ký tự đặc biệt).
 *   - Điểm Toán, Văn, Ngoại ngữ: Phải hợp lệ (là số trong khoảng từ 0 đến 10).
 * - Sau khi nhập thông tin:
 *   - Tính điểm trung bình của mỗi học sinh theo công thức: 
 *     \f[ \text{diemtb} = \frac{2 \times \text{toan} + \text{van} + \text{anh}}{4} \f]
 *   - Phân loại học sinh dựa trên điểm trung bình.
 * - Sau khi nhập xong, danh sách học sinh sẽ được sắp xếp theo thứ tự điểm trung bình giảm dần.
 */
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

/**
 * @brief In thông tin chi tiết của một học sinh.
 * 
 * @details
 * - Hàm này nhận một tham số là học sinh (đối tượng `hocsinh`) và in ra các thông tin
 *   của học sinh đó, bao gồm họ tên, điểm từng môn (Toán, Văn, Ngoại ngữ), điểm trung bình
 *   và xếp loại.
 * 
 * @param a Tham số đầu vào là một đối tượng `hocsinh`, chứa thông tin của học sinh cần
 *          in ra.
 */
void InThongTin(hocsinh &a) {
    cout << "---------------------------\n";
    cout << "Họ và tên học sinh: " << a.hoten << endl;
    cout << "Điểm Toán: " << a.toan << endl;
    cout << "Điểm Văn: " << a.van << endl;
    cout << "Điểm Ngoại ngữ: " << a.anh << endl;
    cout << "Điểm trung bình: " << a.diemtb << endl;
    cout << "Xếp loại: " << a.xeploai << endl;
    cout << "\n";
}

/**
 * @brief Tìm kiếm và hiển thị thông tin học sinh theo tên.
 * 
 * @details
 * - Hàm này yêu cầu người dùng nhập vào một chuỗi tên để tìm kiếm.
 * - Sau đó, hàm sẽ duyệt qua danh sách học sinh đã nhập và kiểm tra xem 
 *   chuỗi tên tìm kiếm có tồn tại trong tên của học sinh hay không.
 * - Nếu tìm thấy, hàm sẽ gọi hàm `InThongTin` để hiển thị thông tin của học sinh đó.
 */
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
/**
 * @brief Hiển thị tên học sinh có điểm trung bình cao nhất.
 * 
 * @details
 * - Hàm giả định rằng danh sách học sinh đã được sắp xếp theo thứ tự điểm trung bình giảm dần
 *   trước khi được gọi (sử dụng hàm `sort` trong hàm `NhapHocSinh`).
 * 
 **/
void HocSinhDiemCao() {
    cout << "Học sinh có điểm trung bình cao nhất là: " << arr[0].hoten << endl;
}

/**
 * @brief Hiển thị danh sách các học sinh có điểm trung bình thấp nhất.
 * 
 * @details
 * - Hàm này sẽ in ra tên của tất cả các học sinh có điểm trung bình thấp nhất trong danh sách học sinh.
 * - Danh sách học sinh được giả định đã được sắp xếp theo thứ tự điểm trung bình tăng dần
 *   trước khi hàm được gọi (sử dụng hàm `sort` trong hàm `NhapHocSinh`).
 * 
 */
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