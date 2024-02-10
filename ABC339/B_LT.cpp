#include<stdio.h>
#include<string.h>

int main(void){
    int H,W,N;

    scanf("%d %d %d", &H, &W, &N);
    int map[W][H];
    int x=0,y=0;
    int hou=1;
    for(int j=0;j<H;j++){
        for(int i=0;i<W;i++){
            map[i][j]=0;
        }
    }

    for(int i=0;i<N;i++){
        if(map[x][y]!=1){
            map[x][y]=1;
            if(hou==1){
                hou=2;
                x++;
            }
            else if(hou==2){
                hou=3;
                y++;
            }
            else if(hou==3){
                hou=4;
                x--;
            }
            else if(hou==4){
                hou=1;
                y--;
            }
        }
        else{
            map[x][y]=0;
            if(hou==1){
                hou=4;
                x--;
            }
            else if(hou==2){
                hou=1;
                y--;
            }
            else if(hou==3){
                hou=2;
                x++;
            }
            else if(hou==4){
                hou=3;
                y++;
            }
        }
        if(y<0)y=H-1;
            if(y>=H)y=0;
            if(x<0)x=W-1;
            if(x>=W)x=0;
        
    }
    for(int j=0;j<H;j++){
        for(int i=0;i<W;i++){
            if(map[i][j]==1){
                printf("#");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}