#pragma once
#include "../CONSOLE_CONTROL/ConsoleControl.h"
#include <vector>
#include "../DATASTRUCTURE/GameObject.h"

class Display
{
public:
    // Control cursor
    ConsoleControl console_control;
    // Color Control
    ColorControl console_color;
    int xGap;
    int yGap;

    Display(int _xGap, int _yGap);
    Display();
    void DisplayStateAtXY(int _x, int _y, GameObject &gameObject);
    void DisplayStateAtXY_Selected(int _x, int _y, GameObject &gameObject);
    void DisplayStateAtXY_Dead(int _x, int _y, GameObject& gameObject);
    void DisplayEnemy(std::vector<GameObject> EnemySlot);
    void DisplayPlayer(std::vector<GameObject> PlayerSlot);
    void AwaitArea();
    void RepositionCursor();
    void Reposition();
    int xPosition;
    int yPosition;
    int xIndex;
    int yIndex;

private:
    void ShowConsoleCursor(bool showFlag);
};