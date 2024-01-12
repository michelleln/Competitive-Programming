class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < mat.size(); i++) {
            int soldiers = 0;
            while (soldiers < mat[0].size() && mat[i][soldiers] == 1) {
                soldiers++;
            }
            map[soldiers].push_back(i);
        }
        vector<int> res;
        for (int i = 0; i <= mat[0].size(); i++){
            if (res.size() >= k) {
                break;
            }
            if (!map[i].empty()) {
                for (int index = 0; index < map[i].size(); index++) {
                    if (res.size() < k) res.push_back(map[i][index]);
                    else return res;
                }
            }
        }
        return res;
    }
};