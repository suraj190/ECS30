#include <iostream>
#include "PolynomialDiv.h"

int main() {

    PolynomialDiv polo("4x^3+2x^2-6x+3","x-3");
    polo.dividePolynomial();


    return 0;
}