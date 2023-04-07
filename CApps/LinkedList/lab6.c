#include "lab6.h"

/*  initList
    this function when called returns and empty list pointer
 */
Node * initList()
{
    Node * p;
    p = malloc(sizeof(Node)); //allocate memory for this node
    
    if(p){
        p->next = NULL;     //every node created will automatically point to nothing
    }
    return p;
    
}

/* getSize
    This function will take a list pointer and return the size of the list.
 */
int getSize(Node * head)
{
    int count=0;
    
    for(;head->next != NULL;head =head->next)count++; //Iterate through entire list by assigning head to the next node each iteration. Runs until the end of the list, since the last node should point to NULL.
                                                        
        
    return count;
}
/* insertAtHead
    This function takes a double Node ponter and a void pointer which references user data. It inserts the data into a new node that is added onto the head. Returns 0 on success and 1 on failure.
 */
int insertAtHead(Node **list, void *data)
{
    Node * p;
    p = initList();  //allocate a new node
    if(p)
    {
        p->data = data;         //put user data into new node
        p->next = *list;        //new node's next pointer now points to the head
        *list = p;              //the head now points to this new node
        return 0;
    }
    else
    {
        return 1;
    }
}

/*  removeFromHead
    This function takes a double node pointer, removes the data stored at the head of the list, and returns the data stored in this removed node. Returns NULL if list is empty
 */
void * removeFromHead(Node **list)
{
    if(*list != NULL)   //test if NULL is empty
    {
        
        Node * head = *list;    //temp variable to help see that the value of list is really the head of the list
        void * data = head->data;   //create a variable to hold the user data so it's not lost after the node is freed.
        *list = head->next;         //list now points to the node directly after the removed one.
        free(head);
    
        return data;
    }
    else
    {
        return NULL;
    }
}

/*  freeList
    This function takes a double pointer to a list and simply frees all the memory allocated in this list. Also sets the value of the double pointer to NULL.
 
 */
void freeList(Node **list)
{
    Node * temp;
    Node * head = *list;
    while(head->next != NULL) //iterate through list until end
    {
        temp = head;
        head = head->next;
        
        free(temp);
    }
    free (head);        //free the last lingering node
            
    *list = NULL;
}

/* getWithLeastMilesDriven
        this function takes a list of car structs, and returns a pointer to the car in the list which has the least miles driven, or NULL if the list is empty.
 */
Car * getWithLeastMilesDriven(Node *list) {
    
    Car *head = list->data;     //tempory car pointer to use within if later on
    if(list != NULL){
    Car *min = list->data;      //min pointer that points to the car with the least mileage
    for(;list->next != NULL;list =list->next){
        head = list->data;                  //ensure head is always pointig to a car struct
        if(head->milesDriven < min->milesDriven) {
            min = list->data;               //when a new low is found, assign to min
        }
    }
    return min;
    }
    return NULL;
}
/*
        This car simply prints the list of cars' data held within the list of cars.
 */
void printCars(Node *list)
{
    Car * car;              //Car pointer to store struct data from node
    if(list != NULL)
    {
        for(;list->next != NULL;list =list->next){
            car = list->data;           //Assign current nodes data to car pointer
        
            printf("Car: VIN = %d, miles = %f, accidents = %d\n",
               car->vin, car->milesDriven, car->numberOfAccidents);
        
        }
    }
}

