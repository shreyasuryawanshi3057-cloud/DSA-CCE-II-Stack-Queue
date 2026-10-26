
#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* prev;
    node* next;

    node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class doublylinkedlist {
private:
    node* head;

public:
    doublylinkedlist() {
        head = nullptr;
    }

    void insert(int val) {
        node* p = new node(val);

        if (head == nullptr) {
            head = p;
        }
        else {
            node* q = head;

            while (q->next != nullptr) {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }
    }

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        node* q = head;

        // If the value is in the first node
        if (q->data == val) {
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete q;
            return;
        }

        // Search for the value
        while (q->next != nullptr) {
            if (q->next->data == val) {
                node* p = q->next;

                q->next = p->next;

                if (p->next != nullptr) {
                    p->next->prev = q;
                }

                delete p;
                return;
            }

            q = q->next;
        }

        cout << "Value " << val << " not found in the list.\n";
    }

    void displayforward() {
        node* q = head;

        cout << "Forward: ";

        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->next;
        }

        cout << "NULL\n";
    }

    void displaybackward() {
        if (head == nullptr) {
            cout << "Backward: NULL\n";
            return;
        }

        node* q = head;

        // Move to the last node
        while (q->next != nullptr) {
            q = q->next;
        }

        cout << "Backward: ";

        while (q != nullptr) {
            cout << q->data << " <-> ";
            q = q->prev;
        }

        cout << "NULL\n";
    }
};

int main() {
    doublylinkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.displayforward();
    list.displaybackward();

    list.remove(20);

    list.displayforward();
    list.displaybackward();

    return 0;
}

/*output
PS D:\shreya251> ./output
Forward: 10 <-> 20 <-> 30 <-> NULL
Backward: 30 <-> 20 <-> 10 <-> NULL
Forward: 10 <-> 30 <-> NULL
Backward: 30 <-> 10 <-> NULL
*/
