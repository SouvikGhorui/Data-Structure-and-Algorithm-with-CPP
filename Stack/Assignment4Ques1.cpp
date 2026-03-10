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
        }
        else{
            top = top+1;
            arr[top]= val;
        }
    }
    int pop(){
        if(top<0){
            return -1;
        }
        int temp = arr[top];
        top = top-1;
        return temp;
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
    void show(){
        
    }
    void ReverseStack(){
        stack temp1(size);
        stack temp2(size);

        // moving elements from original stact to temp1 stack (it reversed the elements)
        while(!isEmpty()){
            temp1.push(pop());
        }
        // moving elements from temp1 to temp2 stack (back to the original order)
        while(!temp1.isEmpty()){
            temp2.push(temp1.pop());
        }
        // moving elements from temp2 to original stack (hence reversed the order)
        while(!temp2.isEmpty()){
            push(temp2.pop());
        }
    }
};

int main(){
    stack s(10);
    s.push(1);
    s.push(2);
    s.ReverseStack();
    while(! s.isEmpty()){
        cout<<s.pop()<<endl;
    }
  return 0;
}