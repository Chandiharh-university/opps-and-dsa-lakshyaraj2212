#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, capacity;
    int* queue;

public:
    // Constructor to initialize the queue
    Queue(int size) {
        capacity = size;
        front = 0;
        rear = -1;
        queue = new int[capacity];
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] queue;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        queue[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1; // Indicate that the queue is empty
        }
        int value = queue[front];
        front = (front + 1) % capacity; // Circular increment
        return value;
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot peek." << endl;
            return -1; // Indicate that the queue is empty
        }
        return queue[front];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == (rear + 1) % capacity;
    }

    // Function to check if the queue is full
    bool isFull() {
        return front == (rear + 2) % capacity;
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != (rear + 1) % capacity; i = (i + 1) % capacity) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of capacity 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // This will show that the queue is full
    q.display();

    return 0;
}