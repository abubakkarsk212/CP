void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,vector<int> &v) {
    // Write your code here
    if(root == NULL) return;
    
    k -=root->data;
   
    v.push_back(root->data);
     //if the root node is K if leaf node
    if(root->left == NULL && root->right == NULL && k==0){
      for(int i =0; i<v.size();i++){
          cout<<v[i]<<" ";
      }
        cout<<endl;
        v.pop_back();
        return;
    }
    //otherwise call in left and right subtree include root which will print the nodes and lastly pop root
    rootToLeafPathsSumToK(root->left,k,v);
    rootToLeafPathsSumToK(root->right,k,v);
    v.pop_back();    
}
//method 1
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k,string str) {
    // Write your code here
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL && root->data == k){
        cout << str<<" "<<root->data<<endl;
        return;
    }
    if(str == ""){
        str =to_string(root->data); 
    }else{
        str = str+" "+to_string(root->data);
    }
    rootToLeafPathsSumToK(root->left,k-root->data,str);
    rootToLeafPathsSumToK(root->right,k-root->data,str);
    
    
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
   // rootToLeafPathsSumToK(root,k,"");
    vector<int> v;
    rootToLeafPathsSumToK(root,k,v);
}
