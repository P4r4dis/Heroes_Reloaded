#ifndef                     __KNIGHT_HPP__
    #define                 __KNIGHT_HPP__

#include "Peasant.hpp"

#define KNIGHT_ATK_COST_POWER 10
#define KNIGHT_ATK_DMG 20

#define KNIGHT_SPC_COST_POWER 30
#define KNIGHT_SPC_DMG 50

#define KNIGHT_CURE_POWER 50


class                       Knight : virtual public Peasant
{
    public:
        Knight(const std::string &name, int power);
        Knight(const Knight &obj);
        ~Knight(void);
    
        int attack(void);
        int special(void);
        void rest(void);

private:
};
#endif //                   !__KNIGHT_HPP__