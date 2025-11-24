#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int capacity;
    int ifront;
    int iback;
    int count;

public:
    Queue(int size = 10) {
        arr = new int[size];
        capacity = size;
        ifront = 0;
        iback = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void resize() {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        for (int i = 0; i < count; i++) {
            newArr[i] = arr[(ifront + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
        ifront = 0;
        iback = count - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            resize();
        }
        iback = (iback + 1) % capacity;
        arr[iback] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            throw "Underflow";
        }
        ifront = (ifront + 1) % capacity;
        count--;
    }

    int peek() {
        if (isEmpty()){
          throw "Underflow";
        }
        return arr[ifront];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.";
            return;
        }
        for (int i = 0; i < count; i++) {
            cout << arr[(ifront + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    q.display();

    return 0;
}
