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

    bool searchRecursion(Node* root, int val){
        if (root == NULL) return false;
        if(root->data == val) return true;
        
        if(root-> data > val) 
        searchRecursion(root->left, val);
        else if (root->data < val)
        searchRecursion(root->right,val);
    }

    bool search(Node* root, int val){
        if(root == NULL) return false;
        
        while(root != NULL){
            if(root-> data == val){
                return true;
            }
            else if(root->data > val){
                root = root-> left;
            }
            else if (root ->data < val){
                root = root->right;
            }

        }
        return false;
    }

    Node* deleteNode(Node* root, int val){
        if(root == NULL) return root;
        if(root->data > val){
            root->left = deleteNode(root->left, val);
        }
        else if (root->data < val){
            root->right = deleteNode(root->right, val);
        }
        else{
            // case 1: no child or 1 child
            if(root ->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if(root-> right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* succ = getSuccesor(root);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
        return root;
    }
// get the smallest element in the right sub tree
    Node* getSuccesor(Node* root){
        Node* curr = root->right;
        while(curr->left!=NULL){
            curr = curr ->left;
        }
        return curr;

    }
};