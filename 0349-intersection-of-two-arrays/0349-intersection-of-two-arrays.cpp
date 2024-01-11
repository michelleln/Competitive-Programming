class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> common;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums1.size(); i++){
            freq[nums1[i]] = 1;
        }
        for (int i = 0; i < nums2.size(); i++){
            if (freq.find(nums2[i]) != freq.end()) freq[nums2[i]] = 2;
        }

        for (auto x: freq){
            if (x.second == 2) common.push_back(x.first);
        }
        return common;
    }
};