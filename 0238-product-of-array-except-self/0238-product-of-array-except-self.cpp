class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        
        int prefix = 1;
        for (int i = 0; i < n; i++){
            results[i] = prefix;
            prefix = prefix * nums[i];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--){
            results[i] = results[i] * postfix;
            postfix = postfix * nums[i];
        }
        return results;
    }
};