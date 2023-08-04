typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *next;
}listnode,*linklist;


linklist linklist_creat();
void linklist_show(linklist l);
linklist linklist_get(linklist l,int position);
int linklist_delete(linklist l,int position);
void linklist_free(linklist l);
linklist linklist_link(linklist l,data_t value);
int linklist_insert(linklist l,data_t value,int position);
int linklist_locate(linklist l,data_t value);
int linklist_reverse(linklist l);
linklist linklist_2max(linklist l,data_t *sump);