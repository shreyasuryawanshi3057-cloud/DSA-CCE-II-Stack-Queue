#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class linkedlist {
private:
    Node* head;

public:
    linkedlist() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void remove(int x) {
        if (head == NULL) {
            cout << x << " not found" << endl;
            return;
        }

        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != x) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << x << " not found" << endl;
            return;
        }

        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }

    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    linkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();

    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.display();

    list.remove(40);
    list.display();

    list.remove(60);
    list.display();

    list.remove(100);
    list.display();

    return 0;
}
PS D:\shreya251> g++ prac4.cpp -o prac4
PS D:\shreya251> ./prac4
10 20 30
10 20 30 40 50 60
10 20 30 50 60
10 20 30 50
100 not found
10 20 30 50 
