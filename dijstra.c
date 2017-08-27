#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max=9999999;

int n;
int ans = 99999999;
int hogya[50001] = {0};
int max1(int a,int b){
    if(a>b) return a;
    else return b;
}
int min1(int a,int b){
    if(a<b) return a;
    else return b;
}
struct node{
    int data;
    struct node* next;
    int weight;
};








int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int e;
    scanf("%d %d\n",&n,&e);
    
    struct node* arr = (struct node*)malloc(n*sizeof(struct node));
    
    for (int i=0;i<n;i++){
        arr[i].data = i+1;
        arr[i].next = NULL;
        arr[i].weight = max;
    }
    
    for (int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d\n",&u,&v,&w);
        if (u==v) continue;
        
        struct node * x = (struct node *)malloc(sizeof(struct node));
        struct node * y = (struct node *)malloc(sizeof(struct node));
        struct node * p = arr + u-1;
        struct node * q = arr + v-1 ;
        
        x->next = q->next;
        y->next = p->next;
        x->data = u;
        y->data = v;
        q->next = x;
        p->next = y;
        x->weight = w;
        y->weight = w;
        
        
        
    }
    
    int visited[50001] = {0};
    int min[n];
    for (int i=0;i<n;i++) min[i]=9999999;
    
    int min_index = 1;
    int dist_till_now = 0;
    
    for (int i=0;i<n;i++){
        //if (hogya[n-1]==1) break;
        
        hogya[min_index-1]=1;
        
        struct node *p = arr + min_index - 1;
        p = p->next;
        
        while(p!=NULL){
            //printf("%d\n",p->data);
            if(hogya[p->data-1]==0){
                
                min[p->data-1] = min1(max1(dist_till_now,p->weight),min[p->data-1]);
                
            }
            p=p->next;
        }
        dist_till_now = 9999999;
        for (int i=0;i<n;i++){
            //printf("%d ",min[i]);
            if(hogya[i]==0){
                if (min[i]<dist_till_now){
                    dist_till_now = min[i];
                    min_index = i+1;
                }
            }
        }//printf("\n");
        
        
        
    }
    
    
    
    if (min[n-1] == 9999999) {
        printf("NO PATH EXISTS\n");
        return 0;
    }
    
    printf("%d\n",min[n-1]);
    
    
    return 0;
}
