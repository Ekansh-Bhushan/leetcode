class Node{
    public:
    int key,value;
    Node* next;
    Node* prev;
        Node(){
            key = -1;
            value = -1;
            next = NULL;
            prev = NULL;
        }

        Node(int key, int value){
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
        void insertAfterNode(Node* node,Node* head){
            Node* temp = head->next;
            head->next = node;
            node->next = temp;
            node->prev = head;
            temp->prev = node;
        }
        void deleteNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev= prevNode;
        }
};

class LRUCache {
public:
    map<int,Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        mpp.clear();
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        node->deleteNode(node);
        node->insertAfterNode(node,head);
        return node->value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->value = value; 
            node->deleteNode(node);
            node->insertAfterNode(node,head);
            return;
        } else if(capacity == mpp.size()) {
             Node* nodeToBedeleted = tail->prev;
            nodeToBedeleted->deleteNode(nodeToBedeleted);
            mpp.erase(nodeToBedeleted->key);
        }


            Node* node = new Node(key,value);
            mpp[key] = node;
            node->insertAfterNode(node,head);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */