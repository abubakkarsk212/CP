#include<stack>
int countNodes(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}
//TC O(N) and SC O(H)
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    if(root == NULL) return;
    stack<BinaryTreeNode<int>*> inorderStack;
    stack<BinaryTreeNode<int>*> revinorderStack;
    int n1 = 0;
    BinaryTreeNode<int> *leftN = root;
    BinaryTreeNode<int> *rightN = root;
    while(leftN){
        inorderStack.push(leftN);
        leftN = leftN->left;
    }
     while(rightN){
        revinorderStack.push(rightN);
        rightN = rightN->right;
    }
    int totalNodes = countNodes(root);
    while(n1<totalNodes-1){
          BinaryTreeNode<int> *inord = inorderStack.top();
          BinaryTreeNode<int> *revinord = revinorderStack.top();
        if(inord->data+revinord->data == s){
            BinaryTreeNode<int> *top = inord;
            inorderStack.pop();
             n1++;
            cout<<inord->data<<" ";
           if(top->right!=NULL){
              top = top->right;
               while(top){
               inorderStack.push(top); 
               top = top->left;
                   
           } 
           } 
          
            cout<<revinord->data<<endl;
          
           revinorderStack.pop();
            n1++;
           if(revinord->left!=NULL){
              revinord = revinord->left;
                while(revinord){
               revinorderStack.push(revinord); 
                revinord = revinord->right;
           } 
           } 
          
        }else if(inord->data+revinord->data > s){
            revinorderStack.pop();
            n1++;
           if(revinord->left!=NULL){
              revinord = revinord->left;
                 while(revinord){
               revinorderStack.push(revinord);
               revinord = revinord->right;
               
           }
           } 
         
        }else{
            inorderStack.pop();
            n1++;
           if(inord->right!=NULL){
              inord = inord->right;
               while(inord){
               inorderStack.push(inord); 
              inord = inord->left;
               
           } 
           } 
           
        }
    }
    
}
