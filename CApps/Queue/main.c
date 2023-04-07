#include "lab8.h"

int main()
{
    Queue *queue;
    int errorCon =0;
    queue = initQueue();
    
    int size =0;
    size = getSize(queue);
    
    printf("Size of list: %d\n",size);
    
    int array[5] = {0, 1, 2, 3, 8};
    
    for(int i = 0;i < 5;i++)
    {
       // if(i %2 ==0)
       // {
            errorCon = enQueue(queue,&array[i]);
            printf("Error condition: %d\n",errorCon);
       // }
        //else
       // {
       //     errorCon = insertAtTail(&array[i],list);
       //     printf("Error condition: %d\n",errorCon);
       // }
        
    }
    size = getSize(queue);
    printf("Size of list: %d\n",size);
    
    
    int * object = peek(queue);
    printf("object retrived: %d\n", *object);
    
    int * object2 = deQueue(queue);
    printf("object retrived: %d\n", *object2);

    int * object3 = peek(queue);
    printf("object retrived: %d\n", *object3);    
    

    size = getSize(queue);
    printf("Size of list: %d\n",size);
   /* int * array1 = removeHead(list);
    printf("Item removed: %d\n", *array1);
    
    int * array2 = removeTail(list);
    printf("Item removed: %d\n", *array2);
    
    int size =0;
    
    size = getSize(list);
    
    printf("Size of list: %d\n",size);
    */
    freeQueue(queue);
}

