#include <iostream>
#include <string>

using namespace std;
// con tro this tham chieu den doi tuong dang goi ham thanh phan
// setter:Dùng để cập nhật giá trị cho thuộc tính từ bên ngoài lớp. Nó cho phép bạn thay đổi giá trị của thuộc tính mà không cần biết giá trị đó được lưu trữ như thế nào.
// getter:Dùng để lấy giá trị của thuộc tính từ bên trong lớp ra ngoài. Nó cho phép bạn truy cập vào giá trị của thuộc tính mà không cần biết cách giá trị đó được tính toán hoặc lấy ra từ đâu.
// get và set được sử dụng để kiểm soát việc truy cập và thay đổi giá trị của các thuộc tính, giúp ngăn chặn việc truy cập trực tiếp vào các thuộc tính từ bên ngoài lớp, đảm bảo tính đóng gói
class Fruif
{
private:
    string name;
    int price;
    string address;

public:
    void printInfo();
    void setname(string name) // con bien name la thuoc string name
    {
        this->name = name; // this -> name la tro den bien name cua private
    }
    void setprice(int price)
    {
        this->price = price;
    }
    void setaddress(string address)
    {
        this->address = address;
    }
    // hoac
    void setFruifData(string name, int price, string address)
    {
        this->name = name;
        this->price = price;
        this->address = address;
    }
    string getname(void)
    {
        return this->name;
 // hoac return name vi name la bien cuc bo
    }
    int getprice(void)
    {
        return this->price;
    }
    string getaddress(void)
    {
        return this->address;
    }
};
void Fruif::printInfo()
{
    cout << "Name:" << this->name << endl;       // hoac this->name;
    cout << "price:" << price << endl;     // hoac this-> price;
    cout << "address:" << address << endl; // hoac this-> address;
}

int main()
{
    Fruif apple;
    int giaTien;
    /*apple.setname("tao my");
    apple.setprice(20000);
    apple.setaddress("viet nam");*/
    apple.setFruifData("tao tau", 30000, "trung quoc");
    apple.printInfo();
    apple.setFruifData()
    giaTien = apple.getprice();
    if (giaTien < 20000)
    {
        cout << "gia re" << endl;
    }
    else
    {
        cout << "dat" << endl;
    }

    return 0;
}