#include <iostream>
#include <string>

using namespace std;

class Transport {
private:
    string brand; // thuong hieu
    string color;

public:
    Transport(string brand, string color) {
        this->brand = brand;
        this->color = color;
    }

    string getBrand() {
        return brand;
    }

    string getColor() {
        return color;
    }

    void display() {
        cout << "brand: " << brand << endl;
        cout << "color: " << color << endl;
    }
};

class Car : public Transport {
private:
    int numberChair; // so ghe
    string name;

public:
    Car(int numberChair, string name, string brand, string color) : Transport(brand, color) {
        this->numberChair = numberChair;
        this->name = name;
    }

    int getNumberChair() {
        return numberChair;
    }

    string getName() {
        return name;
    }

    void display() {
        Transport::display();
        cout << "number of chairs: " << numberChair << endl;
        cout << "name: " << name << endl;
    }
};

class Motorbike : public Transport {
private:
    int numberChair; // so ghe
    string name;

public:
    Motorbike(int numberChair, string name, string brand, string color) : Transport(brand, color) {
        this->numberChair = numberChair;
        this->name = name;
    }

    int getNumberChair() {
        return numberChair;
    }

    string getName() {
        return name;
    }

    void display() {
        Transport::display();
        cout << "number of chairs: " << numberChair << endl;
        cout << "name: " << name << endl;
    }
};

int main() {
    Car x(5, "Toyota", "Toyota", "Red");
    x.display();

    Motorbike y(2, "Yamaha", "Yamaha", "Blue");
    y.display();

    return 0;
}
