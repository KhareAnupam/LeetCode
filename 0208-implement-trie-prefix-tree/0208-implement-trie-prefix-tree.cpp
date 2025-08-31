class Node{
public:
    Node* links[26];
    bool flag = false;
    bool doesExist(char c){
        return (links[c - 'a']!=NULL);
    }
    void put(char c,Node* node){
        links[c-'a'] = node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.length();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->doesExist(word[i])){
                Node* temp = new Node();
                node->put(word[i],temp);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n = word.length();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->doesExist(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return (node->flag);
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();
        Node* node = root;
        for(int i=0;i<n;i++){
            if(!node->doesExist(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */