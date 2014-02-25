// Contained: an object declared as a member of another class contained
// by that class
// Delegation: using the attributes of a contained class to accomplish
// functions otherwise not accessible to that class
// Implemented in terms of: building one class on the capabilities
// of another without using public inheritance

#include <iostream>

// define ULONG and USHORT
typedef unsigned long ULONG;
typedef unsigned short USHORT;

// ************** Part **************
// Abstract base class of parts
class Part
{
public:
	Part():itsPartNumber(1){}
	Part(ULONG PartNumber):itsPartNumber(PartNumber){}
	virtual ~Part(){}
	ULONG getPartNumber() const {return itsPartNumber;}
	virtual void Display() const = 0;
private:
	ULONG itsPartNumber;
};

// Implementation of pure virtual function so that derived classes
// can chain up
void Part::Display() const
{
	std::cout << "\nPart Number: " << itsPartNumber << std::endl;
}

// ******** Car Part ****************
class CarPart : public Part
{
public:
	CarPart():itsModelYear(94){}
	CarPart(USHORT year, ULONG partNumber);
	virtual void Display() const
	{
		Part::Display();
		std::cout << "Model Year: " << itsModelYear << std::endl;
	}
private:
	USHORT itsModelYear;
};

CarPart::CarPart(USHORT year, ULONG partNumber)
{
	itsModelYear = year;
	Part(partNumber);
}

// *************** Airplane Part **************
class AirplanePart : public Part{
public:
	AirplanePart():itsEngineNumber(1){}
	AirplanePart(USHORT EngineNumber, ULONG PartNumber);
	virtual void Display() const
	{
		Part::Display();
		std::cout << "Engine Number: " << itsEngineNumber << std::endl;
	}
private:
	USHORT itsEngineNumber;
};

AirplanePart::AirplanePart(USHORT EngineNumber, ULONG PartNumber)
{
	itsEngineNumber = EngineNumber;
	Part(PartNumber);
}

// ******* Part Node ****************
class PartNode
{
public:
	PartNode(Part*);
	~PartNode();
	void setNext(PartNode * node)
	{
		itsNext = node;
	}
	PartNode * GetNext() const;
	Part * GePart() const;
private:
	Part *itsPart
	PartNode * itsNext;
};

// PartNode Implementations
PartNode::PartNode(Part* pPart)
{
	itsPart = pPart;
	itsNext = 0;
}

PartNode::~PartNode()
{
	delete itsPart;
	itsPart = 0;
	delete itsNext;
	itsNext = 0;
}

// Returns NULL if no next PartNode
PartNode * PartNode::GetNext() const
{
	return itsNext;
}

Part * PartNode::GetPart() const
{
	if (itsPart)
		return itsPart;
	else
		return NULL;
}

// ******** Part List *********
class PartsList
{
public:
	PartsList();
	~PartsList();
	// include copy constructor, operator equals
	void Iterate(void (Part::*f)() const) const;
	Part* Find(ULONG & position, ULONG PartNumber) const;

	Part* GetFirst() const;
	void Insert(Part *);
	Part* operator [](ULONG) const;
	ULONG GetCount() const {return itsCount;}
	static PartsList& GetGlobalPartsList(){return GlobalPartsList;}
private:
	PartNode * pHead;
	ULONG itsCount;
	static PartsList GlobalPartsList;
};

PartsList PartsList::GlobalPartsList;

PartsList::PartsList()
{
	pHead = 0;
	itsCount = 0;
}

PartsList::~PartsList()
{
	delete pHead;
	pHead = 0;
}

Part* PartsList::GetFirst() const
{
	if (pHead)
		return pHead->GetPart();
	else
		return NULL;
}

Part* PartsList::operator[](ULONG offset) const
{
	PartNode* pNode = pHead
}

Part *  PartsList::operator[](ULONG offSet) const
{
  PartNode* pNode = pHead;
  if (!pHead)
     return NULL; // error catch here
  if (offset > itsCount)
     return NULL; // error
  for (ULONG i=0;i<offset; i++)
     pNode = pNode->GetNext();
 return   pNode->GetPart();
}

Part*   PartsList::Find(ULONG & position, ULONG PartNumber)  const
{
  PartNode * pNode = 0;
  for (pNode = pHead, position = 0; pNode!=NULL; pNode = pNode->GetNext(), position++)
  {
  	if (pNode->GetPart()->GetPartNumber() == PartNumber)
  		break;
  }
	if (pNode == NULL)
  	return NULL;
	else
		return pNode->GetPart();
}

void PartsList::Iterate(void (Part::*func)()const) const
{
	if (!pHead)
		return;
	PartNode* pNode = pHead;
	do
		(pNode->GetPart()->*func)();
	while (pNode = pNode->GetNext());
}

void PartsList::Insert(Part* pPart)
{
	PartNode * pNode = new PartNode(pPart);
	PartNode * pCurrent = pHead;
	PartNode * pNext = 0;
	ULONG New =  pPart->GetPartNumber();
	ULONG Next = 0;
	itsCount++;
	if (!pHead) {
		pHead = pNode;
	return; }
	// if this one is smaller than head
	// this one is the new head
	if (pHead->GetPart()->GetPartNumber() > New)
  {
		pNode->SetNext(pHead);
		pHead = pNode;
		return;
	}
	for (;;)
	{
		//if there is no next, append this new one
		if (!pCurrent->GetNext())
		{
			pCurrent->SetNext(pNode);
			return;
		}
		// if this goes after this one and before the next
		// then insert it here, otherwise get the next
		pNext = pCurrent->GetNext();
		Next = pNext->GetPart()->GetPartNumber();
		if (Next > New)
		{
			pCurrent->SetNext(pNode);
			pNode->SetNext(pNext);
			return;
		}
		pCurrent = pNext;
	}
}

class PartsCatalog
{
public:
	void Insert(Part *);
	ULONG Exists(ULONG PartNumber);
	Part * Get(int PartNumber);
	operator+(const PartsCatalog &);
	void ShowAll() { thePartsList.Iterate(Part::Display);
private:
	PartsList thePartsList;
};

void PartsCatalog::Insert(Part * newPart)
{
	ULONG partNumber =  newPart->GetPartNumber();
	ULONG offset;
	if (!thePartsList.Find(offset, partNumber))
	   thePartsList.Insert(newPart);
	else
	{
		cout << partNumber << " was the ";
		switch (offset)
		{
			case 0:  cout << "first "; break;
			case 1:  cout << "second "; break;
			case 2:  cout << "third "; break;
			default: cout << offset+1 << "th ";
		}
		cout << "entry. Rejected!\n";
	}
}

ULONG PartsCatalog::Exists(ULONG PartNumber)
{
	ULONG offset;
	thePartsList.Find(offset,PartNumber);
	return offset;
}

Part * PartsCatalog::Get(int PartNumber)
{
	ULONG offset;
	Part * thePart = thePartsList.Find(offset, PartNumber);
	return thePart;
}

int main() {
	PartsCatalog pc;
	Part * pPart = 0;
	ULONG PartNumber;
	USHORT value;
	ULONG choice;

	while (1) {
		std::cout << "(0)Quit (1)Car (2)Plane: ";
		std::cin >> choice;
		if (!choice)
			break;
		std::cout << "New PartNumber?: ";
		std::cin >>  PartNumber;
		if (choice == 1)
		{
			cout << "Model Year?: ";
			cin >> value;
			pPart = new CarPart(value,PartNumber);
		} else {
      cout << "Engine Number?: ";
      cin >> value;
      pPart = new AirPlanePart(value,PartNumber);
		}
		pc.Insert(pPart);
	}
	pc.ShowAll();
	return 0;
}