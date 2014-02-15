//
//  main.cpp
//  Val Too Big Demo
//
//  Created by Kelsey Breseman on 2/15/14.
//  Copyright (c) 2014 Kelsey Breseman. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{

    unsigned short int smallNumber;
    smallNumber = 65535;
    std::cout << "small number: " << smallNumber << std::endl;
    smallNumber++;
    std::cout << "small number: " << smallNumber << std::endl;
    smallNumber++;
    std::cout << "small number: " << smallNumber << std::endl;
    
    return 0;
}