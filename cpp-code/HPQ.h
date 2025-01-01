#ifndef HPQ_H
#define HPQ_H

#include "HVector.h"
#include <functional>
#include <stdexcept>

using namespace std;

template<typename T, typename Compare = less<T>>
class HPQ
{
private:
    HVector<T> heap; // Use HVector as the underlying container
    Compare comp;    // Comparison object to determine priority

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    HPQ(); // Default constructor
    explicit HPQ(const Compare &compare);

    void push(const T &value);
    void pop();
    T &top();
    const T &top() const;
    bool empty() const;
    int size() const;
};

// Implementation of member functions

template<typename T, typename Compare>
HPQ<T, Compare>::HPQ()
    : comp(Compare())
{}

template<typename T, typename Compare>
HPQ<T, Compare>::HPQ(const Compare &compare)
    : comp(compare)
{}

template<typename T, typename Compare>
void HPQ<T, Compare>::push(const T &value)
{
    heap.push_back(value);
    heapifyUp(heap.getSize() - 1);
}

template<typename T, typename Compare>
void HPQ<T, Compare>::pop()
{
    if (empty())
        throw out_of_range("HPQ is empty. Cannot pop.");
    heap[0] = heap[heap.getSize() - 1];
    heap.pop_back();
    heapifyDown(0);
}

template<typename T, typename Compare>
T &HPQ<T, Compare>::top()
{
    if (empty())
        throw out_of_range("HPQ is empty. Cannot access top.");
    return heap[0];
}

template<typename T, typename Compare>
const T &HPQ<T, Compare>::top() const
{
    if (empty())
        throw out_of_range("HPQ is empty. Cannot access top.");
    return heap[0];
}

template<typename T, typename Compare>
bool HPQ<T, Compare>::empty() const
{
    return heap.getSize() == 0;
}

template<typename T, typename Compare>
int HPQ<T, Compare>::size() const
{
    return heap.getSize();
}

template<typename T, typename Compare>
void HPQ<T, Compare>::heapifyUp(int index)
{
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (comp(heap[parent], heap[index])) {
            swap(heap[parent], heap[index]);
            index = parent;
        } else
            break;
    }
}

template<typename T, typename Compare>
void HPQ<T, Compare>::heapifyDown(int index)
{
    int leftChild, rightChild, largest;
    while (true) {
        leftChild = 2 * index + 1;
        rightChild = 2 * index + 2;
        largest = index;

        if (leftChild < heap.getSize() && comp(heap[largest], heap[leftChild]))
            largest = leftChild;
        if (rightChild < heap.getSize() && comp(heap[largest], heap[rightChild]))
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else
            break;
    }
}

#endif // HPQ_H
