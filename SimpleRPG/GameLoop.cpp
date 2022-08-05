#include "GameLoop.h"

GameLoop::GameLoop()
{

    xGap = 35;
    yGap = 10;
    console_display = Display(xGap, yGap);

    EnemySlot = std::list<GameObject>();
    PlayerSlot = std::list<GameObject>();

    selectPlayerReference = nullptr;
    selectEnemyReference = nullptr;

    GameObject* test_1 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_2 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_3 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_4 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_5 = (GameObject*)malloc(sizeof(GameObject));
    GameObject* test_6 = (GameObject*)malloc(sizeof(GameObject));
    
    test_1 = new GameObject("Test1");
    test_2 = new GameObject("Test2");
    test_3 = new GameObject("Test3");
    test_4 = new GameObject("Test4");
    test_5 = new GameObject("Test5");
    test_6 = new GameObject("Test6");

    EnemySlot.push_back(*test_1);
    EnemySlot.push_back(*test_2);
    EnemySlot.push_back(*test_3);

    PlayerSlot.push_back(*test_4);
    PlayerSlot.push_back(*test_5);
    PlayerSlot.push_back(*test_6);


    playerSelected = false;
    enemySelected = false;
}

void GameLoop::Start()
{
   
    BattleScene();

    int i;
    std::cin >> i;
}

void GameLoop::BattleScene()
{
    // First Game Scene start here:
    console_display.DisplayEnemy(EnemySlot);
    console_display.DisplayPlayer(PlayerSlot);
    console_display.AwaitArea();

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
                selectPlayerReference->Attack(*selectEnemyReference);
                console_display.DisplayStateAtXY(selectEnemyReference->x_position + 1, selectEnemyReference->y_position, *selectEnemyReference);
                console_display.DisplayStateAtXY(selectPlayerReference->x_position + 1, selectPlayerReference->y_position, *selectPlayerReference);
                enemySelected = false;
                playerSelected = false;
            }
            Sleep(250);
        }
    }
}


void GameLoop::SelectEnemy()
{
    selectEnemyReference = IndexOf(EnemySlot, console_display.xIndex);

    if (enemySelected && !selectEnemyReference->IsSame(*selectEnemyReference)) {
        return;
    }
    if (selectEnemyReference->IfDead()) {
        return;
    }

    selectEnemyReference->x_position = console_display.xPosition;
    selectEnemyReference->y_position = console_display.yPosition;
    
    enemySelected = !enemySelected;
    if (enemySelected) {
        console_display.DisplayStateAtXY_Selected(console_display.xPosition + 1,
            console_display.yPosition, *selectEnemyReference);
    }
    else
    {
        console_display.DisplayStateAtXY(console_display.xPosition + 1,
            console_display.yPosition, *selectEnemyReference);
    }

}

void GameLoop::SelectPlayer()
{
    selectPlayerReference = IndexOf(PlayerSlot, console_display.xIndex);

    if (playerSelected && !selectPlayerReference->IsSame(*selectPlayerReference)) {
        return;
    }
    if (selectPlayerReference->IfDead()) {
        return;
    }
    selectPlayerReference->x_position = console_display.xPosition;
    selectPlayerReference->y_position = console_display.yPosition;

    playerSelected = !playerSelected;
    if (playerSelected) {
        console_display.DisplayStateAtXY_Selected(console_display.xPosition + 1,
            console_display.yPosition, *selectPlayerReference);
    }
    else
    {
        console_display.DisplayStateAtXY(console_display.xPosition + 1,
            console_display.yPosition, *selectPlayerReference);
    }
}

GameObject* GameLoop :: IndexOf(std::list<GameObject> targetList,int _index) {
    
    // Create iterator pointing to first element
    std::list<GameObject>::iterator it = targetList.begin();
    
    // Advance the iterator by 2 positions,
    std::advance(it, _index);

    return &(*it);

}
