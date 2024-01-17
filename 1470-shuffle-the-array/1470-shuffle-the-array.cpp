class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> firstHalf(n);
        for (int i = 0; i < n; i++) firstHalf[i] = nums[i];
        int prev = 0;
        int post = n;
        for (int i = 0; i < nums.size() -  1; i = i + 2){
            nums[i] = firstHalf[prev];
            nums[i + 1] = nums[post];
            prev++;
            post++;
        }
        return nums;
    }
};