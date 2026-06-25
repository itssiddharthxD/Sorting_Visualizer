#pragma once
#include <vector>
#include "Sorter.h"

class MergeSort : public Sorter {
private:
    int curr_size;
    int left_start;
    int mid;
    int right_end;
    int i, j, k;
    std::vector<int> L, R;
    bool merging;
    bool finished;

public:
    MergeSort();
    
    bool is_finished() const override;
    int getCompare1() const override;
    int getCompare2() const override;
    
    void reset() override;
    void step(std::vector<int>& arr) override;
};
