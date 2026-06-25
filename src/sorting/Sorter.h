#pragma once

#include <vector>

class Sorter {
public:
    virtual ~Sorter() = default;

    virtual void step(std::vector<int>& arr) = 0;
    virtual void reset() = 0;

    virtual bool is_finished() const = 0;
    virtual int getCompare1() const = 0;
    virtual int getCompare2() const = 0;
};
