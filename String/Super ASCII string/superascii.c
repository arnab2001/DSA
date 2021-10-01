//Super Ascii String Checker - CODEVITA
//Priyanka Kothari

#include <stdio.h>
#include <string.h>

int main()
{
    int t,k=0;
    scanf("%d",&t);
    char arr[100];
    int ans[100]={0};
    while(t--){
        int index[100]={0};
        int flag=1;
        scanf("%s",arr);
        
        for(int i=0;i<strlen(arr);i++){
            int idx=arr[i]-'a'+1;
            index[idx-1]++;
        }
        
        for(int i=0;i<strlen(arr);i++){
            int reidx=arr[i]-'a'+1;
            if(index[reidx-1]!=reidx){
                flag=0;
                break;
            }
        }
        ans[k]=flag;
        k++;
    }
        
    for(int i=0;i<k;i++){
        if(ans[i]==0){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
    return 0;
}