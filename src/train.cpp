// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
    if (!first) return;
    // Разрываем кольцо
    Car* last = first->prev;
    if (last) {
        last->next = nullptr;
    }
    // Удаляем все вагоны
    Car* current = first;
    while (current != nullptr) {
        Car* nextCar = current->next;
        delete current;
        current = nextCar;
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
        if (current->light) {
            current->light = false;
            countOp++; // за выключение лампочки
        }
        length++;
        current = current->next;
        countOp++; // за переход в следующий вагон
    } while (current != first);
    return length;
}

int Train::getOpCount() const {
    return countOp;
}
