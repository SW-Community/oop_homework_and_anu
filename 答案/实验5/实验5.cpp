// 实验5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

enum CPU_RANK { i3 = 3, i5 = 5, i7 = 7, i9 = 9 };
enum RAM_RANK { DDR = 1, DDR2 = 2, DDR3 = 3, DDR4 = 4 };

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

class RAM
{
private:
    RAM_RANK rr;
    int memory;
    float frequency;
public:
    RAM() = default;
    RAM(int rank, int m, float f);
    RAM(RAM& r);
    ~RAM();

    RAM_RANK GetRank();
    float GetFrequency();
    int GetMemory();
    void print();
    void run();
    void stop();
};


class COMPUTER
{
private:
    int price;
    CPU c;
    RAM r;
public:
    COMPUTER();
    COMPUTER(COMPUTER& cp);
    ~COMPUTER();
    void SetComputer(CPU& xc, RAM& xr, int p);
    void print();
    void run() { std::cout << "I booted my computer,seemed everything is ok...\n"; }
    void stop() { std::cout << "shutdown...\n"; }
};


CPU::CPU() { std::cout << "default CPU constructor" << std::endl; }
CPU::CPU(int r, int f, float v) :cr(CPU_RANK(r)), frequency(f), voltage(v) { std::cout << "Build a CPU in Intel..." << std::endl; }
CPU::CPU(CPU& c)
{
    std::cout << "CPU copy constructor" << std::endl;
    cr = c.cr;
    frequency = c.frequency;
    voltage = c.voltage;
}
CPU::~CPU() { std::cout << "CPU distructor" << std::endl; }
CPU_RANK CPU::GetRank() { return cr; }
int CPU::GetFrequency() { return frequency; }
float CPU::GetVoltage() { return voltage; }
void CPU::SetRank(CPU_RANK r) { cr = r; }
void CPU::SetFrequency(int f) { frequency = f; }
void CPU::SetVoltage(float v) { voltage = v; }
void CPU::print() { std::cout << "Intel(R)  Core(TM) CPU i" << GetRank() << " @ " << GetFrequency() << "MHz，voltage：" << GetVoltage() << "V\n"; }
void CPU::run() { std::cout << "CPU stats running" << std::endl; }
void CPU::stop() { std::cout << "CPU is broken down" << std::endl; }

RAM::RAM(int rank, int m, float f):rr((RAM_RANK)rank),memory(m),frequency(f){ std::cout << "constract an RAM in Kingston..." << std::endl;}
RAM::RAM(RAM& r) : rr(r.rr), memory(r.memory), frequency(r.frequency) { std::cout << "RAM copy constructor" << std::endl; }
RAM::~RAM() { std::cout << "distructor\n"; }

RAM_RANK RAM::GetRank() { return rr; }
float RAM::GetFrequency() { return frequency; }
int RAM::GetMemory() { return memory; }
void RAM::print() { std::cout << "RAM craft：DDR" << rr << "\tcapacity：" << memory << "GB\tfrequency：" << frequency << std::endl; }
void RAM::run() { std::cout << "run\n"; }
void RAM::stop() { std::cout << "stop\n"; }


COMPUTER::COMPUTER()
{
    std::cout << "默认构造了一个COMPUTER\n\n";
}

COMPUTER::COMPUTER(COMPUTER& cp)
{
    c = cp.c;
    r = cp.r;
    price = cp.price;
    std::cout << "\n";
}

COMPUTER::~COMPUTER()
{
    std::cout << "正在删除COMPUTER对象\n";
}

void COMPUTER::SetComputer(CPU& xc, RAM& xr, int p)
{
    price = p;
    c = xc;
    r = xr;
    std::cout << "初始化构造了一个COMPUTER! with RMB "<<price<<" yuan"<<std::endl;
}

void COMPUTER::print()
{
    std::cout << "my computer's datasheet is listed as follows:\n";
    c.print();
    r.print();
    std::cout << "its price is" << price << "yuan\n";
}

int main()
{
    CPU mycpu(5, 2400, 2.8);
    RAM myram(3, 8, 2.4);

    COMPUTER c1;
    c1.SetComputer(mycpu, myram, 10000);
    c1.print();
    c1.run();
    c1.stop();
   
    COMPUTER c2(c1);
    c2.print();
    

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
