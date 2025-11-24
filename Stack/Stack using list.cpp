#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next_node;
public:
    Node(int d = 0, Node* next = nullptr) {
        data = d;
        next_node = next;
    }
    int retrieve() {
        return data;
    }
    Node* next() {
        return next_node;
    }
    void setNext(Node* ptr) {
        next_node = ptr;
    }
};

class Stack {
private:
    Node* topPtr;

public:
    Stack() {
        topPtr = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return topPtr == nullptr;
    }

    void push(int n) {
        Node* newNode = new Node(n, topPtr);
        topPtr = newNode;
    }

    void pop() {
        if (isEmpty()) {
            throw "Underflow";
        }
        else {
            Node* temp = topPtr;
            topPtr = topPtr->next();
            delete temp;
            temp = nullptr;
        }
    }

    int top() {
        if (isEmpty()) {
            throw "Stack is empty"; 
        }
        return topPtr->retrieve();
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty." << endl;
        }
        else {
            cout << "Stack (Top -> Bottom): ";
            for (Node* ptr = topPtr; ptr != nullptr; ptr = ptr->next()) {
                cout << ptr->retrieve() << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Stack s;

    // 1. Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Should show: 30 20 10
    s.display(); 

    // 2. Peek at the top
    cout << "Current Top: " << s.top() << endl; 

    // 3. Pop element (Removes 30)
    cout << "Popping top element..." << endl;
    s.pop();
    
    // Should show: 20 10
    s.display(); 

    return 0;
}

