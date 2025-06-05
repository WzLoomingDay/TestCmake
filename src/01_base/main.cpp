#include "add.h"
#include <iostream>

int main(){
    int a = 1;
    int b = 2;
    int c = cal::add(a, b);
    std::cout << "Test Add " << a << " + " << b << " = " << c << std::endl;
    return 0;
}