#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
 };
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
        printf("Memory full\n");
        exit(0);
    }
    return x;
}
void freenode(NODE x)
{
    free(x);
}
NODE dinsert_rear(NODE head,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->rlink=NULL;
    temp->llink=NULL;
    temp->info=item;
    cur=head->llink;
    temp->llink=cur;
    cur->rlink=temp;
    head->llink=temp;
    temp->rlink=head;
    head->info=head->info+1;
    return head;
}
NODE dinsert_front(int item,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->rlink;
    head->rlink=temp;
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}
NODE f_tra(NODE head)
{
    NODE cur;
    int i=0;
    if(head->rlink==head){
        printf("list empty\n");
        return head;
    }
    printf("List :- \n");
    cur=head->rlink;
    while(cur!=head){
        i++;
        if(i%2==0){
            printf("%d\n",cur->info);
        }
        cur=cur->rlink;
    }
    return head;
}
NODE b_tra(NODE head)
{
    NODE cur;
    int i=0;
    if(head->rlink==head){
        printf("list empty\n");
        return head;
    }
    printf("List :- \n");
    cur=head->llink;
    while(cur!=head){
        i++;
        if(i%2==0){
            printf("%d\n",cur->info);
        }
        cur=cur->llink;
    }
    return head;
}
NODE insert_leftpos(int item,NODE head)
{
    NODE temp,cur,prev;
    if(head->rlink==head){
        printf("list empty\n");
        return head;
    }
    cur=head->rlink;
    while(cur!=head){
        if(item==cur->info)
            break;
        cur=cur->rlink;
    }
    if(cur==head){
        printf("key not found\n");
        return head;
    }
    prev=cur->llink;
    printf("enter towards left of %d=",item);
    temp=getnode();
    scanf("%d",&temp->info);
    prev->rlink=temp;
    temp->llink=prev;
    cur->llink=temp;
    temp->rlink=cur;
    return head;
}
NODE insert_rightpos(int item,NODE head)
{
    NODE temp,cur,prev;
    if(head->rlink==head){
        printf("list empty\n");
        return head;
    }
    cur=head->rlink;
    while(cur!=head){
        if(item==cur->info)
            break;
        cur=cur->rlink;
    }
    if(cur==head){
        printf("key not found\n");
        return head;
    }
    prev=cur->rlink;
    printf("Enter item :- ");
    temp=getnode();
    scanf("%d",&temp->info);
    prev->llink=temp;
    temp->rlink=prev;
    cur->rlink=temp;
    temp->llink=cur;
    return head;
}
NODE ddelete(int item,NODE head){
    NODE cur,prev,next;
    int j=0;
    if(head->rlink==head){
        printf("List empty\n");
        return head;
    }
    cur=head->rlink;
    prev=cur->llink;
    next=cur->rlink;
    while(cur!=head){
        j++;
        if(cur->info==item){
            printf("Key found at %d position and is deleted..\n",j);
            freenode(cur);
            prev->rlink=next;
            next->llink=prev;
            return head;
        }
        cur=cur->rlink;
        prev=cur->llink;
        next=cur->rlink;
    }
    printf("Key not found..\n");
    return head;
}
NODE ddelete_front(NODE head)
{
    NODE cur,next;
    if(head->rlink==head){
        printf("List empty\n");
        return head;
    }
    cur=head->rlink;
    next=cur->rlink;
    head->rlink=next;
    next->llink=head;
    printf("Deleted key is %d",cur->info);
    freenode(cur);
    return head;
}
NODE ddelete_rear(NODE head)
{
    NODE cur,prev;
    if(head->rlink==head){
        printf("List empty\n");
        return head;
    }
    cur=head->llink;
    prev=cur->llink;
    head->llink=prev;
    prev->rlink=head;
    printf("Deleted key is %d",cur->info);
    freenode(cur);
    return head;
}
NODE delete_all_key(int item,NODE head)
{
    NODE prev,cur,next;
    int count;
    if(head->rlink==head){
        printf("List empty..");
        return head;
    }
    count=0;
    cur=head->rlink;
    while(cur!=head){
        if(item!=cur->info)
            cur=cur->rlink;
        else{
            count++;
            prev=cur->llink;
            next=cur->rlink;
            prev->rlink=next;
            next->llink=prev;
            freenode(cur);
            cur=next;
        }
    }
    if(count==0)
        printf("Key not found");
    else
        printf("Key found at %d positions and are deleted\n",count);
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head->rlink==head){
        printf("List empty..\n");
        return;
    }
    for(temp=head->rlink;temp!=head;temp=temp->rlink){
        printf("%d\n",temp->info);
    }
}
void search(int item,NODE head){
    NODE temp;
    int j=0;
    temp=head->rlink;
    while(temp!=head){
        j++;
        if(temp->info==item){
            printf("Item found and its position is %d\n",j);
            return;
        }
        temp=temp->rlink;
    }
    printf("Search unsuccessful\n");
}
NODE delete_all(int item,NODE head)
{
    NODE prev,cur,next;
    int count;
    if(head->rlink==head){
        printf("LE");
        return head;
    }
    count=0;
    int j=0;
    cur=head->rlink;
    while(cur!=head){
        if(item!=cur->info)
            cur=cur->rlink;
        else{
            j++;
            if(j==1){
                cur=cur->rlink;
            }
            if(item==cur->info){
                count++;
                prev=cur->llink;
                next=cur->rlink;
                prev->rlink=next;
                next->llink=prev;
                freenode(cur);
                cur=next;
            }
        }
    }
    if(count==0)
        printf("Repeated key not found");
    else
        printf(" Repeated key found at %d positions and are deleted\n",count);
    return head;
}
int main()
{
    int item,choice;
    NODE head;
    head=getnode();
    head->rlink=head;
    head->llink=head;
    for(;;){
        printf("\n1.Insert_rear\n2.Insert front\n3.Insert at left of given key\n4.Insert at right of given key\n5.Delete\n6.Delete front\n7.Delete rear\n8.Delete all key element\n9.Delete duplicates\n10.Search\n11.Display\n12.Forward traverse\n13.Backward traverse\n14.Exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the item at rear end :- ");
                scanf("%d",&item);
                head=dinsert_rear(head,item);
                break;
            case 2: printf("Enter the item at front end :- ");
                scanf("%d",&item);
                head=dinsert_front(item,head);
                break;
            case 3:printf("Enter the key in whose left position you want to insert an item :- ");
                scanf("%d",&item);
                head=insert_leftpos(item,head);
                break;
            case 4:printf("Enter the key in whose right position you want to insert an item :- ");
                scanf("%d",&item);
                head=insert_rightpos(item,head);
                break;
            case 5:printf("Enter the key :- ");
                scanf("%d",&item);
                head=ddelete(item,head);
                break;
            case 6:head=ddelete_front(head);
                break;
            case 7:head=ddelete_rear(head);
                break;
            case 8:printf("Enter the key item :- \n");
                scanf("%d",&item);
                head=delete_all_key(item,head);
                break;
            case 9:printf("Enter the key whose every copy you want to delete :- ");
                scanf("%d",&item);
                head=delete_all(item,head);
                break;
            case 10:printf("Enter item to be searched :- ");
                scanf("%d",&item);
                search(item,head);
                break;
            case 11:printf("List:-\n");
                display(head);
                break;
            case 12:head=f_tra(head);
                break;
            case 13:head=b_tra(head);
                break;
            case 14:exit(0);
                break;
            default:printf("Enter proper instructions!!!");
                break;
        }
    }
    return 0;
}
