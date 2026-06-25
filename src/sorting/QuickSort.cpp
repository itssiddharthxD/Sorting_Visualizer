#include "QuickSort.h"
#include <algorithm>

QuickSort::QuickSort() {
    reset();
}

void QuickSort::reset() {
    while (!stack.empty()) stack.pop();
    partitioning = false;
    finished = false;
}

void QuickSort::step(std::vector<int>& arr) {
    if (finished || arr.size() <= 1) {
        finished = true;
        return;
    }

    if (!partitioning && stack.empty()) {
        stack.push({0, (int)arr.size() - 1});
    }

    if (!partitioning) {
        if (stack.empty()) {
            finished = true;
            return;
        }
        l = stack.top().first;
        h = stack.top().second;
        stack.pop();
        
        if (l < h) {
            pivot = arr[h];
            i = l - 1;
            j = l;
            partitioning = true;
        }
    } else {
        if (j <= h - 1) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
            j++;
        } else {
            std::swap(arr[i + 1], arr[h]);
            int p = i + 1;
            partitioning = false;
            
            stack.push({l, p - 1});
            stack.push({p + 1, h});
        }
    }
}

int QuickSort::getCompare1() const { return partitioning ? j : l; }
int QuickSort::getCompare2() const { return partitioning ? i : h; }
bool QuickSort::is_finished() const { return finished; }
