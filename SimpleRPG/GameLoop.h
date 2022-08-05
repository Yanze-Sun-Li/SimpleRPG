#pragma once
#include "DATASTRUCTURE/GameObject.h"
#include "DISPLAY/Display.h"
#include <list>
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
    GameObject* IndexOf(std::list<GameObject>,int _index);

private:
    bool readToAttack;
    bool playerSelected;
    bool enemySelected;
    int xGap;
    int yGap;
    Display console_display;
    std::list<GameObject> EnemySlot;
    std::list<GameObject> PlayerSlot;
    GameObject* selectEnemyReference;
    GameObject* selectPlayerReference;
};
