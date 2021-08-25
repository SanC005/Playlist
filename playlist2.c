#include <stdio.h>
#include <stdlib.h>

//Creating Node
struct node
{
    char data[200];
    struct node *next;
};
struct node *head,*newnode,*temp;
int count=0;

//Function for inserting song to playlist
void insertsong()
{
count+=1;
newnode=(struct node *)malloc(sizeof(struct node *));
printf("enter the Song u want to insert: ");
scanf("%s", &newnode->data);
            newnode->next = head;
            head = newnode;
            printf("\nSong has been inserted\n");
};

//Function for deleting song from playlist
void deletesong()
{
    int pos,i=1;
    temp=head;
    printf("enter position: ");
    scanf("%d",&pos);
    if (pos>count)
    {
        printf("Invalid position entered\n");
    }
    else if (pos==1)
    {

        temp=head;
        head=temp->next;
        free(temp);

    }
    else {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
    newnode=temp->next;
    temp->next=newnode->next;
    free(newnode);
    }
    count-=1;
}

//Function to display playlist
void display() {
    struct node *current = head;
    if(head==0) {
        printf("Playist is empty\n");
        return;
    }
    printf("List of songs in playlist \n");
    while(current!=0)
    {
        printf("%s\n", current->data);
        current=current->next;
    }
    printf("\n");
}
void main()
{
    int n;
    while (n!=-1){
        printf(" Enter 1 to insert a song\n Enter 2 to delete a song\n Enter 3 to display the playlist\n Enter -1 to exit\n");
        scanf("%d",&n);
        if (n==1)
            insertsong();
        else if(n==2)
            deletesong();
        else if (n==3)
            display();
        else if(n==-1)
            break;
    }
}
