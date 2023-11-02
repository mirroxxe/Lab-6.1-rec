#include <iostream>
#include <cstdlib>
#include <ctime>

const int arraySize = 24;
const int lowerLimit = -50;
const int upperLimit = 15;

void generateRandom(int arr[], int size, int lower, int upper) {
    if (size == 0) {
        return;
    }

    arr[size - 1] = rand() % (upper - lower + 1) + lower;
    generateRandom(arr, size - 1, lower, upper);
}

void print(int arr[], int size) {
    if (size == 0) {
        std::cout << std::endl;
        return;
    }

    std::cout << arr[size - 1] << " ";
    print(arr, size - 1);
}

int countNegative(int arr[], int size) {
    if (size == 0) {
        return 0;
    }

    int count = countNegative(arr, size - 1);
    if (arr[size - 1] < 0 || arr[size - 1] % 2 != 0) {
        return count + 1;
    }

    return count;
}

int sumNegative(int arr[], int size) {
    if (size == 0) {
        return 0;
    }

    int sum = sumNegative(arr, size - 1);
    if (arr[size - 1] < 0 || arr[size - 1] % 2 != 0) {
        return sum + arr[size - 1];
    }

    return sum;
}

void replaceNegative(int arr[], int size) {
    if (size == 0) {
        return;
    }

    if (arr[size - 1] < 0 || arr[size - 1] % 2 != 0) {
        arr[size - 1] = 0;
    }

    replaceNegative(arr, size - 1);
}

int main() {
    int arr[arraySize];
    srand(static_cast<unsigned>(time(0)));

    generateRandom(arr, arraySize, lowerLimit, upperLimit);
    std::cout << "Generated array: ";
    print(arr, arraySize);

    int count = countNegative(arr, arraySize);
    int sum = sumNegative(arr, arraySize);

    std::cout << "Count of negative: " << count << std::endl;
    std::cout << "Sum of negative: " << sum << std::endl;

    replaceNegative(arr, arraySize);
    std::cout << "Modified array: ";
    print(arr, arraySize);

    return 0;
}
