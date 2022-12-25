#include <iostream>
#include <complex>
#include "Line.h"

int main(){
    Line<float> l1(5);
    for (int i = 0; i < l1.size(); i++) {
        l1[i] = Point<float>(i+1, i+2);
    }

    Line<float> l2(5);
    for (int i = 0; i < l2.size(); i++) {
        l2[i] = Point<float>(i - 2, i - 1);
    }

    Line<float> l3 = l1 + l2;
    for (int i = 0; i < l3.size(); i++) {
        std::cout << "(" << l3[i].x << ", " << l3[i].y << ")\n";
    }

    std::cout << "\n";
    std::cout << "Line1: " << l1.lenght() << "\n"
        << "Line2: " << l2.lenght() << "\n"
        << "Line3: " << l3.lenght() << "\n";

    return 0;
}
