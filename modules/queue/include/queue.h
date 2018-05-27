// Copyright 2018 Roman Kudalin

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <cstddef>
#include <algorithm>
#include <stdexcept>

template <typename Ty>
class Queue {
 public:
    explicit Queue(std::size_t size = 0);
    Queue(const Queue<Ty>& rhs);
    ~Queue();

    Ty& front();
    const Ty& front() const;
    Ty& back();
    const Ty& back() const;
    bool empty() const;
    std::size_t size() const;
    void push(const Ty& data);
    void pop();
    void swap(Queue<Ty>& other);

    Queue<Ty>& operator=(Queue<Ty> rhs);
    bool operator==(const Queue<Ty>& rhs) const;
    bool operator!=(const Queue<Ty>& rhs) const;

 private:
    Ty* mem;
    std::size_t dataCount;
    std::size_t capacity;
    int head;
    int tail;
    int nextIndex(int oldIndex) const;
    void resize();
};


// ----------IMPLEMENTATION----------

// ----------PUBLIC METHODS----------

template <typename Ty>
Queue<Ty>::Queue(std::size_t size) : dataCount(0), capacity(size),
head(0), tail(-1) {
    capacity ? mem = new Ty[capacity]() : mem = nullptr;
}

template <typename Ty>
Queue<Ty>::Queue(const Queue<Ty>& rhs) : dataCount(rhs.dataCount),
capacity(rhs.capacity), head(rhs.head), tail(rhs.tail) {
    capacity ? mem = new Ty[capacity]() : mem = nullptr;
    std::copy(rhs.mem, rhs.mem + rhs.dataCount, mem);
}

template <typename Ty>
Queue<Ty>::~Queue() {
    delete[] mem;
}

template <typename Ty>
Ty& Queue<Ty>::front() {
    if (empty())
        throw std::runtime_error("Queue is empty");
    return mem[head];
}

template <typename Ty>
const Ty& Queue<Ty>::front() const {
    if (empty())
        throw std::runtime_error("Queue is empty");
    return mem[head];
}

template <typename Ty>
Ty& Queue<Ty>::back() {
    if (empty())
        throw std::runtime_error("Queue is empty");
    return mem[tail];
}

template <typename Ty>
const Ty& Queue<Ty>::back() const {
    if (empty())
        throw std::runtime_error("Queue is empty");
    return mem[tail];
}

template <typename Ty>
bool Queue<Ty>::empty() const { return dataCount == 0; }

template <typename Ty>
std::size_t Queue<Ty>::size() const { return dataCount; }

template <typename Ty>
void Queue<Ty>::push(const Ty& data) {
    if (dataCount == capacity)
        resize();
    tail = nextIndex(tail);
    mem[tail] = data;
    dataCount++;
}

template <typename Ty>
void Queue<Ty>::pop() {
    if (empty())
        throw std::runtime_error("Queue is empty");
    mem[head].~Ty();
    dataCount--;
    head = nextIndex(head);
}

template <typename Ty>
void Queue<Ty>::swap(Queue<Ty>& other) {
    using std::swap;
    swap(dataCount, other.dataCount);
    swap(capacity, other.capacity);
    swap(head, other.head);
    swap(tail, other.tail);
    swap(mem, other.mem);
}

template <typename Ty>
Queue<Ty>& Queue<Ty>::operator=(Queue<Ty> rhs) {
    swap(rhs);
    return *this;
}

template <typename Ty>
bool Queue<Ty>::operator==(const Queue<Ty>& rhs) const {
    if (size() != rhs.size() || empty() || rhs.empty())
        return false;
    int lhsCurPos = head;
    int rhsCurPos = rhs.head;
    while (true) {
        if (lhsCurPos == this->tail || rhsCurPos == rhs.tail)
            break;
        if (mem[lhsCurPos] != rhs.mem[rhsCurPos])
            return false;
        lhsCurPos = nextIndex(lhsCurPos);
        rhsCurPos = nextIndex(rhsCurPos);
    }
    return back() == rhs.back();
}

template <typename Ty>
bool Queue<Ty>::operator!=(const Queue<Ty>& rhs) const {
    return !(*this == rhs);
}

// ----------------------------------

// ----------PRIVATE METHODS----------

template <typename Ty>
int Queue<Ty>::nextIndex(int oldIndex) const {
    return (oldIndex + 1) % capacity;
}

template <typename Ty>
void Queue<Ty>::resize() {
    auto newCap = capacity > 0 ? capacity * 2 : 2;
    Ty* tmp = new Ty[newCap]();
    std::copy(mem + head, mem + dataCount, tmp);
    if (tail < head)
        std::copy(mem, mem + (tail + 1), tmp + (dataCount - head));
    head = 0;
    tail = dataCount - 1;

    delete[] mem;
    mem = tmp;
    capacity = newCap;
}

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_

