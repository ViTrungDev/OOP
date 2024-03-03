#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    A()
    {
        cout << "Constructor cua lop A " << endl; // khi goi constructor thi no goi cua lop A truoc sau do moi den lop B
    }
    ~A()
    {
        cout << "Destructor cua lop A" << endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout << "Constructor cua lop B" << endl;
    }
    ~B()
    {
        cout << "Destructor cua lop B" << endl; // con khi goi ham huy thi no goi ham huy cua lop B truoc
    }
};
int main()
{
    B obj;
}