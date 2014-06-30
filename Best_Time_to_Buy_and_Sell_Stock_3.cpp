class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        
        vector<int> diff((int)prices.size()-1);
        
        for(int i = 1; i < prices.size(); i++){
            diff[i-1] = prices[i] - prices[i-1];
        }
        
        int max_sum = 0;
        int sum = 0;
        vector<int> mp(diff.size(), 0);
        
        for(int i  = 0; i < diff.size(); i++){
            sum += diff[i];
            if(sum < 0) sum = 0;
            if(sum > max_sum) {
                max_sum = sum;
            }
            
            mp[i] = max_sum;
        }
        
        max_sum = mp[diff.size()-1];
        sum = 0;
        for(int i = diff.size()-1; i > 0; i--){
            sum += diff[i];
            if(sum < 0) sum = 0;
            if(sum + mp[i-1] > max_sum){
                max_sum = sum + mp[i-1];
            }
        }
        return max_sum;
    }
};
