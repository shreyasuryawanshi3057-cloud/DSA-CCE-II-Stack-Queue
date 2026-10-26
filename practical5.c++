#include <iostream>
using namespace std;
const int MAX = 5;
class stack 
{
    private:
    int a[MAX];
    int top;

    public:
    stack()
    {
        top = -1;

    }
    void push(int x){
        if (full())
        {
            cout<<"stack overflow!"<<endl;
            return;

        }
        top++;
        a[top] = x;

    }
    int pop()
    {
        if (empty())
        {
            cout<<"stack overflow"<<endl;
            return -1;

        }
        int x = a[top];
        top--;
        return x;
    }
    int peek()
    {
        if (empty())
        {
            cout<< "stack is empty!"<<endl;
            return -1;

        }
        return a[top];

    }
     bool full()
     {
        return top == MAX -1;
     }
     bool empty()
     {
        return top == -1;
     }
     void display()
     {
        if (empty())
        {
            cout<<"stack is empty!"<<endl;
            return;
        }cout<<"stack element:"<<endl;
        for (int i = top; i>=0; i--)
        {
            cout << a[i] << endl;
        }

     }
    

};
int main()
{
    stack s;
    int x;

    s.push(12);
    s.push(34);
    s.push(56);
    s.push(87);
    s.push(92);
    s.push(99);
    
    s.display();

    if (!s.empty())

    {
        x=s.pop();
        cout<<"removed:"<<x<<endl;
    }
    cout<<"stack after pop:"<<endl;
    s.display();

    if (!s.empty())
    {
        x=s.peek();
        cout << "top element is:"<<x<<endl;

    }
    return 0;
}
/*output
PS D:\shreya251> .\practical5
stack overflow!
stack element:
92
87
56
34
12
removed:92
stack after pop:
stack element:
87
56
34
12
top element is:87
*/