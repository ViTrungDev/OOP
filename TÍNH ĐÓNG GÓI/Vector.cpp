#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }
    int tong = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        tong += arr[i];
    }
    cout << "tong = " << tong;
}