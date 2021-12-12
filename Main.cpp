#include "stdafx.h"
using namespace Math;

void prtMatrix(Matrix a) {
    for(auto i : a.buffer) {
        for(auto j : i) std::cout << j << ' ';
        std::cout << std::endl;
    }
    std::cout << "=============\n";
}

int main()
{
    Matrix a({
        {3, 4, 5}, 
        {9, 2, 4}, 
        {5, 2, 5}
    });
    prtMatrix(a);
    Matrix b({
        {1, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 1}
    });
    prtMatrix(b);

    a = a * b;
    prtMatrix(a);
    a = a + b;
    prtMatrix(a);
    a = a - b;
    prtMatrix(a);
    a *= 10.f;
    prtMatrix(a);
    a /= 10.f;
    prtMatrix(a);

    return 0;
}