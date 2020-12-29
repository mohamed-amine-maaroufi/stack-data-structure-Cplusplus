// STACK_DATA_STRUCTURE.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

/*
* Step 1: Defining Stack item and operations
* Each item of the Stack contains two parts. 
* One part is to store the data and another part to store the address of its next item.
*/
typedef struct Node {
	int data; //the element data
	struct  Node* next; //next element
	
} nodeElement;

/*
* The operations associated with the Stack data structure can be outlined as the function prototypes shown below:
* Function prototypes :
*/
void push(int); // add item to the stack
Node* pop();//Pop item from the stack
void printAll();//print out all items on the screen
int countItems();//return the number of items in the stack
bool find(int);//search for an item
nodeElement *findmin();//show min item
nodeElement *findmax();//show max item

/*
* pfirst points the first item of the Stack and plast point to the last item of the Stack
*/
nodeElement *pfirst;
nodeElement *plast;



int main()
{

	push(5);
	push(1);
	push(4);
	push(6);
	
	printAll();
	
	cout << "\nElements count =  " << countItems() << endl;

	pop();

	printAll();

	cout << "\nMin data element =   " << findmin()->data << endl;
	cout << "\nMax data element =   " << findmax()->data << endl;

	int valueToFind = 7;
	bool isValueExist = find(valueToFind);

	if (isValueExist)
	{
		cout << valueToFind << " is exist in the stack"<< endl;
	}
	else
	{
		cout << valueToFind << " does not exist in the stack" << endl;
	}



}

void push(int value) {
	cout << "\nPush value into the stack ..." << endl;
	nodeElement* newElement = new nodeElement();
	if (newElement == nullptr)
	{
		cout << "The new element is null !!!" << endl;
		exit(100);
	}
	else
	{
		newElement->data = value;

		//Push a new item to the empty stack
		if (pfirst == nullptr && plast == nullptr)
		{
			newElement->next = nullptr;
			pfirst	= newElement;
			plast	= pfirst;
		}
		else
		{
			//Push a new item at the beginning of the stack
			newElement->next = pfirst;
			pfirst = newElement;
		}

		cout << "Pushed into the stack : " << newElement->data << endl;
	}	
}

nodeElement* pop() {
	cout << "\nPop value from the stack ..." << endl;
	nodeElement* popedElement = nullptr, *tmpElement = nullptr;

	if (pfirst != nullptr) //the list not empty
	{
		nodeElement* secondElement = pfirst->next;

		if (secondElement == nullptr) //the list contain one element
		{
			popedElement	= pfirst;
			pfirst			= nullptr;
			plast			= nullptr;
		}
		else //the list contain more than one element
		{
			tmpElement		= pfirst;
			pfirst			= secondElement;
			popedElement	= tmpElement;
			tmpElement		= nullptr;
		}

		cout << "Popped from the stack : " << popedElement->data << endl;
	}
	else
	{
		cout << "You can't popped from the stack, it's empty" << endl;
	}
	
	return popedElement;
}

void printAll() {
	cout << "\nPrint values of the stack ..." << endl;
	nodeElement* element = pfirst;

	if (element != nullptr)
	{
		cout << "Begin - Print all elements :" << endl;
		while (element != nullptr)
		{
			cout << "Data = " << element->data << endl;
			element = element->next;
		}
		cout << "End - Print all elements :" << endl;
	}
	else
	{
		cout << "The stack is empty !!!" << endl;
	}	
}

int countItems() {
	cout << "\nCount elements of the stack ..." << endl;
	int retValue = 0;
	nodeElement* element = pfirst;

	if (element != nullptr)
	{
		while (element != nullptr)
		{
			element = element->next;
			retValue++;
		}		
	}
	else
	{
		cout << "The stack is empty !!!" << endl;
	}

	return retValue;
}

nodeElement *findmin() {
	cout << "\nFind the min value in the stack ..." << endl;
	nodeElement* element = pfirst;
	nodeElement* minElement = pfirst;
	int min = pfirst->data;

	if (element != nullptr)
	{
		while (element != nullptr)
		{
			if (element->data < min)
			{
				min = element->data;
				minElement = element;
			}

			element = element->next;
		}
	}
	else
	{
		cout << "The stack is empty !!!" << endl;
	}

	return minElement;
}

nodeElement *findmax() {
	cout << "\nFind the max value in the stack ..." << endl;
	nodeElement* element = pfirst;
	nodeElement* maxElement = pfirst;
	int max = pfirst->data;

	if (element != nullptr)
	{
		while (element != nullptr)
		{
			if (element->data > max)
			{
				max = element->data;
				maxElement = element;
			}

			element = element->next;
		}
	}
	else
	{
		cout << "The stack is empty !!!" << endl;
	}

	return maxElement;
}

bool find(int value) {
	cout <<"\nFind the value "<< value << " in the list ..." << endl;
	nodeElement* element = pfirst;
	bool isValueExist = false;

	if (element != nullptr)
	{
		while (element != nullptr)
		{
			if (element->data == value)
			{
				isValueExist = true;
				break;
			}

			element = element->next;
		}
	}
	else
	{
		cout << "The stack is empty !!!" << endl;
	}

	return isValueExist;
}