class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        unordered_map<int, int> map;
        for (int i = 0; i < flowerbed.size(); i++){
            if (flowerbed[i] == 1 && i == 0) {
            map[i] = 0;
            map[i + 1] = 0;
            } else if (flowerbed[i] == 1 && i == flowerbed.size() - 1){
            map[i] = 0;
            map[i - 1] = 0;
            } else if (flowerbed[i] == 1 && i != 0 && i != flowerbed.size() - 1){
            map[i - 1] = 0;
            map[i] = 0;
            map[i + 1] = 0;
            } 
        }

        // 1, 0, 0, 0, 0, 1
        // 0: 0, 1: 0, 2: 1, 3: 1, 4: 0, 5: 0
        // any order 3, 0, 1, 2, 4, 5
        int prevAvailable = 0;
        for (int i = 0; i < n; i++) {
            int available = -1;
            // find the first available position to plant
            for (int j = prevAvailable; j < flowerbed.size(); j++) {
                if (map.find(j) == map.end()) {
                    available = j;
                    prevAvailable = j;
                    // cout << "Found" << endl;
                    break;
                }
            }
            // cout << "Position:" + to_string(available) << endl;
            // cannot find anything
            if (available == -1) return false;
            else {
            // plant in the 'available' position
                map[available] = 0;
                if (available != flowerbed.size() - 1) map[available + 1] = 0;
                if (available != 0) map[available - 1] = 0;
            }
        }
        return true;
    }
};