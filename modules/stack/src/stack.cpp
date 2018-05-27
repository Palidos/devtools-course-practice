// Copyright 2018 Gladyshev Alexey

// This file was used to separate the class and describe its methods.
// Everything worked, but Travis CI didn't miss such an implementation.
// So, I had to write all the implementation of the methods in the header file.
// In order to use a separate implementation, you need
// 1) delete the description of all methods from the header file
// 2) put a line in header file after class describe:
//    #include "src / stack.cpp"
// 3) activate the contents of this file

/*
#ifndef MODULES_STACK_INCLUDE_STACK_CPP_
#define MODULES_STACK_INCLUDE_STACK_CPP_

#include "include/stack.h"

#include <string>

template <class ValType>
TStack<ValType>::TStack(int _size) {
    sp = 0;
    if (_size > 0)    size = _size;
    else              size = 1;

    pMem = new ValType[size];

    if (pMem == NULL)
        throw std::string("Out of memory");
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
        throw std::string("Out of memory");
    } else {
        for (int i = 0; i < S.sp; i++)
            pMem[i] = S.pMem[i];
    }
}

template <class ValType>
void TStack<ValType>::Push(ValType var) {
    pMem[sp++] = var;
}

template <class ValType>
ValType TStack<ValType>::Pop(void) {
    return pMem[--sp];
}

template <class ValType>
ValType TStack<ValType>::Top(void) {
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
        for (; (counter < sp) && (pMem[counter] == S.pMem[counter]); counter++) {}

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

#endif  // MODULES_STACK_INCLUDE_STACK_CPP_
*/
