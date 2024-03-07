#include <iostream>
#include <string>
#include "cipher.h"



    const char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    std::string word;
    std::string key;
    std::string fullKey;
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

    std::string cipher::returnFullKey()
    {
        return fullKey;
    }

    std::string cipher::returnDecodedWord()
    {
        return decodedWord;
    }

    void cipher::askForInput()
    {
        std::cout << "Enter value for Word: ";
        std::getline(std::cin, word, '\n');
        std::cout << std::endl;

        std::cout << "Enter value for Key: ";
        std::getline(std::cin, key, '\n');
        std::cout << std::endl;
    }

    void cipher::calcFullKey()
    {
        std::string keyWithLength = "";
        int i = 0;
        int j = 0;
        while(keyWithLength.length() < word.length())
        {
            while(j < key.length() && i < word.length())
            {
                keyWithLength += key[j];
                ++j;
                ++i;
            }
            j = 0;
        }
        fullKey = keyWithLength;
    }

    int cipher::getAlphaNumberValue(char c)
    {
        c = std::tolower(c);
        for(int i = 0; i < 26; ++i)
        {
            if(c == alpha[i])
            {
                return i;
            }
        }
        return -1;
    }

    void cipher::encode()
    {
        std::string returnString;

        for(int i = 0; i < word.length(); ++i)
        {
            int wordValue = getAlphaNumberValue(word[i]);
            int keyValue = getAlphaNumberValue(fullKey[i]);

            int returnChar = (wordValue + keyValue);
            if(returnChar > 25)
            {
                returnChar -= 26;
            }
            
            returnString += alpha[returnChar];
        }

        decodedWord = returnString;
    }

    void cipher::decode()
    {
        std::string returnString;

        for(int i = 0; i < word.length(); ++i)
        {
            int wordValue = getAlphaNumberValue(word[i]);
            int keyValue = getAlphaNumberValue(fullKey[i]);

            int returnChar = (wordValue - keyValue);
            if(returnChar < 0)
            {
                returnChar += 26;
            }

            returnString += alpha[returnChar];
        }

        decodedWord = returnString;
    }