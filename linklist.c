#include<stdio.h>
#include"linklist.h"
#include<stdlib.h>
//
//
linklist linklist_creat()
{
    linklist l,be;
    data_t value=0;
    l=(linklist)malloc(sizeof(listnode));
    l->data=-1;
    l->next=NULL;
    if(l==NULL)
    printf("creating is fail");
    be=l;
    printf("input: ");
    scanf("%d",&value);
    while(value!=-1)
    {
        be->next=(linklist)malloc(sizeof(listnode));
        be->next->data=value;
        be->next->next=NULL;
        be=be->next;
        printf("input: ");
        scanf("%d",&value);
    }
    return l;
}


//
//
linklist linklist_link(linklist l,data_t value)
{
    l->next=(linklist)malloc(sizeof(listnode));
    l->next->data=value;
    l->next->next=NULL;
    return l->next;
}



//
//
int linklist_insert(linklist l,data_t value,int position)
{
    //
    //
    linklist p,s;
    p=linklist_get(l,position-1);
    s=p->next;
    p->next=(linklist)malloc(sizeof(listnode));
    p->next->next=s;
    p->next->data=value;
    return 1;
    //
    //
    /*linklist b,n;
    b=linklist_get(l,position-1);
    if(b==NULL)
    {
        printf("position is fail");
        return -1;
    }
    n=(linklist)malloc(sizeof(listnode));
    n->next=b->next;
    n->data=value;
    b->next=n;
    return 1;*/
}

int linklist_locate(linklist l,data_t value)
{
    int i=0;
    linklist sp=l->next;
    while (sp!=NULL)
    {
        if(sp->data == value)
        {
            return i;
        }
        i++;
        sp=sp->next;
    }
    return 0;
}


//
//
linklist linklist_get(linklist l,int position)
{
    linklist s=l;//地址参变量
    if(position<-1)
    { 
        printf("position is fail\n");
        return NULL;
    }
    while(position+1)
    {  
        s=s->next;
        if(s==NULL)
        break;
        position--;
    }
    return s;
}

//
//
void linklist_show(linklist l)
{
    linklist s=l->next;
    while(s!=NULL)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}

//
//
//
int linklist_delete(linklist l,int position)
{
    linklist head,now;
    head=linklist_get(l,position-1);
    if(head==NULL||head->next==NULL)
    {
        printf("position is fail\n");
        return -1;
    }
    now=head->next;
    head->next=now->next;
    printf("delete %d\n",now->data);
    free(now);
    return 0;
}

//
//
void linklist_free(linklist l)
{
    linklist de=l;
    while (l!=NULL)
    {
        de=l;
        l=l->next;
        free(de);  
    }
}

//
//
int linklist_reverse(linklist l)
{
    if(l==NULL||l->next==NULL)
    {
        return -1;
    }
    linklist sp,ins;
    ins=l->next->next;
    l->next->next=NULL;
    while(ins!=NULL)
    {
        sp=ins->next;
        ins->next=l->next;
        l->next=ins;
        ins = sp ;
    }
    return 0;
}
//
linklist linklist_2max(linklist l,data_t *sump)
{
    linklist maxlink;
    if(l==NULL||l->next==NULL)
    {
        printf("the linklist is not fit");
        return NULL;
    }
    data_t max=0;
    linklist sp=l->next;//sp指向0
    while(sp->next!=NULL)
    {
        if(sp->data+sp->next->data>max)
        {
            maxlink=sp;
            max=sp->data+sp->next->data;
        }
        sp=sp->next;
        *sump=max;
    }
    return maxlink;
}
