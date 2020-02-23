//6210451462 Wannakan Tangyen
#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int data; 
    struct node * next; 
};  

void sortedInsert(struct node ** compare, struct node * new) 
{ 
    struct node * before; 
    if (*compare == NULL || (*compare)->data >= new->data) 
    { 
        new->next = *compare; 
        *compare = new; 
    } 
    else
    { 
        before = *compare; 
        while (before->next!=NULL && before->next->data < new->data) 
        { 
            before = before->next; 
        } 
        new->next = before->next; 
        before->next = new; 
    } 
} 
  
struct node  *newNode(int new_data) 
{ 
    struct node * new = (struct node *) malloc(sizeof(struct node )); 
    new->data  = new_data; 
    new->next =  NULL; 
    return new; 
} 
  
void printList(struct node  *head) 
{ 
    struct node  *temp;
    for (temp=head; temp; temp = temp->next)
        printf("%d\n", temp->data);    
} 
  
int main() 
{ 
    int num;
    struct node* head = NULL; 
    while(1)
    {scanf("%d", &num);
    if(num <= -1)
        break;
    else
    {struct node *new = newNode(num); 
    sortedInsert(&head, new); 
    }
    }

    printList(head); 
  
}