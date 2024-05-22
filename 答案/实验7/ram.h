#pragma once

//#ifndef __ram__
//#define __ram__

enum RAM_RANK { DDR = 1, DDR2 = 2, DDR3 = 3, DDR4 = 4 };

class RAM
{
private:
    RAM_RANK rr;
    int memory;
    float frequency;
public:
    RAM() = default;
    RAM(int rank, int m, float f);
    RAM(const RAM& r);
    ~RAM();

    RAM_RANK GetRank()const;
    float GetFrequency()const;
    int GetMemory()const;
    void print()const;
    void run()const;
    void stop()const;
};

//#endif