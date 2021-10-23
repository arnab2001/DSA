// cpp code for finding length of "Longest Common Subsequence"

/*
      Problem Statement:
                    Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
                    
      e.g-
         
         Input: text1 = "abcde", text2 = "ace" 
         Output: 3  
         
         Input: text1 = "abc", text2 = "def"
         Output: 0
         
*/

// Method1: Time Complexity- O(mn), Space Complexity- O(mn)

// code


#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string &a, string &b) {
     
  vector<vector<int>> m(a.size() + 1, vector<int>(b.size() + 1));
  
  for (auto i = 1; i <= a.size(); ++i)
  {
    for (auto j = 1; j <= b.size(); ++j)
    {
      if (a[i - 1] == b[j - 1]) m[i][j] = m[i - 1][j - 1] + 1;
      else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
    }
  }
      
  return m[a.size()][b.size()];
}

// Driver code
int main()
{
	string a, b;
	
	cin >> a;
	cin >> b;
	
	cout << longestCommonSubsequence(a, b);
  
	return 0;
}


// Method2: Time Complexity- O(mn), Space Complexity- O(min(m, n))

// code

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string &a, string &b) {
     
  if (a.size() < b.size()) return longestCommonSubsequence(b, a);
  
  vector<vector<int>> m(2, vector<int>(b.size() + 1));
  
  for (auto i = 1; i <= a.size(); ++i)
  {
    for (auto j = 1; j <= b.size(); ++j)
    {
      if (a[i - 1] == b[j - 1]) m[i % 2][j] = m[(i -1) % 2][j - 1] + 1;
      
      else m[i % 2][j] = max(m[(i - 1) % 2][j], m[i % 2][j - 1]);
    }
  }
      
      
  return m[a.size() % 2][b.size()];
}

// Driver code
int main()
{
	string a, b;
	
	cin >> a;
	cin >> b;
	
	cout << longestCommonSubsequence(a, b);
  
	return 0;
}
       
