void pN(struct node* p,struct node** next)
{
 
if(p){
    
    
    pN(p->right,next);
    p->next=*next;
    *next=p;
    pN(p->left,next);
}

}
void populateNext(struct node* p)
{
struct node* next=NULL;
pN(p,&next);


}
