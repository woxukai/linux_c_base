#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;
class Sheep
{
public:
	Sheep(const string& name,const string& category="Mounting Sheep" ):
	name_(name),category_(category){}
	void SetName(const string& name){name_ = name;};
	void SetCategory(const string& category){category_ = category;};
	void ShowInfo(){cout << name_ << ":" << category_ << endl; };
private:
	string name_;
	string category_;
};

int main()
{
	Sheep Jolly("Jolly");
	Jolly.ShowInfo();


	Sheep dolly(Jolly);
	dolly.SetName("dolly");
	dolly.ShowInfo();

	Sheep dooly = dolly;
	dooly.SetName("dooly");
	dooly.ShowInfo();

}
