/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
# include "complex.hpp"
# include <cmath>


complex complex::operator+(const complex& other) const {
    return complex(real+ other.real), (real + other.imag);
}

std::string complex::toString()  {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << real << (imag >= 0 ? "+" : "") << imag << "i";
        return oss.str();
}



