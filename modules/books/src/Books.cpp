// Copyright 2018 Bolshakov Konstantin

#include "include/Books.h"

Books::Books(int n, int* arr) {
    this->n = n;
    this->arr = new int[n];
    for (int i = 0; i < n; i++)
        this->arr[i] = arr[i];
}

Books::~Books() {
    delete arr;
}

double Books::CalculatePayForCurrentCollection(int * arr, int collection) {
    double sum = 0.0;
    int arraySize = this->n;
    for (int i = 0; i < arraySize; i++)
        arr[i] != 0 ? arr[i] -= 1 : arr[i] = 0;

    collection == 5 ? sum = 30.0 :
        (collection == 4 ? sum = 25.6 :
        (collection == 3 ? sum = 21.6 :
            (collection == 2 ? sum = 15.2 :
                sum = 8.0)));
    return sum;
}

int Books::CurentCollectionSize(int * arr) {
    int CollectionSize = 0;
    int arraySize = this->n;
    for (int i = 0; i < arraySize; i++)
        arr[i] != 0 ? CollectionSize++ : CollectionSize += 0;
    return CollectionSize;
}

double Books::CalculateAllPayment(int * arr) {
    double payment = 0.0;
    int cur_collection = 0;
    while ((cur_collection = CurentCollectionSize(arr)) != 0)
        payment += CalculatePayForCurrentCollection(arr, cur_collection);
    return payment;
}
