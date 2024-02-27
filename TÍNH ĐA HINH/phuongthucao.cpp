/* Phương thức ảo:Những phương thức ở lớp cha được khai báo với từ khóa "virtual"thì các lớp con có thể kế thừa từ nó
cũng sẽ cài đạt lại các phương thức "trùng tên" của lớp cha-để cho các phương thức của lớp con có thể nạp chồng lại được
-định nghĩa lại các phương thức của lớp cha
- Nếu như lớp cha ko có từ khóa "virtual" thì nó mặc định chạy về phương thức tringf tên của lớp cha
- Tác dụng của từ khóa Virtual: nếu như các phương thức có khai báo từ khóa virtual thì khi new ra 1 đối tượng bất kì thi khi đó nó
sẽ chạy vào phương thức trùng tên của lớp con đó _ nó cho chúng ta goi lại phương thức trùng tên của lớp con.

cú pháp:<virtual><kiểu dữ liệu><Tên phương thức>(các tham số truyền vào nếu có);
*/
#include <iostream>
using namespace std;
class A /* class cha*/
{
public:
    virtual void xuat()
    {
        cout << "Ai keu toi day co A day!!" << endl;
    }
};
class B : public A
{
public:
    void xuat() override // ghi de
    {
        cout << "Ai keu toi day co B day!!" << endl;
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
    A *a = new A;
    a->xuat();
    delete a;

    a = new C;
    a->xuat();
    delete a;

    a = new B;
    a->xuat();
    delete a;

    return 0;
}