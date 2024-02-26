#ifndef                             __ICHARACTER_HPP__
    #define                         __ICHARACTER_HPP__

#include "Peasant.hpp"


class                               ICharacter
{
    public:
        virtual int                 attack(void) = 0;
        virtual int                 special(void) = 0;
        virtual void                rest(void) = 0;

        virtual void                damage(int damage) = 0;

        virtual int                 getPower(void) const = 0;
        virtual int                 getHp(void) const = 0;
        virtual const std::string   &getName() const = 0;
};

#endif //                           !__ICHARACTER_HPP__