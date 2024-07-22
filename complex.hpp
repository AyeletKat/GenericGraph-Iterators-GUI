/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#ifndef COMPLEX_H
#define COMPLEX_H

# include <sstream>
#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>


class complex {
private:
    double real;
    double imag;
    
    //char img_sign;
public:

    complex(double r = 0, double i =0):real(r), imag(i){}
    //complex (complex c): real(c.real), imag(c.imag){}
    // N: complex constructor only real, and one empty. oerator +=, -=, ==, !=, <.
    
    double getImg(){
        return imag;
    }
    double getReal(){
        return real;
    }
    
    complex operator+(const complex& other) const;


    friend std::ostream& operator<<(std::ostream& os, complex& c){
        os.precision(2);
        os <<std::fixed << std::setprecision(2) <<std::to_string(c.getImg()) << "+ " << std::to_string(c.getReal());
        return os;
    }
    /**
     * This complex numbers are being compared based on their radius size. r^2 = x^2 + y^2. 
     */
    bool operator>( complex& other){
        return std::sqrt(real * real + imag * imag) > std::sqrt(other.real * other.real + other.imag * other.imag);
    }
        // yachas seder
    std::string toString () ;

};


#endif // COMPLEX_H
