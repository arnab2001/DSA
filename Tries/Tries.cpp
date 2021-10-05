#include<bits/stdc++.h>
using namespace std;

class Node{
        public:
                Node* arr[26];
                bool flag =false;

                bool isContains(Node * node, char ch){
                        if(node->arr[ch - 'a'] == NULL)
                                return false;
                        else
                                return true;
                }
                void place(char ch, Node * newNode){
                        arr[ch - 'a'] = newNode;
                }
                Node* getNext ( char ch){
                        return arr[ch-'a'];
                }
                void setFlag(){
                        this->flag = true;
                }
};
Node* root = new Node();

void insert(string word){
        Node *temp = root;
        for (int i = 0; i < word.size();i++){
                if( ! temp->isContains(temp, word[i])){
                        Node *newNode = new Node();
                        temp->place(word[i], newNode);
                }
                temp = temp->getNext(word[i]);
        }
        temp->setFlag();
}

bool search(string word){
        Node *temp = root;
        for (int i = 0; i < word.size();i++){
                if(temp->isContains(temp, word[i]))
                        temp = temp->getNext(word[i]);
                else 
                        return false;
        }
        return temp->flag;
}
int main(){
        string str[] = {"sarvesh", "kumar", "sarves", "kum"};
        for (int i = 0; i < 4;i++)
                insert(str[i]);

        for (int i = 0; i < 4;i++)
                search(str[i]) ? cout << "True" << endl : cout << "False" << endl;
        search("sarve") ? cout << "True" << endl : cout << "False" << endl;
}