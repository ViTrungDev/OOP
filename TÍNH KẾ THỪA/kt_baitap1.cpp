#include <iostream>
#include <string>
using namespace std;
class dongVat
{
private:
    string name;
    int age;
    string color;

public:
    void setDV(string name, int age, string color)
    {
        this->name = name;
        this->age = age;
        this->color = color;
    }
    string getname()
    {
        return name;
    }
    int getage()
    {
        return age;
    }
    string getcolor()
    {
        return color;
    }
    dongVat(string name, int age, string color)
    {
        this->name = name;
        this->age = age;
        this->color = color;
    }
    ~dongVat(){};
    void display()
    {
        cout << "Name:" << name << endl;
        cout << "age:" << age << endl;
        cout << "color:" << color << endl;
    }
};
class cat : public dongVat
{
public:
    cat(string name, int age, string color) : dongVat(name, age, color)
    {
    }
    void display();
};
void cat::display()
{
    dongVat::display();
    cout << "meo meo" << endl;
}
class dog : public dongVat
{
public:
    dog(string name, int age, string color) : dongVat(name, age, color){

                                              };
    void display()
    {
        dongVat::display();
        cout << "go go" << endl;
    }
};
int main()
{
    cat meoden("meo long dai", 2, "mau den");
    meoden.display();
    dog cho("cho co", 3, "mau vang");
    cho.display();
    return 0;
}
