class Longest_subsequence{
    public static void main(String args[]) {
        String str = "axxxy";
        int n = str.length();
        int[][] dp = new int[n+1][n+1];
  
        // Fill dp table (similar to LCS loops)
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                // If characters match and indexes are not same
                if (str.charAt(i-1) == str.charAt(j-1) && i!=j)
                    dp[i][j] =  1 + dp[i-1][j-1];         
                       
                // If characters do not match
                else
                    dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
                for(int l=0;l<n;l++){
                    for(int k=0;k<n;k++)
                        System.out.print(dp[l][k] + " ");
                    System.out.println();
                } 
                System.out.println("X---X");
            }
        }
        System.out.println(dp[n][n]);
    }
}