#include <iostream>
#include <string>
#include "cipher.h"



    std::string word;
    std::string key;
    std::string decodedWord;




    cipher::cipher()
    {
        
    }




    std::string cipher::returnWord()
    {
        return word;
    }

    std::string cipher::returnKey()
    {
        return key;
    }

    std::string cipher::returnReturnWord()
    {
        return decodedWord;
    }

    void cipher::askForInput()
    {
        std::cout << "Enter value for Word: ";
        std::cin >> word;
        std::cout << std::endl;

        std::cout << "Enter value for Key: ";
        std::cin >> key;
        std::cout << std::endl;
    }

    std::string cipher::calcFullKey()
    {
        std::string fullKey = "";
        int i = 0;
        int j = 0;
        while(fullKey.length() < word.length())
        {
            while(j < key.length() && i < word.length())
            {
                fullKey += key[j];
                ++j;
                ++i;
            }
            j = 0;
        }
        return fullKey;
    }
