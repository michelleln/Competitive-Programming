class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 0) return {};
        
        int end = 0;
        vector<string> res;
        for (int start = 0; start < n; start++){
            while (end < n - 1 && nums[end] + 1 == nums[end + 1]){
                end++;
            }
            if (end == start)
                res.push_back(to_string(nums[start]));
            else {
                string temp = "";
                temp += to_string(nums[start]) + "->" + to_string(nums[end]);
                res.push_back(temp);
                start = end;
            }
            end++;
        }
        return res;
    }
};