#include<bits/stdc++.h>
using namespace std;
bool isSafe(vector<string>&crosssword, int i, int j, char ch){
        if(crosssword[i][j] == '-' || crosssword[i][j] == ch)
                return true;
        else
                return false;
}

bool fillVertical(vector<string> & crossword ,int k, int l, string w, int i, int size){
        if(i>=size){
                return true;
        } 
        if(k>=crossword.size() || l>=crossword[0].size()){
                return false;
        }
        if(isSafe(crossword, k, l, w[i]) ){
                char x = crossword[k][l];
                crossword[k][l] = w[i];
                bool isallfilled = fillVertical(crossword, k, l + 1, w, i + 1, size);

                if(!isallfilled)
                        crossword[k][l] = x;
                return isallfilled;
        }
        return false;
}


bool fillHorizontal(vector<string> & crossword, int k, int l, string w, int i, int size){
        if(i>=size){
                return true;
        }
        if(k>=crossword.size() || l>=crossword[0].size()){
                return false;
        }
        if(isSafe(crossword, k, l, w[i])){
                char x = crossword[k][l];
                crossword[k][l] = w[i];
               bool isallfilled= fillHorizontal(crossword, k + 1, l, w, i + 1, size);

                if(!isallfilled)
                        crossword[k][l] = x;
               return isallfilled;
        }
        return false;
}

void fill(vector<string> & crossword, string word){
        for (int j = 0; j < word.size() ; j++){
                //now fill current character in crossword
                for (int k = 0; k < crossword.size();k++){
                        bool flag= false;
                        for (int l = 0; l < crossword.size();l++){
                                if( fillHorizontal(crossword, k, l, word, 0, word.size()) ){
                                        flag = true;
                                        // cout << "k " << k << " l " << l << " word " << word <<" ch "<<word[j]<< "  j " << j << endl;
                                        break;
                                }
                                if( fillVertical(crossword, k, l, word, 0, word.size()) ){
                                        // cout << "k " << k << " l " << l << " word "<< word << "  j " << j << endl;
                                        flag = true;
                                        break;
                                }
                        }
                        if(flag){
                                break;
                        }
                }
                //if not fillable try another index of crossword;
        }
}

void fillCrossword(vector<string> &crossword, vector<string> words){
        for (int i = 0; i < words.size() ;i++){
                //now time to fill current word
                fill(crossword, words[i]);
        }
}
bool cmp(string a, string b){
        return a.size() > b.length();
}

int main() {
        vector<string> matrix;
  
        // take input of puzzle in matrix
        // input of grid of size n1 x n1
          matrix.push_back("+++++++++-");
        matrix.push_back("-++++++++-");
        matrix.push_back("-------++-");
        matrix.push_back("-++++++++-");
        matrix.push_back("-++++++++-");
        matrix.push_back("-++++-----");
        matrix.push_back("------+++-");
        matrix.push_back("-++++++++-");
        matrix.push_back("+---------");
        matrix.push_back("++++++++++");
        vector<string> words;
        
        // the words matrix will hold all
        // the words need to be filled in the grid
        words.push_back("CHEMISTRY");
        words.push_back("PHYSICS");
        words.push_back("HISTORY");
        words.push_back("MATHS");
        words.push_back("CIVICS");
        words.push_back("GEOGRAPHY");
        sort(words.begin(), words.end(), cmp);

        fillCrossword(matrix, words);
        for (int i = 0; i < matrix.size();i++){
                cout << matrix[i] << endl;
        }
}