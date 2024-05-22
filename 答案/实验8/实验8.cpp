#include<iostream>

using std::string;

class cpu{
	//细节略去不表。。。
public: 
	string x="520";
};

class Arr{
private:
	cpu* pointer=nullptr;
	int capacity=0;
	int cnt=0;
public:
	void add(cpu c)
	{
		if(cnt==capacity)
		{
			cpu* tmp=new cpu[2*capacity];
			std::swap(tmp,pointer);
			delete[] tmp;
			capacity=capacity*2;	
		}
		pointer[cnt++]=c;
	} 
	
	Arr(Arr& c)
	{
		cnt=c.cnt;
		capacity=c.capacity;
		pointer=new cpu[c.capacity];
		for(int i=0;i<c.cnt;i++)
		{
			pointer[i]=c.pointer[i];
		}
	}
	void output()
	{
		for(int i=0;i<c;i++)
		{
			std::cout<<pointer[i].x;
		}
	}
}; 



int main()
{
	
} 
