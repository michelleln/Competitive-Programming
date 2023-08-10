class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        //vector<int> possibleSpeed;
        for (int i = 0; i < piles.size(); i++){
            sum += piles[i];
        }

        int lower;
        if (sum % h == 0) {
            lower = sum / h;
        } else {
            lower = sum / h + 1;
        }
        int upper = *max_element(piles.begin(), piles.end());
        int mid = 0;

        int min = upper;
        
        while (lower <= upper){
            mid = floor((lower + upper) / 2);
            int hours = 0;
            for (int i = 0; i < piles.size(); i++){
                if (piles[i] %  mid == 0){
                    hours += piles[i] / mid;
                } else {
                    hours += floor(piles[i] / mid) + 1;
                }
            }

            if (hours > h){
                lower = mid + 1;
            } else {
                
                upper = mid - 1;
                if (mid < min) {
                    min = mid;
                }
            }
        }

        return min;
    }
};