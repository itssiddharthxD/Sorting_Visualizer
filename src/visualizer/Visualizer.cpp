#include "Visualizer.h"
#include <raymath.h>

Visualizer::Visualizer(std::vector<int>* arr, int width, int height){

    values = arr;
    screen_width = width;
    screen_height = height;

}

void Visualizer::draw(int compare1, int compare2, bool finished){

    float bar_width = (float) screen_width / values->size();
    int max_val = 800;
    int padding_top = 50;
    int min_height = 50;


    for(int i = 0; i < values->size(); i++){

        float height_ratio = (float) (*values)[i] / max_val;
        float bar_height = height_ratio * (screen_height - padding_top) + min_height;

        float hue = height_ratio * 300.0f;
        Color color = ColorFromHSV(hue, 0.8f, 0.9f);

        if(finished) color = (Color){ 166, 227, 161, 255 };
        else if(i == compare1 || i == compare2) color = RAYWHITE;

        float draw_width = bar_width - 1.0f;
        if(draw_width < 1.0f) draw_width = bar_width;

        DrawRectangle(i * bar_width, screen_height - bar_height + padding_top, draw_width, bar_height, color);
    }

}