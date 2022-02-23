class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    TrieNode *find(TrieNode *node,string pattern){
        if(pattern.size() == 0){
            return node;
        }
        int index = pattern[0]-'a';
        if(node->children[index]!=NULL){
            return find(node->children[index],pattern.substr(1));
        }else{
            return NULL;
        }
    }
    void printAllPairs(TrieNode *node,string pattern,string op){
        bool isLast = true;
        for(int i =0;i<26;i++){
            if(node->children[i]!=0){
                isLast = false;
                break;
            }
        }
        if(isLast){
         return;
        }
        //traversing all child
        for(int i =0; i<26;i++){
            if(node->children[i]!=NULL){
                string temp;
                temp = op+node->children[i]->data;
                if(node->children[i]->isTerminal){
                    cout<<pattern+temp<<endl;
                }
                printAllPairs(node->children[i],pattern,temp);
            }
        }
    }
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i =0; i<input.size();i++){
            insertWord(input[i]);
        }
        TrieNode *currNode =find(root,pattern); 
        if(currNode){
            
            if(currNode->isTerminal){
                cout<<pattern<<endl;
            }
            string str;
           printAllPairs(currNode,pattern,str); 
        }
    }
};
