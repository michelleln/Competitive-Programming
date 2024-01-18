class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sums;
        int number = n;
        while (sums.find(number) == sums.end()){
            sums.insert(number);
            int sum = 0;
            while (number > 0){
                int rightmostDigit = number % 10;
                sum += rightmostDigit * rightmostDigit;
                number = (number - rightmostDigit) / 10;
            }
            number = sum;
            if (number == 1) return true;
        }
        return false;
    }
};