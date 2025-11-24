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
            for(Node *ptr = list_head; ptr!=nullptr;ptr=ptr->next()){
                if(ptr->next()==nullptr){
                    return ptr;
                }
            }
    }
    int front(){
        return head()->retrieve();
    }
    int back(){
        return tail()->retrieve();
    }
    void push_front(int n){
            Node *newNode = new Node(n,list_head,nullptr);
            if(!isEmpty()){
                list_head->setPrev(newNode);
            }
            list_head = newNode;
    }
    void push_back(int n){
        if(isEmpty()){
            push_front(n);
        }
        else{
            Node *newNode = new Node(n,nullptr,tail());
            tail()->setNext(newNode);
        }
    }
    void pop_front(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            Node* temp = list_head;
            list_head = list_head->next();
            if(list_head != nullptr){
                list_head->setPrev(nullptr);
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
            if(tail()->prev() != nullptr){
                tail()->prev()->setNext(nullptr);
            }
            else{
                list_head = nullptr;
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
            while(front()==n){
                pop_front();
            }
            while(back()==n){
                pop_back();
            }
            for(Node* ptr = list_head; ptr->next()!=nullptr;ptr=ptr->next()){
                if(ptr->next()->retrieve()==n){
                    Node* temp = ptr->next();
                    ptr->setNext(temp->next());
                    delete temp;
                    temp = nullptr;
                }
            }
        }
    }
    void display(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            for(Node* ptr = list_head; ptr!=nullptr; ptr=ptr->next()){
                cout<<ptr->retrieve()<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    List l;
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);
    l.push_back(7);
    l.push_back(6);
    l.display();

    return 0;
}