#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Trie {
public:
      bool is_string = false;
        Trie* next[27] = { nullptr };
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(const auto& w : word){
            if(root->next[w - 'a'] == NULL) root->next[w - 'a'] = new Trie();
            root = root->next[w -'a'];
        }
        root->is_string = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        if(!root->next[word[0] - 'a'])
            return false;
        for(const auto& w : word ){
            root = root->next[w - 'a'];
            if(!root)
                return false;
        }
        return root->is_string;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
          if(!root->next[prefix[0] - 'a'])
            return false;
        for(const auto& w : prefix ){
            root = root->next[w - 'a'];
            if(!root)
                return false;
        }
        return true;
    }
};
class Solution {
private:
    vector<string> ans;
public:
    void check(vector<vector<char> >& board, Trie *trie, string temp, int x, int y){
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        if(trie->search(temp))
            ans.push_back(temp);
        if(trie->startsWith(temp)){
            for (int i = 0; i < 4; i++)
            {
                if(0<=x+dx[i] && x+dx[i]<board.size()&& 0<= y+dy[i] && y+dy[i] < board[0].size()){
                    char tmp = board[x][y];
                    board[x][y] = 'a' + 26;
                    check(board, trie, temp + board[x+dx[i]][y+dy[i]], x+dx[i], y+dy[i]);
                    board[x][y] = tmp;
                }
            }
            
        }
    }
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        Trie *trie = new Trie();
        for(const auto& w:words){
            trie->insert(w);
        }
        int h = board.size(), w = board[0].size();

        for(int i = 0; i < h; i++){
            for (int j = 0; j < w; j++)
            {
                check(board, trie, string(1,board[i][j]), i, j);
            }
        }
        return ans;
    }
};