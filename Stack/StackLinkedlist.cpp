#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next =NULL;
    }
};

class stack{
public:
    Node* top;
    stack(){
        top=NULL;
    }
    void push(int val){
        Node* newNode = new Node(val);
        if(top==NULL){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
        
    }

    void pop(){
        if(top == NULL) return;
        else{
            Node* temp = top;
            top = temp->next;
            delete temp;
        }
    }

    int peek(){
        return top->data;
    }
    bool isEmpty(){
        return (top==NULL);
    }


};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(! s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();

    }
    return 0;
}