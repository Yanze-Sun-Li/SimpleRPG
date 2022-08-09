#pragma once
#include "DATASTRUCTURE/GameObject.h"
#include "DISPLAY/Display.h"
#include <vector>
#include <queue>
#include <Windows.h>
#include "FUNCTION/Random.h"
#include <list>
#include "RUNTIMEDATA/Level.h"

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
    int gold;
    int playerAttackChance = -1;
    int enemyAttackChance = -1;
    Random rand;
    int battleResult;
    bool readToAttack;
    bool playerSelected;
    bool enemySelected;
    int xGap;
    int yGap;
    Display console_display;
    Level leveManager;
    
    std::vector<GameObject*> EnemySlot;
    std::vector<GameObject*> PlayerSlot;
    std::vector<GameObject*> DeadEnemySlot;
    std::vector<GameObject*> DeadPlayerSlot;
    std::vector<GameObject*> AlivePlayer;



    GameObject* selectedEnemyReference;
    GameObject* selectedPlayerReference;
    bool IfEnemyAllDead();
    bool IfPlayerAllDead();
    void PlayerRound();
    void EnemyRound();
    int PlayerAliveNumber();
    int EnemyAliveNumber();
    void LoadLevelEnemySlot(std::list<std::vector<GameObject>> level);
    void RemoveDeadEnemy();
    void RemoveDeadPlayer();
    void GameEnd();
    void LoadPlayer();
    void Shop();

};
