class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> carsLog;

        for (int i = 0; i < position.size(); i++){
            double time = (double) (target - position[i]) / speed[i];
            carsLog.push_back({position[i], time});
        }
        sort(carsLog.begin(), carsLog.end());

        double maxTime = 0.0;
        int result = 0;
        for (int i = position.size() - 1; i >= 0; i--){
            double time = carsLog[i].second;
            if (time > maxTime) {
                maxTime = time;
                result++;
            }
        }
        return result;
    }
};