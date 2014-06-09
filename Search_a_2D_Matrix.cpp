class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n-1;
        while(i < m && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        
        return false;
    }
};

pair<int, int> search_2D_matrix(vector<vector<int>> &A, int sr, int sc, int er, int ec, int target){
    if(sr > er || sc > ec) return {-1, -1};
    
    int mr = sr + (er-sr)/2;
    int mc = sc + (ec-sc)/2;
    
    if(A[mr][mc] == target) return {mr, mc};
    else if(A[mr][mc] > target) return search_2D_matrix(A, sr, sc, mr, mc, target);
    else{
        pair<int, int> t = search_2D_matrix(A, mr+1, sc, er, mc, target);
        if(t.first == -1 && t.second == -1) return search_2D_matrix(A, sr, mc+1, er, ec, target);
        else return t;
    }
}

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int sInd, mInd, eInd;
        pair<int, int> rc;
        int nCol, nRow;
        
        nRow = matrix.size();
        nCol = matrix[0].size();
        
        sInd = 0; eInd = nRow*nCol - 1;
        
        while (sInd <= eInd) {
            mInd = sInd + (eInd - sInd)/2;
            rc = index_rc(mInd, nCol);
            
            if (matrix[rc.first][rc.second] == target) {
                return true;
            }else if (matrix[rc.first][rc.second] < target) {
                sInd = mInd + 1;
            }else{
                eInd = mInd - 1;
            }
        }
        
        return false;
    }
    
private:
    pair<int, int> index_rc(int index, int sz){
        return make_pair(index / sz, index % sz);
    }
};
