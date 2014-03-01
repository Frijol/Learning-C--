// Simple event loop

#include <iostream>

class Condition
{
public:
  Condition() { }
  virtual ~Condition() {}
  virtual void Log() = 0;
};
class Normal : public Condition
{
public:
	Normal() { Log(); }
	virtual ~Normal() {}
	virtual void Log() { std::cout << "Logging normal conditions...\n"; }
};
class Error : public Condition
{
public:
	Error() {Log();}
	virtual ~Error() {}
  virtual void Log() { std::cout << "Logging error!\n"; }
};
class Alarm : public Condition
{
public:
	Alarm ();
	virtual   ~Alarm() {}
	virtual void Warn() { std::cout << "Warning!\n"; }
	virtual void Log() { std::cout << "General Alarm log\n"; }
	virtual void Call() = 0;
};
Alarm::Alarm()
{
  Log();
  Warn();
}
class FireAlarm : public Alarm
{
public:
  FireAlarm(){Log();};
  virtual ~FireAlarm() {}
  virtual void Call() { std::cout<< "Calling Fire Dept.!\n"; }
  virtual void Log() { std::cout << "Logging fire call.\n"; }
};
int main()
{
	int input;
	int okay = 1;
	Condition * pCondition;
	while (okay)
	{
		std::cout << "(0)Quit (1)Normal (2)Fire: ";
		std::cin >> input;
		okay = input;
		switch (input)
		{
	  	case 0: break;
	  	case 1:
				pCondition = new Normal;
				delete pCondition;
				break;
			case 2:
			  pCondition = new FireAlarm;
			  delete pCondition;
			  break;
			default:
				pCondition = new Error;
				delete pCondition;
				okay = 0;
				break;
		}
	}
	return 0;
}