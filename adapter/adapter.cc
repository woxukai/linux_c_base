#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;
class ILion
{
public:
	virtual void Roar()
	{
		cout << "I am a Lion" << endl;
	}
	
};

class Hunter
{
public:
	void Hunt(ILion &lion)
	{
		lion.Roar();
	}
};

class WildDog
{
public:
	void Bark()
	{
		cout << "i am a wild dog" << endl;
	}
};

class WildDogAdapter:public ILion
{
public:
	WildDogAdapter(WildDog &dog):dog_(dog)
	{
		
	}

	void Roar() override
	{
		dog_.Bark();
	}
private:
	WildDog &dog_;
};


int main()
{
	WildDog dog;
	WildDogAdapter dogAdapter(dog);

	Hunter hunter;
	hunter.Hunt(dogAdapter);
}
