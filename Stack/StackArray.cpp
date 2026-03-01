#include<iostream>
using namespace std;
class stack{
    int* arr;
    int top;
    int size;
public:
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int val){
        if(top>= size -1){ //overflow
            cout<<"Kaha ghus raha he, jagah hi nehi he..!..(overflow)"<<endl;
            return;
        }
        else{
            top = top+1;
            arr[top]= val;
        }
    }
    void pop(){
        if(top<0){
            cout<<"Bacche ki jaan lega kya!!?.. underflow he"<<endl;
            return;
        }
        top = top-1;
        
    }
    void peek(){
        if(top<0){
            cout<<"khali he";
        }
        else{
            cout<<arr[top];
        }
    }
    bool isEmpty(){
        return (top<0);
    }
    bool isFull(){
        return (top>=size-1);
    }
    void show(){
        
    }

};

int main(){
    stack s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    while(! s.isEmpty()){
        s.peek();
        cout<<endl;
        s.pop();
    }
    cout<<s.isFull()<<endl;
    cout<<s.isEmpty()<<endl;

  return 0;
}