#ifndef units_h
#define units_h

#include <ostream>
#include <sstream>
#include <string>

//cereal
#include <cereal/cereal.hpp>

namespace units
{

typedef double NT;   // Number Type

template<int U1, int U2, int U3, int U4>
class Units
{
    public:
        Units(NT value_=NT(0)) : value(value_) {}

        // This turns the class into a function object that allows
        // the user to easily get at the value.
        NT operator()() const { return value; }

        // Helper function to get a text representation of the
        // object's dimensions.  It is static because the
        // representation is known at compile time.
        static std::string dim(void)
        {
            std::stringstream s;
            s << "<" << U1 << ","<< U2 << ","<< U3 << ","<< U4 << ">";
            return s.str();
        }

        // Helper function for unit conversions.
        NT to(const Units & u) const
        {
            return value/u.value;
        }

        Units & operator=(const Units & rhs)
        {
            value = rhs.value;
            return *this;
        }

        // Arithmetic operators
        Units & operator+=(const Units & rhs)
        {
            value += rhs.value;
            return *this;
        }

        Units & operator-=(const Units & rhs)
        {
            value -= rhs.value;
            return *this;
        }

        Units & operator*=(const NT & rhs)
        {
            value *= rhs;
            return *this;
        }

        Units & operator/=(const NT & rhs)
        {
            value /= rhs;
            return *this;
        }

        //SERIALIZATIoN
        template<class Archive>
        void serialize(Archive & ar) {
            ar(value);
        }
    private:
        NT value;
};


// Addition
template <int U1, int U2, int U3, int U4>
const Units<U1, U2, U3, U4> operator+(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return Units<U1, U2, U3, U4>(lhs() + rhs());
}


// Subtraction
template <int U1, int U2, int U3, int U4>
const Units<U1, U2, U3, U4> operator-(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return Units<U1, U2, U3, U4>(lhs() - rhs());
}


// Multiplication
template <int U1, int U2, int U3, int U4>
const Units<U1, U2, U3, U4> operator*(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return Units<U1, U2, U3, U4>(lhs*rhs());
}

template <int U1, int U2, int U3, int U4>
const Units<U1, U2, U3, U4> operator*(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return rhs*lhs;
}

template <int U1a, int U2a, int U3a, int U4a, int U1b, int U2b, int U3b, int U4b>
const Units<U1a+U1b, U2a+U2b, U3a+U3b, U4a+U4b> operator*(const Units<U1a, U2a, U3a, U4a> & lhs, const Units<U1b, U2b, U3b, U4b> & rhs)
{
    return Units<U1a+U1b, U2a+U2b, U3a+U3b, U4a+U4b>(lhs()*rhs());
}


// Division
template <int U1, int U2, int U3, int U4>
const Units<U1, U2, U3, U4> operator/(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return Units<U1, U2, U3, U4>(lhs()/rhs);
}

template <int U1, int U2, int U3, int U4>
const Units<-U1, -U2, -U3, -U4> operator/(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return Units<-U1, -U2, -U3, -U4>(lhs/rhs());
}

template <int U1a, int U2a, int U3a, int U4a, int U1b, int U2b, int U3b, int U4b>
const Units<U1a-U1b, U2a-U2b, U3a-U3b, U4a-U4b> operator/(const Units<U1a, U2a, U3a, U4a> & lhs, const Units<U1b, U2b, U3b, U4b> & rhs)
{
    return Units<U1a-U1b, U2a-U2b, U3a-U3b, U4a-U4b>(lhs()/rhs());
}


// Comparisons
template <int U1, int U2, int U3, int U4>
bool operator==(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs() == rhs());
}

template <int U1, int U2, int U3, int U4>
bool operator==(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return (lhs() == rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator==(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs == rhs());
}

template <int U1, int U2, int U3, int U4>
bool operator!=(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return not (lhs() == rhs());
}

template <int U1, int U2, int U3, int U4>
bool operator!=(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return not (lhs() == rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator!=(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return not (lhs == rhs());
}


// Ordering
template <int U1, int U2, int U3, int U4>
bool operator<=(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return lhs() <= rhs();
}

template <int U1, int U2, int U3, int U4>
bool operator<=(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return (lhs() <= rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator<=(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs <= rhs());
}


template <int U1, int U2, int U3, int U4>
bool operator>=(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return lhs() >= rhs();
}

template <int U1, int U2, int U3, int U4>
bool operator>=(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return (lhs() >= rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator>=(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs >= rhs());
}


template <int U1, int U2, int U3, int U4>
bool operator<(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return lhs() < rhs();
}

template <int U1, int U2, int U3, int U4>
bool operator<(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return (lhs() < rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator<(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs < rhs());
}


template <int U1, int U2, int U3, int U4>
bool operator>(const Units<U1, U2, U3, U4> & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return lhs() > rhs();
}

template <int U1, int U2, int U3, int U4>
bool operator>(const Units<U1, U2, U3, U4> & lhs, const NT & rhs)
{
    return (lhs() > rhs);
}

template <int U1, int U2, int U3, int U4>
bool operator>(const NT & lhs, const Units<U1, U2, U3, U4> & rhs)
{
    return (lhs > rhs());
}

template <int U1, int U2, int U3, int U4>
std::ostream & operator<<(std::ostream & s, const Units<U1, U2, U3, U4> & rhs)
{
    return s << rhs() << rhs.dim();
}

// operator>> is not provided because the unit type can not be
// created at runtime in any reasonable fashion.  This means there is
// no easy way to serialize unit objects.
//
// If you need to read in an object from a stream, read it into an NT
// variable and put it into an appropriate-type variable.  Example:
//
//      NT x;
//      cin >> x;
//      Length y = x*m;
//
// where the base unit m has already been defined.  This requires you
// to i) know the unit type at compile time and ii) assume its value
// is in terms of the base type.

// Typedefs for fundamental units
typedef units::Units<1,0,0,0> Volume;
typedef units::Units<0,1,0,0> Time;
typedef units::Units<0,0,1,0> Temperature;
typedef units::Units<0,0,0,1> LuminousIntensity;

// Typedefs for derived units
typedef units::Units<1,-1,0,0> Volumetric_Flow;
typedef units::Units<0,-1,0,0> Frequency;

// Unit constants
const Volume l = 1;
const Time s = 1;
const Frequency Hz = 1;
const Temperature K = 1;
const LuminousIntensity cd = 1;
const Temperature C = 274.15*K;
const Volume ml = 1e-3*l;
const Volume ul = 1e-6*l;
const Volume nl = 1e-9*l;
const Frequency kHz = 1e3*Hz;
const Frequency MHz = 1e6*Hz;
const Time minute = 60*s;
const Time hr = 3600*s;

} // namespace units

#endif //#ifndef units_h
