// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

#include <string>
#include <stdexcept>

template <class ValType>
class TStack {
 private:
    ValType* pMem;                      // Array for data
    int size;                           // Size of the stack
    int sp;                             // Pointer to the top of the stack
 public:
    explicit TStack(int _size = 1);     // Initializer constructor
    TStack(const TStack& S);            // Copy Constructor
    ~TStack(void);                      // Destructor

    // Access Methods
    int GetSize() { return size; }
    int GetSP() { return sp; }

    void Push(ValType var);             // Put the value on the stack
    ValType Pop(void);                  // Extract value from stack
    ValType Top(void);                  // Look at value from top of stack

    int IsEmpty(void);                  // Control of emptiness
    int IsFull(void);                   // Overflow control

    int operator == (const TStack& S);
    TStack& operator = (const TStack& S);
};

// Description of class methods

template <class ValType>
TStack<ValType>::TStack(int _size) {
    sp = 0;
    if (_size > 0)    size = _size;
    else              size = 1;

    pMem = new ValType[size];

    if (pMem == NULL)
        throw std::logic_error("Out of memory");
}

template <class ValType>
TStack<ValType>::~TStack(void) {
    delete[]pMem;
    pMem = NULL;
}

template <class ValType>
TStack<ValType>::TStack(const TStack<ValType> &S) {
    size = S.size;
    sp = S.sp;

    pMem = new ValType[size];
    if (pMem == NULL) {
        throw std::logic_error("Out of memory");
    } else {
        for (int i = 0; i < S.sp; i++)
            pMem[i] = S.pMem[i];
    }
}

template <class ValType>
void TStack<ValType>::Push(ValType var) {
    if (IsFull())
        throw std::logic_error("Stack overflow");
    else
        pMem[sp++] = var;
}

template <class ValType>
ValType TStack<ValType>::Pop(void) {
    if (IsEmpty())
        throw std::logic_error("Stack is empty");
    else
        return pMem[--sp];
}

template <class ValType>
ValType TStack<ValType>::Top(void) {
    if (IsEmpty())
        throw std::logic_error("Stack is empty");
    else
        return pMem[sp - 1];
}

template <class ValType>
int TStack<ValType>::IsEmpty(void) {
    return (sp == 0);
}

template <class ValType>
int TStack<ValType>::IsFull(void) {
    return (sp == size);
}

template <class ValType>
int TStack<ValType>::operator == (const TStack& S) {
    int res = 0, counter = 0;

    if ((size == S.size) && (sp == S.sp)) {
        for (; (counter < sp) && (pMem[counter] == S.pMem[counter]);
                counter++) {}

        if (counter == sp)
            res = 1;
    }

    return res;
}

template <class ValType>
TStack<ValType>& TStack<ValType>::operator = (const TStack &S) {
    if (this != &S) {
        if (size != S.size) {
            delete[]pMem;
            pMem = new ValType[S.size];
        }
        size = S.size;
        sp = S.sp;

        if (pMem == NULL) {
            std::string("Out of memory");
        } else {
            for (int i = 0; i < S.sp; i++)
                pMem[i] = S.pMem[i];
        }
    }

    return *this;
}

#endif  // MODULES_STACK_INCLUDE_STACK_H_
