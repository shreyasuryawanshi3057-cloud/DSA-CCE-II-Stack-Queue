/student roll __cpp_lib_string_udls
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    char division;

public:
    void getData()
    {
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Division: ";
        cin >> division;
    }

    void displayData()
    {
        cout << "\n----- Student Details -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Division: " << division << endl;
    }
};

int main()
{
    Student s;

    s.getData();
    s.displayData();

    return 0;
}