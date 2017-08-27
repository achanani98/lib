#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define max 10000000

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        int m;
        scanf("%d %d",&n,&m);
        int *man[n];
        int min[n];
        int *adj[n];
        int hogya[n];
        for (int i=0;i<n;i++){
            man[i]=(int *)malloc(n*sizeof(int));
            adj[i]=(int *)malloc(n*sizeof(int));
        }
        
        for (int i=0;i<n;i++){
            min[i]=max;
            hogya[i]=0;
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                adj[i][j]=max;
                man[i][j]=max;
                if (i==j) adj[i][j]=0;
            }
        }
        for(int a1 = 0; a1 < m; a1++){
            int x; 
            int y; 
            int r; 
            scanf("%d %d %d",&x,&y,&r);
            if(r<adj[x-1][y-1]) adj[x-1][y-1]=r;
            if(r<adj[y-1][x-1]) adj[y-1][x-1]=r;
        }
        int s; 
        scanf("%d",&s);
        
        int dist_till_now=0;
        int smallest_index=s-1;
        int smallest_dist=max;
        int next_small=n;
        
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                
                
                if(i==0){
                    man[i][j]=adj[smallest_index][j];
                    min[j]=man[i][j];
                }
                else{
                    if(hogya[j]==0){
                        if(min[j]>adj[smallest_index][j]+dist_till_now) min[j]=adj[smallest_index][j]+dist_till_now;
                        man[i][j]=min[j];    
                        
                    }
                    else{
                        man[i][j]=min[j];
                    }
                    
                    
                }
                if(man[i][j]<smallest_dist){
                    if(j!=smallest_index&&hogya[j]==0){
                        smallest_dist=man[i][j];
                        next_small=j;
                    }
                }
            }
            
            hogya[smallest_index]=1;
            smallest_index=next_small;
            dist_till_now=smallest_dist;
            smallest_dist=max;
            
        }
        for (int j=0;j<n;j++){
            if(j!=s-1&&min[j]!=max) printf("%d ",min[j]);
            else if(j!=s-1&&min[j]==max){
                printf("%d ",-1);
            }
        }printf("\n");
        
        
    }
    return 0;
}
