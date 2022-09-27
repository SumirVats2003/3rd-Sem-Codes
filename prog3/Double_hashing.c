#include<stdio.h>
#include<stdlib.h>
int hash_fun1(int doubeHash_value)
{
 return  doubeHash_value % 50;
}
int hash_fun2(int doubeHash_value)
{
 return 47 - (doubeHash_value % 47);
}

int DoubleHashing_Insert(int doublehash_arr[],int doubeHash_value)
{
        int h1 = hash_fun1(doubeHash_value);
        int h2 = hash_fun2(doubeHash_value);

        if (doublehash_arr[h1] == -1)
        {
             doublehash_arr[h1] = doubeHash_value;
            return 1;
        }

         //Else if works in the case of duplication
        else if (doublehash_arr[h1] == doubeHash_value)
            {
            printf("No Duplicates are allowed in the hash table ");
            return 0;
           }


        //Else works in the case of collision
         else
            {
            for (int i = 1; i < 50; i++)
                {
                int t = (h1 + i*h2) % 50;
                    if (doublehash_arr[t] == -1 )
                    {
                        doublehash_arr[t] = doubeHash_value;
                        //printf("The value %d is insert at key %d in the hash table",doubeHash_value,t);
                        return 1;
                    }
                    else if (doublehash_arr[t] == doubeHash_value)
                    {
                    printf("\nNo Duplicates are allowed in the hash table ");
                    return 0;
                    }
                    else
                        //printf("\ncontinue....");
                        continue;
                }
           }
    return 0;
}
int UpdatedHashTable(int doublehash_arr[])
{
   for(int i = 0; i < 50 ;i++)
   {
    printf(" %d",doublehash_arr[i]);
   }
return 0;
}
int DoubleHashing_Srch(int doublehash_arr[],int doubeHash_value)
{
   int h1 = hash_fun1(doubeHash_value);
   int h2 = hash_fun2(doubeHash_value);
    if (doublehash_arr[h1] == doubeHash_value)
    {
     printf("The value %d is found at key %d in the hash table\n",doubeHash_value,h1);
     return 1;
    }

    else if ( doublehash_arr[h1] == -1)
    {
         printf("The value %d is not found in the hash table\n",doubeHash_value);
         return 0;
    }

    else
        for (int i = 1; i < 50; i++)
        {
             int t = (h1 + i*h2) % 50;
                    if (doublehash_arr[t] == doubeHash_value )
                    {
                    printf("The value %d is found at key %d in the hash table\n",doubeHash_value,t);
                    return 1;
                    }
                    else
                        continue;
        }
        printf("The value not found");
return 0;

}
int DoubleHashing_Del(int doublehash_arr[],int doubeHash_value)
{
   int h1 = hash_fun1(doubeHash_value);
   int h2 = hash_fun2(doubeHash_value);
    if (doublehash_arr[h1] == doubeHash_value)
    {
     doublehash_arr[h1] = -99;
     printf("The doubeHash_value %d is deleted at key %d in the hash table\n",doubeHash_value,h1);
     return 1;
    }

    else if ( doublehash_arr[h1] == -1)
    {
         printf("The doubeHash_value %d is not found in the hash table\n",doubeHash_value);
         return 0;
    }

    else
        for (int i = 1; i < 50; i++)
        {
           int t = (h1 + i*h2) % 50;
                    if (doublehash_arr[t] == doubeHash_value )
                    {
                    doublehash_arr[t] = -99;
                    printf("The value %d is deleted at key %d in the hash table\n",doubeHash_value,t);
                    return 1;
                    }
                    else
                        continue;
        }
        printf("The value not found");
return 0;

}
int main()
{
    int doubeHash_value;
    int option;
    int j=0;
    printf("THIS IS THE PROGRAM FOR DOUBLE HASHING PROBING\n");
    int doublehash_arr[50];
    for (int i= 0 ;i <50; i++)
        {
        doublehash_arr[i] = -1;
        printf(" %d",doublehash_arr[i]);
        }
     while(1)
    {
       printf("\n*********************************************************************");
       printf("\nOur current Hash table is :\n");
       UpdatedHashTable(doublehash_arr);
       printf("\n*********************************************************************");
       printf("\nWHICH OPERATION DO YOU WANT TO PERFORM?\n 1. INSERT \n 2. SEARCH \n 3. DELETE \n 4. NONE\n");
        scanf("%d",&option);
         if ( option == 1)
            {

             printf("Enter the value to be inserted ");
             scanf("%d",&doubeHash_value);
             DoubleHashing_Insert(doublehash_arr,doubeHash_value);

           }
         else if( option == 2)
          {
             printf("Enter the value to be searched ");
             scanf("%d",&doubeHash_value);
             DoubleHashing_Srch(doublehash_arr,doubeHash_value);
          }

          else if( option == 3)
          {
             printf("Enter the value to be deleted ");
             scanf("%d",&doubeHash_value);
             DoubleHashing_Del(doublehash_arr,doubeHash_value);
          }
          else
          {
           printf("*********************************************************************");
           break;
          }

     }
     return 0;
}




