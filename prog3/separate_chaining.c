#include<stdio.h>
#include<stdlib.h>

#define size 51

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

struct search_help
{
    struct node *search_help_ptr;
    int index;
}sh1;

typedef struct search_help SH;

NODE *HASH_TABLE[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        HASH_TABLE[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    NODE *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(HASH_TABLE[key] == NULL)
        HASH_TABLE[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        NODE *temp = HASH_TABLE[key];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newNode;
    }
}

void print()
{
    int i;

    for(i=0;i<size;i++)
    {
        NODE *temp = HASH_TABLE[i];
        printf("HASH_TABLE[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

NODE *search_chaining(int value){
    NODE *PTR;
    int key = value % size;
    if(HASH_TABLE[key]==NULL){
     printf("%d th list is empty\n",key);
    }
    else
        printf("%d th list is not empty\n",key);
        for(PTR=HASH_TABLE[key];PTR->next!=NULL;PTR=PTR->next)
        {
            printf("Inside the first for loop");
            if(PTR->data==value){
                    printf("Inside the first if condition");
                    printf("Element found in %d th list",key);
                    return PTR;
                }
        }
        if(PTR->data==value){
            printf("Inside the second if condition");
            printf("Element found in %d th list",key);
            printf("Reached return statement");
            return PTR;
            }
        else
           {
             printf("element not found in %d th list and hence not in the hashtable",key);
             return NULL;
           }

    /*if(PTR->next==NULL&&flag==0){
        printf("Inside the the third if condition");
        printf("Element no");
        return NULL;}*/
}

NODE *search_chaining_deletion(int value, int *index_pointer){
    NODE *PTR;
    struct search_help
    {
    struct node *search_help_ptr;
    int index;
    }sh1;
    typedef struct search_help SH;
    int key = value % size;
    if(HASH_TABLE[key]==NULL){
     printf("%d th list is empty\n",key);
    }
    else
        printf("%d th list is not empty\n",key);
        for(PTR=HASH_TABLE[key];PTR->next!=NULL;PTR=PTR->next)
        {
            printf("Inside the first for loop");
            if(PTR->data==value){
                    printf("Inside the first if condition");
                    printf("Element found in %d th list",key);
                    *index_pointer=key;
                    return PTR;
                }
        }
        if(PTR->data==value){
            printf("Inside the second if condition");
            printf("Element found in %d th list",key);
            printf("Reached return statement");
            *index_pointer=key;
            return PTR;
            }
        else
           {
             printf("element not found in %d th list and hence not in the hashtable",key);
             *index_pointer=key;
             return NULL;
           }

    /*if(PTR->next==NULL&&flag==0){
        printf("Inside the the third if condition");
        printf("Element no");
        return NULL;}*/
}

int delete_chaining(int value)
{

    NODE *LOC, *TEMP;
    int index;
    /*struct delete_help
    {
    struct node *delete_help_ptr;
    int index_delete;
    }dh1;*/
    //printf("Line 130\n");
    //printf("Line 132\n");
    LOC=search_chaining_deletion(value,&index);
    if(LOC==NULL){
        printf("Element does not lie in the hashtable");
    }
    if(LOC==HASH_TABLE[index]){
        if(HASH_TABLE[index]->next==NULL)
            HASH_TABLE[index]=NULL;
        else
        HASH_TABLE[index]=HASH_TABLE[index]->next;
        return(value);
    }
    for(TEMP=HASH_TABLE[index];TEMP->next!=LOC;TEMP=TEMP->next)
    ;
    TEMP->next=LOC->next;
    /*if(LOC->next==NULL)
    LOC=TEMP;*/
    return(LOC->data);
}

int main()
{
    //init array of list to NULL
    int upper=10000, lower=0,i=0, new_element, search_element, delete_element, deleted_element;

    init();
    srand(time(0));
    while(i<size){
        int temp, value;
        temp=rand()%upper;
        if(temp>=lower){
            value=temp;
            insert(value);
            i++;
        }
        else
            continue;
    }

    print();
    
    printf("Enter the value of the element you want to insert");
    scanf("%d",&new_element);
    insert(new_element);

    print();

    printf("Enter the element you want to search");
    scanf("%d",&search_element);
    search_chaining(search_element);

    // printf("The value at the found address is %d",search(search_element)->data);
    printf("Enter the element you want to delete");
    scanf("%d",&delete_element);
    deleted_element=delete_chaining(delete_element);

    print();
    
    return 0;
}
