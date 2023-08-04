#include<stdio.h>
#include"linklist.h"
int main()
{
    linklist l,max;
    data_t sum=0;
    l=linklist_creat();
    linklist_show(l);
    linklist_reverse(l);
    linklist_show(l);
    max=linklist_2max(l,&sum);
    printf("%d\n",sum);
    linklist_free(l);
    return 0;
}