class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        
        for (int i = 0; i < n; i++){
            map[nums[i]]++;
        }
        
        vector<vector<int>> collection(n+1);
        for (auto it = map.begin(); it != map.end(); it++){
            collection[it->second].push_back(it->first);
        }
        
        vector<int> results;
        for (int i = n; i >= 0 ; i--){
            if (results.size() >= k){
                break;
            }
            if (!collection[i].empty()){
                results.insert(results.end(), collection[i].begin(), collection[i].end());
            }
        }
        return results;
    }
};