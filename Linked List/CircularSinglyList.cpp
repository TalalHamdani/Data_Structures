#include<iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next_node;
public:
    Node(int d = 0, Node *next = nullptr){
        data = d;
        next_node = next;
    }
    int retrieve(){
        return data;
    }
    Node *next(){
        return next_node;
    }
    void setNext(Node* ptr){
        next_node = ptr;
    }
};

class CircularList{
private:
    Node* list_head;
public:
    CircularList(){
        list_head = nullptr;
    }
    bool isEmpty(){
        return list_head==nullptr;
    }
    Node* head(){
        return list_head;
    }
    Node* tail(){
        if(isEmpty()){
            return nullptr;
        }
        Node* ptr = list_head;
        while (ptr->next() != list_head) {
            ptr = ptr->next();
        }
        return ptr;
    }
    int front(){
        return head()->retrieve();
    }
    int back(){
        return tail()->retrieve();
    }
    void push_front(int n){
        Node *newNode = new Node(n,nullptr);
        if(isEmpty()){
            list_head = newNode;
            newNode->setNext(newNode);
        }
        else{
            newNode->setNext(list_head);
            tail()->setNext(newNode);
            list_head = newNode;
        }
    }
    void push_back(int n){
        if(isEmpty()){
            push_front(n);
        }
        else{
            Node *newNode = new Node(n,list_head);
            tail()->setNext(newNode);
        }
    }
    void pop_front(){
        if(isEmpty()){
            throw "Underflow";
        }
        
        Node* temp = list_head;
        if(list_head->next() == list_head){
            delete list_head;
            list_head = nullptr;
        }
        else{
            Node *t = tail();
            list_head = list_head->next();
            t->setNext(list_head);
            delete temp;
        }
        temp = nullptr;
    }
    void pop_back(){
        if(isEmpty()){
            throw "Underflow";
        }     
        if(tail()==list_head){
            delete list_head;
            list_head = nullptr;
        }
        else{
             Node* ptr = list_head;
            while(ptr->next() != tail()) {
                ptr = ptr->next();
            }
            Node *temp = tail();
            ptr->setNext(list_head);
            delete temp;
        }
    }
    void erase(int n){
        if(isEmpty()){
            throw "Underflow";
        }

        while(front() == n){
            pop_front();
            if(isEmpty()){
                return;
            }
        }
        while(back() == n){
            pop_back();
            if(isEmpty()){
                return;
            }
        }
        Node* prev = list_head;
        Node* curr = list_head->next();
        while(curr != list_head){
            if(curr->retrieve() == n){
                prev->setNext(curr->next());
                delete curr;
                curr = prev->next();
            }
            else{
                prev = curr;
                curr = curr->next();
            }
        }
    }
    void display(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            Node* ptr = list_head;
            do {
                cout << ptr->retrieve() << " ";
                ptr = ptr->next();
            } while (ptr != list_head);
            cout << endl;
        }
    }
};

int main() {
    CircularList c;
    c.push_front(5);
    c.push_front(1);
    c.push_front(5);
    c.push_front(2);
    c.push_front(5);
    c.push_front(5);

    cout << "Original list: ";
    c.display(); // Expected: 5 5 2 5 1 5

    c.erase(5);

    cout << "List after erasing 5: ";
    c.display(); // Expected: 2 1

    CircularList c2;
    c2.push_front(5);
    c2.push_front(5);
    c2.push_front(5);

    cout << "\nOriginal list 2: ";
    c2.display(); // Expected: 5 5 5

    c2.erase(5);
    
    cout << "List 2 after erasing 5: ";
    c2.display(); // Expected: List is empty.
}