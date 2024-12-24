#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Stack class to manage stack operations
class Stack {
private:
    Node* top; // Pointer to the top node of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr; // Initially, the stack is empty
    }

    // Function to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top; // Link the new node to the previous top
        top = newNode; // Update the top to the new node
        cout << "Pushed: " << value << endl;
    }

    // Function to remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1; // Indicate that the stack is empty
        }
        int value = top->data; // Get the data from the top node
        Node* temp = top; // Store the current top node
        top = top->next; // Update the top to the next node
        delete temp; // Free the memory of the old top node
        return value; // Return the popped value
    }

    // Function to return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return -1; // Indicate that the stack is empty
        }
        return top->data; // Return the data from the top node
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // Return true if top is null
    }

    // Function to display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = top; // Start from the top
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " "; // Print the data
            temp = temp->next; // Move to the next node
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Pop all elements to free memory
        }
    }
};

int main() {
    Stack s; // Create a stack

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    cout << "Popped: " << s.pop() << endl;
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.push(40);
    s.display();

    return 0;
}