#ifndef                 __ENCHANTER_HPP__
    #define             __ENCHANTER_HPP__

#include "Peasant.hpp"

class                   Enchanter : public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        Enchanter(const Enchanter &obj);
        ~Enchanter(void);
};
#endif //               !__ENCHANTER_HPP__