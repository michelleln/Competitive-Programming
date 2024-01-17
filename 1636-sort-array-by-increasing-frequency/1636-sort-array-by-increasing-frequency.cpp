class Solution {
public:
    static bool compare (int &a, int &b){
        return a > b;
    }

    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) map[nums[i]]++;
        unordered_map<int, vector<int>> freq;
        for (auto x : map) {
            for (int j = 0; j < x.second; j++){
                freq[x.second].push_back(x.first);
            }
            sort(freq[x.second].begin(), freq[x.second].end(), compare);
        }
        
        vector<int> res;
        for (int i = 1; i <= nums.size(); i++){
            if (!freq[i].empty()){
                res.insert(res.end(), freq[i].begin(), freq[i].end());
            }
        }
        return res;
    }
};