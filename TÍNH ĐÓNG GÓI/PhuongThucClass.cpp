#include <iostream>
#include <string>
using namespace std;

class SinhVien
{
private:
    string HoTen, DiaChi;
    float Toan, Van;
    // co 2 cach dinh nghia phuong thuc cho class
public:
    // cach 1: khai bao va Dinh nghia ngay trong class
    void Nhap()
    {
        // thuc thi o day
        fflush(stdin); // xoa bo nho dem
        cout << "nhap ho ten sinh vien:";
        getline(cin, HoTen);
        cout << "nhap dia chi:";
        getline(cin, DiaChi);
        cout << "nhap diem toan:";
        cin >> Toan;
        cin.ignore();
        cout << "nhap diem van:";
        cin >> Van;
        cin.ignore();
    }
    // cach 2: khai bao trong class va dinh nghia ben ngoai
    void in();
    float DiemTB();
};
// Kieu tra ve cua phuong thuc Tenclass::TenPhuong thuc(){// viet code o day}
// cach 2:

float SinhVien::DiemTB()
{
    return (Toan + Van) / 2;
}
void SinhVien::in()
{
    cout << "------------------------------------" << endl;
    cout << "Ho Ten:" << HoTen << endl;
    cout << "Dia chi:" << DiaChi << endl;
    cout << "Diem trung binh:" << DiemTB() << endl;
    cout << "------------------------------------" << endl;
}
int main()
{
    SinhVien SV;
    SV.Nhap(); // tính đóng gói
    SV.in();
    return 0;
}