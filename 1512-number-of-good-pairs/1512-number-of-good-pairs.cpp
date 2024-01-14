class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += map[nums[i]];
            map[nums[i]]++;
        }
        return res;
    }
};