#ifndef HVECTOR_H
#define HVECTOR_H

#include <stdexcept>
using namespace std;
template<typename T>
class HVector
{
private:
    T *data;       // Pointer to the array holding elements
    int capacity;  // Current allocated size
    int size;      // Number of elements in the vector
    void resize(); // Resize the vector when capacity is reached

public:
    HVector(); // Constructor
    HVector(int initialCapacity, const T &initialValue);
    ~HVector(); // Destructor

    void push_back(const T &value);
    void pop_back();
    T &operator[](int index);
    const T &operator[](int index) const;
    T &front(); // Access the first element
    const T &front() const;
    T &back(); // Access the last element
    const T &back() const;
    int getSize() const;
    bool empty() const;
};

// Implementation of HVector template methods

template<typename T>
HVector<T>::HVector()
    : data(nullptr)
    , capacity(0)
    , size(0)
{}

template<typename T>
HVector<T>::HVector(int initialCapacity, const T &initialValue)
    : capacity(initialCapacity)
    , size(initialCapacity)
{
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = initialValue;
    }
}

template<typename T>
HVector<T>::~HVector()
{
    delete[] data;
}

template<typename T>
void HVector<T>::push_back(const T &value)
{
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

template<typename T>
void HVector<T>::pop_back()
{
    if (size == 0)
        throw out_of_range("HVector is empty. Cannot pop.");
    size--;
}

template<typename T>
T &HVector<T>::operator[](int index)
{
    if (index < 0 && index >= size)
        throw out_of_range("Index out of bounds.");
    return data[index];
}

template<typename T>
const T &HVector<T>::operator[](int index) const
{
    if (index < 0 && index >= size)
        throw out_of_range("Index out of bounds.");
    return data[index];
}

template<typename T>
T &HVector<T>::front()
{
    if (empty())
        throw out_of_range("HVector is empty. Cannot access front.");
    return data[0];
}

template<typename T>
const T &HVector<T>::front() const
{
    if (empty())
        throw out_of_range("HVector is empty. Cannot access front.");
    return data[0];
}

template<typename T>
T &HVector<T>::back()
{
    if (empty())
        throw out_of_range("HVector is empty. Cannot access back.");
    return data[size - 1];
}

template<typename T>
const T &HVector<T>::back() const
{
    if (empty())
        throw out_of_range("HVector is empty. Cannot access back.");
    return data[size - 1];
}

template<typename T>
int HVector<T>::getSize() const
{
    return size;
}

template<typename T>
bool HVector<T>::empty() const
{
    return size == 0;
}

template<typename T>
void HVector<T>::resize()
{
    capacity = (capacity == 0) ? 1 : capacity * 2;
    T *newData = new T[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

#endif // HVECTOR_H
