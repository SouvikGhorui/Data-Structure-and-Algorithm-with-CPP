#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }

    
    Node* insert(Node* root, int val){
        Node* newNode = new Node(val);
        if(root == NULL) return newNode;
        Node* curr = root;
        while(curr!= NULL){
            if(curr->data > val && curr->left != NULL){
                curr = curr->left;
            }
            else if(curr ->data < val && curr->right != NULL){
                curr = curr->right;
            }
            else break;
        }
        if(curr->data > val){
            curr->left = newNode;
        }
        else{
            curr -> right = newNode;
        }
        return root;
    }

    Node* insertRecursion( Node* root, int val){
        Node* newNode = new Node(val);
        if(root == NULL){
            return newNode;
        }
        if(root->data > val){
            insertRecursion(root->left, val);
        }
        else{
            insertRecursion(root->right, val);
        }
        return root;
    }

    
};