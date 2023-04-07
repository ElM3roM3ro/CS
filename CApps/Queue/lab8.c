#include "lab8.h"

// -------------------------------- STRUCT DEFINITIONS
typedef struct nodestruct {
    void * data;
    struct nodestruct *next;
} Node;

typedef struct {
    Node *rear;             //Implementing a circular queue with one tail pointer
    int * size;
} QueueInfo;

struct Queue{
    QueueInfo *info;
};

//Helper functions

/*  makeNode
    This function takes in a pointer to user data and a pointer to the node following the created node. Returns a pointer to newly allocated node.
 */
Node *makeNode(void * data, Node * next)
{
    Node * p = malloc(sizeof(Node));
    
    if(p)
    {
        *p = (Node){ data, next };
    }
    
    return p;
}

/*  setSize
    This function takes a queue pointer and the size that you want to set the queue size to.
 */
void setSize(Queue *q, int size) {
    int *sizePtr = q->info->size;
    *sizePtr = size;        //store given size in the size variable of the
                            //QueueInfo struct.
}

// Implementation functions

/*  initQueue O(1)
    This function returns an empty Queue pointer(without a placholder node).
 */
Queue * initQueue()
{
    Queue * p = malloc (sizeof(Queue));
    p->info = malloc(sizeof(QueueInfo));   //Allocate memory for apspects of Queue
    int *size = malloc(sizeof(int));       //and QueueInfo structs.
    
    if(size && p->info && p)        //Check if malloc failed during allocation
    {
        p->info->rear = NULL;
        *size = 0;                  //Initializing queue size as 0.
        p->info->size = size;
    }
    
    return p;
}
/*  getSize O(1)
    This function takes a Queue pointer and returns the size of the given Queue.
 */
int getSize(Queue *q)
{
    int * size = q->info->size;
    return *size;
}

/*  enQueue O(1)
    This function takes a Queue pointer and user data. It stores the given data into a new node at the back (or rear) of the queue. Returns 0 on success or 1 on failure.
 */
int enQueue(Queue *q, void * data)
{
    Node *insert = makeNode(data, NULL);
    int size = getSize(q);
    
    if(!insert)             //Check if malloc failed
    {
        return 1;
    }
    if(q->info->rear == NULL)       //Check to see if Queue is empty. If so,
    {                               //Place new node in the queue.
        q->info->rear = insert;
        q->info->rear->next = insert;
        setSize(q,size+1);
        return 0;
    }
    
    //Code executed if Queue is populated and not empty.
    insert->next = q->info->rear->next;
    q->info->rear->next = insert;
    q->info->rear = insert;
    setSize(q,size+1);
    return 0;

}

/*  peek O(1)
    This function takes a Queue pointer and returns the data at the front of the Queue. If the given queue is empty, NULL is returned. Otherwise, the data is simply returned.
 */
void * peek(Queue *q)
{
    if(q->info->rear == NULL)   //Test if queue is empty.
    {
        return NULL;
    }
    void * object = q->info->rear->next->data;  //initialize object variable to the
                                                //Contents of the front of queue.
    return object;
}

/*  deQueue O(1)
    This function will take a Queue pointer and remove/return the data at the front of the queue. If the list is empty, NULL is returned.
 */
void * deQueue(Queue *q)
{
    int size = getSize(q);
    if(q->info->rear ==NULL)            //Test if queue is empty
    {
        return NULL;
    }
    Node * delete = q->info->rear->next;        //Set Node pointer to node to be deleted.
    void * obj = delete->data;
    q->info->rear->next = delete->next;
    free(delete);
    
    setSize(q,size-1);
    return obj;
}

/*  freeQueue O(1)
    This function takes a Queue pointer and simply frees all the memory allocated to the queue.
 */
void freeQueue(Queue *q) {
    
    if(q->info->rear != NULL){         //Test if given Queue was not empty
        int size = getSize(q);
        
        //Following code frees the allocated memory of the nodes within the Queue
        while(size != 0)
        {
            Node * delete = q->info->rear->next;
            q->info->rear->next = delete->next;
            free(delete);
            
            setSize(q,size-1);        //Iterate size to traverse through the queue
            size = getSize(q);
        }
    }
    //Code executed regardless of whether or not the Queue was empty.
    //Following code frees every aspect of queue allocated during initialization.
    free(q->info->size);
    free(q->info);
    free(q);
}

