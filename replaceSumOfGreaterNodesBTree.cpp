int sumNodes(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;
    int sl = sumNodes(root->left);
    int sr = sumNodes(root->right);
    return sl+sr+root->data;
    
}
//method 2 O(N) and O(H) space
int previousSumWithReplace(BinaryTreeNode<int> *root,int sumGTC){
    // Write your code here
    if(root == NULL) return 0;
    //For root
    int sR = previousSumWithReplace(root->right,sumGTC);
    int originalRootValue = root->data;
    root->data = root->data+sR+sumGTC;
    int sL = previousSumWithReplace(root->left,root->data);
    return originalRootValue+sR+sL;
    

}
//method 1 by sorting T.c O(N) and space O(N)
void inorderVector(BinaryTreeNode<int> *root,vector<BinaryTreeNode<int>*> &v){
    if(root == NULL) return;
    inorderVector(root->left,v);
    v.push_back(root);
    inorderVector(root->right,v);
}
void replaceWithLargerNodesSorted(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL) return;
    //Firsst traverse inorder and add to vctor
    vector<BinaryTreeNode<int>*> sortedNodes;
    inorderVector(root,sortedNodes);
    int totalSum = sumNodes(root);
    for(int i =0; i<sortedNodes.size();i++){
        int cValue = sortedNodes[i]->data;
        sortedNodes[i]->data = totalSum;
        totalSum-=cValue;
    }
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    // replaceWithLargerNodesSorted(root);
    previousSumWithReplace(root,0);
}
