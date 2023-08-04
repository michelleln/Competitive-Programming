class Solution {
public:
    //my way but doesn't work since doesnt account for cases like this (){}[]
    bool isValid(string s) {
        bool valid = true;
        stack<char> log;
        map<char, char> collection = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

        if ((s.size() % 2) == 1){
            return false;
        }

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                log.push(s[i]);
                i++;
            }
            if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if (log.empty()){
                    return false;
                }
                if(s[i] == collection[log.top()]){
                    log.pop();
                    i++;
                } else {
                    return false;
                }
            }
        }

        if (log.empty()){
            return true;
        } else {
            return false;
        }
    }
};