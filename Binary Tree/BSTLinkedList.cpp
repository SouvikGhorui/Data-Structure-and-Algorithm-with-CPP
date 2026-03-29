#include<iostream>
using namespace std;

class treeNode{
public:
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST{
public:
    treeNode* root;
    BST(){
        root = NULL;
    }
    bool isEmpty(){
        return root == NULL;
    }
};
int main(){
    int option;

    do{
        cout<<"What operation do you want to perform"<<"Select option numbers"
        <<"Press 0 to exit"<<endl;
        cout<<"1. Insert Node"<< endl;
        cout<<"2. Search Node"<< endl;
        cout<<"3. Delete Node"<< endl;
        cout<<"4. Print BST Values"<< endl;
        cout<<"0. Exit program"<< endl;
    
        cin>>option;
    switch(option){
        case 0:
            break;
        case 1:
            cout<<"Insert"<<endl;
            break;
        case 2:
            cout<<"Search"<<endl;
            break;
        case 3:
            cout<<"Delete"<<endl;
            break;
        case 4:
            cout<<"Print an traverse"<<endl;
            break;
        default:
            cout<<"Enter valid number"<<endl;
            break;
        
    };
    }while(option!=0);

    return 0;
}