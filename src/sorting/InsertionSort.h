#pragma once
#include <vector>
#include "Sorter.h"

class InsertionSort : public Sorter {
private:
    int i, j, key;
    bool finished;
    bool state_extract;

public:
    InsertionSort();
    
    bool is_finished() const override;
    int getCompare1() const override;
    int getCompare2() const override;
    
    void reset() override;
    void step(std::vector<int>& arr) override;
};
