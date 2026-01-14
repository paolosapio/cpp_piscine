#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

# include <iostream>

class Fixed 
{
private:
    int _fpn; //fixed point number
    static const int fractional = 8; // static es como una global

public:
    Fixed();                              // Default Constructor
    Fixed(const Fixed &other);            // Copy Constructor
    Fixed &operator=(const Fixed &other); // Copy Assignment Operator
    ~Fixed();                             // Destructor

    int getRawBits(void) const;           //geter
    void setRawBits(int const raw);        //seter
};

#endif