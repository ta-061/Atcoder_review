#include<stdio.h>

int main(void){
    int N;

    scanf("%d",&N);
    long long A;
    long long ans=0;
    for(int j=0;j<N;j++){
        scanf("%lld", &A);
        ans+=A;
        if(ans<0){
            ans=0;
        }
    }
    printf("%lld",ans);
}