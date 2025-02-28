class LRUCache {
public:
    class Node{
        public:
            int val;
            int key;
            Node* prev;
            Node* next;
            Node(int key,int val){
                this->key=key;
                this->val=val;
            }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mpp;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* newNode){
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node* newNode){
        Node* prevNode=newNode->prev;
        Node* nextNode=newNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* resNode=mpp[key];
            int ans=resNode->val;
            mpp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mpp[key]=head->next;
            return ans;
        }
return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* curr=mpp[key];
            mpp.erase(key);
            deleteNode(curr);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */