#include <iostream>
using namespace std;

class complex{
    private:
    float real;
    float imag;
    public:
    complex(){
        real = 0;
        imag = 0;
    }
    complex(float r,float i){
        real = r;
        imag = i;
    }
~complex(){ }
void display(){
    cout<<real<<"+"<<imag<<"i"<<endl;
}
complex operator+(complex c){
    return complex(real+c.real,imag+c.imag);
}
complex operator-(complex c){
    return complex(real-c.real,imag-c.imag);
}
complex operator*(complex c){
    float r = real*c.real-imag*c.imag;
    float i = real*c.imag+imag*c.real;
    return complex(r,i);

}
};
    
int main(){
    complex c1(1,8),c2(3,4);
    cout<<"\nfirst complex number: ";
    c1.display();
    cout<<"second complex number: ";
    c2.display();

    complex sum = c1 + c2;
    cout<<"\nsum: ";
    sum.display();

    complex diff = c1 - c2;
    cout<<"difference: ";
    diff.display();

    complex prod = c1 * c2;
    cout<<"product: ";
    prod.display();
    return 0;

}

/*output
[Running] cd "d:\shreya251\" && g++ prac1.cpp -o prac1 && "d:\shreya251\"prac1

first complex number: 1+8i
second complex number: 3+4i

sum: 4+12i
difference: -2+4i
product: -29+28i

[Done] exited with code=0 in 1.458 seconds

*/
