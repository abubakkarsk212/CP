#include<climits>
class BST {
    // Define the data members
   BinaryTreeNode<int> *root;
   public:
    BST() { 
        // Implement the Constructor
        root == NULL;
    }
 private:
   
     void printHelper(BinaryTreeNode<int> *root){
        if(root == NULL) return;
        
        cout<<root->data<<":";
        if(root->left){
          cout<<"L:"<<root->left->data<<",";  
        }
        if(root->right){
          cout<<"R:"<<root->right->data;  
        }
        cout<<endl;
        printHelper(root->left);
        printHelper(root->right);
         
     }
     bool searchHelper(int data,BinaryTreeNode<int> *root){
        if(root == NULL) return false;
        
        if(root->data == data) return true;
        else if(root->data > data) return searchHelper(data,root->left);
        else return searchHelper(data,root->right);
         
     }
    BinaryTreeNode<int>* insertHelper(int data,BinaryTreeNode<int> *root) { 
        // Implement the insert() function 
        if(root == NULL){
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            return node;
        }
        
        if(root->data >= data){
             BinaryTreeNode<int> *left = insertHelper(data,root->left);
             root->left = left;
        }
        else{
            BinaryTreeNode<int> *node = insertHelper(data,root->right);
            root->right = node;
        }
       return root;
         
         
    }
    BinaryTreeNode<int>* removeHelper(int data,BinaryTreeNode<int> *root) { 
        // Implement the remove() function
        if(root == NULL) return root;
        if(root->data > data){
            BinaryTreeNode<int> *temp = removeHelper(data,root->left);
            root->left = temp;
        }else if(root->data < data){
            BinaryTreeNode<int> *temp = removeHelper(data,root->right);
            root->right = temp;
        }
        
        if(root->data == data){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }else if(!root->left){
                //delete(root->right) don't do this as it will delete whole right
                BinaryTreeNode<int> *right = root->right;
                root->right = NULL;
                delete root;
                return right;
            }else if(!root->right){
                BinaryTreeNode<int> *left = root->left;
                root->left = NULL;
                delete root;
                return left;
            }
            else{
                BinaryTreeNode<int> *temp = root->right;
                while(temp->left!=NULL){
                    temp = temp->left;
                }
                int minV = temp->data;
                root->data = minV;
                BinaryTreeNode<int> *t = removeHelper(minV,root->right);
                root->right = t;
                return root;
            }
        }
        
    }
    
	/*----------------- Public Functions of BST -----------------*/
 public:
    void remove(int data) { 
        // Implement the remove() function 
        this->root = removeHelper(data,root);
    }

   
    void print() { 
        // Implement the print() function
       printHelper(root);
        
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root = insertHelper(data,root);
    }

    bool search(int data) {
		// Implement the search() function 
        return searchHelper(data,root);
    }
};
