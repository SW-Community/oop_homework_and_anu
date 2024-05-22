// 实验3-2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

enum CPU_RANK { i3=3, i5=5, i7=7, i9=9 };

class CPU
{
private:
    CPU_RANK cr;
    int frequency;
    float voltage;
public:
    CPU_RANK GetRank();
    int GetFrequency();
    float GetVoltage();
    void SetRank(CPU_RANK r);
    void SetFrequency(int f);
    void SetVoltage(float v);
    void print();
    void run();
    void stop();
};

CPU_RANK CPU::GetRank() { return cr; }
int CPU::GetFrequency() { return frequency; }
float CPU::GetVoltage() { return voltage; }
void CPU::SetRank(CPU_RANK r) { cr = r; }
void CPU::SetFrequency(int f) { frequency = f; }
void CPU::SetVoltage(float v) { voltage = v; }
void CPU::print() { std::cout << "Intel(R)  Core(TM) CPU i" << cr <<" @ "<<frequency<<"MHz，电压："<<voltage<<"V\n" ; }
void CPU::run() { std::cout << "开始挖矿" << std::endl; }
void CPU::stop() { std::cout << "CPU挂了，花钱重新买台电脑吧" << std::endl; }
int main()
{
    CPU thispc;
    thispc.SetRank(i5);
    thispc.SetFrequency(2110);
    thispc.SetVoltage(1.097);
    CPU_RANK x = thispc.GetRank();
    int  f = thispc.GetFrequency();
    int v = thispc.GetVoltage();
    std::cout << x << " " << f << " " << v << std::endl;
    thispc.print();
    thispc.run();
    thispc.stop();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
