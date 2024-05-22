#include<iostream>
#include"computer.h"

COMPUTER::COMPUTER()
{
    std::cout << "COMPUTER default constructor\n";
}

COMPUTER::COMPUTER(const COMPUTER& cp)
{
    c = cp.c;
    r = cp.r;
    price = cp.price;
    std::cout << "COMPUTER copy constructor\n";
}

COMPUTER::~COMPUTER()
{
    std::cout << "COMPUTER distructor\n";
}

COMPUTER::COMPUTER(const CPU& xc, const RAM& xr, int p)
{
    price = p;
    c = xc;
    r = xr;
    std::cout << "COMPUTER constructor with RMB " << price << " yuan" << std::endl;
}

void COMPUTER::SetComputer(const CPU& xc, const RAM& xr, int p)
{
    price = p;
    c = xc;
    r = xr;
    std::cout << "COMPUTER set with RMB " << price << " yuan" << std::endl;
}

void COMPUTER::print()const
{
    std::cout << "my computer's datasheet is listed as follows:\n";
    c.print();
    r.print();
    std::cout << "its price is" << price << "yuan\n";
}

void COMPUTER::run()const
{
    std::cout << "computer is running\n";
}

void COMPUTER::stop()const
{
    std::cout << "computer stop!\n";
}