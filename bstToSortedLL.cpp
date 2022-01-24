pair<Node<int>*,Node<int>*> constructLinkedListImproved(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<Node<int>*,Node<int>*> temp;
        //Here first is head and second is tail
        temp.first = NULL;
        temp.second = NULL;
        return temp;
    }
    Node<int> *midNode = new Node<int>(root->data);
    pair<Node<int>*,Node<int>*> left = constructLinkedListImproved(root->left);
    pair<Node<int>*,Node<int>*> right = constructLinkedListImproved(root->right);
    if(left.second)
     left.second->next = midNode;
    midNode->next = right.first;
    
    pair<Node<int>*,Node<int>*> res;
    if(left.second)
     res.first = left.first;
    else
     res.first = midNode; 
    if(right.second)
     res.second = right.second;
    else
     res.second = midNode;   
    
    return res;
    
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
//     if(root==NULL) return NULL;
//     if(!root->left && !root->right){
//     Node<int> *midNode = new Node<int>(root->data);
//         return midNode;
//     } 
    
//     Node<int> *midNode = new Node<int>(root->data);
    
//     Node<int> *headL = constructLinkedList(root->left);
//     Node<int> *headR = constructLinkedList(root->right);

//     if(headL){
//      Node<int> *temp= headL;
//     while(temp->next){
//         temp = temp->next;
//     }
//     temp->next = midNode; 
//     }
    
//     midNode->next = headR;
//     if(headL)
//      return headL; 
//     else
//       return midNode;
    
    return constructLinkedListImproved(root).first;
}
