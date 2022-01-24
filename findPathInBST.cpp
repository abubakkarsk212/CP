vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL) return NULL;
    
    if(root->data == data){
        vector<int> *res = new vector<int>();
        res->push_back(root->data);
        return res;
    }
    if(root->data > data){
        vector<int> *left = getPath(root->left,data);
        if(left){
            left->push_back(root->data);
            return left;
        }
    }else{
       vector<int> *right = getPath(root->right,data);
        if(right){
            right->push_back(root->data);
            return right;
        } else{
            return NULL;
        }
    }
}
