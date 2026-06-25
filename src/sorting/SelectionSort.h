#pragma once
#include <vector>
#include "Sorter.h"

class SelectionSort : public Sorter {
private:
    int i, j, min_idx;
    bool finished;

public:
    SelectionSort();
    
    bool is_finished() const override;
    int getCompare1() const override;
    int getCompare2() const override;
    
    void reset() override;
    void step(std::vector<int>& arr) override;
};
