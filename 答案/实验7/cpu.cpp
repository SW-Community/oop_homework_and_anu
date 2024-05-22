#include<iostream>
#include"cpu.h"

CPU::CPU() { std::cout << "CPU default constructor" << std::endl; }
CPU::CPU(int r, int f, float v) :cr(CPU_RANK(r)), frequency(f), voltage(v) { std::cout << "Build a CPU in Intel..." << std::endl; }
CPU::CPU(const CPU& c)
{
    std::cout << "CPU copy constructor" << std::endl;
    cr = c.cr;
    frequency = c.frequency;
    voltage = c.voltage;
}
CPU::~CPU() { std::cout << "CPU distructor" << std::endl; }
CPU_RANK CPU::GetRank()const { return cr; }
int CPU::GetFrequency()const { return frequency; }
float CPU::GetVoltage()const { return voltage; }
void CPU::SetRank(CPU_RANK r) { cr = r; }
void CPU::SetFrequency(int f) { frequency = f; }
void CPU::SetVoltage(float v) { voltage = v; }
void CPU::print() const{ std::cout << "Intel(R)  Core(TM) CPU i" << GetRank() << " @ " << GetFrequency() << "MHz£¬voltage£º" << GetVoltage() << "V\n"; }
void CPU::run() const{ std::cout << "CPU stats running" << std::endl; }
void CPU::stop() const{ std::cout << "CPU is broken down" << std::endl; }