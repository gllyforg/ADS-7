// Copyright 2022 NNTU-CS
#include <vector>
#include <random>
#include <iostream>

#include "train.h"

int main() {
    const int MAX_N = 200;
    const int STEP = 10;
    // Experiment 1: all lights OFF
    std::cout << "ALL OFF:\n";
    for (int n = 10; n <= MAX_N; n += STEP) {
        Train train;
        for (int i = 0; i < n; i++) train.addCar(false);
        train.getLength();
        std::cout << n << "," << train.getOpCount() << std::endl;
    }
    // Experiment 2: all lights ON
    std::cout << "\nALL ON:\n";
    for (int n = 10; n <= MAX_N; n += STEP) {
        Train train;
        for (int i = 0; i < n; i++) train.addCar(true);
        train.getLength();
        std::cout << n << "," << train.getOpCount() << std::endl;
    }
    // Experiment 3: random lights
    std::cout << "\nRANDOM:\n";
    std::mt19937 gen(42);
    std::uniform_int_distribution<> dis(0, 1);
    for (int n = 10; n <= MAX_N; n += STEP) {
        Train train;
        for (int i = 0; i < n; i++) train.addCar(dis(gen));
        train.getLength();
        std::cout << n << "," << train.getOpCount() << std::endl;
    }
    return 0;
}
