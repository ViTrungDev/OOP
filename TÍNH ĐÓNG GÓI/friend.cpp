// ham bạn trong lập trình hướng đối tượng
// Cú pháp: ta thêm từ khóa friendtrước class.
// có thể truy cập vào các thuộc tinh của class
#include <iostream>
#include <string>

using namespace std;
class SinhVien
{
private:
    char ID;
    string NAME;
    int AGE;
    float POINT;

public:
    friend void nhap(SinhVien &SV); // ham friend(ban)
    void in();
    void setSinhVien(char ID, string NAME, int AGE, float POINT)
    {
        this->ID = ID;
        this->NAME = NAME;
        this->AGE = AGE;
        this->POINT = POINT;
    }
    char getID()
    {
        return this->ID;
    }
    string getNAME()
    {
        return this->NAME;
    }
    int getAGE()
    {
        return this->AGE;
    }
    float getPOINT()
    {
        return this->POINT;
    }
    SinhVien(void)
    {
        ID = 0000;
        NAME = "unknow";
        AGE = 00;
        POINT = 00;
    }
    ~SinhVien(){};
};
void nhap(SinhVien &SV)
{
    cout << "Nhap thong tin cho sinh vien:" << endl;
    cin >> SV.ID;
    cin.ignore();
    cout << "nhap ho ten sinh vien:" << endl;
    getline(cin, SV.NAME);
    cout << "nhap tuoi:" << endl;
    cin >> SV.AGE;
    cout << "nhap diem:" << endl;
    cin >> SV.POINT;
    cin.ignore();
}
void SinhVien::in()
{
    cout << "ID:" << ID << endl;
    cout << "Name:" << NAME << endl;
    cout << "Age:" << AGE << endl;
    cout << "Point:" << POINT << endl;
}
int main()
{
    SinhVien SV1;
    nhap(SV1);
    SV1.in();
}