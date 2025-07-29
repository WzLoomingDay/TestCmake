#include <iostream>
#include "cal_math.h"

int main(){
    std::cout << "Test Add " << cal::add(1, 2) << std::endl;
    std::cout << "Test Minus " << cal::minus(1, 2) << std::endl;
    std::cout << "Test Multi " << cal::multi(1, 2) << std::endl;
    std::cout << "Test Div " << cal::div(1, 2) << std::endl;
    return 0;
}
