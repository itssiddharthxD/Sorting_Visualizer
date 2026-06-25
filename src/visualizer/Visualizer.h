#pragma once

#include <raylib.h>
#include <vector>

class Visualizer{

    private:
        std::vector<int>* values;

        int screen_width;
        int screen_height;
        
    public:
        Visualizer(std::vector<int>* arr, int width, int height);

        void draw(int compare1, int compare2, bool finished);

};
