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

class Queue{
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
        if(isEmpty()){
            return nullptr;
        }
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
            Node *newNode = new Node(n,list_head);
            list_head = newNode;
    }
    
    void pop(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            Node *temp = tail();
            for(Node *ptr=list_head; ptr!=nullptr; ptr=ptr->next()){
                if(ptr->next()==tail()){
                    delete tail();
                    ptr->setNext(nullptr);
                }
            }
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
            for(Node* ptr = list_head; ptr!=tail();ptr=ptr->next()){
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
           for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next()) {
				cout << ptr->retrieve() << " ";
			}
			cout << "\n"; 
        }
    }
};

int main() {
	Queue q;
	q.push(5);
    q.push(4);
    q.push(3);
    q.push(7);
    q.push(6);
    q.display();

    return 0;
}
