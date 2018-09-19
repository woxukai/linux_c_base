#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

class Burger
{
public:
	class BurgerBuilder;
	void showFlavors()
	{
		cout << size_;
		if(cheese_) cout << "-cheese";
		if(peperoni_) cout << "-peperoni";
		if(lettuce_) cout << "-lettuce";
		if(tomato_) cout << "-tomato";
		cout << endl;

	}
private:
	Burger(int size):size_(size) {}
	int size_ = 7;          //大小
	bool cheese_ = false;   //奶酪
	bool peperoni_ = false; //意大利辣香肠
	bool lettuce_ = false; //莴苣
	bool tomato_ = false; //西红柿

};

class Burger::BurgerBuilder
{
public:
	BurgerBuilder(int size)
	{
		burger_ = new Burger(size);
	}

	Burger *Build()
	{
		return burger_;
	}

	BurgerBuilder& AddCheese()
	{
		burger_->cheese_ = true;
		return *this;
	}

	BurgerBuilder& AddPeperoni()
	{
		burger_->peperoni_ = true;
		return *this;
	}

	BurgerBuilder& AddLettuce()
	{
		burger_->lettuce_ = true;
		return *this;
	}

	BurgerBuilder& AddTomato()
	{
		burger_->tomato_ = true;
		return *this;
	}
private:
	Burger *burger_;
};

int main(void)
{
	Burger *burger = Burger::BurgerBuilder(14).AddCheese().AddLettuce().AddPeperoni().AddTomato().Build();
	burger->showFlavors();
	exit(0);

}

void hello()
{
	//printf("hello from thread: %d\n ",(int)this_thread::get_id());
	cout << "thread id is " << this_thread::get_id() << endl;
}
