#include<stdio.h>
#include<stdlib.h>


int hash_fun(int value,int cap)
{
 return  value % cap;
}

int linear_insert(int arr[],int value, int cap)
{

    int i = hash_fun(value,cap);
    while(arr[i] != -1 && arr[i]!= -99 && arr[i] != value)
    {
        i = (i+1)%cap;
    }
    if(arr[i] == value)
    {
     printf(" No Duplicates are allowed in the hash table ");
     return 0;
    }

    else
    {
        arr[i] = value;
        printf("The value %d is inserted at %d key in the hash table ",value,i);
        return 1;
    }
    return 0;

}

int UpdatedHashTable(int cap,int arr[])
{
   for(int i = 0; i < cap ;i++)
   {
    printf(" %d",arr[i]);
   }
return 0;
}

int linear_srch(int arr[],int value,int cap)
{
  int key = hash_fun(value,cap);
  int i = key;
      while(arr[i]!= -1)
      {
          if (arr[i] == value )
          {
           printf("The value %d is found at %d key in the hash table ",value,i);
           return 1;
          }

          i = (i+1)%cap;
          if(i == key)
          {
            return 0;
          }
      }
   return 0;
}

int linear_del(int arr[],int value,int cap)
{
  int key = hash_fun(value,cap);
  int i = key;
    while(arr[i]!= -1)
      {
          if (arr[i] == value)
          {
             arr[i] = -99;
             printf("The value %d has been deleted from key %d in the hash table ",value,i);
            return 1;
          }
          i = (i+1)%cap;
          if(i == key)
          {
            return 0;
          }

      }
   return 0;
}

int main()
{
    int value,srch_flag,del_flag;
    int cap = 50;
    int option;
    printf("THIS IS THE PROGRAM FOR LINEAR PROBING ");
    int arr[50];
    for (int i= 0 ;i <cap; i++)
        {
        arr[i] = -1;
        }
    while(1)
    {
       printf("\n*********************************************************************");
       printf("\nOur current Hash table is :\n");
       UpdatedHashTable(cap,arr);
       printf("\n*********************************************************************");
       printf("\nWHICH OPERATION DO YOU WANT TO PERFORM?\n 1. INSERT \n 2. SEARCH \n 3. DELETE \n 4. NONE\n");
        scanf("%d",&option);
         if ( option == 1)
            {

             printf("Enter the value to be inserted ");
             scanf("%d",&value);
             linear_insert(arr,value,cap);

           }
         else if( option == 2)
          {
             printf("Enter the value to be searched ");
             scanf("%d",&value);
             srch_flag = linear_srch(arr,value,cap);
             if(srch_flag == 0)
                printf("The value %d is not found in the hash table ",value);

          }

          else if( option == 3)
          {
             printf("Enter the value to be deleted ");
             scanf("%d",&value);
             del_flag = linear_del(arr,value,cap);
             if(del_flag == 0)
                printf("The value %d is not found in the hash table ",value);
          }
          else
          {
           printf("*********************************************************************");
           break;
          }

     }
    return 0;
}


