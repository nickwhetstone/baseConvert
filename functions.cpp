#include <iostream>
#include "functions.h"

void baseConvert()
{
    int num, base, mod;
    // Digits 0-9, A-Z, a-z
    std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", go;
    std::cout << "Welcome to BaseConvert. Please input the number whose base you'd like to change." << std::endl;
    do {
        std::cout << "Number: ";
        std::cin >> num;
        while(!std::cin)
        {
            std::cin.clear(), std::cin.ignore();
            std::cout << "Invalid input. Please input an integer." << std::endl;
            std::cin >> num;
        }
        int number = num;
        std::cout << "Base: ";
        std::cin >> base;
        std::string final = "";
        // Unary case
        if (base == 1)
            for(int i=0; i<num; i++)
                final += "1";
        // Other cases
        else
            while( number != 0 ) {
                mod = number % base;
                number /= base;
                final = digits.substr(mod, 1)+final;
            }
        std::cout << num << " base " << base << " is: " << final << "." << std::endl << "If you'd like to convert another number, input 'yes'; to return to the main menu, input 'no'." << std::endl;
        std::cin >> go;
    } while (go == "yes");
    mainMenu();
}

void mainMenu()
{
    char select;
    std::cout << "Welcome to baseConvert! What would you like to do?" << std::endl <<
    "C: Convert" << std::endl <<
    "X: Exit" << std::endl;
    std::cin >> select;
    while (true)
    {
        switch (select)
        {
            case 'C':
                baseConvert();
                break;
            case 'X':
                exit(EXIT_SUCCESS);
                break;
            default: std::cout << "Error: Try again." << std::endl;
                     mainMenu()
                     break;
        }
    }
}
