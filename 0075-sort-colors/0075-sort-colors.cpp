class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        int i = 0;
        while (i <= upper && i >= lower && lower <= upper){
            //if(nums[i] == nums[lower] || nums[i] == nums[upper]){
            //      i++;
            //}
            if (nums[i] == 0 && i != lower){
                nums[i] = nums[lower];
                nums[lower] = 0;
                lower++;
            } 
            else if (nums[i] == 2 && i != upper){
                nums[i] = nums[upper];
                nums[upper] = 2;
                upper--;
            }
            else {
                i++;
            }
            
        }
        return nums;
    }
};