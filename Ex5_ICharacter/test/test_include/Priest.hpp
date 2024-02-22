#ifndef                     __PRIEST_HPP__
    #define                 __PRIEST_HPP__

#include "Enchanter.hpp"

#define PRIEST_HP 100
#define PRIEST_POWER 100

#define PRIEST_CURE_COST_POWER 0
#define PRIEST_CURE 100
class                   Priest : virtual public Enchanter
{
    public:
        Priest(const std::string &name, int power);
        Priest(const Priest &obj);
        ~Priest(void);

        void                rest(void);
};

#endif //                   !__PRIEST_HPP__