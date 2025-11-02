class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) 
{  
    vector<vector<int> > mat(m, vector<int> (n, 0));
    vector<vector<vector<int> > > arr(m, vector<vector<int>> (n, vector<int> (4, 0)));
    
    
    //SECTION 1
    //Setting up the walls
    for(int i = 0; i<w.size(); i++)
        mat[w[i][0]][w[i][1]] = -1;

    //Setting up the gaurds
    for(int i = 0; i<g.size(); i++)
        mat[g[i][0]][g[i][1]] = 2; 

   
    //SECTION 2
    int left = 0, right = 1, up = 2, down = 3; 
    //Guards to the left of (i, j)
    for(int i =0; i<m; i++)
    {
        int gg = -1; 
        for(int j = 0; j< n; j++)
        {
            if(mat[i][j] == -1)
                gg = -1; 
            else if(mat[i][j] == 2)
                gg = j;
            else if(mat[i][j] == 0)
                arr[i][j][left] = gg; 
        }
    }
    
    //Guards to the right of (i, j) 
    for(int i = 0; i<m; i++)
    {
        int gg = -1; 
        for(int j = n-1; j>-1; j--)
        {
            if(mat[i][j] == -1)
                gg = -1; 
            else if(mat[i][j] == 2)
                gg = j;
            else if(mat[i][j] == 0)
                arr[i][j][right] = gg;
        }
    }
    
    //Guards above (i, j)
    for(int j = 0; j < n; j++)
    {
        int gg = -1; 
        for(int i = 0; i < m; i++)
        {
            if(mat[i][j] == -1)
                gg = -1; 
            else if(mat[i][j] == 2)
                gg = j;
            else if(mat[i][j] == 0)
                arr[i][j][up] = gg; 
        }
    }
    
    //Guards below (i, j)
    for(int j = 0; j < n; j++)
    {
        int gg = -1; 
        for(int i = m-1; i > -1; i--)
        {
            if(mat[i][j] == -1)
                gg = -1; 
            else if(mat[i][j] == 2)
                gg = j;
            else if(mat[i][j] == 0)
                arr[i][j][down] = gg; 
        }
    }
    

    //SECTION 3
    int ans = 0; 
    
    for(int i =0; i<m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j][left] == -1 and arr[i][j][right] == -1 and arr[i][j][up] == -1 and arr[i][j][down] == -1)
                ans++;
        }
    }
    
    return ans;        
}
};