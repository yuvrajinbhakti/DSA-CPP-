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