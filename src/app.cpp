#include <iostream>
#include <string>
#include "cipher.h"



int main(int argc, char* argv[])
{
    cipher c;
    char choice;

    std::cout << "E - encode word" << std::endl << "D - decode word" << std::endl;
    choice = std::getchar();
    choice = std::toupper(choice);
    std::cin.ignore(INT64_MAX, '\n');

    c.askForInput();
    c.calcFullKey();

    std::cout << c.returnWord() << std::endl;
    std::cout << c.returnKey() << std::endl;
    std::cout << c.returnFullKey() << std::endl;

    switch (choice)
    {
        case 'E':
            c.encode();
            break;
        case 'D':
            c.decode();
            break;
        default:
            std::cout << "invalid choice entered" << std::endl;
            break;
    }
    std::cout << c.returnDecodedWord() << std::endl;


    return 0;
}