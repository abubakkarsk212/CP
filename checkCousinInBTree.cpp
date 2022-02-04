int depthOfNode(BinaryTreeNode<int> *root, int node){
    if(root == NULL) return -1;
    if(root->data == node) return 0;
    int left = depthOfNode(root->left,node);
    if(left!=-1){
        return left+1;
    }
    int right = depthOfNode(root->right,node);
    if(right!=-1)
     return right+1;
    
    return -1;
}
bool isSibling(BinaryTreeNode<int> *root, int p, int q){
    if(root == NULL) return false;
    
    if(root->left && root->right){
        if(root->left->data == p && root->right->data == q){
            return true;
        }
        else if(root->left->data == q && root->right->data == p){
            return true;
        }else{
            return isSibling(root->left,p,q) || isSibling(root->right,p,q);
        }
    }
    if(root->left!= NULL){
        return isSibling(root->left,p,q);
    }else{
        return isSibling(root->right,p,q);
    }
    
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    if(root == NULL) return false;

    return  depthOfNode(root,p) == depthOfNode(root,q) && !isSibling(root,p,q);
    
}
