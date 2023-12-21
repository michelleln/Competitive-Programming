class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        for (int i = 0; i < strs.size(); i++){
            string key = getKey(strs[i]);
            map[key].push_back(strs[i]);
        }
        
        vector<vector<string>> results;
        for (auto it = map.begin(); it != map.end(); it++){
            results.push_back(it->second);
        }
        return results;
    }
private:
    string getKey(string s) {
        vector<int> count(26);
        for (int i = 0 ; i < s.size(); i++){
            count[s[i] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++){
            key.append(to_string(count[i]) + "#");
        }
        return key;
    }
};

    