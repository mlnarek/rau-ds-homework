#include "Vector.h"
#include <iostream>

template <typename T>
Vector<T>::Vector() : _data(nullptr), _size(0), _capacity(0) {}

template <typename T>
Vector<T>::Vector(size_t initial_size) : _data(new T[initial_size]), _size(initial_size), _capacity(initial_size) {}

template <typename T>
Vector<T>::~Vector() {
    delete[] _data;
}

template <typename T>
Vector<T>::Vector(const Vector& other) : _data(new T[other._capacity]), _size(other._size), _capacity(other._capacity) {
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _capacity = other._capacity;
        _data = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template <typename T>
void Vector<T>::_resize_capacity(size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < _size; ++i) {
        new_data[i] = _data[i];
    }
    delete[] _data;
    _data = new_data;
    _capacity = new_capacity;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (_size >= _capacity) {
        _resize_capacity(_capacity == 0 ? 1 : _capacity * 2);
    }
    _data[_size++] = value;
}

template <typename T>
void Vector<T>::pop_back() {
    if (_size > 0) {
        _size--;
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) { return _data[index]; }

template <typename T>
const T& Vector<T>::operator[](size_t index) const { return _data[index]; }

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return _data[index];
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= _size) throw std::out_of_range("Index out of range");
    return _data[index];
}

template <typename T>
T& Vector<T>::front() { return _data[0]; }

template <typename T>
const T& Vector<T>::front() const { return _data[0]; }

template <typename T>
T& Vector<T>::back() { return _data[_size - 1]; }

template <typename T>
const T& Vector<T>::back() const { return _data[_size - 1]; }

template <typename T>
size_t Vector<T>::size() const { return _size; }

template <typename T>
size_t Vector<T>::capacity() const { return _capacity; }

template <typename T>
bool Vector<T>::empty() const { return _size == 0; }

template <typename T>
void Vector<T>::reserve(size_t new_capacity) {
    if (new_capacity > _capacity) {
        _resize_capacity(new_capacity);
    }
}

template <typename T>
void Vector<T>::clear() {
    _size = 0;
}

template <typename T>
T* Vector<T>::begin() { return _data; }
template <typename T>
const T* Vector<T>::begin() const { return _data; }

template <typename T>
T* Vector<T>::end() { return _data + _size; }
template <typename T>
const T* Vector<T>::end() const { return _data + _size; }

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    std::cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
    
    Vector<int> v2 = v;
    v2.push_back(40);
    
    std::cout << "v back: " << v.back() << "\n";
    std::cout << "v2 back: " << v2.back() << "\n";
    std::cout << "Vector passed\n";
    return 0;
}
