class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> posMap;
        for (int i = 0; i < nums.size(); i++){
            posMap[nums[i]].push_back(i);
        }
        
        int minLength = nums.size() + 1;
        int maxFreq = 0;
        for (auto x : posMap){
            if (x.second.size() > maxFreq){
                maxFreq = x.second.size();
                minLength = x.second.back() - x.second[0] + 1;
            } else if (x.second.size() == maxFreq) minLength = min(x.second.back() - x.second[0] + 1, minLength);
        }
        
        return minLength;
    }
};