For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
The root will remain the same. So you just need to insert nodes in the given Binary Tree.
Example:
alt txt

After making the changes to the above-depicted tree, the updated tree will look like this.
alt txt

You can see that every node in the input tree has been duplicated and inserted to the left of itself.




    // Write your code here
    if(root == NULL) return NULL;
    
    BinaryTreeNode<int> *left = insertDuplicateNodeH(root->left);
    BinaryTreeNode<int> *right = insertDuplicateNodeH(root->right);
    
    
    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(root->data);
    root->left = node;
    node->left = left;
    return root;
    
}
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    root = insertDuplicateNodeH(root);
}
