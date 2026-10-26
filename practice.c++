
#include <iostream>
using namespace std;

class Rectangle
{
public:
    float length;
    float breadth;

    float calculateArea()
    {
        return length * breadth;
    }
};

int main()
{
    Rectangle r1;

    r1.length = 10;
    r1.breadth = 20;

    cout << "Area of r1 is: " << r1.calculateArea() << endl;

    return 0;
}