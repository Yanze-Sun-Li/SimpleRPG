#include "ConsoleControl.h"

using std::cout;
using std::endl;
void ColorControl::Yellow(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 6);
    cout << text << endl;
}

void ColorControl::Yellow(int text)
{
    SetConsoleTextAttribute(
        console_color, 6);
    cout << text << endl;
}

void ColorControl::Yellow(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 6);
    cout << text << ": " << value << endl;
}

void ColorControl::Green(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 10);
    cout << text << endl;
}
void ColorControl::Green(int text)
{
    SetConsoleTextAttribute(
        console_color, 10);
    cout << text << endl;
}

void ColorControl::Green(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 10);
    cout << text << ": " << value << endl;
}

void ColorControl::Green(const char* text, int value, const char* _text, int _value)
{
    SetConsoleTextAttribute(
        console_color, 10);
    cout << text << ": " << value << _text << _value <<  endl;
}

void ColorControl::LightBlue(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 11);
    cout << text << endl;
}
void ColorControl::LightBlue(int text)
{
    SetConsoleTextAttribute(
        console_color, 11);
    cout << text << endl;
}

void ColorControl::LightBlue(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 11);
    cout << text << ": " << value << endl;
}

void ColorControl::White(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 15);
    cout << text << endl;
}
void ColorControl::White(int text)
{
    SetConsoleTextAttribute(
        console_color, 15);
    cout << text << endl;
}

void ColorControl::White(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 15);
    cout << text << ": " << value << endl;
}

void ColorControl::Gray(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 7);
    cout << text << endl;
}
void ColorControl::Gray(int text)
{
    SetConsoleTextAttribute(
        console_color, 7);
    cout << text << endl;
}

void ColorControl::Gray(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 7);
    cout << text << ": " << value << endl;
}

void ColorControl::DarkGray(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 8);
    cout << text << endl;
}
void ColorControl::DarkGray(int text)
{
    SetConsoleTextAttribute(
        console_color, 8);
    cout << text << endl;
}

void ColorControl::DarkGray(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 8);
    cout << text << ": " << value << endl;
}

void ColorControl::Red(const char *text)
{
    SetConsoleTextAttribute(
        console_color, 12);
    cout << text << endl;
}
void ColorControl::Red(int text)
{
    SetConsoleTextAttribute(
        console_color, 12);
    cout << text << endl;
}

void ColorControl::Red(const char *text, int value)
{
    SetConsoleTextAttribute(
        console_color, 12);
    cout << text << ": " << value << endl;
}

ColorControl::ColorControl()
{
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
}

void ConsoleControl::CursorXY(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
