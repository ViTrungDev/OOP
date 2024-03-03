/*Bài toán ứng dụng trong lĩnh vực nông nghiệp: Quản lý thông tin về các loại cây trồng.
 Yêu cầu: Thêm cây trồng: Cho phép người dùng nhập thông tin về một loại cây trồng, bao gồm Tên cây, Loại cây và Thời gian trồng.
 Lưu thông tin đó vào tệp tin. Hiển thị danh sách cây trồng: Đọc từ tệp tin và in ra màn hình danh sách các loại cây trồng.
 Tìm kiếm cây trồng theo loại: Nhập 2.Loại cây và tìm kiếm xem có thông tin về các cây trồng thuộc loại đó trong danh sách hay không.*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class cayTrong
{
private:
    string tenCay;
    string loaiCay;
    string Tg;

public:
    void timkiem();
    friend istream &operator>>(istream &in, cayTrong &Ct);
    friend ostream &operator<<(ostream &out, cayTrong Ct);
    void luuFile(cayTrong &caytrong);
    void docFile();
    cayTrong(void)
    {
        this->tenCay = "unknow";
        this->loaiCay = "unknow";
        this->Tg = "unknow";
    }
    ~cayTrong(){};
    void setcayTrong(string tenCay, string loaiCay, string Tg)
    {
        this->tenCay = tenCay;
        this->loaiCay = loaiCay;
        this->Tg = Tg;
    }
    string gettenCay(void)
    {
        return tenCay;
    }
    string getloaiCay(void) const
    {
        return loaiCay;
    }
    string getTg(void)
    {
        return Tg;
    }
};
void timkiem(const vector<cayTrong> &dsCay, const string &loaiCay)
{
    int count = 0;
    for (const auto &cay : dsCay)
    {
        if (cay.getloaiCay() == loaiCay)
        {
            cout << cay << endl;
            count++;
        }
    }
    cout << "Co " << count << " cay thuoc loai " << loaiCay << endl;
}
void docFileVaTimKiem(const string &loaiCay)
{
    ifstream file("caytrong.txt");
    if (!file.is_open())
    {
        cout << "mo file ko thanh cong!" << endl;
    }
    else
    {
        vector<cayTrong> dsCay;
        string tenCay, loaiCayFile, Tg;
        while (getline(file, tenCay) && getline(file, loaiCayFile) && getline(file, Tg))
        {
            cayTrong Ct;
            Ct.setcayTrong(tenCay, loaiCayFile, Tg);
            dsCay.push_back(Ct);
        }
        file.close();
        timkiem(dsCay, loaiCay);
    }
}

void cayTrong::luuFile(cayTrong &caytrong)
{
    ofstream file("caytrong.txt", ios::app);
    if (!file.is_open())
    {
        cout << "mo file ko thanh cong!" << endl;
    }
    else
    {
        file << caytrong.gettenCay() << endl;
        file << caytrong.getloaiCay() << endl;
        file << caytrong.getTg() << endl;
    }
    cout << "Luu thong tin cay trong thanh cong!" << endl;
    file.close();
}
void cayTrong::docFile()
{
    ifstream file("caytrong.txt");
    if (!file.is_open())
    {
        cout << "mo file ko thanh cong!" << endl;
    }
    else
    {
        string luufile;
        while (getline(file, luufile))
        {
            cout << luufile << endl;
        }
    }
    file.close();
}
istream &operator>>(istream &in, cayTrong &Ct)
{
    cout << "nhap du lieu..." << endl;
    cout << "nhap ten cay:";
    getline(in, Ct.tenCay);
    cout << "nhap loai cay:";
    getline(in, Ct.loaiCay);
    cout << "nhap thoi gian:";
    getline(in, Ct.Tg);
    return in;
}
ostream &operator<<(ostream &out, cayTrong Ct)
{
    out << "===========================================" << endl;
    out << "Thong tin cay:" << Ct.tenCay << endl;
    out << "Thong tin Loai cay:" << Ct.loaiCay << endl;
    out << "Thong tin thoi gian trong:" << Ct.Tg << endl;
    out << "===========================================" << endl;
    return out;
}
void menu()
{
    cout << "1.Nhap thong tin" << endl;
    cout << "2.In thong tin" << endl;
    cout << "3.Luu thong tin vao file" << endl;
    cout << "4.Doc thong tin tu file" << endl;
    cout << "5.Tim kiem cay" << endl;
    cout << "0.Thoat chuong trinh" << endl;
}
int main()
{
    vector<cayTrong> dsCay; // danh sách các cây
    int luachon;

    do
    {
        menu();
        cout << "nhap lua chon:";
        cin >> luachon;
        cin.ignore();

        if (luachon == 1)
        {
            cayTrong C1;
            cin >> C1;
            dsCay.push_back(C1); // thêm cây vào danh sách
        }
        else if (luachon == 2)
        {
            for (int i = 0; i < dsCay.size(); i++)
            {
                cout << dsCay[i] << endl; // in ra từng cây trong danh sách
            }
        }
        else if (luachon == 3)
        {
            for (int i = 0; i < dsCay.size(); i++)
            {
                dsCay[i].luuFile(dsCay[i]); // lưu từng cây vào file
            }
        }
        else if (luachon == 4)
        {
            cayTrong C1;
            C1.docFile();
        }
        else if (luachon == 5)
        {
            string loaiCay;
            cout << "Nhap ten loai cay can tim: ";
            getline(cin, loaiCay);
            docFileVaTimKiem(loaiCay);
        }

        else if (luachon != 0)
        {
            cout << "lua chon ko hop le!" << endl;
        }
    } while (luachon != 0);

    return 0;
}
