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
    void DisplayEnemy(std::vector<GameObject*> EnemySlot);
    void DisplayPlayer(std::vector<GameObject*> PlayerSlot);
    void Re_DisplayAll(std::vector<GameObject*> PlayerSlot, std::vector<GameObject*> EnemySlot);
    void AwaitArea();
    void DisplayAttackChance();
    void RepositionCursor();
    void RepositionPosition();
    void Clean();
    int xPosition;
    int yPosition;
    int xIndex;
    int yIndex;
    int playerAttackChance;

private:
    void ShowConsoleCursor(bool showFlag);
};
