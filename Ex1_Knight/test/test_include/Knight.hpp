#ifndef                     __KNIGHT_HPP__
    #define                 __KNIGHT_HPP__

#include "Peasant.hpp"

#define KNIGHT_ATK_COST_POWER 10
#define KNIGHT_ATK_DMG 20


class                       Knight : public Peasant
{
    public:
        Knight(const std::string &name, int power);
        Knight(const Knight &obj);
        ~Knight(void);
    private:
};
#endif //                   !__KNIGHT_HPP__