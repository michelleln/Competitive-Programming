class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int currentMax = nums[0];
        int currentidMax = 0;
        vector<int> result;
        bool decreasing = true;
        int checkDecreasing = 0;
        while (checkDecreasing < nums.size() - 1 && decreasing == true){
            if (nums[checkDecreasing] < nums[checkDecreasing + 1]){
                decreasing = false;
            }
            checkDecreasing++;
        }
        if (decreasing == true && nums.size() > k){
            for (int i = 0; i < nums.size() - k + 1; i++){
                result.push_back(nums[i]);
            }
            return result;
        }
        int i = 0;
        int j = k;
        int max = checkMax(nums, 0, k);
        result.push_back(max);
        while (i < nums.size() - k && j < nums.size()){
            //int max = checkMax(nums, i, k);
            j = i + k;
            if (nums[j] >= max){
                result.push_back(nums[j]);
                max = nums[j];
                j++;
                i++;
            }
            else if (nums[j] < max && nums[i] < max){
                result.push_back(max);
                j++;
                i++;
            } else if (nums[j] < max && nums[i + 1] == max) {
                result.push_back(max);
                j++;
                i++;
            }
            else {
                i = j - k + 1;
                max = checkMax(nums, i, k);
                result.push_back(max);
                j++;
                //i++;
            }
        }
        return result;
    }
private:
    int checkMax(vector<int>& nums, int startidx, int k){
        int firstMax = nums[startidx];
        for (int i = startidx; i < startidx + k; i++){
            if (nums[i] > firstMax){
                firstMax = nums[i];
            }
        }
        return firstMax;
    }
};