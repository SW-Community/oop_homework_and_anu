#pragma once
#include"cpu.h"
#include"ram.h"

class CPU;
class RAM;

class COMPUTER
{
private:
    int price;
    CPU c;
    RAM r;
public:
    COMPUTER();
    COMPUTER(const COMPUTER& cp);
    COMPUTER(const CPU& xc, const RAM& xr, int p);
    ~COMPUTER();
    void SetComputer(const CPU& xc, const RAM& xr, int p);
    void print()const;
    void run()const;
    void stop()const;
};