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
