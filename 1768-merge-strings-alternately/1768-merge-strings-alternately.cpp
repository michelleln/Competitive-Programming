class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        for (int i = 0; i < min(word1.size(), word2.size()); i++){
            res += word1[i];
            res += word2[i];
        }
        if (word1.size() == word2.size()) return res;
        else if(word1.size() > word2.size()) {
            for (int i = word2.size(); i < word1.size(); i++) res += word1[i]; 
        } else {
            for (int i = word1.size(); i < word2.size(); i++) res += word2[i];
        }
        return res;
    }
};