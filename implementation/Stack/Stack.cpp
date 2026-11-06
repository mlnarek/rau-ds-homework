#include "Stack.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Stack<T>::Stack() {
    _data = nullptr;
    _capacity = 0;
    _size = 0;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] _data;
}

template <typename T>
Stack<T>::Stack(const Stack& other) {
    _capacity = other._capacity;
    _size = other._size;
    _data = new T[_capacity];
    for (int i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        delete[] _data;
        _capacity = other._capacity;
        _size = other._size;
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::expand() {
    int new_cap = (_capacity == 0) ? 1 : _capacity * 2;
    T* new_data = new T[new_cap];
    for (int i = 0; i < _size; i++) {
        new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _capacity = new_cap;
}

template <typename T>
void Stack<T>::push(const T& x) {
    if (_size == _capacity) {
        expand();
    }
    _data[_size] = x;
    _size++;
}

template <typename T>
void Stack<T>::pop() {
    if (_size > 0) {
        _size--;
    }
}

template <typename T>
T& Stack<T>::top() {
    if (_size == 0) throw std::out_of_range("Stack is empty");
    return _data[_size - 1];
}

template <typename T>
const T& Stack<T>::top() const {
    if (_size == 0) throw std::out_of_range("Stack is empty");
    return _data[_size - 1];
}

template <typename T>
int Stack<T>::size() const {
    return _size;
}

template <typename T>
int Stack<T>::capacity() const {
    return _capacity;
}

template <typename T>
bool Stack<T>::is_empty() const {
    return _size == 0;
}

template <typename T>
void Stack<T>::clear() {
    _size = 0;
}

template <typename T>
T& Stack<T>::peek() {
    return top();
}

template <typename T>
const T& Stack<T>::peek() const {
    return top();
}

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    std::cout << "Top: " << s.top() << "\n"; // 30
    s.pop();
    std::cout << "Top after pop: " << s.top() << "\n"; // 20
    std::cout << "Size: " << s.size() << "\n";
    std::cout << "Stack passed\n";
    return 0;
}
