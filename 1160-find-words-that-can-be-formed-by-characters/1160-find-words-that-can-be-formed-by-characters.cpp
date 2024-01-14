class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> map;
        int sum = 0;
        for (int i = 0; i < chars.size(); i++) {
            map[chars[i]]++;
        }
        unordered_map<char, int> word;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++){
                word[words[i][j]]++;
            }
            auto it = word.begin();
            while (it != word.end()){
                if (it->second <= map[it->first]) it++;
                else break;
            }
            if (it == word.end()) sum += words[i].size();
            word.clear();
        }
        return sum;
    }
};