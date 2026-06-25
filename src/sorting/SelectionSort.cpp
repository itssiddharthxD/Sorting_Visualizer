#include "SelectionSort.h"
#include <algorithm>

SelectionSort::SelectionSort() {
    reset();
}

void SelectionSort::reset() {
    i = 0;
    j = 1;
    min_idx = 0;
    finished = false;
}

void SelectionSort::step(std::vector<int>& arr) {
    if (finished || arr.empty()) {
        finished = true;
        return;
    }

    if (j < arr.size()) {
        if (arr[j] < arr[min_idx]) {
            min_idx = j;
        }
        j++;
    } else {
        std::swap(arr[i], arr[min_idx]);
        i++;
        min_idx = i;
        j = i + 1;
        
        if (i >= arr.size() - 1) {
            finished = true;
        }
    }
}

int SelectionSort::getCompare1() const { return j < 1000 ? j : i; } 
int SelectionSort::getCompare2() const { return min_idx; }
bool SelectionSort::is_finished() const { return finished; }
