#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;
        cout << value << " inserted into queue.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Deleted element: " << arr[front] << "\n";

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- QUEUE USING ARRAY ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
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
/*
--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 10
10 inserted into queue.

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 20
20 inserted into queue.

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value: 30
30 inserted into queue.

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Queue elements: 10 20 30

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 2
Deleted element: 10

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 3
Queue elements: 20 30

--- QUEUE USING ARRAY ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 4
Exiting...
*/
