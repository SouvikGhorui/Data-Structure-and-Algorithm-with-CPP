#include<iostream>
using namespace std;

#define MAX 100

class CircularQueue{
public:
    int front;
    int rear;
    int* arr;
    int capacity;
    int count;
    CircularQueue(){
        arr = new int[MAX];
        front = 0;
        rear = -1;
        capacity = MAX;
        count=0;
    }
    bool overflow(){
        return count == capacity;
    }
    bool underflow(){
        return count ==0;
    }
    void dequeue(){
        if(underflow()){
            cout<<"There is no element to delete"<<endl;
            return;
        }
        arr[front] = -1;
        front = (front+1)% capacity;
        count -=1;
    }
    void enqueue(int val){
        if(overflow()){
            cout<<"There is no space"<<endl;
            return;
        }
        rear = (rear+1)% capacity;
        arr[rear] = val;
        count+=1;
    }
    void peek(){
        if(underflow()){
            cout<<"There is nothing to show"<<endl;
            return;
        }
        cout<<arr[front]<<endl;

    }
    int totalEle(){
        return count;
    }
};
int main(){
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    cout<<"Total element present in Queue: "<<q.totalEle()<<endl;
    cout<<"The elements are following "<<endl;
    while(!q.underflow()){
        q.peek();
        q.dequeue();
    }
    return 0;
}