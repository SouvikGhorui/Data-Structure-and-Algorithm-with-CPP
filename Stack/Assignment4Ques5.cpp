#include<iostream>
#include<string>
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
    int pop(){
        if(top<0){
            return -1;
        }
        int temp =arr[top];
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

};

int main(){
    string expre;
    cout<<"Enter the expression:"<<endl;
    cin>>expre;
    int n = expre.length();
    stack s(10);
    for(int i=0;i<n; i++){
        if((expre[i]!='+') && (expre[i]!= '-') && (expre[i]!= '*') && (expre[i]!= '/')){
            s.push(expre[i]- '0');
        }
        
        if((expre[i]=='+') || (expre[i]== '-') || (expre[i]== '*') || (expre[i]== '/')){
            int val1 = s.pop();
            int val2 = s.pop();
            int temp =0;
            switch (expre[i])
            {
            case '+':
                temp = val2 + val1;
                break;
            case '-':
                temp = val2 - val1;
                break;
            case '*':
                temp = val2 * val1;
                break;
                case '/':
                temp = val2 / val1;
                break;
            default:
                break;
            }
            s.push(temp);
        }
    }
    while(!s.isEmpty()){
        cout<<s.peek();
        s.pop();
    }
    return 0;
}