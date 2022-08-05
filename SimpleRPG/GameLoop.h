#pragma once
#include "DATASTRUCTURE/GameObject.h"
#include "DISPLAY/Display.h"
#include <vector>
#include <queue>
#include <Windows.h>

class GameLoop
{
public:
    GameLoop();
    void Start();
    /// <summary>
    /// This is battle logic for how the game running an battle scene
    /// Battle result: -1 for none, 0 for Enemy win, 1 for player win.
    /// </summary>
    void BattleScene();
    /*void SelectGameObject();*/
    void SelectEnemy();
    void SelectPlayer();


private:
    int battleResult;
    bool readToAttack;
    bool playerSelected;
    bool enemySelected;
    int xGap;
    int yGap;
    Display console_display;
    std::vector<GameObject> EnemySlot;
    std::vector<GameObject> PlayerSlot;
    GameObject* selectedEnemyReference;
    GameObject* selectedPlayerReference;
    bool IfEnemyDead();
    bool IfPlayerDead();
};
