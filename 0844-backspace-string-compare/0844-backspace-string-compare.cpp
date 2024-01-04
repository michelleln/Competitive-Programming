class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int newSLength = processString(s);
        int newTLength = processString(t);
        
        if (newSLength != newTLength) {
            return false;
        } else {
            for (int i = 0; i < newSLength; i++){
                if (s[i] != t[i]) return false;
            }
        }
        return true;
    }
private:
    int processString(string &s) {
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && j != 0) {
                j--;
            } else if (s[i] != '#') {
                s[j] = s[i];
                j++;
            }
        }
        return j;
    }
};