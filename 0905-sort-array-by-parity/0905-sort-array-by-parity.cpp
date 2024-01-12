class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        while (lower < upper){
            if (nums[lower] % 2 == 0) lower++;
            else if (nums[upper] % 2 == 1) upper--;
            else if (nums[upper] % 2 == 0 && nums[lower] % 2 == 1){
                int temp = nums[lower];
                nums[lower] = nums[upper];
                nums[upper] = temp;
                upper--;
                lower++;
            } 
        }
        return nums;
    }
};