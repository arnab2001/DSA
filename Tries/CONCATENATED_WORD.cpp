//https://leetcode.com/problems/concatenated-words/
class Node{
public :
    bool endOfWord = false; 
    Node* children[26];
};
class Solution {
    Node* root = new Node() ;
public:
    void insert(string& word){
        Node* node = root ;
        
        for(auto ch : word){
            if(node -> children[ch- 'a'] == NULL){
                node -> children[ch - 'a'] = new Node() ;
            }
            node = node -> children[ch - 'a'];
        }
        node -> endOfWord = true ;
    }
    bool isComplex(int index , int wordSoFar , string & word){
        if(index == word.length()){
            if(wordSoFar >= 2) return true ;
            return false;
        }
        Node* node = root ;
        for(int i = index ; i < word.length() ; i++){
            if(node -> children[word[i] - 'a'] == NULL) return false ;
            node = node -> children[word[i] - 'a'] ;
            if(node -> endOfWord == true){
                bool findNext = isComplex(i + 1, wordSoFar + 1 , word);
                if(findNext == true) return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto word : words){
            insert(word);
        }
        vector<string> ans;
        
        for(auto word : words){
            if(isComplex(0 , 0 , word)){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};
