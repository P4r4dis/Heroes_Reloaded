#ifndef                     __PRIEST_HPP__
    #define                 __PRIEST_HPP__

#include "Enchanter.hpp"

class                       Priest : public Enchanter
{
    public:
        Priest(const std::string &name, int power);
        Priest(const Priest &obj);
        ~Priest(void);
};

#endif //                   !__PRIEST_HPP__