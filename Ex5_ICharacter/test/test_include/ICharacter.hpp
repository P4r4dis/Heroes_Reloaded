#ifndef                 __ICHARACTER_HPP__
    #define             __ICHARACTER_HPP__

#include "Peasant.hpp"


class                   ICharacter
{
    public:
        virtual int     attack(void) = 0;
        virtual int     special(void) = 0;
    private:
};

#endif //               !__ICHARACTER_HPP__