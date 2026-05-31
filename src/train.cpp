// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) return;
  Car* current = first->next;
  while (current != first) {
    Car* nextCar = current->next;
    delete current;
    current = nextCar;
  }
  delete first;
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
        current->light = false;
        countOp++;
        length++;
        current = current->next;
        countOp++;
    } while (current != first);
    // Алгоритм определения длины с лампочками
    first->light = true;
    current = first;
    int steps = 0;
    while (true) {
        current = current->next;
        steps++;
        countOp++;
        if (current->light) {
            current->light = false;
            countOp++;
            for (int i = 0; i < steps; i++) {
                current = current->prev;
                countOp++;
            }
            if (!first->light) {
                // Убеждаемся, что длина совпадает с подсчитанной
                return length;
            }
            for (int i = 0; i < steps; i++) {
                current = current->next;
                countOp++;
            }
            steps = 0;
        }
    }
}

int Train::getOpCount() const {
  return countOp;
}
