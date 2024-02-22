#ifndef                     __PALADIN_HPP__
    #define                 __PALADIN_HPP__

#include <iostream>
#include "Knight.hpp"
#include "Priest.hpp"

#define PALADIN_HP 100
#define PALADIN_POWER 100

class                       Paladin : virtual public Knight, virtual public Priest
{
    public:
        Paladin(const std::string &name, int power);
        Paladin(const Paladin &obj);
        ~Paladin(void);

        int                 attack(void);
        int                 special(void);
        void                rest(void);
    private:
};
#endif //                   !__PALADIN_HPP__