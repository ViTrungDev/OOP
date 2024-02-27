#include <iostream>
#include <string>

using namespace std;
class Person
{
private:
    string name;
    int age;

public:
    void setPerson(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    string getname()
    {
        return this->name;
    }
    int getage()
    {
        return this->age;
    }
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    ~Person(){};
    void display();
};
void Person::display()
{
    cout << "Name:" << name << endl;
    cout << "Age:" << age << endl;
}
class Student : public Person
{ // class Student ke thua cac thuoc tinh name va age tu class person
private:
    double gpa;

public:
    Student(string name, int age, double gpa) : Person(name, age) // chi can gan gpa vi name va age da ke thua tu person
    {
        this->gpa = gpa;
    }
    void setgpa(double gpa)
    {
        this->gpa = gpa;
    }
    double getgpa()
    {
        return this->gpa;
    }
    void display();
};
void Student::display()
{
    Person::display(); // Kế thừa hàm display của lớp cha
    cout << "gpa:" << gpa << endl;
}
class Teacher : public Person
{
private:
    double salary; // tien luong
public:
    Teacher(string name, int age, double salary) : Person(name, age)
    {
        this->salary = salary;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getsalary()
    {
        return this->salary;
    }
    void display()
    {
        Person::display();
        cout << "Salary:" << salary << endl;
    }
};
int main()
{
    Student s("tran van a", 20, 3.4);
    Teacher a("tran thi b", 23, 1200);
    s.display();
    a.display();

    return 0;
}