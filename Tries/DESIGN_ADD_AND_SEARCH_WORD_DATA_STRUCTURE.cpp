//https://leetcode.com/problems/design-add-and-search-words-data-structure/
class Node{
    public:
    bool endOfWords = false;
    Node* children[26];
};
class WordDictionary {
    Node * root ;
public:
    WordDictionary() {
        root = new Node() ;
    }
    
    void addWord(string word) {
        Node* node = root ;
        for(auto ch : word){
            if(node -> children[ch - 'a'] == NULL){
                node -> children[ch - 'a'] = new Node() ;
            }
            node = node -> children[ch - 'a'] ;
        }
        node -> endOfWords = true ;
    }
    bool searchSub(Node * node , string& word){

        int i = 0 ;
        for(auto ch : word){
            if(ch != '.'){
                if(node -> children[ch - 'a'] == NULL) return false;
            }else{
                string subStr = word.substr(i+1);
                for(int i = 0 ; i < 26 ; i++){
                    bool willFind = false;
                    if(node -> children[i] != NULL)
                    willFind = searchSub(node -> children[i] , subStr);
                    if(willFind == true) return true ;
                }
                return false;
            }
            node = node -> children[ch - 'a'] ;
             i += 1;
        }
        
        
        return node -> endOfWords;
    }
    bool search(string word) {
        int i = 0 ;
        Node * node = root ;
        for(auto ch : word){
            if(ch != '.'){
                if(node -> children[ch - 'a'] == NULL) return false;
            }else{
                
                string subStr = word.substr(i+1);
                for(int i = 0 ; i < 26 ; i++){
                    bool willFind = false;
                    if(node -> children[i] != NULL)
                    willFind = searchSub(node -> children[i] , subStr);
                    if(willFind == true) return true ;
                }
                return false;
            }
            node = node -> children[ch - 'a'] ;
            i += 1;
        }
        
        
        return node -> endOfWords;
    }
};

//Sir ka code
class Node{
    public:
    bool endOfWords = false;
    Node* children[26];
};
class WordDictionary {
    Node * root ;
public:
    WordDictionary() {
        root = new Node() ;
    }
    
    void addWord(string word) {
        Node* node = root ;
        for(auto ch : word){
            if(node -> children[ch - 'a'] == NULL){
                node -> children[ch - 'a'] = new Node() ;
            }
            node = node -> children[ch - 'a'] ;
        }
        node -> endOfWords = true ;
    }
    bool searchSub(Node * root , string& word , int index){
        if(index == word.length()) return root -> endOfWords ;
        if(word[index] != '.'){
            if(root -> children[word[index] - 'a'] == NULL){
                return false;
            }else{
                return searchSub(root -> children[word[index] - 'a'] , word , index + 1);
            }
        }else{
            for(int i = 0 ; i < 26 ; i++){
                if(root -> children[i] != NULL){
                    bool isPresent = searchSub(root -> children[i] , word , index + 1);
                    if(isPresent) return true ;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        
        return searchSub(root , word , 0);
    }
};
