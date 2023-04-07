#include "lab6.h"

int main()
{
    Node *list;
    list = initList();
    int errorcode =1;
    Car * Array =createArray(sizeof(Car),3);
    Array[0].vin = 1;
    Array[0].milesDriven = 8;
    Array[0].numberOfAccidents =12;
    
    Array[1].vin = 2;
    Array[1].milesDriven = 7;
    Array[1].numberOfAccidents =3;
    
    Array[2].vin = 3;
    Array[2].milesDriven = 6;
    Array[2].numberOfAccidents =0;
    
    for(int i = 0; i < 3;i++)
    {
        errorcode = insertAtHead(&list, &Array[i]);
        printf("%d\n",errorcode);
    }
    
    printf("List length is: %d\n", getSize(list));
    
    
   /* Car * carRemoved = removeFromHead(&list);
    
    printf("Id of removed node: %d\n",carRemoved->vin);
    
    Car * carRemoved2 = removeFromHead(&list);
    
    printf("Id of removed node: %d\n",carRemoved2->vin);*/
    
    Car * leastMiles = getWithLeastMilesDriven(list);
    
    printf("Id of least miles: %d\n",leastMiles->vin);
    
    printCars(list);
    freeList(&list);
    
}
