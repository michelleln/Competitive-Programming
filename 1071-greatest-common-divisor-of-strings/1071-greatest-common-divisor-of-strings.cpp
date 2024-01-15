class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string base1 = getBaseString(str1);
        string base2 = getBaseString(str2);
        string res = "";
        if (base1.size() != base2.size()) return "";
        else {
            for (int i = 0; i < base1.size(); i++){
                if (base1[i] != base2[i]) return "";
                else continue;
            }
        }
        int rep1 = str1.size() / base1.size();
        int rep2 = str2.size() / base1.size();
        for (int i = 0; i < gcd(rep1, rep2); i++){
            res += base1;
        }
        return res;
    }

    string getBaseString(string str) {
        string base = "";
        
        for (int i = 0; i < str.size(); i++) {
            if (str.size() % (i + 1) == 0){
                int length = i + 1;
                base = str.substr(0, length);
                
                int iter = 1;
                while (iter < str.size() / length){
                    int start = length * iter;
                    string temp = str.substr(start, length);
                    for (int i = 0; i < length; i++){
                        if (temp[i] == base[i]) continue;
                        else {
                            iter = str.size() / length + 2;
                            break;
                        }
                    }
                    iter++;
                }
                if (iter == str.size() / length) {
                    cout << base << endl;
                    return base;
                }
            }
        }
        return base;
    }
};