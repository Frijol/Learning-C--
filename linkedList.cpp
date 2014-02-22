// Demonstration of simple linked list

#include <iostream>
class Cat
{
public:
	Cat() {itsAge = 1; }
	Cat(int age):itsAge(age){}
	~Cat(){};
	int getAge() const {return itsAge; }
private:
	int itsAge;
};

// manages list, orders by cat's age
class Node
{
public:
	Node(Cat*);
	~Node();
	void setNext(Node * node) {itsNext = node; }
	Node * getNext() const {return itsNext; }
	Cat * getCat() const {return itsCat; }
	void insert(Node *);
	void display();
private:
	Cat *itsCat;
	Node *itsNext;
};

Node::Node(Cat *pCat)
{
	itsCat = pCat;
	itsNext = 0;
}

Node::~Node()
{
	std::cout << "Deleting node...";
	delete itsCat;
	itsCat = 0;
	delete itsNext;
	itsNext = 0;
}

/* Insert:
Orders cats based on their ages */
void Node::insert(Node * newNode)
{
	if (!itsNext)
	{
		itsNext = newNode;
	} else {
		int nextCatsAge = itsNext->getCat()->getAge();
		int newAge = newNode->getCat()->getAge();
		int thisNodeAge = itsCat->getAge();

		if (newAge >= thisNodeAge && newAge < nextCatsAge)
		{
			newNode->setNext(itsNext);
			itsNext = newNode;
		} else {
			itsNext->insert(newNode);
		}
	}
}

void Node::display()
{
	if (itsCat->getAge() > 0)
	{
		std::cout << "My cat is " << itsCat->getAge() << std::endl;
	}
	if (itsNext)
	{
		itsNext->display();
	}
}

int main()
{
	Node *pNode = 0;
	Cat *pCat = new Cat(0);
	int age;

	Node *pHead = new Node(pCat);
	while(1)
	{
		std::cout << "New cat's age? (0 to quit)\n";
		std::cin >> age;
		if (!age)
		{
			break;
		}
		pCat = new Cat(age);
		pNode = new Node(pCat);
		pHead->insert(pNode);
	}
	pHead->display();
	delete pHead;
	std::cout << "Exiting...\n";
}