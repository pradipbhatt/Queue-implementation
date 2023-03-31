#include <iostream>
#define MAX_SIZE 1000 // maximum size of the queue

using namespace std;

class Queue {
    private:
        int arr[MAX_SIZE];
        int front;
        int rear;
    public:
        Queue() {
            front = -1;
            rear = -1;
        }
        bool isEmpty() {
            return front == -1 && rear == -1;
        }
        bool isFull() {
            return rear == MAX_SIZE - 1;
        }
        void enqueue(int x) {
            if (isFull()) {
                cout << "Error: Queue is full" << endl;
                return;
            }
            else if (isEmpty()) {
                front = rear = 0;
            }
            else {
                rear++;
            }
            arr[rear] = x;
        }
        void dequeue() {
            if (isEmpty()) {
                cout << "Error: Queue is empty" << endl;
                return;
            }
            else if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }
        int peek() {
            if (isEmpty()) {
                cout << "Error: Queue is empty" << endl;
                return -1;
            }
            return arr[front];
        }
};

int main() {
    system("cls");
    Queue q;
    int choice, value;

    while (true) {
        cout << "1. Enqueue an element" << endl;
        cout << "2. Dequeue an element" << endl;
        cout << "3. Peek the front element" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Front element of the queue: " << q.peek() << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice, please try again" << endl;
        }

        cout << endl;
    }

    return 0;
}