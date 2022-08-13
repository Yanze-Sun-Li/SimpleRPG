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
    /// <summary>
    /// Display an game object at certain x, y console position.
    /// </summary>
    void DisplayStateAtXY(int _x, int _y, GameObject &gameObject);
    /// <summary>
    /// Display an game object at certain x, y console position in [Select state style].
    /// </summary>
    void DisplayStateAtXY_Selected(int _x, int _y, GameObject &gameObject);
    /// <summary>
    /// Display an game object at certain x, y console position in [Dead state style].
    /// </summary>
    void DisplayStateAtXY_Dead(int _x, int _y, GameObject& gameObject);
    /// <summary>
    /// Display game objects into certain enemy position (3 maximum).
    /// </summary>
    void DisplayEnemy(std::vector<GameObject*> EnemySlot);
    /// <summary>
    /// Display game objects into certain player position (3 maximum).
    /// </summary>
    void DisplayPlayer(std::vector<GameObject*> PlayerSlot);
    /// <summary>
    /// Clean all the content in console, and re-display all the enemy and player
    /// </summary>
    void Re_DisplayAll(std::vector<GameObject*> PlayerSlot, std::vector<GameObject*> EnemySlot);
    /// <summary>
    /// Display the await area content, including instruction sentences.
    /// </summary>
    void AwaitArea();
    void DisplayAttackChance();
    /// <summary>
    /// Reposition the cursor position into xPosition and yPosition
    /// </summary>
    void RepositionCursor();
    /// <summary>
    /// Re calculate position into xPosition and yPosition based on xIndex and yIndex
    /// </summary>
    void RepositionPosition();
    /// <summary>
    /// Console clean
    /// </summary>
    void Clean();
    /// <summary>
    /// Display shop menu
    /// </summary>
    void DisplayShop();
    /// <summary>
    /// Display picking player members menu
    /// </summary>
    void DisplayPlayerPicker(std::vector<GameObject*> player_team);
    /// <summary>
    /// Display how much gold does player have.
    /// </summary>
    /// <param name="gold"> - Must give integer input, the gold value not store in the Display class.</param>
    void DisplayGold(int gold);
    int xPosition;
    int yPosition;
    int xIndex;
    int yIndex;
    int playerAttackChance;

private:
    void ShowConsoleCursor(bool showFlag);
};
