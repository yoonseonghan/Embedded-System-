#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//List ADT Type Defintions
typedef struct node
{
	void* dataPtr;
	struct node* link;
} NODE;
typedef struct
{
	int count;
	int key;
	NODE* pos;
	NODE* head;
	NODE* rear;
	int (*compare) (void* argu1, void* argu2);
} LIST;

//Prototype Declarations
LIST* createList(int (*compare)
	(void* argu1, void* argu2));
LIST* destroyList(LIST* list);
int addNode(LIST* pList, void* dataInPtr);
bool removeNode(LIST* pList,
	void* keyPtr,
	void** dataOutPtr);
bool searchList(LIST* pList,
	void* pArgu,
	void** pDataOut);
bool traverse(LIST* pList,
	int fromWhere,
	void** dataOutPtr);
int listCount(LIST* pList);
bool emptyList(LIST* pList);
bool fullList(LIST* pList);
static bool _insert(LIST* pList,
	NODE* pPre,
	void* dataInPtr);
static void _delete(LIST* pList,
	NODE* pPre,
	NODE* pLoc,
	void** dataOutPtr);
static bool _search(LIST* pList,
	NODE** pPre,
	NODE** pLoc,
	void* pArgu);
//End of List ADT Definitions 

/*=============== createList ==============
Allocates dynamic memory for a list head
node and returns its address to caller
 Pre compare is address of compare function
 used to compare two nodes.
 Post head has allocated or error returned
 Return head node pointer or null if overflow
 */
