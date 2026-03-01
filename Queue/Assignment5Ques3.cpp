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

    void KthShift(int k){
        if (underflow()){
            return;
        }
        
        for( int i= 0; i< k; i++){
            enqueue(arr[front]);
            dequeue();
        }
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
    void show(){
        if(underflow()){
            return;
        }
        int temp = front;
        while(temp <= rear){
            cout<<arr[temp]<<endl;
            temp= (temp +1) % capacity;
        }
    }
};
int main(){
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"The elements are following "<<endl;
    q.show();
    cout<<"Shifting elements 2 places (k = 2) "<<endl;
    q.KthShift(2);
    cout<<"The elements are following "<<endl;
    q.show();
    
    return 0;
}