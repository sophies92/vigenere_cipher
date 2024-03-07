#include <iostream>
#include <string>
#include "cipher.h"



int main(int argc, char* argv[])
{
    cipher c;

    c.askForInput();
    std::string fullKey = c.calcFullKey();

    std::cout << c.returnWord() << std::endl;
    std::cout << c.returnKey() << std::endl;
    std::cout << fullKey << std::endl;

    return 0;
}