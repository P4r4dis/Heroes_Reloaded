#ifndef                     __PALADIN_HPP__
    #define                 __PALADIN_HPP__

#include "Knight.hpp"
#include "Priest.hpp"
#include "Enchanter.hpp"
class                       Paladin :  virtual public Knight,  virtual public Priest
{
    public:
        Paladin(const std::string &name, int power);
        Paladin(const Paladin &obj);
        ~Paladin(void);
        
        int                 attack(void);
};
#endif //                   !__PALADIN_HPP__