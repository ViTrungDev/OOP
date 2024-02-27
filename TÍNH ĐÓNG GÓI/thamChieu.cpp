// tham chiếu: kí hiệu là &
// đc sử dụng để trỏ đến gia trị cần thay đổi
// sử dụng từ khóa const để giữ lại giá trị ban đầu của biến
#include <iostream>

using namespace std;
void updatebalance(int &balance, int change)
{
    balance += change;
}

int main()
{
    int amount = 0;
    // nap tien vao the
    updatebalance(amount, 20000);
    cout << amount << endl;
    // rut tien
    updatebalance(amount, -10000);
    cout << "so du sau khi rut la:" << amount << endl;

    return 0;
}