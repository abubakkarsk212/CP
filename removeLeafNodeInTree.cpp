// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
#include<queue>
TreeNode<int>* removeLeafNodesCorrect(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return NULL;
    if(root->numChildren()==0){
        return NULL;
    }
   vector<int> v;
    for(int i =0; i<root->numChildren();){
        if(root->getChild(i)->numChildren() == 0){
            // root->removeChild(i);
            // v.push_back(i);
            root->removeChild(i);
        }else{
            TreeNode<int> *child = removeLeafNodesCorrect(root->getChild(i));
           root->setChild(i,child);
            i++;
        }
    }
    //  for(int i =v.size()-1; i>=0;i--){
    //     int index = v[i];
    //      root->removeChild(index);
    // }
    
    return root;
}
TreeNode<int>* removeLeafNodesH(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL) return NULL;
    if(root->numChildren()==0){
        return NULL;
    }
 
    queue<TreeNode<int>*> q1;
    q1.push(root);
    while(!q1.empty()){
        TreeNode<int>* t = q1.front();
        
        q1.pop();
      
        for(int i =0; i<t->numChildren();i++){
           
            if(t->getChild(i)->numChildren() == 0){
                t->removeChild(i);
            
                
              }else
                q1.push(t->getChild(i));
            
        }
    }
    return root;
}
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    // Write your code here
return removeLeafNodesCorrect(root);
// return removeLeafNodesH(root);
    
}
