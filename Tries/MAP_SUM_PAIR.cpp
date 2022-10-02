//https://leetcode.com/problems/map-sum-pairs/
class Node{
    public:
    int sumTillNow = 0 ;
    Node* children[26];
};
class MapSum {
    Node * root ;
public:
    MapSum() {
        root = new Node() ;
    }
    
    void insert(string key, int val) {
        Node* node = root ;
        int prevSum = 0 ;
        for(auto ch : key){
            if(node -> children[ch - 'a'] == NULL){
                node -> children[ch - 'a'] = new Node() ;
            }
            node = node -> children[ch - 'a'] ;
        }
        node -> sumTillNow = val ;

    }
    void calculateSum(Node* node ,int & sum){
        sum += node -> sumTillNow ;
        for(auto child : node -> children){
            if(child != NULL){
                calculateSum(child , sum);
            }
        }
    }
    int sum(string prefix) {
        Node* node = root ; 
        int sum = 0;
        for(auto ch : prefix){
            if(node -> children[ch -'a'] == NULL) return 0;
            node = node -> children[ch - 'a'] ;
        }
        calculateSum(node , sum) ;
        return sum ;
    }
};
