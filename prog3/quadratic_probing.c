#include <stdio.h>
#include <stdlib.h>
int Quad_hash_fun(int Quad_value)
{
	return Quad_value % 50;
}

int Quadratic_Insert(int quad_arr[], int Quad_value)
{
	int h = Quad_hash_fun(Quad_value);
	// printf("this is h %d",h);
	if (quad_arr[h] == -1)
	{
		quad_arr[h] = Quad_value;
		// printf("\nThe value %d is insert at key %d in the hash table",Quad_value,h);
		return 1;
	}

	// Else if works in the case of duplication
	else if (quad_arr[h] == Quad_value)
	{
		printf("No Duplicates are allowed in the hash table ");
		return 0;
	}

	// Else works in the case of collision
	else
	{
		for (int i = 1; i < 50; i++)
		{
			int t = (h + (i * i)) % 50;
			if (quad_arr[t] == -1)
			{
				quad_arr[t] = Quad_value;
				// printf("The value %d is insert at key %d in the hash table",Quad_value,t);
				return 1;
			}
			else if (quad_arr[t] == Quad_value)
			{
				printf("\nNo Duplicates are allowed in the hash table ");
				return 0;
			}
			else
				// printf("\ncontinue....");
				continue;
		}
	}
	return 0;
}
int UpdatedHashTable(int quad_arr[])
{
	for (int i = 0; i < 50; i++)
	{
		printf(" %d", quad_arr[i]);
	}
	return 0;
}
int Quadratic_Srch(int quad_arr[], int Quad_value)
{
	int h = Quad_hash_fun(Quad_value);
	if (quad_arr[h] == Quad_value)
	{
		printf("The value %d is found at key %d in the hash table\n", Quad_value, h);
		return 1;
	}

	else if (quad_arr[h] == -1)
	{
		printf("The value %d is not found in the hash table\n", Quad_value);
		return 0;
	}

	else
		for (int i = 1; i < 50; i++)
		{
			int t = (h + i * i) % 50;
			if (quad_arr[t] == Quad_value)
			{
				printf("The Quad_value %d is found at key %d in the hash table\n", Quad_value, t);
				return 1;
			}
			else
				continue;
		}
	printf("The value not found");
	return 0;
}
int Quadratic_Del(int quad_arr[], int Quad_value)
{
	int h = Quad_hash_fun(Quad_value);
	if (quad_arr[h] == Quad_value)
	{
		quad_arr[h] = -99;
		printf("The value %d is deleted at key %d in the hash table\n", Quad_value, h);
		return 1;
	}

	else if (quad_arr[h] == -1)
	{
		printf("The value %d is not found in the hash table\n", Quad_value);
		return 0;
	}

	else
		for (int i = 1; i < 50; i++)
		{
			int t = (h + i * i) % 50;
			if (quad_arr[t] == Quad_value)
			{
				quad_arr[t] = -99;
				printf("The value %d is deleted at key %d in the hash table\n", Quad_value, t);
				return 1;
			}
			else
				continue;
		}
	printf("The value not found\n");
	return 0;
}
int main()
{
	int Quad_value;
	int option;
	printf("THIS IS THE PROGRAM FOR QUADRATIC PROBING\n");
	int quad_arr[50];
	for (int i = 0; i < 50; i++)
	{
		quad_arr[i] = -1;
		printf(" %d", quad_arr[i]);
	}
	while (1)
	{
		printf("\n*********************************************************************");
		printf("\nOur current Hash table is :\n");
		UpdatedHashTable(quad_arr);
		printf("\n*********************************************************************");
		printf("\nWHICH OPERATION DO YOU WANT TO PERFORM?\n 1. INSERT \n 2. SEARCH \n 3. DELETE \n 4. NONE\n");
		scanf("%d", &option);
		if (option == 1)
		{

			printf("Enter the value to be inserted ");
			scanf("%d", &Quad_value);
			Quadratic_Insert(quad_arr, Quad_value);
		}
		else if (option == 2)
		{
			printf("Enter the value to be searched ");
			scanf("%d", &Quad_value);
			Quadratic_Srch(quad_arr, Quad_value);
		}

		else if (option == 3)
		{
			printf("Enter the value to be deleted ");
			scanf("%d", &Quad_value);
			Quadratic_Del(quad_arr, Quad_value);
		}
		else
		{
			printf("*********************************************************************");
			break;
		}
	}
	return 0;
}
