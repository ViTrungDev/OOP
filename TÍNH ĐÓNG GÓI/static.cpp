#include <iostream>
#include <string>

using namespace std;
class SinhVien
{
private:
    static int tangID;
    string ID;
    string Name;
    string Adress;

public:
    static void tangdem()
    {
        tangID++;
    }
    int gettangdem()
    {
        return this->tangID;
    }
    void nhap();
    void in();
};
int SinhVien::tangID = 0;
void SinhVien::nhap()
{
    ++tangID;
    this->ID = "SV" + string(2 - to_string(tangID).length(), '0') + to_string(tangID);
    cout << "Import name:" << this->Name << endl;
    getline(cin, Name);
    cout << "Import adress:" << this->Adress << endl;
    getline(cin, Adress);
}
void SinhVien::in()
{
    cout << "output ID:" << ID << endl;
    cout << "output Name:" << Name << endl;
    cout << "output Adress:" << Adress << endl;
}
int main()
{
    SinhVien sv;
    sv.nhap();
    sv.in();
}