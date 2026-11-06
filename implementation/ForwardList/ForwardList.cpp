#include "ForwardList.h"
#include <iostream>

template <typename T>
ForwardList<T>::ForwardList() : _head(nullptr), _size(0) {}

template <typename T>
ForwardList<T>::~ForwardList() {
    clear();
}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
    if (other._head) {
        _head = new Node(other._head->data);
        Node* current = _head;
        Node* other_current = other._head->next;
        while (other_current) {
            current->next = new Node(other_current->data);
            current = current->next;
            other_current = other_current->next;
        }
        _size = other._size;
    }
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& other) {
    if (this != &other) {
        clear();
        if (other._head) {
            _head = new Node(other._head->data);
            Node* current = _head;
            Node* other_current = other._head->next;
            while (other_current) {
                current->next = new Node(other_current->data);
                current = current->next;
                other_current = other_current->next;
            }
            _size = other._size;
        }
    }
    return *this;
}

template <typename T>
void ForwardList<T>::push_front(const T& x) {
    Node* new_node = new Node(x);
    new_node->next = _head;
    _head = new_node;
    _size++;
}

template <typename T>
void ForwardList<T>::pop_front() {
    if (_head) {
        Node* temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
    }
}

template <typename T>
T& ForwardList<T>::front() { return _head->data; }
template <typename T>
const T& ForwardList<T>::front() const { return _head->data; }

template <typename T>
void ForwardList<T>::insert_after(Node* node, const T& value) {
    if (!node) return;
    Node* new_node = new Node(value);
    new_node->next = node->next;
    node->next = new_node;
    _size++;
}

template <typename T>
void ForwardList<T>::erase_after(Node* node) {
    if (!node || !node->next) return;
    Node* temp = node->next;
    node->next = temp->next;
    delete temp;
    _size--;
}

template <typename T>
void ForwardList<T>::clear() {
    while (_head) {
        pop_front();
    }
}

template <typename T>
void ForwardList<T>::reverse() {
    Node* prev = nullptr;
    Node* current = _head;
    Node* next = nullptr;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    _head = prev;
}

template <typename T>
int ForwardList<T>::size() const { return _size; }

template <typename T>
bool ForwardList<T>::empty() const { return _size == 0; }

template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin() { return _head; }
template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::begin() const { return _head; }

int main() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    std::cout << "Size: " << list.size() << "\n";
    
    list.reverse();
    std::cout << "Front after reverse: " << list.front() << "\n";

    ForwardList<int> list2 = list;
    list2.push_front(5);
    std::cout << "list2 size: " << list2.size() << "\n";

    std::cout << "ForwardList passed\n";
    return 0;
}
