// public:
//     class Node{
//         Node* prev;
//         Node* next;
//         int val;
//         Node(int val1){
//             prev= NULL;
//             next = NULL;
//             val = val1;
//         }
//     };
    
class LRUCache {
public:
    class Node{
        public:
        Node* prev;
        Node* next;
        int val;
        int key;
        Node(int key1,int val1){
            prev= NULL;
            next = NULL;
            val = val1;
            key = key1;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    int size;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        head->next= tail;
        tail->prev = head;
        // head->prev = NULL;
        // tail->next = NULL;
        size=0;
        cap= capacity;
    }
    void insertAfterHead(Node* node){
        Node* first = head->next;
        head->next = node;
        node->next = first;
        first->prev = node;
        node->prev=head;
    }
    void deleteNode(Node* node){
        Node* first = node->prev;
        Node* second = node->next;
        first->next = second;
        second->prev=first;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node = mp[key]; 
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->val = value; 
            deleteNode(node);
            insertAfterHead(node);
            return;
        }
        else{
            Node* node = new Node(key,value);
            if(size==cap){
                Node* lastNode= tail->prev;
                deleteNode(lastNode);
                mp.erase(lastNode->key);
                size--;
            }
            insertAfterHead(node);
            mp[key]=node;
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */