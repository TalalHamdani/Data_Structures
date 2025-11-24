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

class Queue {
private:
    Node* top;

public:
    Queue() {
        top = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void queue(int n) {
        Node* newNode = new Node(n, top);
        top = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            throw "Underflow";
        }
        if (top->next() == nullptr) {
            delete top;
            top = nullptr;
        }
        else {
            Node* temp = top;
            while (temp->next()->next() != nullptr) {
                temp = temp->next();
            }
            delete temp->next();
            temp->setNext(nullptr);
        }
    }
    int front() {
        if (isEmpty()) {
            throw "Queue is empty"; 
        }
        
        Node* temp = top;
        while (temp->next() != nullptr) {
            temp = temp->next();
        }
        return temp->retrieve();
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        }
        else {
            cout << "Queue (Rear -> Front): ";
            for (Node* ptr = top; ptr != nullptr; ptr = ptr->next()) {
                cout << ptr->retrieve() << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Queue q;

    //queue elements (Enqueuing at Head)
    q.queue(10);
    q.queue(20);
    q.queue(30); 

    // Should show: 30 20 10
    q.display(); 

    //Peek at the front (The opposite end)
    try {
        cout << "Current Front: " << q.front() << endl; 
    } catch (const char* msg) {
        cout << msg << endl;
    }

    //dequeue element
    cout << "dequeueping front element..." << endl;
    q.dequeue();
    
    // Should show: 30 20
    q.display(); 
    
    //dequeue again
    cout << "dequeueping front element..." << endl;
    q.dequeue();
    
    // Should show: 30
    q.display();

    return 0;
}
