// & 1 if 1 and 1, else 0 (1 if both are ones)
// | 1 if 1 and 0 or 1 and 1 or 1 and 0, else 0 (1 if there is a one)
// ^ 1 if 1 and 0 or 0 and 1, else 0 (1 if they are different)
// ~ 1 if 0, else 0 (toggle)

#include <iostream>
#include <string>

enum STATUS { FullTime, PartTime } ;
enum GRADLEVEL { UnderGrad, Grad } ;
enum HOUSING { Dorm, OffCampus };
enum FOODPLAN { OneMeal, AllMeals, WeekEnds, NoMeals };

class student
{
public:
	student():
	myStatus(FullTime),
  myGradLevel(UnderGrad),
  myHousing(Dorm),
  myFoodPlan(NoMeals)
  {}
  ~student(){}
  STATUS GetStatus();
  void SetStatus(STATUS);
  unsigned GetPlan() { return myFoodPlan; }
private:
	unsigned myStatus : 1;
	unsigned myGradLevel: 1;
	unsigned myHousing : 1;
	unsigned myFoodPlan : 2;
};

STATUS student::GetStatus()
{
	if (myStatus)
	  return FullTime;
	else
	  return PartTime;
}

void student::SetStatus(STATUS theStatus)
{
   myStatus = theStatus;
}

int main()
{
	student Jim;
	if (Jim.GetStatus()== PartTime)
		std::cout << "Jim is part time" << std::endl;
	else
		std::cout << "Jim is full time" << std::endl;
	Jim.SetStatus(PartTime);

	if (Jim.GetStatus())
		std::cout << "Jim is part time" << std::endl;
	else
		std::cout << "Jim is full time" << std::endl;
	std::cout << "Jim is on the " ;
	char Plan[80];
	switch (Jim.GetPlan())
	{
    case  OneMeal: strcpy(Plan,"One meal"); break;
    case  AllMeals: strcpy(Plan,"All meals"); break;
    case WeekEnds: strcpy(Plan,"Weekend meals"); break;
    case NoMeals: strcpy(Plan,"No Meals"); break;
    default : std::cout << "Something bad went wrong!\n"; break;
  }
  std::cout << Plan << " food plan." << std::endl;
	return 0;
}