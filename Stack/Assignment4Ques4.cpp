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
    int peek(){
        if(top<0){
            return -1;
        }
        else{
            return arr[top];
        }
    }
    bool isEmpty(){
        return (top<0);
    }
    bool isFull(){
        return (top>=size-1);
    }

};

int main(){
    int n;
    cout<<"Enter non-negative number:"<<endl;
    cin>>n;
    stack s(10);
    // while n is not 0 ...
    while(n!=0){
        // store the remainder...
        int temp = n % 2;
        // put it to stack
        s.push(temp);
        // replace n by quotient
        n = n/2;
    }
    // print the binary representation
    while(! s.isEmpty()){
        cout<<s.peek();
        s.pop();
    }
    return 0;
}