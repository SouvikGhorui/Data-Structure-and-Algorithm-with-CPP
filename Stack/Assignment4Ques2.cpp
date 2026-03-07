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
    string word;
    int n = 0;
    cout<<"Enter the word"<<endl;
    cin>>word;
    // storing the length of the string
    n = word.length();
    // create a stack of size n( length of string)
    stack s(n);
    for(int i = 0; i< n; i++){
        // check if stack if not empty and the character at the top is matched with the ith character
        if((! s.isEmpty()) && (s.peek() == word[i])){
            // if yes, then the character is a adjecent duplicate and i don't want this character to be in stack
            // so, we pop the character
            s.pop();
        }
        else{
            // the char is not a adjacent duplicate and hence add it to stack
            s.push(word[i]);
        }
    }
    cout<<"Input: "<<word<<endl;
    // define a variable to store our output
    string result;
    // while there is an char in the stack, loop runs
    while(! s.isEmpty()){
        // concaticate each char to the left
        result = s.peek() + result;
        // now pop the char we already added to the output string
        s.pop();
    }
    cout<<"Output :"<<result;


    return 0;
}