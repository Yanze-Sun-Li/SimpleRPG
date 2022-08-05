#include "Display.h"

Display::Display(int _xGap, int _yGap)
{
	console_color = ColorControl();
	console_control = ConsoleControl();
	xGap = _xGap;
	yGap = _yGap;
	xPosition = 10;
	yPosition = yGap + yGap;
	xIndex = 0;
	yIndex = 2;
	ShowConsoleCursor(true);
}

Display::Display()
{
	console_color = ColorControl();
	console_control = ConsoleControl();
	xGap = 35;
	yGap = 10;
	xPosition = 10;
	yPosition = yGap + yGap;
	xIndex = 0;
	yIndex = 2;
	ShowConsoleCursor(true);
}

void Display::DisplayStateAtXY(int _x, int _y, GameObject &gameObject)
{
	if (gameObject.IfDead())
	{
		DisplayStateAtXY_Dead(_x,_y,gameObject);
		return;
	}
	console_control.CursorXY(_x, _y);
	console_color.White(gameObject.name.c_str());
	console_control.CursorXY(_x, _y + 1);
	console_color.White(gameObject.description.c_str());
	console_control.CursorXY(_x, _y + 2);
	console_color.Green("Health", gameObject.health);
	console_control.CursorXY(_x, _y + 3);
	console_color.Red("Attack", gameObject.attack);
	console_control.CursorXY(_x, _y + 4);
	console_color.LightBlue("Defend", gameObject.defend);
	console_control.CursorXY(_x, _y + 5);
	console_color.Gray("Dodge", gameObject.dodge);
}

void Display::DisplayStateAtXY_Selected(int _x, int _y, GameObject &gameObject)
{
	console_control.CursorXY(_x, _y);
	console_color.Green(gameObject.name.c_str());
	console_control.CursorXY(_x, _y + 1);
	console_color.Green(gameObject.description.c_str());
	console_control.CursorXY(_x, _y + 2);
	console_color.Green("Health", gameObject.health);
	console_control.CursorXY(_x, _y + 3);
	console_color.Green("Attack", gameObject.attack);
	console_control.CursorXY(_x, _y + 4);
	console_color.Green("Defend", gameObject.defend);
	console_control.CursorXY(_x, _y + 5);
	console_color.Green("Dodge", gameObject.dodge);
}

void Display::DisplayStateAtXY_Dead(int _x, int _y, GameObject& gameObject)
{
	console_control.CursorXY(_x, _y);
	console_color.DarkGray(gameObject.name.c_str());
	console_control.CursorXY(_x, _y + 1);
	console_color.DarkGray(gameObject.description.c_str());
	console_control.CursorXY(_x, _y + 2);
	console_color.DarkGray("Health", gameObject.health);
	console_control.CursorXY(_x, _y + 3);
	console_color.DarkGray("Attack", gameObject.attack);
	console_control.CursorXY(_x, _y + 4);
	console_color.DarkGray("Defend", gameObject.defend);
	console_control.CursorXY(_x, _y + 5);
	console_color.DarkGray("Dodge", gameObject.dodge);
}

void Display::DisplayEnemy(std::vector<GameObject> EnemySlot)
{
	int i = 0;
	for (GameObject object : EnemySlot)
	{
		if (!object.IfDead())
			DisplayStateAtXY(10 + i * xGap, 1, object);
		i++;
	}
}

void Display::DisplayPlayer(std::vector<GameObject> PlayerSlot)
{
	int i = 0;
	for (GameObject object : PlayerSlot)
	{
		if (!object.IfDead())
			DisplayStateAtXY(10 + i * xGap, 1 + yGap, object);
		i++;
	}
}

void Display::AwaitArea()
{
	console_control.CursorXY(xPosition, yPosition);
	console_color.White("Arrow Key to move, Space to select/de-select. C to confirm attack");
	console_control.CursorXY(xPosition, yPosition + 1);
	console_color.White("C to confirm attack");
	console_control.CursorXY(xPosition, yPosition + 2);
	console_color.Yellow("Select your unit first, then select an enemy to attack.");
	console_control.CursorXY(xPosition, yPosition + 3);
	console_color.Green("The amount of attack chances for each round increase based on how many member in the team.");
}

void Display::RepositionCursor()
{
	console_control.CursorXY(xPosition, yPosition);
}

void Display::Reposition()
{
	xPosition = 9 + xIndex * xGap;
	switch (yIndex)
	{
	case 0:
		yPosition = 1;
		break;
	case 1:
		yPosition = 1 + yGap;
		break;
	case 2:
		yPosition = 2 * yGap;
		break;
	}
}

void Display::Clean()
{
	system("cls");
}

void Display::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	cursorInfo.dwSize = 50;
	SetConsoleCursorInfo(out, &cursorInfo);
}