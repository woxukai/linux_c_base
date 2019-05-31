#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * （1）实现了抽象和实现部分的分离

桥接模式分离了抽象部分和实现部分，从而极大的提供了系统的灵活性，让抽象部分和实现部分独立开来，分别定义接口，这有助于系统进行分层设计，从而产生更好的结构化系统。对于系统的高层部分，只需要知道抽象部分和实现部分的接口就可以了。

（2）更好的可扩展性

由于桥接模式把抽象部分和实现部分分离了，从而分别定义接口，这就使得抽象部分和实现部分可以分别独立扩展，而不会相互影响，大大的提供了系统的可扩展性。

（3）可动态的切换实现

由于桥接模式实现了抽象和实现的分离，所以在实现桥接模式时，就可以实现动态的选择和使用具体的实现。

（4）实现细节对客户端透明，可以对用户隐藏实现细节。
*/

 /*
 12  *桥接模式（Bridge)是一种结构型设计模式。Bridge模式基于类的最小设计原则，通过使用封装、
 13  聚合及继承等行为让不同的类承担不同的职责。它的主要特点是把抽象(Abstraction)与行为实现(Implementation)分离开来，
 14  从而可以保持各部分的独立性以及应对他们的功能扩展。
 15  * */

class ITheme
{
public:
	virtual string getColor() = 0;
};

class DarkTheme:public ITheme
{
public:
	string getColor() override
	{
		return "Dark Black";
	}
};


class LightTheme: public ITheme
{
public:
	string getColor() override
	{
		return "off white";
	}
};

class AquaTheme:public ITheme
{
public:
	string getColor() override
	{
		return "light blue";
	}
};


class IWebPage
{
public:
	IWebPage(ITheme &theme):theme_(theme){}
	virtual string getContent() = 0;
protected:
	ITheme &theme_;
};


class About:public IWebPage
{
public:
	About(ITheme &theme):IWebPage(theme){}
	string getContent()
	{
		return "About page in" + theme_.getColor();
	}
};



class Careers:public IWebPage
{
public:
	Careers(ITheme &theme):IWebPage(theme){}
	string getContent()
	{
		return "Careers page in" + theme_.getColor();
	}
};

int main()
{
	DarkTheme darkTheme;
	About about(darkTheme);
	Careers careers(darkTheme);

	cout << about.getContent() << endl;
	cout << careers.getContent() << endl;
}
