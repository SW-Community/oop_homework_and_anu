#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>

using std::vector;
using std::map;
using std::set;
using std::string;

struct Nanny{
	int phone;
	string table[7];
	vector<string>comments;
};

map<string,Nanny>Nanny_Datapool;

string Covert_To(int i) //This is a auxiliary function for display the interface is friendly
{
	string s;
	switch(i)
	{
		case 1:{s="MON";break;}
		case 2:{s="TUE";break;}
		case 3:{s="WED";break;}
		case 4:{s="THU";break;}
		case 5:{s="FRI";break;}
		case 6:{s="SAT";break;}
		case 7:{s="SUN";break;}
	}
	return s;
} 

//The following three functions are for the parent user 

void Show_Nannys_slots(const string& Nanny_Name)
{
	std::cout<<"nanny "<<Nanny_Name<<"£¨phone number +86 "<<Nanny_Datapool[Nanny_Name].phone<<"£© "<<"it's schedule is as follows£º\n"; 
	for(int i=1;i<=7;i++)
	{
		std::cout<<std::setw(10)<<Covert_To(i); 
	}
	std::cout<<"\n------------------------------------------------------------------------\n";
	for(int i=0;i<7;i++)
	{
		std::cout<<std::setw(10)<<Nanny_Datapool[Nanny_Name].table[i];
	}
	std::cout<<std::endl;
}

bool Book_Nanny(int Weekday,const string& Nanny_Name,const string& Child_Name)
{
	if(!Nanny_Datapool[Nanny_Name].table[Weekday-1].empty()){return false;}
	Nanny_Datapool[Nanny_Name].table[Weekday-1]=Child_Name;
	return true;
}

void Add_Comment(const string &Nanny_Name)
{
	string s;
	std::cout<<"Please enter your nanny "<<Nanny_Name<<" evaluate\n";
	getchar();
	std::cout<<"System limitation (programmer level is limited), only one paragraph is supported£¬no limit to the number of words, but not too much, thank you for your cooperation\n";
	std::getline(std::cin,s);
	Nanny_Datapool[Nanny_Name].comments.push_back(s);
	std::cout<<"Your comments are our greatest encouragement. We look forward to serving you next time!\n";
}

//The following functions are for administrator users

void Add_Nanny(const string& Nanny_Name,int phone)
{
	Nanny_Datapool[Nanny_Name].phone=phone;
	std::cout<<"Add nanny information "<<Nanny_Name<<" success£¡\n"; 
}

void Show_Nannys_Duty(const string& Nanny_Name)
{
	set<string>Baby_List;
	for(int i=0;i<7;i++)
	{
		if(!Nanny_Datapool[Nanny_Name].table[i].empty()){Baby_List.insert(Nanny_Datapool[Nanny_Name].table[i]);}
	}
	std::cout<<"nanny "<<Nanny_Name<<" The children looked after were as follows:\n";
	for(auto it=Baby_List.begin();it!=Baby_List.end();it++)
	{
		std::cout<<std::setw(10)<<*it;
	} 
	std::cout<<std::endl;
}

//Here is a common function

void Show_Nannys_Comments(const string& Nanny_Name)
{
	int i=1;
	for(auto it=Nanny_Datapool[Nanny_Name].comments.begin();it!=Nanny_Datapool[Nanny_Name].comments.end();it++,i++)
	{
		std::cout<<"comment"<<i<<": "<<*it<<std::endl;
	}
} 

//The following is the interface display function 

void Show_Title()
{
	system("title [main menu] - Baby sitter reservation and management system¡ª¡ªBy Dream girl");
	system("color 16");
	std::cout<<"======================================================"<<std::endl;
	std::cout<<"|                                                     |"<<std::endl;
	std::cout<<"     Baby sitter reservation andmanagement system     |"<<std::endl;
	std::cout<<"|                                                     |"<<std::endl;
	std::cout<<"======================================================"<<std::endl;
	std::cout<<"\nFunction Description: support parents to view scheduled comments on nanny, support administrators to modify nanny information\n\n";
}


void Show_Parent_Menu()
{
	system("title [Parent users] - Baby sitter reservation and management system¡ª¡ªBy Dream girl");
	system("color 5f");
	std::cout<<"=================================\n";
	std::cout<<"  1:   View nanny information and schedule\n";
	std::cout<<"  2£º  Booking nanny home service\n";
	std::cout<<"  3£º  Evaluate our services or provide feedback\n";
	std::cout<<"  4£º  View comments\n";
	std::cout<<"=================================\n";
	std::cout<<"Please enter the menu number£º"; 
}

void Show_Admin_Menu()
{
	system("title [administrators] - Baby sitter reservation and management system¡ª¡ªBy Dream girl");
	system("color 24");
	std::cout<<"=================================\n";
	std::cout<<"  1:      Enter the nanny information\n";
	std::cout<<"  2£º   View the current status of the nanny\n";
	std::cout<<"  3£º       View comments\n";
	std::cout<<"=================================\n"; 
	std::cout<<"Please enter the menu number£º";
} 

int main()//the main menu 
{
	while(1)
	{
		int x;
		char c;
		Show_Title();
		std::cout<<"Please select your identity: parent (P) or administrator (A)£º";
		string name;
		std::cin>>c;
		switch(c)
		{
			case 'P':	case 'p':
			{
				Show_Parent_Menu();
				std::cin>>x;
				while(1)
				{
					std::cout<<"please enter the name of nanny£º"; 
					std::cin>>name;
					if(Nanny_Datapool.count(name)){break;}
					std::cout<<"Nanny does not exist, please re-enter\n";
				}
				if(x==1){Show_Nannys_slots(name);} 
				if(x==2)
				{
					int day;
					string child;
					std::cout<<"Please enter the day of the week you want to book£º\n";
					std::cin>>day;
					std::cout<<"Please enter the child's name£º\n";
					std::cin>>child; 
					bool is_ok=Book_Nanny(day,name,child);
					if(is_ok){std::cout<<"Operation successful£¡\n";}
					else{std::cout<<"operation failed£¡\n";}
				}
				if(x==3)
				{
					Add_Comment(name);
				} 
				if(x==4){Show_Nannys_Comments(name);} 
				break;
			}
			
			case 'A':	case 'a':
			{
				Show_Admin_Menu(); 
				std::cin>>x; 
				std::cout<<"Please enter the name of the nanny£º"; 
				std::cin>>name;
				if(x==1)
				{
					int phone;
					std::cout<<"Please enter the phone number of the nanny£º\n";
					std::cin>>phone;
					Add_Nanny(name,phone);
					
				}
				if(x==2)
				{
					Show_Nannys_Duty(name);
				} 
				if(x==3){Show_Nannys_Comments(name);}
				break;
			}
		}
		system("pause");
		std::cin.clear();
		std::cin.sync(); 
		system("cls");
	}
	return 0;
}
