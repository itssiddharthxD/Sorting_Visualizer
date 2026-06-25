#include "InsertionSort.h"

InsertionSort::InsertionSort() {
    reset();
}

void InsertionSort::reset() {
    i = 1;
    j = 0;
    key = 0;
    finished = false;
    state_extract = true;
}

void InsertionSort::step(std::vector<int>& arr) {
    if (finished || arr.size() <= 1) {
        finished = true;
        return;
    }

    if (state_extract) {
        key = arr[i];
        j = i - 1;
        state_extract = false;
    } else {
        if (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        } else {
            arr[j + 1] = key;
            i++;
            state_extract = true;
            if (i >= arr.size()) {
                finished = true;
            }
        }
    }
}

int InsertionSort::getCompare1() const { return i; }
int InsertionSort::getCompare2() const { return j >= 0 ? j : 0; }
bool InsertionSort::is_finished() const { return finished; }
