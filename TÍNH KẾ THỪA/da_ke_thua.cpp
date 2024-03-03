#include <iostream>
using namespace std;

class hocSinh
{
private:
    string id;
    string name;

public:
    void sethocSinh(string id, string name)
    {
        this->id = id;
        this->name = name;
    }
    string getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    void nhap()
    {
        cout << "nhap thong tin cho id:";
        getline(cin, id);
        cout << "nhap thong tin cho name:";
        getline(cin, name);
    }
    void in()
    {
        cout << "Thong tin id:" << getid() << endl;
        cout << "Thong tin name:" << getname() << endl;
    }
};

class giaoVien
{
private:
    string monHoc;
    float D1;
    float D2;
    float D3;

public:
    void setGiaoVien(string monHoc, float D1, float D2, float D3)
    {
        this->monHoc = monHoc;
        this->D1 = D1;
        this->D2 = D2;
        this->D3 = D3;
    }
    string getMonhoc()
    {
        return monHoc;
    }
    float getD1()
    {
        return D1;
    }
    float getD2()
    {
        return D2;
    }
    float getD3()
    {
        return D3;
    }
    void nhap()
    {
        cout << "nhap mon hoc:";
        getline(cin, monHoc);
        cout << " Nhap diem 1 :";
        cin >> D1;
        cin.ignore();
        cout << "Nhap diem 2:";
        cin >> D2;
        cin.ignore();
        cout << "Nhap diem 3:";
        cin >> D3;
        cin.ignore();
    }
    void in()
    {
        cout << "Mon hoc" << getMonhoc() << endl;
        cout << "Diem 1:" << getD1() << endl;
        cout << "Diem 2:" << getD2() << endl;
        cout << "Diem 3:" << getD3() << endl;
    }
};

class QlHoc_Sinh : public hocSinh, public giaoVien // đa kế thừa
{
public:
    float gpa()
    {
        return (getD1() + getD2() + getD3()) / 3;
    }
    void nhap()
    {
        hocSinh::nhap();
        giaoVien::nhap();
    }
    void in()
    {
        hocSinh::in();
        giaoVien::in();
        cout << "GPA: " << gpa() << endl;
    }
};

int main()
{
    QlHoc_Sinh hs;
    hs.nhap();
    // hs.hocSinh::nhap();
    hs.in();
    // hs.hocSinh::in();
    return 0;
}
