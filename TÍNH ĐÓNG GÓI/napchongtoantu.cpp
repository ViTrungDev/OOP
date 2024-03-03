#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class SinhVien
{
private:
    string id;
    string ten;
    string tuoi;
    string diachi;
    float diemtb;

public:
    friend istream &operator>>(istream &in, SinhVien &a);
    friend ostream &operator<<(ostream &out, SinhVien a);
    friend SinhVien &operator+(SinhVien a, SinhVien b);
    bool operator<(SinhVien a);
    friend bool operator>(SinhVien a, SinhVien b);
};
// SinhVien &operator+(SinhVien a, SinhVien b)
// {
//     SinhVien c;
//     SinhVien c = SinhVien a.diemtb + SinhVien b.diemtb;
//     return c;
// }
bool operator>(SinhVien a, SinhVien b)
{
    return a.diemtb > b.diemtb;
}
bool SinhVien::operator<(SinhVien a)
{
    return this->diemtb < a.diemtb;
}
istream &operator>>(istream &in, SinhVien &a)
{
    cout << "nhap thong tin:" << endl;
    cout << "nhap id:";
    in >> a.id;
    in.ignore();
    cout << "nhap ten:";
    getline(in, a.ten);
    cout << "nhap tuoi:";
    getline(in, a.tuoi);
    cout << "nhap dia chi:";
    getline(in, a.diachi);
    cout << "nhap diem tb:";
    in >> a.diemtb;
    return in;
}
ostream &operator<<(ostream &out, SinhVien a)
{
    out << "id:" << a.id << "" << a.ten << "" << a.tuoi << "" << a.diachi << "" << a.diemtb << endl;
    return out;
}
int main()
{
    SinhVien x, y;
    cin >> x >> y;
    if (x > y)
        cout << "yes";
    else
    {
        cout << "no";
    }
    // cout << x;
}
