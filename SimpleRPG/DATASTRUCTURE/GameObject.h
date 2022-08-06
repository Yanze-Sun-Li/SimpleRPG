#pragma once
#include <string>
#include "../CONSOLE_CONTROL/ConsoleControl.h"

class GameObject
{
public:
    int index;
    int x_position;
    int y_position;
    std::string name;
    std::string description;
    int health;
    int attack;
    int defend;
    int dodge;
    GameObject(std::string name, std::string description, int _health, int _attack, int _defend, int _dodge);
    void CopyGameObject(GameObject &target);
    GameObject();
    GameObject(std::string _name);
    ~GameObject();
    /// <summary>
    /// Take damage from other GameObject
    /// </summary>
    /// <param name="damage"> - The amount of damage</param>
    void TakeDamage(int damage);
    /// <summary>
    /// This GameObject is attacking other GameObject
    /// </summary>
    /// <param name="target"> - The target this GameObject want to attack. </param>
    void Attack(GameObject &target);
    /// <summary>
    /// Return whether this GameObject is dead.
    /// </summary>
    /// <returns>
    /// Bool if this GameObject is dead.
    /// </returns>
    bool IfDead();
    /// <summary>
    /// Cout the current state of this GameObject.
    /// </summary>
    void State(ColorControl console_color);
    /// <summary>
    /// Description of the GameObject
    /// </summary>
    void FullDescription(ColorControl console_color);
    bool IsEmpty();
    bool IsSame(GameObject& _gameObject);
    friend bool operator==(const GameObject& left, const GameObject& right);

};
