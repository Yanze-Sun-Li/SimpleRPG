#include "GameObject.h"

GameObject::GameObject(std::string _name, std::string _description, int _health, int _attack, int _defend, int _dodge)
{
    name = _name;
    description = _description;
    health = _health;
    attack = _attack;
    defend = _defend;
    dodge = _dodge;
}
GameObject::GameObject()
{
    name = "";
    description = "";
    health = 0;
    attack = 0;
    defend = 0;
    dodge = 0;
}

GameObject::GameObject(std::string _name)
{
    name = _name;
    description = "Test Object";
    health = 1;
    attack = 1;
    defend = 1;
    dodge = 1;
}

void GameObject::CopyGameObject(GameObject &target)
{
    name = target.name;
    description = target.description;
    health = target.health;
    attack = target.attack;
    defend = target.defend;
    dodge = target.dodge;
}

GameObject::~GameObject()
{
}

void GameObject::TakeDamage(int _damage)
{
    if (_damage <= defend)
    {
        _damage = 1;
    }
    else
    {
        _damage -= defend;
    }

    health -= _damage;

}

void GameObject::Attack(GameObject &target)
{
    target.TakeDamage(attack);

}

bool GameObject::IfDead()
{
    return health <= 0 ? true : false;
}

void GameObject::State(ColorControl console_color)
{
    console_color.White(name.c_str());
    console_color.Green("Health", health);
    console_color.Red("Attack", attack);
    console_color.LightBlue("Defend", defend);
    console_color.Gray("Dodge", dodge);
}

void GameObject::FullDescription(ColorControl console_color)
{
    console_color.White(name.c_str());
    console_color.White(description.c_str());
    console_color.Green("Health", health);
    console_color.Red("Attack", attack);
    console_color.LightBlue("Defend", defend);
    console_color.Gray("Dodge", dodge);
}

bool GameObject::IsEmpty() {
    return name == "" &&
        description == "" &&
        health == 0 &&
        attack == 0 &&
        defend == 0 &&
        dodge == 0 ? true : false;
}

bool GameObject::IsSame(GameObject& _gameObject)
{
    return name == _gameObject.name &&
        description == _gameObject.description &&
        health == _gameObject.health &&
        attack == _gameObject.attack &&
        defend == _gameObject.defend &&
        dodge == _gameObject.dodge ? true : false;
}

bool operator==(const GameObject& left, const GameObject& right)
{
    return left.name == right.name &&
        left.description == right.description &&
        left.health == right.health &&
        left.attack == right.attack &&
        left.defend == right.defend &&
        left.dodge == right.dodge ? true : false;
}
