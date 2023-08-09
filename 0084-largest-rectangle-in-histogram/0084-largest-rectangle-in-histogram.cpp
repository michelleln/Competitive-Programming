class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> heightLog;
        int n = heights.size();
        vector<int> nextShorterDistance(n);
        vector<int> prevShorterDistance(n);

        for (int i = 0; i < n; i++){
            while (!heightLog.empty() && heights[i] < heightLog.top().second){
                nextShorterDistance[heightLog.top().first] = i - heightLog.top().first;
                heightLog.pop();
            }
            heightLog.push({i, heights[i]});
        }
        while (!heightLog.empty()){
            nextShorterDistance[heightLog.top().first] = n - heightLog.top().first;
            heightLog.pop();
        }

        for (int i = n - 1; i >= 0; i--){
            while (!heightLog.empty() && heights[i] < heightLog.top().second){
                prevShorterDistance[heightLog.top().first] = heightLog.top().first - i - 1;
                heightLog.pop();
            }
            heightLog.push({i, heights[i]});
        }
        while (!heightLog.empty()){
            prevShorterDistance[heightLog.top().first] = heightLog.top().first;
            heightLog.pop();
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (nextShorterDistance[i] + prevShorterDistance[i]);
            if (area > maxArea){
                maxArea = area;
            }
        }
        return maxArea;
    }
};