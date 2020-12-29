# C++ Stack Data Structure

C++ program to create a Stack data structure. This Stack data structure is to store the integer values. 

  - Add items
  - Delete items
  - Count items
  - Show min and max value of items
  - Find an item
  - Print all items

  
```sh
/*
* Defining Stack item and operations
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
```
