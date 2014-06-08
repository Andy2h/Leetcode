class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if(S.empty()) return vector<vector<int>>();
        
        vector<vector<int>> result;
        
        sort(S.begin(), S.end());
        subset_helper(result, vector<int>(), S);
        return result;
    }
private:
    void subset_helper(vector<vector<int>> &result, vector<int> sofar, vector<int> rest){
        if(rest.empty()){
            result.push_back(sofar);
            return;
        }
        
        int x = rest[0];
        sofar.push_back(x);
        rest.erase(rest.begin());
        subset_helper(result, sofar, rest);
        
        while(!rest.empty() && x == rest[0]){
            rest.erase(rest.begin());
        }
        sofar.pop_back();
        subset_helper(result, sofar, rest);
    }
};
