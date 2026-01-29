class Solution {
private:
    void dfs(vector<vector<char>> & grid,vector<vector<int>> &vis,int x,int y){
        int n=grid.size(),m=grid[x].size();
        vis[x][y]=1;

        int diffX[4]={-1,0,1,0};
        int diffY[4]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nx=x+diffX[i];
            int ny=y+diffY[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny]=='1' ){
                dfs(grid,vis,nx,ny);
            }

        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};



/*
class Solution{
public:
    void dfs(vector<vector<char>> &grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{-1,-1}, {-1,0}, {-1,1},
                           {0,-1},         {0,1},
                           {1, -1}, {1,0}, {1,1}};
        grid[row][col] = '2';
        for(auto it: dir){
            int nrow = row + it.first;
            int ncol = col + it.second;
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == '1'){
                dfs(grid, nrow, ncol);
            }
        }

    }
    int numIslands(vector<vector<char>> &grid){
        int island = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != '2' && grid[i][j] == '1'){
                        dfs(grid, i, j);
                        island++;
                }
            }
        }
        return island;
        
    }
};
*/