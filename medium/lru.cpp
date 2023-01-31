#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> store;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1); // This one is used to avoid uncessary checks of NULL pointers.
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head->next = tail;
        this->tail->prev = head;
    }

    /**Helper function**/

    void deleteNode(Node* delete_node) {
        Node* prev_node = delete_node->prev;
        Node* next_node = delete_node->next;

        prev_node->next = next_node;
        next_node->prev = prev_node;
    }

    void addNode(Node* new_node) {
        Node* temp_node = this->head->next;
        new_node->next = temp_node;
        new_node->prev = this->head;

        this->head->next = new_node;
        temp_node->prev = new_node;
    }
    
    int get(int key) {
        // if it will not be able to find then it will point to last iterator
        if(store.find(key) != store.end()) {
            Node* temp_node = store[key];
            int new_node_val = temp_node->val;

            deleteNode(temp_node);
            addNode(new Node(key, new_node_val));
            store.erase(key);
            store[key] = this->head->next;
            return new_node_val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // if key does exist then then take that and delete from store
        if(store.find(key) != store.end()) {
            Node* temp_node = store[key];
            deleteNode(temp_node);
            addNode(new Node(key, value));
            store[key] = this->head->next;
        } else {
            if(store.size() >= this->capacity) {
                Node* temp_node = this->tail->prev; // take prev node of tail
                store.erase(temp_node->key); // delete through key
                deleteNode(temp_node); // and delete them;
                addNode(new Node(key, value));
                store[key] = this->head->next;
            } else {
                addNode(new Node(key, value));
                store[key] = this->head->next;
            }
        }
    }
};

int main() {
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    cout << lRUCache->get(1) << endl;    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout << lRUCache->get(2) << endl;    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache->get(1) << endl;    // return -1 (not found)
    cout << lRUCache->get(3) << endl;    // return 3
    cout << lRUCache->get(4) << endl;    // return 4
}