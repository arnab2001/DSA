//https://leetcode.com/problems/longest-word-in-dictionary/

//TRIE
class Node{
  public:
    bool endOfWord = false;
    Node* children [26] ;
};
class Solution {
    Node * root = new Node() ;
public:
    void insert(string word) {
        Node* node = root ;
        for(auto ch : word){
            if(node -> children[ch -'a'] == NULL){    
                node -> children[ch - 'a'] = new Node() ;
            }
            node = node -> children[ch - 'a'];
        }
        
        node -> endOfWord = true ;
    }
    void helper(Node* node , string wordSoFar , string &ans){
        if(wordSoFar.length() > ans.length()) ans = wordSoFar ;
        for(int i = 0 ; i < 26 ; i+=1){
            if(node -> children[i] != NULL and node -> children[i] -> endOfWord){
                string s(1, 'a'+i);
                helper(node -> children[i] , wordSoFar + s , ans);
            }
        }
    }
    string longestWord(vector<string>& words) {
        for(auto word : words){
            insert(word);
        }
        string ans = "";
        helper(root , "" , ans);
        return ans ;
    }
};
//hashmap
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        int n=words.size();
        int g=0;
        string ans;
        unordered_map<string,bool> m;
        for(int i=0;i<n;i++)
        {
            if(m[words[i].substr(0,words[i].length()-1)]||words[i].length()==1)
            {
                m[words[i]]=true;
                if(words[i].length()>ans.length())
                {
                    ans=words[i];
                    g=words[i].length();
                }
            }
        }
        return ans;
    }
};
