#pragma once
#include <Windows.h>
#include <iostream>
/// <summary>
/// Control output color
/// </summary>
class ColorControl
{
public:
	/// <summary>
	/// Print text that have color Yellow
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void Yellow(const char *text);
	void Yellow(int text);
	void Yellow(const char *text, int value);
	/// <summary>
	/// Print text that have color Green
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void Green(const char *text);
	void Green(int text);
	void Green(const char *text, int value);
	/// <summary>
	/// Print text that have color LightBlue
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void LightBlue(const char *text);
	void LightBlue(int text);
	void LightBlue(const char *text, int value);
	/// <summary>
	/// Print text that have color White
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void White(const char *text);
	void White(int text);
	void White(const char *text, int value);
	/// <summary>
	/// Print text that have color Gray
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void Gray(const char *text);
	void Gray(int text);
	void Gray(const char *text, int value);
	/// <summary>
	/// Print text that have color DarkGray
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void DarkGray(const char *text);
	void DarkGray(int text);
	void DarkGray(const char *text, int value);
	/// <summary>
	/// Print text that have color Red
	/// </summary>
	/// <param name="text"> - The sentences you want to color</param>
	void Red(const char *text);
	void Red(int text);
	void Red(const char *text, int value);
	ColorControl();

private:
	// Color of the console
	HANDLE console_color;
};

class ConsoleControl
{
public:
	/// <summary>
	/// Control the movement of Cursor.
	/// </summary>
	/// <param name="x"> - Position X</param>
	/// <param name="y"> - Position Y</param>
	void CursorXY(int x, int y);

private:
};
