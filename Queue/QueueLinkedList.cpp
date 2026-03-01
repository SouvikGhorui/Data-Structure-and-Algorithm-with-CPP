#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class Queue{
public:
    Node* front;
    Node* rear;
    Queue(){
        front = rear = NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(front== NULL){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void pop(){
        if(front ==NULL){
            return;
        }
        Node* temp = front;
        front = front ->next;
        temp->next = NULL;
        delete temp;
    }
    int peek(){
        return front->data;
    }
    bool isEmpty(){
        return front ==NULL;
    }      

};


int main(){
    Queue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    while(! Q.isEmpty()){
        cout<<Q.peek()<<"->";
        Q.pop();
    }
    cout<<"NULL";
    return 0;
}