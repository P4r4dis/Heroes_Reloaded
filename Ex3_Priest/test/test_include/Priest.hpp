#ifndef                     __PRIEST_HPP__
    #define                 __PRIEST_HPP__

#include "Enchanter.hpp"

#define PRIEST_BASE_CURE_HP 100
#define PRIEST_BASE_CURE_POWER 100
class                       Priest : public Enchanter
{
    public:
        Priest(const std::string &name, int power);
        Priest(const Priest &obj);
        ~Priest(void);

        void                rest(void);
};

#endif //                   !__PRIEST_HPP__