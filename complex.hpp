/*
Email adress: ayeletk03@gmail.com
ID: 325408409
*/
#ifndef COMPLEX_H
#define COMPLEX_H

# include <sstream>

class complex {
private:
    double real;
    double imag;
    //char img_sign;
public:

    complex(double r, double i);
    // N: complex constructor only real, and one empty. oerator +=, -=, ==, !=, <.
    

    double getImg() const;
    double getReal() const;
    // Other operations...
    
    complex operator+(const complex& other) const;
    friend std::ostream &operator<<(std::ostream &stream, const complex &num);
    bool operator<(const complex& other) const; // yachas seder
};

#endif // COMPLEX_H
