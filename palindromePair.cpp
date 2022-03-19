class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }
     bool isPal(string str){
        int i =0;
        int j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
bool search(TrieNode *node,string str){
        if(str.size() == 0){
           // if(node->isTerminal) return true;
           return true; 
        }
        bool isLast = true;
        for(int i =0;i<26;i++){
         if(node->children[i]){
             isLast = false;
             break;
         }
        }
    if(isLast){
        return isPal(str);
    }
        int index = str[0]-'a';
        TrieNode *child;
        if(node->children[index]!=NULL){
            child = node->children[index];
        }else{
            return false;
        }
        return search(child,str.substr(1));
    }
    /*..................... Palindrome Pair................... */
   

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        //insert element
        for(int i =0; i<words.size();i++){
            add(words[i]);
        }
        for(int i =0; i<words.size();i++){
           string str = words[i];
           if(isPal(str)) return true; 
           reverse(str.begin(), str.end()); 
           if(search(root,str)) return true; 
        }
        return false;
    }
};