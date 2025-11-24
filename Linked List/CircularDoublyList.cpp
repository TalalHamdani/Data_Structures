#include<iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next_node;
    Node* prev_node;
public:
    Node(int d = 0, Node *next = nullptr, Node *prev = nullptr){
        data = d;
        next_node = next;
        prev_node = prev;
    }
    int retrieve(){
        return data;
    }
    Node *next(){
        return next_node;
    }
    Node *prev(){
        return prev_node;
    }
    void setNext(Node* ptr){
        next_node = ptr;
    }
    void setPrev(Node* ptr){
        prev_node = ptr;
    }
};

class List{
private:
    Node* list_head;
public:
    List(){
        list_head = nullptr;
    }
    bool isEmpty(){
        return list_head==nullptr;
    }
    Node* head(){
        return list_head;
    }
    Node* tail(){
        if (isEmpty()){
            return nullptr;
        }
        return list_head->prev();
    }
    int front(){
        return head()->retrieve();
    }
    int back(){
        return tail()->retrieve();
    }
    void push_front(int n){
        Node* newNode = new Node(n);
        if(isEmpty()){
            list_head = newNode;
            newNode->setNext(newNode);
            newNode->setPrev(newNode);
        }
        else{
            Node* t = tail();
            newNode->setNext(list_head);
            list_head->setPrev(newNode);
            newNode->setPrev(t);
            t->setNext(newNode);
            list_head = newNode;
        }
    }
    void push_back(int n){
        if(isEmpty()){
            push_front(n);
        }
        else{
            Node *newNode = new Node(n);
            Node* t = tail();
            newNode->setNext(list_head);
            list_head->setPrev(newNode);
            newNode->setPrev(t);
            t->setNext(newNode);
        }
    }
    void pop_front(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            Node* temp = list_head;
            if(list_head->next() == list_head){
                delete list_head;
                list_head = nullptr;
            }
            else{
                Node* t = tail();
                Node* newHead = list_head->next();
                t->setNext(newHead);
                newHead->setPrev(t);
                list_head = newHead;
            }
            delete temp;
            temp = nullptr;
        }
    }
    void pop_back(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            Node *temp = tail();
            if(temp == list_head){
                delete list_head;
                list_head = nullptr;
            }
            else{
                Node* newTail = temp->prev();
                newTail->setNext(list_head);
                list_head->setPrev(newTail);
            }
            delete temp;
            temp = nullptr;
        }
    }
    void erase(int n){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            while(front() == n){
                pop_front();
                if(isEmpty()){
                    return;
                }
            }
            while(back()==n){
                pop_back();
                if(isEmpty()){
                    return;
                }
            }
            Node* curr = list_head->next();
            while(curr != list_head){
                if(curr->retrieve() == n){
                    Node* prev = curr->prev();
                    Node* next = curr->next();
                    prev->setNext(next);
                    next->setPrev(prev);
                    Node *temp = curr;
                    curr = next;
                    delete temp;
                }
                else{
                    curr = curr->next();
                }
            }
        }
    }
    void display(){
        if(isEmpty()){
            cout << "List is empty" << endl;
            return;
        }
        Node* ptr = list_head;
        do{
            cout << ptr->retrieve() << " ";
            ptr = ptr->next();
        }while(ptr != list_head);
        cout << endl;
    }
};

int main() {
    List cdl;
    cdl.push_back(10);
    cdl.push_back(20);
    cdl.push_front(5); // List: 5 10 20
    cdl.display();

    cout << "Popping from back..." << endl;
    cdl.pop_back(); // List: 5 10
    cdl.display();

    cout << "Popping from front..." << endl;
    cdl.pop_front(); // List: 10
    cdl.display();

    // Test erase
    cdl.push_front(5);
    cdl.push_back(10);
    cdl.push_back(15);
    cdl.push_back(10);
    cout << "\nNew list for erase test: ";
    cdl.display(); // List: 5 10 10 15 10

    cout << "Erasing all 10s..." << endl;
    cdl.erase(10);
    cdl.display(); // List: 5 15
}