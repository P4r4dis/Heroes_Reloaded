#ifndef                     __PALADIN_HPP__
    #define                 __PALADIN_HPP__

#include "Knight.hpp"
#include "Priest.hpp"
#include "Enchanter.hpp"
class                       Paladin : public Knight, public Priest
{
    public:
        Paladin(const std::string &name, int power);
        Paladin(const Paladin &obj);
        ~Paladin(void);
};
#endif //                   !__PALADIN_HPP__