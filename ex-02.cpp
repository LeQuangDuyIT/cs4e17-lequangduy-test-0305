#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Vemaybay {
private:
    string tenchuyen;
    string ngaybay;
    int giave;

public:
    Vemaybay(string ten = "", string ngay = "", int gia = 0) : tenchuyen(ten), ngaybay(ngay), giave(gia) {}
    ~Vemaybay() {}

    void Nhap() {
        cout << "Nhap ten chuyen: ";
        cin >> tenchuyen;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap gia ve: ";
        cin >> giave;
    }

    void Xuat() {
        cout << "Ten chuyen: " << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }

    int getgiave() {
        return giave;
    }
};

class Nguoi {
protected:
    string hoten;
    string gioitinh;
    int tuoi;

public:
    Nguoi(string ten = "", string gt = "", int age = 0) : hoten(ten), gioitinh(gt), tuoi(age) {}
    ~Nguoi() {}

    void Nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }

    void Xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }
};

class Hanhkhach : public Nguoi {
private:
    Vemaybay *ve;
    int soluong;

public:
    Hanhkhach(string ten = "", string gt = "", int age = 0) : Nguoi(ten, gt, age), ve(nullptr), soluong(0) {}
    ~Hanhkhach() {
        delete[] ve;
    }

    void Nhap() {
        Nguoi::Nhap();
        cout << "Nhap so luong ve may bay: ";
        cin >> soluong;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++) {
            cout << "Nhap thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Nhap();
        }
    }

    void Xuat() {
        Nguoi::Xuat();
        cout << "So luong ve may bay: " << soluong << endl;
        for (int i = 0; i < soluong; i++) {
            cout << "Thong tin ve may bay thu " << i + 1 << ":" << endl;
            ve[i].Xuat();
        }
    }

  int tongtien() const {
    int total = 0;
    for (int i = 0; i < soluong; i++) {
        total += ve[i].getgiave();
    }
    return total;
}
};

int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;

    vector<Hanhkhach> danhSachHanhKhach(n);

    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
        danhSachHanhKhach[i].Nhap();
    }

    cout << "Danh sach hanh khach va so tien phai tra:" << endl;
    for (int i = 0; i < n; i++) {
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
    }

    sort(danhSachHanhKhach.begin(), danhSachHanhKhach.end(), [](const Hanhkhach &a, const Hanhkhach &b) {
        return a.tongtien() > b.tongtien();
    });

    cout << "Danh sach hanh khach sau khi sap xep:" << endl;
    for (int i = 0; i < n; i++) {
        danhSachHanhKhach[i].Xuat();
        cout << "Tong tien phai tra: " << danhSachHanhKhach[i].tongtien() << endl;
    }

    return 0;
}