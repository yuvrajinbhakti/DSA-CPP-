// class Solution {
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

//         vector<vector<int>> ans;
//         int n = heights.size();
//         int m = heights[0].size();

//         vector<vector<bool>> pac(n, vector<bool>(m));
//         vector<vector<bool>> atl(n, vector<bool>(m));
        
//         // we wil start with those cells which were already connected to oceans
//         for (int i = 0; i < n; i++) {

//             dfs(heights, pac, i, 0, -1, -1); // first col
//             dfs(heights, atl, i, m-1, -1, -1); // last col
//         }

//         for (int j = 0; j < m; j++) {

//             dfs(heights, pac, 0, j, -1, -1); // first row 
//             dfs(heights, atl, n - 1, j, -1, -1); // last row
//         }

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (pac[i][j] && atl[i][j])
//                     ans.push_back({i, j});
//             }
//         }
//         return ans;
//     }

//     void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j, int oi, int oj) {

//         if (i < 0 || i >= h.size() || j<0 || j>=h[0].size() || vis[i][j]) return;
//         if (oi >= 0 && oj >=0 && h[i][j] < h[oi][oj]) return; // rain water will not move into ocean from smaller to bigger height

//         vis[i][j] = true;
//         dfs(h, vis, i - 1, j, i, j);
//         dfs(h, vis, i + 1, j, i, j);
//         dfs(h, vis, i, j - 1, i, j);
//         dfs(h, vis, i, j + 1, i, j);
//     }
// };

class Solution {
public:

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& heights, int n, int m)
    {
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true; // mark visited

            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && heights[r][c] <= heights[nr][nc] && !vis[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m)); // visited array
        vector<vector<bool>> atl(n, vector<bool>(m));
        queue<pair<int,int>>q;

        // push cells connected to pacific ocean
        for(int i=n-1;i>=0;i--) q.push({i, 0}); // first col 
        for(int i=m-1;i>=0;i--) q.push({0, i}); // first row

        bfs(q, pac, heights, n, m);

        // push cells connected to atlantic ocean
        for(int i=n-1;i>=0;i--) q.push({i, m-1}); // last col
        for(int i=m-1;i>=0;i--) q.push({n-1, i}); // last row

        bfs(q, atl, heights, n, m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};