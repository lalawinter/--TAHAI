class Node {
public:
    int key, value;
    Node* prev;
    Node* next;
    Node (int k, int v) {
        key = k;
        value = v;
    }
}

class doubleList {
public:
    Node* head = new Node(0, 0);
    Node* tail = new Node(0, 0);
    int size;
    doubleList() {
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void remove(Node* x) {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    void addLast(Node* x) {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    void removeFirst() {
        if(head->next == tail) {
            return;
        }
        Node* first = head->next;
        remove(first);
        return first;
    }

    int Size() {
        return size;
    }
}

class LRUcache {
public:
    unordered_map<int, Node*> imap;
    doubleList* cache = new doubleList();
    int cap;
    LRUcache(int capacity) {
        cap = capacity;
    }

    void makeRecently(int key) {
        Node* x = imap[key];
        cache->remove(x);
        cache->addLast(x);
    }

    void addRecently(int key, int value) {
        Node* x = new Node(key, value);
        cache->addLast(x);
        imap.emplace(key, value);
    }

    void removeLeastRecently() {
        Node* deleteNode = cache->removeFirst();
        int key = deleteNode->key;
        imap.erase(key);
    }

    void deleteKey(int key) {
        Node* x = imap[key];
        cache->remove(x);
        imap.erase(key);
    }

    int get(int key) {
        if(!imap.count(key)) {
            return -1
        }
        makeRecently(key);
        return imap[key]->value;
    }

    void put(int key, int value) {
        if(imap.count(key)) {
            deleteKey(key);
            addRecently(key, value);
            return;
        }
        if(cap == cache->Size()) {
            removeLeastRecently();
        }
        addRecently(key,value);
    }
}