class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> all;
        generate(n, 0, 0, "", all);
        return all;
    }
private:
    void generate(int n, int open, int close, string result, vector<string>& all) {
        if (open == n && close == n){
            all.push_back(result);
            return;
        }
        if (open < n){
            //do this instead of result += '(' so that the result string wouldnt be altered
            generate(n, open + 1, close, result + '(', all);
        }
        if (close < open){
            ;
            generate(n, open, close + 1, result + ')', all);
        }
    }
};