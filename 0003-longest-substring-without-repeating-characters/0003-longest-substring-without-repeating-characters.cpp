class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charLog;
        int lower = 0;
        int upper = 0;
        int maxLength = 0;

        while (upper < s.size()){
            while (charLog.find(s[upper]) != charLog.end()){
                charLog.erase(s[lower]);
                lower++;
            }

            maxLength = max(maxLength, upper - lower + 1);
            charLog.insert(s[upper]);
            upper++;
        }
        
        return maxLength;
    }
};