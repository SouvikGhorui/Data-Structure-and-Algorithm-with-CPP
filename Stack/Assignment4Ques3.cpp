#include<iostream>
#include<string>
using namespace std;
class stack{
    char* arr;
    int top;
    int size;
public:
    stack(int size){
        this->size = size;
        arr = new char[size];
        top = -1;
    }
    void push(char val){
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
    char peek(){
        if(top<0){
            return '\0';
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
    string expre;
    int n=0;
    cout<<"Enter the expression:"<<endl;
    getline(cin, expre);
    n =expre.length();
    stack s(n);
    for(int i = 0; i<n ;i++){
        // if char is a opening bracket...
        if((expre[i]=='(' )|| (expre[i]=='{') || (expre[i]=='[') ){
            // push it to stack
            s.push(expre[i]);
        }
        // if char is a closing bracket...
        if((expre[i]==')' )|| (expre[i]=='}') || (expre[i]==']') ){
            // if we have a closing bracket but the stack is empty.. Unbalanced..
            if(s.isEmpty()){
                cout<<"Unbalanced";
                return 0;
            }
            // check for ()
            if((expre[i]==')') && (s.peek()=='(')){
                s.pop();
            }
            // check for {}
            else if((expre[i]=='}') && (s.peek()=='{')){
                s.pop();
            }
        // check for []
            else if((expre[i]==']') && (s.peek()=='[')){
                s.pop();
            }
        }
    }
    if(!s.isEmpty()){
        cout<<"Unbalanced";
    }
    else{
        cout<<"Balanced";
    }

  return 0;
}