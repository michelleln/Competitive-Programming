class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> collection;

        if (tokens.size() == 1){
            return stoi(tokens[0]);
        }

        int i = 0;
        while (i < tokens.size()){
            string token = tokens[i];
            while (token.size() > 1 || isdigit(token[0])){
                collection.push(stoi(token));
                i++;
                token = tokens[i];
            }
            int num2 = collection.top();
            collection.pop();
            int num1 = collection.top();
            collection.pop();
            
            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            collection.push(result);
            i++;
        }
        return collection.top();
    }
};