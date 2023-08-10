class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;
        int mid = 0; 
        while (lower <= upper){
            mid = ceil(lower + upper) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return -1;
    }
};