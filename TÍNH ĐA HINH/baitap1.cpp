#include <iostream>
#include <string>
using namespace std;

class DocGia
{
private:
    string name;
    string dateTime;
    int effectiveDate;

public:
    DocGia(string name, string dateTime, int effectiveDate)
    {
        this->name = name;
        this->dateTime = dateTime;
        this->effectiveDate = effectiveDate;
    }
    ~DocGia(){};
    void setDocGia(string name, string dateTime, int effectiveDate)
    {
        this->name = name;
        this->dateTime = dateTime;
        this->effectiveDate = effectiveDate;
    }
    string getname()
    {
        return this->name;
    }
    string getdateTime()
    {
        return this->dateTime;
    }
    int geteffectiveDate()
    {
        return this->effectiveDate;
    }
    virtual void input();
    virtual void output();
    virtual float cardMoney()
    {
        return 0;
    }
};

void DocGia::input()
{
    cout << "Enter information for readers..." << endl;
    cout << "Enter name:";
    getline(cin, name);
    cout << "Enter the card creation date:";
    getline(cin, dateTime);
    cout << "Enter the number of months the card is valid:";
    cin >> effectiveDate;
    cin.ignore();
}

void DocGia::output()
{
    cout << "==========================================" << endl;
    cout << "Name:" << getname() << endl;
    cout << "Date Time:" << getdateTime() << endl;
    cout << "Effective Date:" << geteffectiveDate() << endl;
}

class children : public DocGia
{
private:
    string deputy; // nguoi dai dien
public:
    children(string name, string dateTime, int effectiveDate, string deputy) : DocGia(name, dateTime, effectiveDate)
    {
        this->deputy = deputy;
    }
    ~children(){};
    void setDeputy(string deputy)
    {
        this->deputy = deputy;
    }
    string getDeputy()
    {
        return this->deputy;
    }
    float cardMoney() override
    {
        return geteffectiveDate() * 5.000;
    }
    void input();
    void output();
};

void children::input()
{
    DocGia::input();
    cout << "Enter representative information:";
    getline(cin, deputy);
}

void children::output()
{
    DocGia::output();
    cout << "Representative information:" << getDeputy() << endl;
    cout << "Card money:" << cardMoney() << ".000 VND" << endl;
}

class adult : public DocGia
{
private:
    string diachi;
    string CCCD;

public:
    adult(string name, string dateTime, int effectiveDate, string CCCD, string diachi) : DocGia(name, dateTime, effectiveDate)
    {
        this->CCCD = CCCD;
        this->diachi = diachi;
    }
    ~adult(){};
    void setdiachi(string diachi)
    {
        this->diachi = diachi;
    }
    string getdiachi()
    {
        return diachi;
    }
    void setCCCD(string CCCD)
    {
        this->CCCD = CCCD;
    }
    string getCCCD()
    {
        return this->CCCD;
    }
    float cardMoney() override
    {
        return geteffectiveDate() * 10.000;
    }
    void input();
    void output();
};

void adult::input()
{
    DocGia::input();
    cout << "Enter CCCD:" << endl;
    cin >> CCCD;
    cin.ignore();
    cout << "diachi" << endl;
    getline(cin, diachi);
}

void adult::output()
{
    DocGia::output();
    cout << "CCCD:" << getCCCD() << endl;
    cout << "diachi:" << getdiachi() << endl;
    cout << "Card money:" << cardMoney() << ".000 VND" << endl;
}

int main()
{
    /* DocGia *docgia = new children("hoang van a", "17/2/2017", 8, "deputy");
     docgia->input();
     docgia->output();
     delete docgia;
 */
    DocGia *docgia = new adult("tran dinh a", "20/1/2011", 10, "098764928", "ha noi");
    docgia->input();
    docgia->output();
    delete docgia;
    return 0;
}
