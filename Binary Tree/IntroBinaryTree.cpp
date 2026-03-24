#include<iostream>
#include<vector>
#include<queue>
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
static int idx = -1;
Node* buildTree(vector<int> preorder ){
    idx++;
    if(preorder[idx]== -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    
    return root;

}

//preorder traversal
void preOrder(Node* root){
    if( root == NULL) return;
    cout<<root->data<<endl;
    preOrder(root->left);
    preOrder(root->right);
}

//inorder traversal
void inOrder(Node* root){
    if (root == NULL) return;
    inOrder(root->left);
    cout<< root->data<<endl;
    inOrder(root->right);
}

//postorder traversal
void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<< endl;
}


//level order
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){

        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }

        cout<<curr->data<< " ";
        if (curr->left != NULL){
            q.push(curr->left);
        }
        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

// Height of tree
int height(Node* root){
    if(root == NULL) return 0;
    int leftht = height(root -> left);
    int rightht = height(root -> right);
    return max(leftht, rightht)+1; 
}

// Count Nodes 
int countNode(Node* root){
    if (root == NULL){
        return 0;
    }
    int countLeft = countNode(root->left);
    int countRight = countNode(root->right);
    return countLeft + countRight + 1;
}

// sum of nodes 
int sumOfNodes(Node* root){
    if(root == NULL) return 0;
    int leftsum = sumOfNodes(root-> left);
    int rightsum = sumOfNodes(root-> right);
    return leftsum + rightsum + root->data;
}

// identical binary trees
bool isIdentical(Node* p, Node* q){
    if(p==NULL || q == NULL){
        return p == q;
    }
    bool isLeftsame= isIdentical(p->left, q->left);
    bool isRightsame = isIdentical(p->right, q->right);
    return isLeftsame && isRightsame && (p->data == q-> data);
}

// subtree of another tree 
bool isSubtree(Node* root, Node* subroot){
    if(subroot == NULL) return true;
    if(root == NULL) return false;
    if(root->data == subroot->data && isIdentical(root, subroot)){
        return true;
    }
    return (isSubtree(root->left, subroot) || isSubtree(root->right, subroot));
}

int main(){
    vector<int> p = {1 ,2 ,-1 ,-1 , 3 , 4, -1, -1, 5, -1, -1};
    vector<int> q = {3 , 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node* root1 = buildTree(p);
    idx = -1;
    Node* root2 = buildTree(q);
    levelOrder(root1);
    levelOrder(root2);
    cout<<"Height of the binary tree= " <<height(root1)<<endl;
    cout<<"Total number of nodes = "<<countNode(root1)<<endl;
    cout<<"Sum of nodes = "<< sumOfNodes(root1)<< endl;
    cout<<"Is the p and q trees are identical ? "<<boolalpha<< isIdentical(root1, root2)<<endl;
    cout<< "is the p is a subtree of q ?"<< boolalpha << isSubtree(root1, root2);

    return 0;
}
