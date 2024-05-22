#pragma once

//˵����΢������#pragma once ����ͷ�ļ�ֻ����һ�Σ���˲���Ҫ��������

// #ifndef __cpu__
//#define __cpu__

enum CPU_RANK { i3 = 3, i5 = 5, i7 = 7, i9 = 9 };

class CPU
{
private:
    CPU_RANK cr;
    int frequency;
    float voltage;
public:
    CPU();
    CPU(int c, int f, float v);
    CPU(const CPU& c);
    ~CPU();
    CPU_RANK GetRank()const;
    int GetFrequency()const;
    float GetVoltage()const;
    void SetRank(CPU_RANK r);
    void SetFrequency(int f);
    void SetVoltage(float v);
    void print()const;
    void run()const;
    void stop()const;
};

//#endif