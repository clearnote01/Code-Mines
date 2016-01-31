#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct trie_node
{
	struct trie_node* numdigit[10];
	int phone_number;
	//if phone number = 1, then it would imply that the number is a phone number
};

struct trie_node* create_node(int num)
{
	int i;
	struct trie_node* node = (struct trie_node*)calloc(1,sizeof(struct trie_node));
	for(i=0;i<10;i++)
	{
		node->numdigit[i] = NULL;
	}
	node->phone_number=num;
	return node;
}
int trie_insert(struct trie_node* root, int* array,int level)
{
	/*if the number returns 0, this means that the number was inserted successfully in the trie, otherwise it will return 1 because some number was already present*/
	int number = 0;
	if(level==-1)
		return 0;
		/*This would mean that there was a new insertion in the trie*/
	int bit = array[level];
	if(root->numdigit[bit]==NULL)
	{
		if (level!=0)
			root->numdigit[bit] = create_node(0);
		else 
			root->numdigit[bit] = create_node(1);
		number = trie_insert(root->numdigit[bit], array, level-1);
	}
	else
	{
		if ((root->numdigit[bit]->phone_number == 1)&&(level ==0))
			return 0;
		else if ((root->numdigit[bit]->phone_number == 1)||(level==0))
			return 1;
		else 
			number = trie_insert(root->numdigit[bit], array, level-1);
	}
	return number;
}
//global declaration of root
struct trie_node* root;
int main()
{
	int test,j;
	scanf("%d",&test);
	for(j=0;j<test;j++)
	{
		root = create_node(0);
		int no_of_phones,i,flag,k;
		scanf("%d",&no_of_phones);
		char phone[no_of_phones][10];
		for(i=0;i<no_of_phones;i++)
		{
			scanf("%s",phone[i]);
		}
		for(i=0;i<no_of_phones;i++)
		{
			int length = strlen(phone[i]);
			int array[length];
			for(k=0;k<length;k++)
			{
				array[length-k-1] = (int)phone[i][k] - 48;
			}
			int check = trie_insert(root, array, length-1);
			if (check == 1)
			{
				flag = -1;
				break;
			}
			else 
				flag = 0;
		}
		if(flag == -1)
		{
			printf("NO\n");
		}
		else 
			printf("YES\n");
	}
	return 0;
}

		
		


