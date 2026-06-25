#pragma once
#include <vector>
#include <stack>
#include "Sorter.h"

class QuickSort : public Sorter {
private:
    std::stack<std::pair<int, int>> stack;
    bool partitioning;
    int l, h;
    int pivot;
    int i, j;
    bool finished;

public:
    QuickSort();
    
    bool is_finished() const override;
    int getCompare1() const override;
    int getCompare2() const override;
    
    void reset() override;
    void step(std::vector<int>& arr) override;
};
