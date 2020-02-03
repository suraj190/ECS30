//
// Created by Suraj M on 2/19/18.
//

#ifndef POLYNOMIAL_DIVISION_POLYNOMIALDIV_H
#define POLYNOMIAL_DIVISION_POLYNOMIALDIV_H
#include <string>
#include <iostream>


class PolynomialDiv {

public:
    PolynomialDiv(std::string poly1, std::string poly2);
    void dividePolynomial();
    void getRemainder();
    void getQuotient();



private:
    void convertStringtoInt(std::string& poly1,std::string& poly2);
    std::string poly1,poly2;
    int cpoly1,cpoly2;
};


#endif //POLYNOMIAL_DIVISION_POLYNOMIALDIV_H
