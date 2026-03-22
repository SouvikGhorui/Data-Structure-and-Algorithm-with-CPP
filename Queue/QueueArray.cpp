#include<iostream>
using namespace std;
class Queue{
public :
    int* arr;
    int capacity;
    int front;
    int rear ;
    Queue(int size){
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }
    
    bool isEmpty(){
        return (front == rear +1);
    }
    bool isFull(){
        return (rear == capacity -1) && (front >0);
    }
    void enqueue(int val){
        if(rear == capacity -1 && front ==0){
            cout<<"Array is Full";
            return;
        }
        else if(rear == capacity-1 && front > 0){
            int totalEle = rear - front +1;
            for(int i = 0; i<totalEle; i++){
                arr[i] = arr[front +i];
            }
            front = 0;
            rear= totalEle;
            arr[rear] = val;
            cout<<"Enqueued: "<<val<<endl;
        }
        else{
            rear +=1;
            arr[rear] = val;
            cout<<"Enqueued: "<<val<<endl;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<"Dequeued: "<<arr[front]<<endl;
        arr[front] = -1;
        front +=1;
        if(front >rear){
            front = 0;
            rear = -1;
        }
        
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        else{
            cout<<arr[front]<<endl;
        }
    }
};
int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    while(!q.isEmpty()){
        q.dequeue();
    }

    return 0;

}