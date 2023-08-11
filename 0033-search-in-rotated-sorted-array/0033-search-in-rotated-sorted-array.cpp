class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid = 0;

        while (lower <= upper) {
            mid = (lower + upper) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] <= nums[upper]){
                if (nums[mid] > target){
                    upper = mid - 1;
                } else if (nums[mid] < target && nums[upper] >= target){
                    lower = mid + 1;
                } else if (nums[mid] < target && nums[upper] < target){
                    upper = mid - 1;
                }
            } else if (nums[mid] > nums[upper]){
                if (nums[mid] < target){
                    lower = mid + 1;
                } else if (nums[mid] > target && nums[upper] < target){
                    upper = mid - 1;
                } else if (nums[mid] > target && nums[upper] >= target){
                    lower = mid + 1;
                }
            }
        }
        return -1;
    }
};