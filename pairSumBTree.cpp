#include<climits>
#include <bits/stdc++.h>
bool isNode(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root == NULL) return false;
    
    if(root->data == sum){
        root->data = INT_MIN;
        return true;
    }
    bool left = isNode(root->left,sum);
    bool right = isNode(root->right,sum);
    return left || right;
}
//best approach
void traversePreOrder(vector<int> *a,BinaryTreeNode<int> *root){
    if(root == NULL) return;
    a->push_back(root->data);
    traversePreOrder(a,root->left);
    traversePreOrder(a,root->right);
    
}
void sumPairBetter(BinaryTreeNode<int> *root, int sum){
    vector<int> *arr = new vector<int>();
    traversePreOrder(arr,root);
    sort(arr->begin(),arr->end());
    int i =0, j = arr->size()-1;
    while(i<j){
        if(arr->at(i)+arr->at(j) == sum){
            if(arr->at(i) < arr->at(j)) cout<<arr->at(i)<<" "<<arr->at(j)<<endl;
            else cout<<arr->at(i)<<" "<<arr->at(j)<<endl;
            i++;
            j--;
        }else if(arr->at(i)+arr->at(j) < sum){
            i++;
        }else{
            j--;
        }
    }
}

//O(N2) approach
void pairSum(BinaryTreeNode<int> *curr,BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(curr == NULL) return;
    
    if(sum-curr->data !=curr->data &&curr->data!=INT_MIN && isNode(root,sum-curr->data)){
        
        if((sum-(curr->data)) > curr->data){
            cout<< curr->data<<" "<<sum-(curr->data)<<endl;
        }else{
            cout<<sum-(curr->data)<<" "<< curr->data<<endl;
            
        }
    }
    pairSum(curr->left,root,sum);
    pairSum(curr->right,root,sum);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    // pairSum(root,root,sum);
    sumPairBetter(root,sum);
}
