struct Node {
    int key, value;
    Node *prev, *next;
    Node(int key, int value) {
        this->key=key;
        this->value=value;
        prev=next=nullptr;
    }
};

class LRUCache {
    Node *data[10001];
    int capacity;
    Node *head, *tail; 
public:
    
    LRUCache(int capacity) {
        for(int i=0; i<10001; i++)
            data[i]=nullptr;
        this->capacity=capacity;
        head=new Node(-1,-1); // dummy nodes
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(data[key]!=nullptr)
        {
            Node *temp=data[key];
            Node *node=new Node(temp->key,temp->value);
            node->next=head->next;
            head->next=node;
            node->prev=head;
            node->next->prev=node;
            data[key]=node;
            
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return node->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(data[key]!=nullptr)
        {
            Node *temp=data[key];
            Node *node=new Node(key,value);
            node->next=head->next;
            head->next=node;
            node->prev=head;
            node->next->prev=node;
            data[key]=node;
            
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return;
        }
        capacity--;
        if(capacity<0)
        {
            Node *node=tail->prev;
            node->prev->next=node->next;
            node->next->prev=node->prev;
            data[node->key]=nullptr;
            delete node;
            capacity=0;
        }
        Node *node=new Node(key,value);
        node->next=head->next;
        head->next=node;
        node->prev=head;
        node->next->prev=node;
        data[key]=node;
    }
};
