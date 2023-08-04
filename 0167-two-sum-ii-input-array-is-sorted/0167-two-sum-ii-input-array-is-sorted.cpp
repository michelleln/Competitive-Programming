class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size() - 1;

        int sum = numbers[lower] + numbers[upper];
        while (sum != target && lower + 1 < upper) {
            if (sum < target) {
                lower++;
            } else if (sum > target){
                upper--;
            }
            sum = numbers[lower] + numbers[upper];
        }

        //if (sum == target){
            vector<int> result;
            result.push_back(lower + 1);
            result.push_back(upper+1);
            
        //}

        return result;
    }
};