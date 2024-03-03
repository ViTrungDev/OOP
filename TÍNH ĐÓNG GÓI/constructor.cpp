/* ham khoi tao constructor : là hàm đặc biệt để khởi tạo đối tượng
Constructor trung ten với class
Constructor đc gọi khi khoi tao class
*/
#include <iostream>
#include <string>

using namespace std;
class student
{
private:
    string ID;
    string name;
    int age;
    float point;

public:
    student(void) // ham tao constructor ko co tham so
    {
        cout << "The parameterless constructor is called!" << endl;
        ID = "0000";
        name = "unknown";
        age = 0;
        point = 0;
    }
    student(string ID, string name, int age, float point) // ham tao construct co nhieu tham so
    {
        cout << "The four-argument initialization function is called!" << endl;
        this->ID = ID;
        this->name = name;
        this->age = age;
        this->point = point;
    }
    ~student() // ham huy
    {
        cout << "destructor is called !" << endl;
    }
    void output();
};
void student::output()
{
    cout << "ID:" << ID << endl;
    cout << "Name:" << name << endl;
    cout << "Age:" << age << endl;
    cout << "Point:" << point << endl;
}
int main()
{
    student s;
    s.output();
    student S1("111", "unknown", 0, 0.0);
    S1.output();

    return 0;
}
