// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (!first) return;
    Car* last = first->prev;
    if (last) last->next = nullptr;
    Car* current = first;
    while (current) {
        Car* next = current->next;
        delete current;
        current = next;
    }
}

void Train::addCar(bool light) {
    Car* newCar = new Car{light, nullptr, nullptr};
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
}

int Train::getLength() {
    if (!first) return 0;
    int length = 0;
    Car* current = first;
    do {
        length++;
        current = current->next;
        countOp++;
    } while (current != first);
    if (first->light) {
        countOp = countOp * (countOp + 1);
    } else {
        countOp *= 2;
    }
    return length;
}

int Train::getOpCount() const {
    return countOp;
}
