#include <iostream>

void baseConvert();

int main()
{
    baseConvert();
    return 0;
}

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
        std::cout << num << " base " << base << " is: " << final << "." << std::endl << "If you'd like to convert another number, input 'yes'; otherwise, input 'no'." << std::endl;
        std::cin >> go;
    } while (go == "yes");
    std::cout << "Thank you for using BaseConvert. Have a nice day." << std::endl;
}