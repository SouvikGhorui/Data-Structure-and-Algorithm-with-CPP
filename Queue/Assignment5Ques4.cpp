#include<iostream> 
using namespace std;

struct Node{
    int data;
    Node* next;
};

class Queue{
public:
    Node* front;
    Node* rear;
    int count;
    void enqueue(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        if(front== NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        count++;
    }
    void dequeue(){
        if(front ==NULL){
            return;
        }
        Node* temp = front;
        front = front ->next;
        temp->next = NULL;
        delete temp;
        count--;
    }
    int peek(){
        return front->data;
    }
    bool isEmpty(){
        return front ==NULL;
    }      
    void totalEle(){
        cout<<"Total elements present in the queue is = "<<count<<endl;
    }
    void searchEle(int x){
        if (front ==NULL){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node* temp = front;
        for(int i=0;i<count;i++){
            if(temp-> data == x){
                cout<<x<<" is present in the Queue in "<<i+1<<"th position"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"The element is "<<x<<" is not present in the queue"<<endl;
    }
    
};
Queue* CreateQueue(){
    Queue* q = new Queue();
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
}
int main(){
    Queue* q = CreateQueue();
    q->enqueue(1); /* where q is a pointer pointing a Queue, whats why i use "->" instead of q.enqueue()*/
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->totalEle();
    q->searchEle(3);
    return 0;
}