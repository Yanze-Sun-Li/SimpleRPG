#pragma once
#include "DATASTRUCTURE/GameObject.h"
#include "DISPLAY/Display.h"
#include <vector>
#include <queue>
#include <Windows.h>
#include "FUNCTION/Random.h"
#include <list>
#include "RUNTIMEDATA/Level.h"
#include "RUNTIMEDATA/DATA_Player.h"

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
    DATA_Player playerData;
    
    std::vector<GameObject*> EnemySlot;
    std::vector<GameObject*> PlayerSlot;
    std::vector<GameObject*> DeadEnemySlot;
    std::vector<GameObject*> DeadPlayerSlot;
    std::vector<GameObject*> AlivePlayer;



    GameObject* selectedEnemyReference;
    GameObject* selectedPlayerReference;
    /// <summary>
    /// If all the enemy objects in the team are dead?
    /// </summary>
    bool IfEnemyAllDead();
    /// <summary>
    /// If all the player objects in the team are dead?
    /// </summary>
    bool IfPlayerAllDead();
    /// <summary>
    /// Player turn to act, reading keyboard input and give response.
    /// </summary>
    void PlayerRound();
    /// <summary>
    /// Enemy randomly pick players in player slot to attack.
    /// </summary>
    /// <param name="amount"></param>
    void EnemyRound();
    /// <summary>
    /// Return how many of player objects are alive in player team.
    /// </summary>
    int PlayerAliveNumber();
    /// <summary>
    /// Return how many of player objects are alive in enemy team.
    /// </summary>
    int EnemyAliveNumber();
    /// <summary>
    /// Loading level information
    /// </summary>
    void LoadLevelEnemySlot(std::list<std::vector<GameObject>> level);
    /// <summary>
    /// Remove dead enemy from enemy team.
    /// </summary>
    void RemoveDeadEnemy();
    /// <summary>
    /// Remove dead player from enemy team.
    /// </summary>
    void RemoveDeadPlayer();
    /// <summary>
    /// If game end, this function clean up all the momery usage.
    /// </summary>
    void GameEnd();
    /// <summary>
    /// Loading player information
    /// </summary>
    void LoadPlayer();
    /// <summary>
    /// Shop level for player upgrade
    /// </summary>
    void Shop();
    /// <summary>
    /// Increase all player members attack damage
    /// </summary>
    void PlayerAddAttack(int amount);
    /// <summary>
    /// Increase all player members defend value
    /// </summary>
    void PlayerAddDefend(int amount);
    /// <summary>
    /// healing all the player member into their maximum value.
    /// </summary>
    void PlayerHealing();

};
