# include "complex.hpp"
# include <cmath>


double complex::getImg() const{
    return this->imag;
}
double complex::getReal() const{
    return this->real;
}


std::ostream &operator<<(std::ostream &stream, const complex &num){
        double number = num.getImg();
        if (number > 0) return (stream << num.getReal() << "+" << num.getImg() << "i");
        else if (number < 0) return (stream << num.getReal() << num.getImg() << "i");
        else return (stream << num.getReal());// imaginary part = 0
}


complex complex::operator+(const complex& other) const {
    return complex((this->getReal() + other.getReal()), (this->getImg() + other.getImg()));
}

bool complex::operator<(const complex& other) const{
    return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
}

