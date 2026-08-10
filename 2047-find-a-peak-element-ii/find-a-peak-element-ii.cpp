class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int ans = -1;
        int p1 = -1,p2 = -1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
               if(mat[i][j] > ans){
                ans = mat[i][j];
                p1 = i;
                p2 = j;
               }

            }
        }

        return {p1,p2};
    }
};