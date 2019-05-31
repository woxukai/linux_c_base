#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

/*
 *当需要构建不同风格的对象，同时需要避免构造器重叠时使用生成器模式。
 与工厂模式的主要区别在于：当创建过程一步到位时，使用工厂模式，
 而当创建过程需要多个步骤时，使用生成器模式。
 * */

/*
 *以下情况应当使用建造者模式：

1、 产品对象的内部结构需要有不同的展示。
2、 不同的展示对象属性依赖与同一个产品对象，产品对象内部顺序可自行调整使用。
3、 在对象创建过程中会使用到系统中的一些其它对象，这些对象在产品对象的创建过程中不易得到。

使用建造者模式主要有以下效果：

1、 建造模式的使用使得产品的内部表象可以独立的变化。使用建造者模式可以使客户端不必知道产品内部组成的细节。
2、 每个特定的建造者都独立于其它建造者和程序的其余部分，这提高拉模块化程度，并使得添加其建造者变的灵活简单。
3、 因为每一个建造者都是根据数据来逐步构造出最终的产品的，因此对建造者构造的每个最终产品从头到尾有更好的控制能力。
 * */

//汉堡
class Burger
{
public:
	class BurgerBuilder; //声明
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

//定义：将一个复杂的对象，分成多分，使同样的构建过程，能有不同的表示，这样的设计模式被称为建造者模式。
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
	
	//奶酪
	BurgerBuilder& AddCheese()
	{
		burger_->cheese_ = true;
		return *this;
	}
	
	//意大利奶肠
	BurgerBuilder& AddPeperoni()
	{
		burger_->peperoni_ = true;
		return *this;
	}

	//莴苣
	BurgerBuilder& AddLettuce()
	{
		burger_->lettuce_ = true;
		return *this;
	}

	//西红柿
	BurgerBuilder& AddTomato()
	{
		burger_->tomato_ = true;
		return *this;
	}
private:
	Burger *burger_; //指针对象
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
