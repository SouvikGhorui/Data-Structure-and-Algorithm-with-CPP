#include<iostream>
#include<stack>
using namespace std;
class Queue{
public:
    int* arr;
    int capacity;
    int front;
    int rear;
    Queue(int size){
        capacity = size;
        arr = new int[size];
        front = 0;
        rear = -1;
    }
    bool overFlow(){
        return (rear==capacity-1) && (front==0);
    }
    bool underFlow(){
        return (front == rear +1);
    }
    void enqueue(int val){
        if (overFlow()){
            cout<<"Queue is FULL!"<<endl;
            return;
        }
        else if((rear == capacity - 1)&& (front >0)){
            int totalEle = rear - front+1;
            for (int i = 0; i< totalEle; i++){
                arr[i] = arr[front +i];
            }
            front = 0;
            rear = totalEle;
            arr[rear] = val;
            //cout<<"Enqueued: "<<arr[rear]<<endl;
        }
        else{
            arr[++rear] = val;
            //cout<<"Enqueued: "<<arr[rear]<<endl;
            
        }
    }
    int Dequeue(){
        if(underFlow()){
            return -1;
        }
        else{
            int val = arr[front];
            arr[front] = -1;
            front++;
            return val;
        }
    }
    void ReverseQueue(){
        stack <int> s;
        int count = rear - front +1;
        for(int i = 0; i<count ;i++){
            s.push(Dequeue());
        }
        while(! s.empty()){
            enqueue(s.top());
            s.pop();
        }
        show();
    }

    void reverseQueueInplace(){
        int tempfront = front;
        int temprear = rear;
        while(tempfront <temprear){
            int temp = arr[tempfront];
            arr[tempfront]=arr[temprear];
            arr[temprear] = temp;
            tempfront++;
            temprear--;
        }
    }
    void reverseUptoKth(int k){
        int tempfront = front;
        int temprear = (k-1)-front;
        while(tempfront <temprear){
            int temp = arr[tempfront];
            arr[tempfront]=arr[temprear];
            arr[temprear] = temp;
            tempfront++;
            temprear--;
        }
    }
    void show(){
        if(underFlow()){
            return;
        }
        int temp = front;
        while(temp <= rear){
            cout<<arr[temp]<<endl;
            temp++;
        }
    }
};
int main(){
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.show();
    cout<<"After reverse\n";
    q.reverseUptoKth(3);
    q.show();
    return 0;
}