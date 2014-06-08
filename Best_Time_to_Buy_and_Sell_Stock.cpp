class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() < 2) return 0;
        
        vector<int> diff(prices.size()-1);
        
        adjacent_difference(prices.begin(), prices.end(), diff.begin());
        
        int sum = 0; 
        int max_sum = 0;
        
        for(int i = 0; i < diff.size(); i++){
            sum += diff[i];
            if(sum < 0){
                sum = 0;
            }
            
            if(sum > max_sum){
                max_sum = sum;
            }
        }
        
        return max_sum;
    }
};
