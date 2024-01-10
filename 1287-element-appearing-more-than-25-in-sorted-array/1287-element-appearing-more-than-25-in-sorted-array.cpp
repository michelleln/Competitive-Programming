class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int start = 0;
        int maxFreq = 0;
        int number = 0;
        int i = 0;
        while (i < arr.size()) {
            while (i < arr.size() && arr[i] == arr[start]) {
                i++;
            }
            if (i - start > maxFreq){
                number = arr[start];
                maxFreq = i - start;
            }
            start = i;
        } 
        return number;
    }
};