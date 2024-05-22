#include<iostream>
#include"ram.h"

RAM::RAM(int rank, int m, float f) :rr((RAM_RANK)rank), memory(m), frequency(f) { std::cout << "RAM default constructor" << std::endl; }
RAM::RAM(const RAM& r) : rr(r.rr), memory(r.memory), frequency(r.frequency) { std::cout << "RAM copy constructor" << std::endl; }
RAM::~RAM() { std::cout << "RAM distructor\n"; }

RAM_RANK RAM::GetRank()const { return rr; }
float RAM::GetFrequency()const { return frequency; }
int RAM::GetMemory()const { return memory; }
void RAM::print()const { std::cout << "RAM craft£ºDDR" << rr << "\tcapacity£º" << memory << "GB\tfrequency£º" << frequency << std::endl; }
void RAM::run()const { std::cout << "RAM run\n"; }
void RAM::stop()const{ std::cout << "RAM stop\n"; }