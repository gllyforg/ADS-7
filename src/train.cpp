// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (!first) return;
    Car* current = first;
    Car* nextCar = nullptr;
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
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
    countOp = 0;
    Car* current = first;
    // Mark starting car
    current->light = true;
    int length = 1;
    while (true) {
        current = current->next;
        countOp++;
        if (current->light) {
            // Found the marked car, go back to start
            for (int i = 0; i < length; i++) {
                current = current->prev;
                countOp++;
            }
            break;
        } else {
            length++;
            current->light = true;
        }
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}

void Train::resetOpCount() {
    countOp = 0;
}
