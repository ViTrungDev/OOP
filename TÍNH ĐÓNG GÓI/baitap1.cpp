#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SinhVien
{
private:
    static int Id;
    string MaSV;
    string TenSV;
    float DiemTB;

public:
    void nhap()
    {
        ++Id;
        this->MaSV = "SV" + string(3 - to_string(Id).length(), '0') + to_string(Id);
        cout << "-----------------------------------" << endl;
        cout << "Nhap thong tin cho sinh vien:" << endl;
        cout << "Nhap ten sinh vien:";
        getline(cin, TenSV);
        cout << "Nhap Diem TB:";
        cin >> DiemTB;
        cin.ignore();
        cout << "------------------------------------" << endl;
    }

    void in()
    {
        cout << "========================================" << endl;
        cout << "Ma sinh vien la:" << getMaSV() << endl;
        cout << "Ho ten sinh vien la:" << getTenSV() << endl;
        cout << "Diem trung binh la:" << getDiemTB() << endl;
        cout << "========================================" << endl;
    }

    void LuuFile()
    {
        ofstream file("sinhvien.txt", ios::app);
        if (!file.is_open())
        {
            cout << "Mo file khong thanh cong!" << endl;
        }
        else
        {
            file << MaSV << endl;
            file << TenSV << endl;
            file << DiemTB << endl;
        }
        file.close();
    }

    void DocFile()
    {
        ifstream file("sinhvien.txt");
        if (!file.is_open())
        {
            cout << "Mo file khong thanh cong!" << endl;
        }
        else
        {
            string Luu;
            while (getline(file, Luu))
            {
            }
        }
        file.close();
    }

    string getMaSV()
    {
        return MaSV;
    }

    string getTenSV()
    {
        return TenSV;
    }

    float getDiemTB()
    {
        return DiemTB;
    }

    static void tangdem()
    {
        Id++;
    }

    static int getdem()
    {
        return Id;
    }

    static void ThemSV(SinhVien SV[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            SV[i].nhap();
            SV[i].LuuFile();
        }
    }

    friend void TimKiem(SinhVien SV[], int n);
};

int SinhVien::Id = 0;

void TimKiem(SinhVien SV[], int n)
{
    string masv;
    cout << "Nhap Ma sinh vien can tim kiem: ";
    getline(cin, masv);

    for (int i = 0; i < n; i++)
    {
        if (masv == SV[i].getMaSV())
        {
            SV[i].in();
            return; // Kết thúc vòng lặp khi tìm thấy sinh viên
        }
    }

    cout << "Khong tim thay sinh vien voi MaSV: " << masv << endl;
}

void menu()
{
    cout << "1. Nhap thong tin sinh vien" << endl;
    cout << "2. Tim kiem thong tin sinh vien" << endl;
    cout << "3. In thong tin sinh vien" << endl;
    cout << "4. Thoat" << endl;
}

int main()
{
    SinhVien sv[100]; // assuming a maximum of 100 students
    int soluong = 0;  // number of students entered
    int choice;

    do
    {
        menu();
        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice)
        {
        case 1:
            int soluongThem;
            cout << "Nhap so luong sinh vien muon nhap: ";
            cin >> soluongThem;
            cin.ignore(); // Clear the input buffer
            SinhVien::ThemSV(sv, soluongThem);
            soluong += soluongThem;
            break;

        case 2:
            TimKiem(sv, soluong);
            break;

        case 3:
            for (int i = 0; i < soluong; i++)
            {
                sv[i].in();
            }
            break;

        case 4:
            cout << "Thoat chuong trinh." << endl;
            break;

        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
