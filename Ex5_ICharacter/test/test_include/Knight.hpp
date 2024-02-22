#ifndef                     __KNIGHT_HPP__
    #define                 __KNIGHT_HPP__

#include <iostream>
#include "Peasant.hpp"

#define KNIGHT_HP 100
#define KNIGHT_POWER 100

#define KNIGHT_ATK_COST_POWER 10
#define KNIGHT_ATK_DAMAGE 20

#define KNIGHT_SPC_COST_POWER 30
#define KNIGHT_SPC_DAMAGE 50

#define KNIGHT_CURE_COST_POWER 0
#define KNIGHT_CURE_POWER 50

class                       Knight : virtual public Peasant
{
    public:
        Knight(const std::string &name, int power);
        Knight(const Knight &obj);
        ~Knight(void);

        int                 attack(void);
        int                 special(void);
        void                rest(void);

        bool                isOutForAtk(void);
        bool                isOutForSpc(void);
        bool                isOutForRest(void);


    private:
};
#endif //                   !__KNIGHT_HPP__