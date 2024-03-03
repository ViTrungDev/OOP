#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class SinhVien
{
private:
    string Id;
    string Name;
    string address;
    float Point;

public:
    void setSinhVien(string Id, string Name, string address, float Point)
    {
        this->Id = Id;
        this->Name = Name;
        this->address = address;
        this->Point = Point;
    }
    string getId(void)
    {
        return this->Id;
    }
    string getName(void)
    {
        return this->Name;
    }
    string getaddress(void)
    {
        return this->address;
    }
    float getPoint(void)
    {
        return this->Point;
    }
    void input();
    void LuuFile(SinhVien &SV);
    void DocFile();
    void output();
};
void SinhVien::output()
{
    cout << "------------------------------" << endl;
    cout << "ID:" << this->getId() << endl;
    cout << "Name:" << this->getName() << endl;
    cout << "Adress:" << this->getaddress() << endl;
    cout << "Point:" << this->getPoint() << endl;
}
void SinhVien::input()
{
    cout << "nhap thong tin cho sinh vien." << endl;
    cout << "nhap id:";
    getline(cin, Id);
    cout << "nhap ten:";
    getline(cin, Name);
    cout << "nhap dia chi:";
    getline(cin, address);
    cout << "nhap diem:";
    cin >> Point;
    cin.ignore();
}
void SinhVien::LuuFile(SinhVien &SV)
{
    ofstream outfile("sinhvien.csv", ios::app); // Mở file để ghi, chế độ 'append' để thêm vào cuối file
    if (!outfile.is_open())
    {
        cout << "mo file ko thanh cong !";
    }
    else
    {
        outfile << SV.getId() << endl;
        outfile << SV.getName() << endl;
        outfile << SV.getaddress() << endl;
        outfile << SV.getPoint() << endl;
    }
    outfile.close();
}
void SinhVien::DocFile()
{
    ifstream infile("sinhvien.csv"); // Mở file để đọc
    if (!infile.is_open())
    {
        cout << "mo file ko thanh cong !";
    }
    else
    {
        string line;
        while (getline(infile, line)) // Đọc từng dòng trong file
        {
            // cout << line << endl; // In ra màn hình
        }
    }
    infile.close();
}

int main()
{
    SinhVien SV;
    SV.input();
    SV.LuuFile(SV);
    SV.DocFile();
    for (int i = 0; i < 10; i++)
    {
        SV.output();
    };
}
