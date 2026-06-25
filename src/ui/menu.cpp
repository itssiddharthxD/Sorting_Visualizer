#include "menu.h"
#include <raylib.h>

Menu::Menu() {
    selected_algorithm = Algorithm::NONE;
    hover_bubble = false;
    hover_selection = false;
    hover_insertion = false;
    hover_merge = false;
    hover_quick = false;
}

void Menu::update(bool& start_visualization, Algorithm& algo) {
    Vector2 mouse_pos = GetMousePosition();

    Rectangle btnBubble = { 600, 300, 300, 60 };
    Rectangle btnSelection = { 600, 380, 300, 60 };
    Rectangle btnInsertion = { 600, 460, 300, 60 };
    Rectangle btnMerge = { 600, 540, 300, 60 };
    Rectangle btnQuick = { 600, 620, 300, 60 };

    hover_bubble = CheckCollisionPointRec(mouse_pos, btnBubble);
    hover_selection = CheckCollisionPointRec(mouse_pos, btnSelection);
    hover_insertion = CheckCollisionPointRec(mouse_pos, btnInsertion);
    hover_merge = CheckCollisionPointRec(mouse_pos, btnMerge);
    hover_quick = CheckCollisionPointRec(mouse_pos, btnQuick);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if (hover_bubble) { selected_algorithm = Algorithm::BUBBLE; start_visualization = true; }
        else if (hover_selection) { selected_algorithm = Algorithm::SELECTION; start_visualization = true; }
        else if (hover_insertion) { selected_algorithm = Algorithm::INSERTION; start_visualization = true; }
        else if (hover_merge) { selected_algorithm = Algorithm::MERGE; start_visualization = true; }
        else if (hover_quick) { selected_algorithm = Algorithm::QUICK; start_visualization = true; }
    }
    
    if (start_visualization) {
        algo = selected_algorithm;
    }
}

void Menu::draw() {
    ClearBackground((Color){ 30, 30, 46, 255 });

    DrawText("SORTING VISUALIZER", 420, 150, 60, RAYWHITE);
    DrawText("Select an algorithm to begin", 550, 230, 30, LIGHTGRAY);

    auto DrawButton = [](Rectangle rect, const char* text, bool hover) {
        Color baseColor = (Color){ 69, 71, 90, 255 };
        Color hoverColor = (Color){ 137, 180, 250, 255 };
        Color color = hover ? hoverColor : baseColor;
        
        DrawRectangleRounded(rect, 0.2f, 10, color);
        
        int textWidth = MeasureText(text, 30);
        DrawText(text, rect.x + (rect.width - textWidth) / 2, rect.y + 15, 30, hover ? (Color){30, 30, 46, 255} : RAYWHITE);
    };

    DrawButton({ 600, 300, 300, 60 }, "Bubble Sort", hover_bubble);
    DrawButton({ 600, 380, 300, 60 }, "Selection Sort", hover_selection);
    DrawButton({ 600, 460, 300, 60 }, "Insertion Sort", hover_insertion);
    DrawButton({ 600, 540, 300, 60 }, "Merge Sort", hover_merge);
    DrawButton({ 600, 620, 300, 60 }, "Quick Sort", hover_quick);
}