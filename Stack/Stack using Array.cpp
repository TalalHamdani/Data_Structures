#include<iostream>
using namespace std;

class Stack{
private:
    int *array;
    int stack_size;
    int array_capacity;

    void resize(){
        int new_capacity = array_capacity * 2;
        int *new_array = new int[new_capacity];

        for(int i=0; i<array_capacity;i++){
            new_array[i] = array[i];
        }

        delete []array;
        array = new_array;
        array_capacity = new_capacity;
    }

public:
    Stack(){
        array_capacity = 10;
        array = new int[array_capacity];
        stack_size = 0;
    }
    ~Stack(){
        delete [] array;
    }
    
    bool isEmpty(){
        return stack_size == 0;
    }
    
    int top(){
        if(isEmpty()){
            throw "underflow";
        }
        else{
            return array[stack_size-1];
        }
    }

    int pop(){
        if(isEmpty()){
            throw "Underflow";
        }
        else{
            int poppedValue = array[--stack_size];
            return poppedValue;
        }
    }

    void push(int n){
        if(stack_size == array_capacity){
            resize();
        }
        else{
            array[stack_size] = n;
            stack_size++;
        }
    }

    void display(){
    cout << "Stack (top → bottom): ";
        for (int i = stack_size - 1; i >= 0; i--)
            cout << array[i] << " ";
        cout << endl;    
    }
};

int main(){
    Stack s;
    s.push(5);
    s.display();
    s.push(10);
    s.display();
    s.pop();
    s.display();
    s.push(15);
    s.display();
    cout<<"Top : "<<s.top();
}