#pragma once

enum class Algorithm {
    BUBBLE,
    SELECTION,
    INSERTION,
    MERGE,
    QUICK,
    NONE
};

class Menu {
private:
    Algorithm selected_algorithm;
    bool hover_bubble;
    bool hover_selection;
    bool hover_insertion;
    bool hover_merge;
    bool hover_quick;

public:
    Menu();
    void update(bool& start_visualization, Algorithm& algo);
    void draw();
};