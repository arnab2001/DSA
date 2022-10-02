// Link - https://codeforces.com/contest/1398/problem/C
// You are given an array a1,a2,…,an consisting of integers from 0 to 9. A subarray al,al+1,al+2,…,ar−1,ar is good if the sum of elements of this subarray is equal to the length of this subarray (∑i=lrai=r−l+1).

// For example, if a=[1,2,0], then there are 3 good subarrays: a1…1=[1],a2…3=[2,0] and a1…3=[1,2,0].

// Calculate the number of good subarrays of the array a.

// arr[r]- arr[l] = r-l;
// arr[r]- r = arr[l]- l
//
void harshit(){
    int n;
    cin>>n;
    string s; cin>>s;
    vector<int> arr(n+1,0);
    // f(i,n){
    //     arr[i+1] = arr[i]+ (s[i]-'0');
    // }
    int sum=0;
    map<int,int> mp;
    mp[0]=1;
    int res=0;
    for(int i=0; i<n; i++){
        sum+=(s[i]-'0');
        int x = sum - i -1;
        mp[x]+=1;
    }
    for(auto k: mp){
        res+=k.second * (k.second-1)/2;
    }
    cout<<res<<endl;
}