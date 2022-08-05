#include "GameLoop.h"

GameLoop::GameLoop()
{
    rand = Random();
    battleResult = -1;
    xGap = 35;
    yGap = 10;
    console_display = Display(xGap, yGap);

    EnemySlot = std::vector<GameObject>();
    PlayerSlot = std::vector<GameObject>();
    DeadEnemySlot = std::vector<GameObject>();

    selectedPlayerReference = nullptr;
    selectedEnemyReference = nullptr;

    GameObject* test_1 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_2 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_3 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_4 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_5 = (GameObject*)malloc(sizeof(GameObject));
    //GameObject* test_6 = (GameObject*)malloc(sizeof(GameObject));

    
    test_1 = new GameObject("Test1");
    test_2 = new GameObject("Test2");
    test_3 = new GameObject("Test3");
    test_4 = new GameObject("Test4");
    test_5 = new GameObject("Test5");
    //test_6 = new GameObject("Test6");

    EnemySlot.push_back(*test_1);
    EnemySlot.push_back(*test_2);
    EnemySlot.push_back(*test_3);

    PlayerSlot.push_back(*test_4);
    PlayerSlot.push_back(*test_5);
    //PlayerSlot.push_back(*test_6);


    playerSelected = false;
    enemySelected = false;
}

void GameLoop::Start()
{
   
    BattleScene();
    console_display.Clean();
    switch (battleResult)
    {
    case -1:
        std::cout << "Error"<<std::endl;
    case 0:
        std::cout << "Enemy have the victory!" << std::endl;
    case 1:
        std::cout << "Player have the victory!" << std::endl;
    default:
        break;
    }
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
    console_display.DisplayEnemy(EnemySlot);
    console_display.DisplayPlayer(PlayerSlot);
    console_display.AwaitArea();

    while (true) {
        if (PlayerRound()) {
            break;
        }
        RemoveDeadEnemy();
    }

    GameEnd();

}



void GameLoop::SelectEnemy()
{
    if (EnemySlot.empty()) { return; }
    selectedEnemyReference = &EnemySlot[console_display.xIndex];

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
    selectedPlayerReference = &PlayerSlot[console_display.xIndex];

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

bool GameLoop::IfEnemyDead() {
    bool enemyDead = true;
    for (GameObject ob : EnemySlot) 
    {
        enemyDead = ob.IfDead();
    }
    return enemyDead;
}

bool GameLoop::IfPlayerDead() {
    bool playerDead = true;
    for (GameObject ob : PlayerSlot)
    {
        playerDead = ob.IfDead();
    }
    return playerDead;
}

bool GameLoop::PlayerRound() {

    playerAttackChance = PlayerAliveNumber();

    while (!GetAsyncKeyState(VK_ESCAPE))
    {

        if (GetAsyncKeyState(VK_UP) && console_display.yIndex != 0)
        {
            console_display.yIndex -= 1;
            console_display.Reposition();
            console_display.RepositionCursor();
            Sleep(250);
        }
        if (GetAsyncKeyState(VK_DOWN) && console_display.yIndex != 1)
        {
            console_display.yIndex += 1;
            console_display.Reposition();
            console_display.RepositionCursor();
            Sleep(250);
        }
        if (GetAsyncKeyState(VK_RIGHT) && console_display.xIndex != 2)
        {
            console_display.xIndex += 1;
            console_display.Reposition();
            console_display.RepositionCursor();
            Sleep(250);
        }
        if (GetAsyncKeyState(VK_LEFT) && console_display.xIndex != 0)
        {
            console_display.xIndex -= 1;
            console_display.Reposition();
            console_display.RepositionCursor();
            Sleep(250);
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
                selectedPlayerReference->Attack(*selectedEnemyReference);
                console_display.DisplayStateAtXY(selectedEnemyReference->x_position + 1, selectedEnemyReference->y_position, *selectedEnemyReference);
                console_display.DisplayStateAtXY(selectedPlayerReference->x_position + 1, selectedPlayerReference->y_position, *selectedPlayerReference);
                enemySelected = false;
                playerSelected = false;
                if (IfPlayerDead())
                {
                    battleResult = 0;
                    return true;
                }
                else if (IfEnemyDead())
                {
                    battleResult = 1;
                    return true;
                }
                else if (playerAttackChance <= 0) {
                    return false;
                }
            }
        }
    }
}

bool GameLoop::EnemyRound() {


    //for (int i = 0; i < EnemyAliveNumber(); i++)
    //{
    //    
    //}

    return false;
}

void GameLoop::RemoveDeadEnemy() {

}

void GameLoop::RemoveDeadPlayer() {

}

void GameLoop::GameEnd()
{
}

int GameLoop::PlayerAliveNumber()
{
    int alive = PlayerSlot.size();
    for (GameObject ob : PlayerSlot) {
        if (ob.IfDead()) {
            alive -= 1;
        }
    }
    return alive;
}

int GameLoop::EnemyAliveNumber()
{
    int alive = EnemySlot.size();
    for (GameObject ob : EnemySlot) {
        if (ob.IfDead()) {
            alive -= 1;
        }
    }
    return alive;
}