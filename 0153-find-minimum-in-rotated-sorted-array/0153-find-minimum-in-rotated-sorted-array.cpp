class Solution {
public:
    int findMin(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid;

        if (nums.size() == 1){
            return nums[0];
        }

        while (lower <= upper){
            mid = (lower + upper) / 2;
            if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            } else if (mid >= 1 && nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            else if (nums[lower] < nums[mid]){
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return nums[0];
    }
};