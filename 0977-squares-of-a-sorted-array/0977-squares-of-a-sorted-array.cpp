class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
            int first = 0;
            while (first < nums.size() - 1 && nums[first] < 0 && nums[first + 1] < 0) {
                first++;
            }
            int second = first + 1;
            while (first >= 0 && second < nums.size()) {
                if (nums[first] * nums[first] <= nums[second] * nums[second]){
                    result.push_back(nums[first] * nums[first]);
                    first--;
                } else {
                    result.push_back(nums[second] * nums[second]);
                    second++;
                }
            }
                while (second < nums.size()){
                    result.push_back(nums[second] * nums[second]);
                    second++;
                }
                while (first >= 0){
                    result.push_back(nums[first] * nums[first]);
                    first--;
                }
            return result;
        }
        
};