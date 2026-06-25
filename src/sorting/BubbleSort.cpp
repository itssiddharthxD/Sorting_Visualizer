#include <algorithm>

#include "BubbleSort.h"

BubbleSort::BubbleSort(){
    reset();
}

void BubbleSort::reset(){
    i = 0;
    j = 0;
    finished = false;
}

void BubbleSort::step(std::vector<int>& arr){

    if(finished) return;

    if(arr[j] > arr[j + 1]){
        std::swap(arr[j], arr[j + 1]);
    }

    j++;

    if(j >= arr.size() - i - 1){
        j = 0;
        i++;
    }

    if(i >= arr.size() - 1){
        finished = true;
    }

}

int BubbleSort::getCompare1() const { return i; }
int BubbleSort::getCompare2() const { return j; }
bool BubbleSort::is_finished() const { return finished; }