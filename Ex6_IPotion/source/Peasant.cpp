#include "../include/Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)    :   _name(name),
                                                            _hp(PEASANT_HP)
{
    if (power > PEASANT_POWER)
        _power = PEASANT_POWER;
    else if (power < 0)
        _power = 0;
    else
        _power = power;
    std::cout   << _name << " goes for an adventure." << std::endl;
}

Peasant::Peasant(const Peasant &obj)    :   _name(obj._name), _hp(obj._hp),
                                            _power(obj._power)
{}

Peasant::~Peasant(void)
{
    std::cout   << _name << " is back to his crops." << std::endl;
}

const std::string       &Peasant::getName(void) const
{
    return _name;
}

int                     Peasant::getHp(void) const
{
    return _hp;
}

int                     Peasant::getPower(void) const
{
    return _power;
}

void                    Peasant::setHp(int hp)
{
    if (hp > PEASANT_HP)
        _hp = PEASANT_HP;
    else if (hp < 0)
        _hp = 0;
    else
        _hp = hp;
}

void                    Peasant::setPower(int power)
{
    if (power > PEASANT_POWER)
        _power = PEASANT_POWER;
    else if (power < 0)
        _power = 0;
    else
        _power = power;
}

bool                    Peasant::isOutForAtk(void)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is out of combat." << std::endl;
        return true;
    }
    else if (_power < PEASANT_ATK_COST_POWER)
    {
        std::cout << _name << " is out of power." << std::endl;
        return true;
    }

    return false;
}

bool                    Peasant::isOutForSpc(void)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is out of combat." << std::endl;
        return true;
    }
    else if (_power == 0 || _power < PEASANT_SPC_COST_POWER)
    {
        std::cout << _name << " is out of power." << std::endl;
        return true;
    }

    return false;
}

bool                    Peasant::isOutForRest(void)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is out of combat." << std::endl;
        return true;
    }

    return false;
}

int                     Peasant::attack(void)
{
    if (isOutForAtk() == false)
    {
        setPower(_power - PEASANT_ATK_COST_POWER);
        std::cout << _name << " tosses a stone." << std::endl;
        return PEASANT_ATK_DAMAGE;
    }
    else
        return 0;
}

int                     Peasant::special(void)
{
    if (isOutForSpc() == false)
    {
        setPower(_power - PEASANT_SPC_COST_POWER);
        std::cout << _name << " doesn't know any special move." << std::endl;
        return PEASANT_SPC_DAMAGE;
    }
    else
        return 0;
}

void                    Peasant::rest(void)
{
    if (isOutForRest() == false)
    {
        setPower(_power + PEASANT_CURE_POWER);
        setHp(_hp + 0);
        std::cout << _name << " takes a nap." << std::endl;
    }
}

void                    Peasant::damage(int damage)
{
    if (_hp > 0)
    {
        setHp(_hp - damage);
        (_hp <= 0) ? std::cout << _name << " is out of combat." << std::endl :
        std::cout << _name << " takes " << damage << " damage." << std::endl;

        if (_hp <= 0)
            std::cout << _name << " is out of combat." << std::endl;
    }
    else
        std::cout << _name << " is out of combat." << std::endl;

}