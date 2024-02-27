/*Phương thức thuần ảo: là những phương thức sẽ đc khai báo ở lớp cha còn việc định nghĩa sẽ de các lớp con đảm nhận
-bắt buộc
cú pháp: <virtual><kieu dữ liêu><ten phương thức>(các phương thức chuyền vào nếu có)=0;
Lưu ý:
nếu ở lớp cha có khai báo phương thức thuần ảo thì quy tắc các lớp con nào mà kế thừa lại từ lóp cha thì các lớp con kế thừa
từ lớp cha đó bắt buộc phải đi định nghĩa lại phương thức thuần ảo của lớp cha đó
- nếu lớp con mà không định nghĩa lại thì sẽ báo lỗi.
*/
/*
Khi nào cài đại phương thức ảo và phương thức thuần ảo ??
- dùng phương thức ảo: khi ở lớp cha nó có thông tin gì để tính toán
- dùng phương thức thuần ảo: khi lớp cha nó không có thông tin để tính toán.
*/
/*Biến phương thức thuần ảo thành phương thức ảo:
 */
#include <iostream>
using namespace std;
class A /* class cha*/
{
public:
    virtual void xuat() // phuong thuc ao
    {
        cout << "Ai keu toi day co A day!!" << endl;
    }
    // virtual void tinhToan() = 0; // phuong thuc thuan ao
    // virtual int TinhToan()=0;
    virtual int tinhToan() // bien thuan ao thanh ao
    {
        return 0;
    }
};
class B : public A
{
public:
    void xuat() override // ghi de
    {
        cout << "Ai keu toi day co B day!!" << endl;
    }
    int tinhToan()
    {
        return 2 * 3;
    }
};
class C : public A
{
public:
    void xuat() override
    {
        cout << "Ai keu toi day co C day!!" << endl;
    }
};
int main()
{
    A *x = new C;
    cout << x->tinhToan() << endl;
    delete x;
    x = new B;
    cout << x->tinhToan();
    delete x;
    return 0;
}