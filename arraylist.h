#include <iostream>
#include <cstdlib>
#include <cmath>
#include "list.h"

using namespace std;

class ArrayList : public List {
    int* array;
    int size;
    int capacity = 5;


    void dynamic_add() {

//      change (0.75) depending on desired minimum percentage
//      if (size >= 0.75 * capacity) {

        int new_size = floor(capacity * 1.5);  // change 1.5 depending on desired growth rate
        int* new_array = (int*)realloc(array, sizeof(int) * new_size);

        if (new_array) {
            array = new_array;
            capacity = new_size;
        } else {
            // Handle realloc failure (e.g., by not updating capacity)
        }
    }

    void dynamic_deduce() {
        if (size < capacity * 2 / 3) {
            int new_size = ceil(capacity / 2.0); // Rounds up to the nearest integer

            if (new_size < 5) {
                new_size = 5; // Ensure the new size is at least 5
            }
            int* new_array = (int*)realloc(array, sizeof(int) * new_size);

            if (new_array) {
                array = new_array;
                capacity = new_size;
            } else {
                // Handle realloc failure (e.g., by not updating capacity)
            }
        }
    }


public:
    ArrayList() {
//        capacity = 5;
        array = (int*)calloc(capacity, sizeof(int));
        size = 0;
    }

    void add(int num) {
        if (size == capacity) {
            dynamic_add();
        }
        array[size++] = num;
    }

    int remove(int num) {
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                for (int j = i; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                array[size - 1] = 0;
                size = size - 1;
                if (size <= 0.67 * capacity) {
                    dynamic_deduce();
                }
                return i + 1;
            }
        }
        return -1;
    }

    int get(int pos) {
        if (pos >= 1 && pos <= size) {
            return array[pos - 1];
        }
        return -1; // Handle out-of-bounds access
    }

    int removeAll(int num) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                for (int j = i; j < size - 1; j++) {
                    array[j] = array[j + 1];
                }
                size--;
                count++;
                i--;
            }
        }

        if (size <= 0.67 * capacity) {
            dynamic_deduce();
        }

        return count;
    }

    void _size() {
        cout << "size: " << size << endl;

    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (int i = size; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }
};