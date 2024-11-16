//#include <iostream>
//using namespace std;
//
//class DoublyLinkedList {
//private:
//    struct Node {
//        int value;
//        Node* next;
//        Node* prev;
//
//        Node(int val) : value(val), next(nullptr), prev(nullptr) {}
//    };
//
//    Node* head;
//    Node* tail;
//    size_t size;
//
//    Node* getNodeAt(size_t index) {
//        if (index >= size) return nullptr;
//        Node* current = head;
//        for (size_t i = 0; i < index; ++i) current = current->next;
//        return current;
//    }
//
//public:
//    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
//
//    DoublyLinkedList(initializer_list<int> values) : DoublyLinkedList() {
//        for (int value : values) append(value);
//    }
//
//    ~DoublyLinkedList() {
//        while (head) {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    void append(int value) {
//        Node* newNode = new Node(value);
//        if (!head) head = tail = newNode;
//        else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//        ++size;
//    }
//
//    int& operator[](size_t index) {
//        Node* node = getNodeAt(index);
//        if (node) return node->value;
//        if (head) return head->value; 
//    }
//
//    void deleteByValue(int value) {
//        Node* current = head;
//        while (current) {
//            if (current->value == value) {
//                Node* toDelete = current;
//                if (current->prev) current->prev->next = current->next;
//                else head = current->next;
//                if (current->next) current->next->prev = current->prev;
//                else tail = current->prev;
//                current = current->next;
//                delete toDelete;
//                --size;
//            }
//            else current = current->next;
//        }
//    }
//
//    void removeDuplicates() {
//        Node* current = head;
//        while (current) {
//            Node* runner = current->next;
//            while (runner) {
//                if (runner->value == current->value) {
//                    Node* toDelete = runner;
//                    if (runner->prev) runner->prev->next = runner->next;
//                    if (runner->next) runner->next->prev = runner->prev;
//                    if (runner == tail) tail = runner->prev;
//                    runner = runner->next;
//                    delete toDelete;
//                    --size;
//                }
//                else runner = runner->next;
//            }
//            current = current->next;
//        }
//    }
//
//    int findMin() {
//        if (!head) return 0; 
//        int minValue = head->value;
//        for (Node* current = head->next; current; current = current->next)
//            if (current->value < minValue) minValue = current->value;
//        return minValue;
//    }
//
//    int findMax() {
//        if (!head) return 0; 
//        int maxValue = head->value;
//        for (Node* current = head->next; current; current = current->next)
//            if (current->value > maxValue) maxValue = current->value;
//        return maxValue;
//    }
//};
//
//int main() {
//    DoublyLinkedList list = { 1, 2, 2, 3, 4, 5, 2 };
//
//    cout << "Value at index 2: " << list[2] << endl;
//    list[2] = 42;
//    cout << "Value at index 2 after change: " << list[2] << endl;
//
//    list.deleteByValue(2);
//    cout << "After deleting value 2, minimum value: " << list.findMin() << endl;
//
//    list.removeDuplicates();
//    cout << "After removing duplicates, maximum value: " << list.findMax() << endl;
//
//}
