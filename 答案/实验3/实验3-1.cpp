// 实验3-1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

class Clock
{
private:
    int hour, minute, second;
public:
    Clock(int h=0,int m=0,int s=0);
    void Set_Time(int h=8, int m=8, int s=8);
    void Show_Time();
};

Clock::Clock(int h,int m,int s):hour(h),minute(m),second(s){}
void Clock::Set_Time(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}

void Clock::Show_Time()
{
    std::cout<<"现在是：虚拟时间\t" << hour << "：" << minute << "：" << second<<std::endl;
}

int main()
{
    Clock ca, cb;
    std::cout << "第一个" << std::endl;
    ca.Set_Time(520,13,14);
    ca.Show_Time();
    std::cout << std::endl <<"接下来是第二个"<< std::endl;
    cb.Set_Time();
    cb.Show_Time();
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
