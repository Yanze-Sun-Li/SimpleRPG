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
    void BattleScene();
    /*void SelectGameObject();*/
    void SelectEnemy();
    void SelectPlayer();

private:
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
};
