#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted element: " << front->data << "\n";

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = nullptr;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- QUEUE USING LINKED LIST ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
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
