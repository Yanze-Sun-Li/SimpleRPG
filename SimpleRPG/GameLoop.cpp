#include "GameLoop.h"

GameLoop::GameLoop()
{
    leveManager = Level();
    rand = Random();
    battleResult = -1;
    xGap = 35;
    yGap = 10;
    console_display = Display(xGap, yGap);

    EnemySlot = std::vector<GameObject*>();
    PlayerSlot = std::vector<GameObject*>();
    DeadEnemySlot = std::vector<GameObject*>();
    DeadPlayerSlot = std::vector<GameObject*>();
    AlivePlayer = std::vector<GameObject*>();

    selectedPlayerReference = nullptr;
    selectedEnemyReference = nullptr;

    GameObject* Enemy1 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Enemy2 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Enemy3 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Player1 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Player2 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Player3 = (GameObject*)malloc(sizeof(GameObject));

    Enemy1 = new GameObject("Test1");
    Enemy2 = new GameObject("Test2");
    Enemy3 = new GameObject("Test3");
    Player1 = new GameObject("Test4");
    Player2 = new GameObject("Test5");
    Player3 = new GameObject("Test6");

    EnemySlot.push_back(Enemy1);
    EnemySlot.push_back(Enemy2);
    EnemySlot.push_back(Enemy3);

    PlayerSlot.push_back(Player1);
    PlayerSlot.push_back(Player2);
    PlayerSlot.push_back(Player3);


    playerSelected = false;
    enemySelected = false;
}

void GameLoop::Start()
{
   
    LoadLevelEnemySlot(leveManager.Level_One);

    battleResult = -1;

    int i;
    std::cin >> i;
}

void GameLoop::BattleScene()
{
    playerAttackChance = PlayerAliveNumber();
    enemyAttackChance = EnemyAliveNumber();
    //Reseting the winning indicator
    battleResult = -1;
    // First Game Scene start here:
    console_display.Re_DisplayAll(PlayerSlot, EnemySlot);
    console_display.playerAttackChance = playerAttackChance;
    console_display.DisplayAttackChance();

    while (battleResult ==-1) {
        PlayerRound();
        EnemyRound();
        RemoveDeadEnemy();
        console_display.Re_DisplayAll(PlayerSlot, EnemySlot);
    }

    GameEnd();

}



void GameLoop::SelectEnemy()
{
    if (EnemySlot.empty()) { return; }
    selectedEnemyReference = EnemySlot[console_display.xIndex];

    if (enemySelected && !selectedEnemyReference->IsSame(*selectedEnemyReference)) {
        return;
    }
    if (selectedEnemyReference->IfDead()) {
        return;
    }

    selectedEnemyReference->x_position = console_display.xPosition;
    selectedEnemyReference->y_position = console_display.yPosition;
    
    enemySelected = !enemySelected;
    if (enemySelected) {
        console_display.DisplayStateAtXY_Selected(console_display.xPosition + 1,
            console_display.yPosition, *selectedEnemyReference);
    }
    else
    {
        console_display.DisplayStateAtXY(console_display.xPosition + 1,
            console_display.yPosition, *selectedEnemyReference);
    }

}

void GameLoop::SelectPlayer()
{
    if (PlayerSlot.empty()) { return; }
    selectedPlayerReference = PlayerSlot[console_display.xIndex];

    if (playerSelected && !selectedPlayerReference->IsSame(*selectedPlayerReference)) {
        return;
    }
    if (selectedPlayerReference->IfDead()) {
        return;
    }
    selectedPlayerReference->x_position = console_display.xPosition;
    selectedPlayerReference->y_position = console_display.yPosition;

    playerSelected = !playerSelected;
    if (playerSelected) {
        console_display.DisplayStateAtXY_Selected(console_display.xPosition + 1,
            console_display.yPosition, *selectedPlayerReference);
    }
    else
    {
        console_display.DisplayStateAtXY(console_display.xPosition + 1,
            console_display.yPosition, *selectedPlayerReference);
    }
}

bool GameLoop::IfEnemyAllDead() {
    bool enemyDead = true;
    for (GameObject* ob : EnemySlot) 
    {
        if (!ob->IfDead()) {
            enemyDead = false;
        }
    }
    return enemyDead;
}

bool GameLoop::IfPlayerAllDead() {
    bool playerDead = true;
    for (GameObject* ob : PlayerSlot)
    {
        if (!ob->IfDead())
            playerDead = false;
    }
    return playerDead;
}

void GameLoop::PlayerRound() {

    std::cout << "Player round!";

    playerAttackChance = PlayerAliveNumber();
    console_display.playerAttackChance = playerAttackChance;
    console_display.DisplayAttackChance();

    while (!GetAsyncKeyState(VK_ESCAPE) && playerAttackChance > 0)
    {

        if (GetAsyncKeyState(VK_UP) && console_display.yIndex != 0 && console_display.xIndex + 1 <= EnemySlot.size())
        {
            console_display.yIndex -= 1;
            console_display.RepositionPosition();
            console_display.RepositionCursor();
            Sleep(250);
        }
        if (GetAsyncKeyState(VK_DOWN) && console_display.yIndex != 1 && console_display.xIndex + 1 <= PlayerSlot.size())
        {
            console_display.yIndex += 1;
            console_display.RepositionPosition();
            console_display.RepositionCursor();
            Sleep(250);
        }

        if (console_display.yIndex == 0)
        {
            if (GetAsyncKeyState(VK_RIGHT) && console_display.xIndex+1 < EnemySlot.size())
            {
                console_display.xIndex += 1;
                console_display.RepositionPosition();
                console_display.RepositionCursor();
                Sleep(250);
            }
            if (GetAsyncKeyState(VK_LEFT) && console_display.xIndex != 0)
            {
                console_display.xIndex -= 1;
                console_display.RepositionPosition();
                console_display.RepositionCursor();
                Sleep(250);
            }
        }

        if (console_display.yIndex == 1)
        {
            if (GetAsyncKeyState(VK_RIGHT) && console_display.xIndex+1 < PlayerSlot.size())
            {
                console_display.xIndex += 1;
                console_display.RepositionPosition();
                console_display.RepositionCursor();
                Sleep(250);
            }
            if (GetAsyncKeyState(VK_LEFT) && console_display.xIndex != 0)
            {
                console_display.xIndex -= 1;
                console_display.RepositionPosition();
                console_display.RepositionCursor();
                Sleep(250);
            }
        }


        if (GetAsyncKeyState(VK_SPACE) && console_display.yIndex != 2)
        {
            switch (console_display.yIndex)
            {
            case 0:
                SelectEnemy();
                break;
            case 1:
                SelectPlayer();
                break;
            }
            Sleep(250);
        }
        if (GetAsyncKeyState(0x43))
        {
            if (enemySelected && playerSelected) {
                playerAttackChance -= 1;
                console_display.playerAttackChance = playerAttackChance;
                selectedPlayerReference->Attack(*selectedEnemyReference);
                console_display.Re_DisplayAll(PlayerSlot,EnemySlot);
                console_display.DisplayAttackChance();
                enemySelected = false;
                playerSelected = false;
                if (IfEnemyAllDead()) {
                    battleResult = 1;
                }
            }
        }
    }
}

void GameLoop::EnemyRound() 
{
    enemyAttackChance = EnemyAliveNumber();
    for (GameObject* ob : EnemySlot)
    {
        if (IfPlayerAllDead())
        {
            battleResult = 0;
            break;
        }
        if (PlayerSlot.empty())
        {
            break;
        }
        if (enemyAttackChance <= 0) {
            enemyAttackChance = -1;
            break;
        }

        if (!ob->IfDead())
        {
            AlivePlayer.clear();
            for (GameObject* ob_p : PlayerSlot)
            {
                if (!ob_p->IfDead())
                {
                    AlivePlayer.push_back(ob_p);
                }
            }
            ob->Attack(*AlivePlayer[rand.random(AlivePlayer.size())]);
            console_display.Re_DisplayAll(PlayerSlot, EnemySlot);
            enemyAttackChance--;
            RemoveDeadPlayer();
        }
        
    }
}

void GameLoop::RemoveDeadEnemy() {
    
    int i= 0;

    for (GameObject* ob : EnemySlot) {
        //Give index
        EnemySlot[i]->index = i;
        //If dead, index decrease while delete this object
        if (EnemySlot[i]->IfDead())
        {
            
            EnemySlot.erase(EnemySlot.begin() + EnemySlot[i]->index);
            i--;
        }
        //If not dead, increase. if dead, stay same.
        i++;
    }
}

void GameLoop::RemoveDeadPlayer() {
    int i = 0;

    for (GameObject* ob : PlayerSlot) {
        //Give index
        PlayerSlot[i]->index = i;
        //If dead, index decrease while delete this object
        if (PlayerSlot[i]->IfDead())
        {

            PlayerSlot.erase(PlayerSlot.begin() + PlayerSlot[i]->index);
            i--;
        }
        //If not dead, increase. if dead, stay same.
        i++;
    }
}

void GameLoop::GameEnd()
{
    for (int i = 0; i < DeadEnemySlot.size(); i++)
    {
        free(DeadEnemySlot[i]);
    }
    for (int i = 0; i < DeadPlayerSlot.size(); i++)
    {
        free(DeadPlayerSlot[i]);

        DeadEnemySlot.clear();
        DeadPlayerSlot.clear();
    }
}

int GameLoop::PlayerAliveNumber()
{
    int alive = PlayerSlot.size();
    for (GameObject* ob : PlayerSlot) {
        if (ob->IfDead()) {
            alive -= 1;
        }
    }
    return alive;
}

int GameLoop::EnemyAliveNumber()
{
    int alive = EnemySlot.size();
    for (GameObject* ob : EnemySlot) {
        if (ob->IfDead()) {
            alive -= 1;
        }
    }
    return alive;
}

void GameLoop::LoadLevelEnemySlot(std::list<std::vector<GameObject>> level) {
    EnemySlot.clear();
    GameObject* Enemy1 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Enemy2 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* Enemy3 = (GameObject*)malloc(sizeof(GameObject));

    for (std::vector<GameObject> team : level)
    {
        Enemy1 = &team[0];
        Enemy2 = &team[1];
        Enemy3 = &team[2];

        EnemySlot.push_back(Enemy1);
        EnemySlot.push_back(Enemy2);
        EnemySlot.push_back(Enemy3);

        BattleScene();
        console_display.Clean();
        switch (battleResult)
        {
        case -1:
            std::cout << "Error" << std::endl;
            break;
        case 0:
            std::cout << "Enemy have the victory!" << std::endl;
            goto PlayerLose;
        case 1:
            continue;
        default:
            break;
        }
    }
PlayerLose:
    return;
}

//void GameLoop::LoadPlayer() {
//
//}