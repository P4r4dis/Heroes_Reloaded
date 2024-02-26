#ifndef                             __IPOTION_HPP__
    #define                         __IPOTION_HPP__

#include <iostream>

class                               IPotion
{
    public:
        IPotion(void);
        virtual ~IPotion(void);

        virtual int getValuePotion(void) const = 0;
};

#endif //                           !__IPOTION_HPP__