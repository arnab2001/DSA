//Partition Problem


class Solution{
public:
    bool isSubsetSum(int arr[], int sum,int n){
        // code here 
        //int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<n+1;i++)
        {
           for(int j=0;j<sum+1;j++)
           {
               if(i==0) dp[i][j]=false;
               if(j==0) dp[i][j]=true;
           }
        }
        //for(int j=0;j<sum+1;)
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1]<=j)
                {
                    //dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);
                    dp[i][j]=(dp[i-1][j-arr[i-1]]||dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        if(N==0) return 1;
        else
        {
            int sum=0;
            for(int i=0;i<N;i++) sum+=arr[i];
            if(sum%2!=0) return false;
            else if(sum%2==0) return isSubsetSum(arr,sum/2,N);
        }
    }
};