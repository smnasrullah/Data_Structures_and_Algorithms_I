#include<iostream>
#include<vector>

using namespace std;
class Tree{
  public: 
  struct Node{
   int data;
   Node *left;
   Node *right;
  


  };

  Node *root;
  Tree(){
    root=nullptr;
  }

  Node *createNode(int value){
  Node *newNode=new Node();
  newNode->data=value;
  newNode->left=nullptr;
  newNode->right=nullptr;

  return newNode;


  }
int search(vector<int>&inorder,int left,int right,int val){

    for(int i=left;i<=right;i++){

        if(inorder[i]==val)
          return i;
    }
    return -1;
}



Node *helper(vector<int>&preorder,vector<int>&inorder,int &preIdx,int left, int right){

if(left>right){
    return nullptr;
}
    Node *root=createNode(preorder[preIdx]);
    int inIdx=search(inorder,left,right,preorder[preIdx]);
    preIdx++;
    root->left=helper(preorder,inorder,preIdx,left,inIdx-1);
    root->right=helper(preorder,inorder,preIdx,inIdx+1,right);
    return root;
}

  void buildTree(vector<int>&preorder,vector<int>&inorder){

    int preIdx=0;
    root=helper(preorder,inorder,preIdx,0,inorder.size()-1);
  }

  void displayPre(Node *node){
   if(node==nullptr)
   return;

   cout<<node->data<<" ";
   displayPre(node->left);
   displayPre(node->right);



  }


};


int main(){
  Tree t;
  vector<int>inorder={4,2,5,1,6,3,7};
  vector<int>preorder={1,2,4,5,3,6,7};
  t.buildTree(preorder,inorder);

  t.displayPre(t.root);
  cout<<endl;

    return 0;
}