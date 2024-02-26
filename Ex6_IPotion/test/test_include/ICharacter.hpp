#ifndef                             __ICHARACTER_HPP__
    #define                         __ICHARACTER_HPP__

#include <iostream>

#include "PoisonPotion.hpp"
#include "PowerPotion.hpp"
#include "HealthPotion.hpp"

class                               ICharacter
{
    public:
        ICharacter(void);
        virtual ~ICharacter(void);

        virtual int                 attack(void) = 0;
        virtual int                 special(void) = 0;
        virtual void                rest(void) = 0;

        virtual void                damage(int damage) = 0;

        virtual int                 getPower(void) const = 0;
        virtual int                 getHp(void) const = 0;
        virtual const std::string   &getName() const = 0;
        
        virtual void                drink(const PoisonPotion& potion) = 0;
        virtual void                drink(const PowerPotion& potion) = 0;
        virtual void                drink(const HealthPotion& potion) = 0;
};

#endif //                           !__ICHARACTER_HPP__