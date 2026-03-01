#include<iostream>
using namespace std;
class TwoStack{
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack(int size){
        this-> size = size;
        top1=-1;
        top2= size;
        arr = new int[size];
    }
    void push1(int val){
        if(top2 - top1 >1){
            top1++;
            arr[top1] = val;
        }
    }
    void push2(int val){
        if(top2-top1>1){
            top2--;
            arr[top2] = val;
        }
    }
    int pop1(){
        if(top1>=0){
            int x = arr[top1];
            top1--;
            return top1;
        }
        return -1;
    }
    int pop2(){
        if(top2<size){
            int x = arr[top2];
            top2++;
            return x;
        }
        return -1;
    }

};
int main(){

    TwoStack s(10);
    s.push1(1);
    s.push1(1);
    s.push1(1);
    
    return 0;
}