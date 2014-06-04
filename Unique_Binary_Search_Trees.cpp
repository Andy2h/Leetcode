class Solution {
    
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += numTrees(i)*numTrees(n-i-1);
        }
        
        return sum;
    }
};

// memorize the temp result for faster recursion
class Solution {
    
public:
    int numTrees(int n) {
        if(n <= 1) return 1;
        
        vector<int> A(n+1, 0);
        A[0] = A[1] = 1;
        
        return num_tree_helper(n, A);
    }
private:
    int num_tree_helper(int n, vector<int> &A){
        int cnt = 0;
        
        for(int i = 1; i <=n; i++){
            if(A[i-1] == 0){
                A[i-1] = num_tree_helper(i-1, A);
            }
            if(A[n-i] == 0){
                A[n-i] = num_tree_helper(n-i, A);
            }
            cnt += A[i-1]*A[n-i] ;
        }
        
        return cnt;
        
    }
};
