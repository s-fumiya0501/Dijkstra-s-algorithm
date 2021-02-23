#include<stdio.h>
#include<stdbool.h>
#define N 17
#define M -1
int a[N][N]={
                 {0,410,900,M,M,M,M,M,M,M,M,M,M,M,M,M,M},
                 {410,0,M,440,M,M,M,M,M,M,M,M,M,M,M,M,M},
                 {900,M,0,250,M,M,M,M,M,M,640,M,M,M,M,M,M},
                 {M,440,250,0,M,230,M,M,M,M,M,M,M,M,M,M,M},
                 {M,360,M,M,0,240,550,M,M,M,M,M,M,M,M,M,M},
                 {M,M,M,230,240,0,240,M,M,660,M,M,M,M,M,M,M},
                 {M,M,M,M,550,240,0,660,M,M,M,M,M,M,M,M,M},
                 {M,M,M,M,M,M,660,0,340,M,M,M,M,M,590,M,M},
                 {M,M,M,M,M,M,M,340,0,140,M,M,M,470,M,M,M},
                 {M,M,M,M,M,660,M,M,140,0,470,M,470,M,M,M,M},
                 {M,M,640,M,M,M,M,M,M,M,0,1700,M,M,M,M,M},
                 {M,M,M,M,M,M,M,M,M,M,M,0,240,M,M,M,170},
                 {M,M,M,M,M,M,M,M,M,470,M,240,0,180,M,M,M},
                 {M,M,M,M,M,M,M,M,470,M,M,M,180,0,450,M,180},
                 {M,M,M,M,M,M,590,M,M,M,M,M,M,M,0,M,M},
                 {M,M,M,M,M,M,M,M,M,M,M,M,M,M,M,0,190},
                 {M,M,M,M,M,M,M,M,M,M,M,170,M,180,M,190,0}
                 
                 };

void main(void){
    int npoint =N;
    int sp;
    int dp;

    printf("start->");
    scanf("%d",&sp);
    printf("goal->");
    scanf("%d",&dp);
    sp=sp-1;
    dp=dp-1;

    int sRoute[N];
    int sDist;

    int pdist[N];
    int pRoute[N];
    bool pfixed[N];
    int spoint,i,j,newdist;

    sDist=99999;

    for(i=0;i<npoint;i++){
        sRoute[i]=-1;
        pdist[i]=99999;
        pfixed[i]=false;
    }

    pdist[sp]=0;
    while(true){
        i=0;
        while(i<npoint){
            if(pfixed[i]==0){
                break;
            }
            i=i+1;
        }
        if(i==npoint){
        break;
        }
        for(j=i+1;j<npoint;j++){
            if((pfixed[j]==0)&&(pdist[j]<pdist[i])){
                i=j;
            }
        }
        spoint=i;
        pfixed[spoint]=true;

        for(j=0;j<npoint;j++){
            if((a[spoint][j]>0)&&(pfixed[j]==0)){
                newdist=pdist[spoint]+a[spoint][j];
                if(newdist<pdist[j]){
                    pdist[j]=newdist;
                    pRoute[j]=spoint;
                }
            }
        }
    }
    sDist=pdist[dp];
    j=0;
    i=dp;
     while(i!=sp){
         sRoute[j]=i;
         i=pRoute[i];
         j=j+1;
     }

     sRoute[j]=sp;

     printf("出発地点から目的地までの最短経路\n");
     for(i=j;i>=0;i--){
         printf("%d->",sRoute[i]+1);
     }
     printf("\n出発地点から目的地の最短距離= %d",sDist);

    
 
}
