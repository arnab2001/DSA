// Time limit: 1.00 s Memory limit: 512 MB
// Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.
//https://cses.fi/problemset/task/1662
// Input:
// 5
// 3 1 2 7 4

// Output:
// 1

void harshit(){
    int n;
    cin>>n;
    vector<int> arr(n);
    f(i,n) cin>>arr[i];
    
    int res=0;
    map<int,int> mp;
    int sum=0;
    mp[0]=1;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        res+=mp[(sum%n+n)%n];
        mp[(sum%n+n)%n]++;
    }
    cout<<res;
}