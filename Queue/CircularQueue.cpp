#include<iostream>
using namespace std;

class CircularQueue {
public:
    int* arr;
    int front;
    int rear;
    int capacity;

    CircularQueue(int size) {
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return (rear == -1);
    }

    bool isFull() {
        // If the next position of rear is front, it's full
        return ((rear + 1) % capacity == front && rear != -1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        // If inserting the first element
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        // Logical "removal"
        arr[front] = -1;

        if (front == rear) { 
            // Only one element was present, now queue is empty
            front = 0;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }

    int totalEle() {
        if (isEmpty()) return 0;
        if (rear >= front) {
            return rear - front + 1;
        } else {
            // return (capacity - front) + (rear + 1);
            return capacity +(rear - front +1);
        }
    }
    void show(){
        if(isEmpty()){
            return;
        }
        int index = front;
        int count = totalEle();
        for(int i =0; i < count ; i++){
            cout<< arr[index]<< " ";
            index = (index + 1)% capacity;
        }
    }
};
int main(){
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.show();
    
    return 0;
}