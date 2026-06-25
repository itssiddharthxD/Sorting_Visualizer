#include <raylib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>

#include "visualizer/Visualizer.h"
#include "sorting/Sorter.h"
#include "sorting/BubbleSort.h"
#include "sorting/SelectionSort.h"
#include "sorting/InsertionSort.h"
#include "sorting/MergeSort.h"
#include "sorting/QuickSort.h"
#include "ui/menu.h"

int WIDTH = 1500, HEIGHT = 900;
bool is_paused = true;
float timer = 0.0f;
float delay = 0.001f;

enum class GameState{
    MENU,
    SORTING

};

std::vector<int> GenerateArray(){
    std::vector<int> arr;

    for(int i = 0; i < 200; i++){
        arr.push_back(rand() % 700 + 20);
    }

    return arr;
}

void HandleInput(bool& isPaused, std::vector<int>& values, std::unique_ptr<Sorter>& sorter, float& delay, GameState& state){

    if(IsKeyPressed(KEY_SPACE)){
        isPaused = !isPaused;
    }

    if(IsKeyPressed(KEY_R)){
        values = GenerateArray();
        sorter->reset();
        isPaused = true;
    }

    if(IsKeyPressed(KEY_M)){
        state = GameState::MENU;
        isPaused = true;
    }

    if(IsKeyDown(KEY_UP)){
        delay *= 0.9f;
        if(delay < 0.0001f) delay = 0.0001f;
    }

    if(IsKeyDown(KEY_DOWN)){
        delay *= 1.1f;
        if(delay > 1.0f) delay = 1.0f;
    }
}

void controls_menu(){

    Rectangle controls = {10, 10, 140, 40};

    Vector2 mouse_pos = GetMousePosition();
    bool hovering = CheckCollisionPointRec(mouse_pos, controls);

    DrawRectangleRounded(controls, 0.3f, 10, (Color){69, 71, 90, 200});

    DrawText("CONTROLS", 25, 20, 20, RAYWHITE);

    if(hovering){
        DrawRectangleRounded({10, 60, 250, 170}, 0.1f, 10, (Color){30, 30, 46, 220});
        DrawRectangleRoundedLines({10, 60, 250, 170}, 0.1f, 10, RAYWHITE);

        DrawText("[SPACE] - Play/Pause", 20, 75, 20, RAYWHITE);
        DrawText("[R] - Shuffle", 20, 105, 20, RAYWHITE);
        DrawText("[UP] - Faster", 20, 135, 20, RAYWHITE);
        DrawText("[DOWN] - Slower", 20, 165, 20, RAYWHITE);
        DrawText("[M] - Main Menu", 20, 195, 20, RAYWHITE);
    }

}

int main(){

    srand(time(NULL));

    InitWindow(WIDTH, HEIGHT, "Sorting Visualizer");
    SetTargetFPS(600);

    std::vector<int> values = GenerateArray();

    Visualizer visualizer(&values, WIDTH, HEIGHT);

    Menu menu;

    GameState state = GameState::MENU;

    std::unique_ptr<Sorter> sorter = std::make_unique<BubbleSort>();
    Algorithm current_algo = Algorithm::NONE;


    while(!WindowShouldClose()){

        switch(state){

            case GameState::MENU:{

                bool start_visualization = false;
                Algorithm selected_algo = Algorithm::NONE;
                menu.update(start_visualization, selected_algo);

                if(start_visualization) {
                    state = GameState::SORTING;
                    if(current_algo != selected_algo){
                        current_algo = selected_algo;
                        switch(current_algo){
                            case Algorithm::BUBBLE: sorter = std::make_unique<BubbleSort>(); break;
                            case Algorithm::SELECTION: sorter = std::make_unique<SelectionSort>(); break;
                            case Algorithm::INSERTION: sorter = std::make_unique<InsertionSort>(); break;
                            case Algorithm::MERGE: sorter = std::make_unique<MergeSort>(); break;
                            case Algorithm::QUICK: sorter = std::make_unique<QuickSort>(); break;
                            default: break;
                        }
                    }
                    values = GenerateArray();
                    sorter->reset();
                    is_paused = true;
                }

                BeginDrawing();
                menu.draw();
                EndDrawing();
                break;

            }

            case GameState::SORTING:{

                HandleInput(is_paused, values, sorter, delay, state);

                timer += GetFrameTime();

                if(!is_paused && timer >= delay){
                    sorter->step(values);
                    timer = 0;
                }

                BeginDrawing();
                ClearBackground((Color){30, 30, 46, 255});

                visualizer.draw(sorter->getCompare1(), sorter->getCompare2(), sorter->is_finished());
                controls_menu();

                EndDrawing();
                break;

            }

        }

    }


    CloseWindow();

    return 0;
}