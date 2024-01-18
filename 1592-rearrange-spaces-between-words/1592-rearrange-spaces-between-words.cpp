class Solution {
public:
    string reorderSpaces(string text) {
        string res = "";
        vector<string> words;
        int noSpace = 0;

        string word = "";
        for (int i = 0; i < text.size(); i++){
            if (text[i] == ' '){
                noSpace++;
                if (word.size() != 0) {
                    words.push_back(word);
                    word = "";
                }
            } else word += text[i];
        }
        if (word.size() != 0) words.push_back(word);

        if (words.size() == 1) {
            string strSpace = "";
            for (int i = 0; i < noSpace; i++) strSpace += ' ';
            res += words[0] + strSpace;
            return res;
        }
        int space = noSpace / (words.size() - 1);
        int extra = noSpace % (words.size() - 1);
        string strExtra = "";
        for (int i = 0; i < extra; i++) strExtra += ' ';
        string strSpace = "";
        for (int i = 0; i < space; i++) strSpace += ' ';
        for (int i = 0; i < words.size() - 1; i++){
            res += words[i];
            res += strSpace;
        }
        res += words[words.size() - 1];
        res += strExtra;
        return res;
    }
};