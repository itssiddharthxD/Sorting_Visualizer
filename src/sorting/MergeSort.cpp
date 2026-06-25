#include "MergeSort.h"
#include <algorithm>

MergeSort::MergeSort() {
    reset();
}

void MergeSort::reset() {
    curr_size = 1;
    left_start = 0;
    merging = false;
    finished = false;
}

void MergeSort::step(std::vector<int>& arr) {
    if (finished || arr.size() <= 1) {
        finished = true;
        return;
    }

    int n = arr.size();

    if (!merging) {
        if (curr_size > n - 1) {
            finished = true;
            return;
        }

        if (left_start >= n - 1) {
            curr_size *= 2;
            left_start = 0;
            if (curr_size > n - 1) {
                finished = true;
            }
            return;
        }

        mid = std::min(left_start + curr_size - 1, n - 1);
        right_end = std::min(left_start + 2 * curr_size - 1, n - 1);
        
        int n1 = mid - left_start + 1;
        int n2 = right_end - mid;
        
        L.clear();
        R.clear();
        for (int x = 0; x < n1; x++) L.push_back(arr[left_start + x]);
        for (int y = 0; y < n2; y++) R.push_back(arr[mid + 1 + y]);
        
        i = 0;
        j = 0;
        k = left_start;
        merging = true;
    } else {
        if (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        } else if (i < L.size()) {
            arr[k] = L[i];
            i++;
            k++;
        } else if (j < R.size()) {
            arr[k] = R[j];
            j++;
            k++;
        } else {
            merging = false;
            left_start += 2 * curr_size;
        }
    }
}

int MergeSort::getCompare1() const { return merging ? k : left_start; }
int MergeSort::getCompare2() const { return merging ? mid : right_end; }
bool MergeSort::is_finished() const { return finished; }
