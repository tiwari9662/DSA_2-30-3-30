#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
}*cn,*last,*head,*previous,*current;

struct Node *start=NULL;
struct Node* createNode()
{
    printf("Creating a Node \n");
    struct Node *node1;
    node1=(struct Node*)malloc(sizeof(struct Node*));
    if (node1==NULL)
    {
        printf("unable to allocate the memory to newNode!");
        exit(1);
    }
    printf("enter the data :");
    scanf("%d",&node1->data);
    fflush(stdin);
    return node1;
}
int find()
{
    int num,pos=0,count=0;
    printf("enter the data you want to search \n");
    scanf("%d",&num);
    fflush(stdin);
    cn=start;
    while (cn !=NULL)
    {
        ++count;
        if (cn->data == num)
        {
            pos=count;
            previous=cn;
        }
        cn=cn->link;
    }
    printf("found at position %d \n",pos);
    return pos; 
}

void binsert()
{
	struct Node *newnode;
	int data;
    int pos=find();
	newnode=createNode();

    current=previous->link;
    printf("the previous is %d and current is %d \n ",previous->data,current->data);
	if(start==NULL)
	{
        printf("there is no list available \n");
        //start=newnode;
	}
	else
    {
        newnode->link=current;
        previous->link=newnode;
    }
}

void appendNode()
{
    struct Node *newNode;
    newNode=createNode();
    if(start==NULL)
    {
        printf("creating new List \n");
        start=newNode;
        last=newNode;
        newNode->link=NULL;
    }
    else
    {
        printf("adding in old list\n");
        last=start;
		while(last->link!=NULL)
		{
			last=last->link;
		}
		last->link=newNode;
		last=newNode;
		newNode->link=NULL;
    }
}

void close()
{
    printf("Thank you! for choosing us \n");
    exit(0);
}
void printList()
{
    cn=start;
    int count=0;
    while (cn != NULL)
    {
        printf(" the data at %d node is %d \n",++count,cn->data);
        cn=cn->link;
    } 
}
int main()
{
    char ch;
    int choice;
    do
    {
        system("color 0A");
        printf("1. create first node.\n");
        printf("2. print list.\n");
        printf("3. append node \n");
        printf("4. insert in between \n");
        printf("5. find \n");
        printf("6. close \n");
        system("color 07");

        printf("enter ur choice :");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice)
        {
            case 1: appendNode();
                    break;
            case 2: printList();
                    break;
            case 3: appendNode();
                    break;
            case 4: binsert();
                    break;
            case 5: find();
                    break;
            case 6: close();
                    break;
            default:printf("there is no choice like this !");
                    break;
        }
        printf("do u want to continue[y/Y] ? : ");
        scanf("%c",&ch);
        fflush(stdin);
    } while (ch=='y' || ch=='Y');
    return 0;
}



