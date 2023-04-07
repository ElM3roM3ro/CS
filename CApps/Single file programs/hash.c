#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

/*  Author: Victor Peralta

*/



//Defintion for a Node ADT
typedef struct Node Node;
struct Node {
    void *data;         //this pointer holds the customer element in it's entirety
    int dataKey;        //this holds the secondary (hard copy) key when put inside of a linked list
    Node *next;         //Simply points to the next node in the linked list
};

//This function inserts a given element into the given hashtable. The function returns -1
//when there is a collison.
int InsertFailCollision(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    int hashKey = HashFunc(key);        //establish hashing key with given key and chosen function
    void * box = (hashtable + hashKey * elementSize); //initilize a "box" that holds the info of the hash key in the hashtable

    if(*(int*)box== 0)          //All hashes are set to 0 originally, so to check for an empty slot, we simply check if our box = 0
    {
        memcpy(box,element,elementSize);     //copy data from the element into our empty box
        return 1;
    }
    return -1;              //return -1 when there is a collision
}

//This function simply searches for a specified element given a hashkey. If the element is in the hashtable,
//return the element in the hashtable. If not found, return NULL
void * SearchNoCollision(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    int hashKey = HashFunc(key);
    void * box = (hashtable + hashKey * elementSize);

    if(*(int*)box !=0)          //Test if hashkeyed box is not empty. If not, then we return box
    {
        return box;
    }

    return NULL;
}

//This function creates a key for hashing using the divison method
int DivMethod(int key)
{
	return key % TABLESIZE;
}

//This function creates a key for hashing using the multiplicaion method
int MultMethod(int key)
{
    //Code without the use of a floor function
    float tempKey = key * .618033987;  //(sqrt5 -1) divided by 2. multiply the key by Kunuths number
    int floor = (int)tempKey;          //"floor" tempKey, making it a whole number
    return TABLESIZE * (tempKey -floor);   // The return type is int, so the product will be "floored" by way of conversion

    //code using the floor function from math.h
    /*
    double A = (sqrt(5)-1)/2;
    int hash = floor(8*(key*A-(floor(key*A))));
    return hash;*/
}

//This code simply allocates and initializes memory for a "chain" hash table.
void * AllocateChainTable(int elementCountMax)
{
    Node *c = malloc(elementCountMax*sizeof(Node));     //creates space for a table of elementCountMax nodes
    for(int x=0; x< elementCountMax; x++)               //for loop to initilize the values of all nodes
    {
        c[x].dataKey = -1;
        c[x].next = NULL;
        c[x].data = NULL;
    }

    return c;
}

//This function frees the memory allocated by both the AllocateChainTable and insertchain
void FreeChainTable(void * hashtable)
{
    Node *table = hashtable;
    Node * temp, * head;
    for(int x= 0; x<TABLESIZE;x++)          //Loop through our entire hash table
    {
        table = hashtable + x *sizeof(Node);        //Set our head table variable to table[x]. Utilizing poiinter aritmetic because we cannot deference a void pointer
        if(table->next !=NULL)                 //Check if a linked list is present in this current hash table slot
        {
            head = table->next;                 //set our linked list head to the start of a linked list
            while(head!=NULL)                         //while our head is not equal to NULL. (while we aren't at the end of the linked list)
            {
                temp = head;                    //Placeholder for head, as we want to free it later
                head = head->next;
                free(temp);
            }
        }
    }
    free(hashtable);
}

//This function inserts any given element into our hashtable. By way of chaining
int InsertChain(	void * hashtable, int elementSize, int elementCountMax,
                            int key, void * element, int (*HashFunc)(int key))
{
    int hashKey = HashFunc(key);
    Node *item = (hashtable + (hashKey * sizeof(Node)));        //item is the specific key "box" that we want to insert into
    Node * insert  = malloc(sizeof(Node));              //allocate memory for a node we want to insert to our chain

    if(!insert)                 //test if malloc failed
    {
        return -1;
    }

    insert->data = element;         //Populate our newly created node with the customers data
    insert->dataKey = key;

    insert->next = item->next;      //insert at head of our linked list
    item->next = insert;

    return 1;

}

//This function searches our hash table, and the linked lists within them to try to find a specified key. It returns the customer with a specified key
void * SearchChain(void * hashtable, int key, int elementSize, int (*HashFunc)(int key))
{
    int hashKey = HashFunc(key);
     Node * item = (hashtable + (hashKey * sizeof(Node)));          //Specific hashkeyed box whose linked list we want to search

    if(item->next != NULL)     //Check if there is a linked list in this box
    {
        Node * traversal = item->next;     //Pointer that will traverse through the linked list
        while(traversal->next != NULL && traversal->dataKey !=key)      //While we havent reached the end of the chain && while we havent found the key
        {
            traversal = traversal->next;        //Set trav to the node in front
        }

        if(traversal->dataKey == key)      //Check if the resulting pointer while statement has the key we want
        {
            return traversal->data;        //return the customer info, which was stored in data in the insertchain fucntion
        }

    }
    return NULL;        //return NULL if the customer with given key was not found
}
