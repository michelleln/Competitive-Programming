class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int, int> map;
        for (int i = 0; i < logs.size(); i++){
            for (int j = logs[i][0]; j < logs[i][1]; j++){
                map[j]++;
            }
        }
        int maxPopulation = 0;
        int year = 0;
        for (auto x : map){
            if (x.second > maxPopulation){
                maxPopulation = x.second;
                year = x.first;
            } else if (x.second == maxPopulation){
                year = min(year, x.first);
            }
        }
        return year;
    }
};