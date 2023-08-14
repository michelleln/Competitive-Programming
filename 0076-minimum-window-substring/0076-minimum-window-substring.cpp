class Solution {
public:
string minWindow(string s, string t) {
        int i = 0;
        int j = 0;
        //vector<pair<int, string>> minLength;
        unordered_map<char, int> charNeeded;
        for (int i = 0; i < t.size(); i++){
            if (charNeeded.find(t[i]) != charNeeded.end()){
                charNeeded[t[i]]++;
            }
            else {
                charNeeded.insert({t[i], 1});
            }
        }

        int length = 0;
        int log = t.size();
        unordered_map<char, int> excess;
        int minLength = s.size() + 1;
        string minString;
        
        while (i < s.size()) {
            
            while (charNeeded.find(s[i]) == charNeeded.end() && i < s.size()){
                i++;
            }
            
            while (s[i] == s[i + 1] && excess[s[i]] > charNeeded[s[i]]){
                i++;
                excess[s[i]]--;
            }
            while (j < s.size() && log > 0){
                //if (charNeeded.find(s[j]) == charNeeded.end()){
                    //length++;
                if (charNeeded[s[j]] == 0){
                    excess[s[j]]++;
                    //length++;
                    //cout << excess[s[j]];
                }
                else if (charNeeded[s[j]] > 0){
                    charNeeded[s[j]]--;
                    log--;
                }
                j++;
                
            }
            
            if (log == 0){
                if (j - i < minLength){
                    minLength = j - i;
                    minString = s.substr(i, j - i);
                }
                //minLength.push_back({j - i, s.substr(i, j - i)});
            }
            
            if (excess[s[i]] > 0){
                excess[s[i]]--;
                //length--;
                i++;
            } else {
                charNeeded[s[i]] = 1;
                log = 1;
                i++;
            }
            
        }
        
        /*if (minLength.empty()){
            return "";
        }
        sort(minLength.begin(), minLength.end());
        return minLength[0].second;*/
        return minString;
}
};