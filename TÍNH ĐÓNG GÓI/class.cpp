#include <iostream>
#include <string.h>
using namespace std;

class SinhVien
{
    // bao gom private: Riêng tư ; public:bên ngoài,cộng đồng ; protected: bảo vệ
private:
    string MaSV;
    string HoTen;

public: // có thể viết bên trong public hoặc chuyền phạm vi
    void nhap()
    {
        cout << "nhap ma sinh vien:";
        getline(cin, MaSV);
        cout << "nhap Ho Ten:";
        getline(cin, HoTen);
    }
    void in()
    {
        cout << "-----------------------------------------" << endl;
        cout << "ma sinh vien la:" << MaSV << endl;
        cout << "Ho ten sinh vien la:" << HoTen << endl;
        cout << "-----------------------------------------" << endl;
    }
};
// VD: void SinhVien::nhap();

int main()
{
    SinhVien SV;
    SV.nhap();
    SV.in();
    return 0;
}