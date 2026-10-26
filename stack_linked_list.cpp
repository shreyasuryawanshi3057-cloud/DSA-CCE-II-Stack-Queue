#include <iostream>
using namespace std;

class Stack {
    struct Node {
        int data;
        Node* next;
    };

    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack.\n";
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node* temp = top;
        cout << "Popped element: " << top->data << "\n";

        top = top->next;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK USING LINKED LIST ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
/*
--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 1
Enter value: 10
10 pushed into stack.

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 1
Enter value: 20
20 pushed into stack.

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 1
Enter value: 30
30 pushed into stack.

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 3
Stack elements: 30 20 10

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 2
Popped element: 30

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 3
Stack elements: 20 10

--- STACK USING LINKED LIST ---
1. Push
2. Pop
3. Display
4. Exit
Enter choice: 4
Exiting...
*/
