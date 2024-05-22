// 实验4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

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
    CPU(CPU& c);
    ~CPU();
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

CPU::CPU() { std::cout << "正在默认构造初始化。。。"<<std::endl; }
CPU::CPU(int r, int f, float v) :cr(CPU_RANK(r)), frequency(f), voltage(v) { std::cout << "正在初始化。。。"<<std::endl; }
CPU::CPU(CPU& c)
{
    std::cout << "拷贝构造函数。。。" << std::endl;
    cr = c.cr;
    frequency = c.frequency;
    std::cout << "voltage故意未拷贝，请自行添加" << std::endl;
}
CPU::~CPU() { std::cout << "CPU报废了，正在回收~~~~~~~" << std::endl; }
CPU_RANK CPU::GetRank() { return cr; }
int CPU::GetFrequency() { return frequency; }
float CPU::GetVoltage() { return voltage; }
void CPU::SetRank(CPU_RANK r) { cr = r; }
void CPU::SetFrequency(int f) { frequency = f; }
void CPU::SetVoltage(float v) { voltage = v; }
void CPU::print() { std::cout << "Intel(R)  Core(TM) CPU i" << cr << " @ " << frequency << "MHz，电压：" << voltage << "V\n"; }
void CPU::run() { std::cout << "开始挖矿" << std::endl; }
void CPU::stop() { std::cout << "CPU挂了，花钱重新买台电脑吧" << std::endl; }

void fun1(CPU c)
{
    std::cout << "测试形式参数拷贝\n";
}

CPU fun2()
{
    CPU x;
    std::cout << "测试返回拷贝\n";
    return x;
}

int main()
{
    CPU thepc;
    CPU mygirlfriend(5, 1600, 11.5);
    CPU i = mygirlfriend;
    fun1(mygirlfriend);
    i = fun2();
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
