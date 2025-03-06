class Solution {
public:
/*
Using hash map
Complexity
Time complexity: O(n x n)
Space complexity: O(n x n)
*/
    // vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //     unordered_map<int,int> freq;
    //     for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid.size();j++){
    //             freq[grid[i][j]]++;
    //         }
    //     }
    //     int repeat=0,miss=0,n=grid.size()*grid.size();
    //     for(int i=1;i<=n;i++){
    //         if(freq[i]==2)repeat=i;
    //         if(freq[i]==0)miss=i;
    //     }
    //     return {repeat,miss};
    // }

/*
Using Math
Complexity
Time complexity: O(n x n)
Space complexity: O(1)

Here we take sume of all element and equate that to sum of 1 to n^2
Again we take sum of the square of the numbers and equate that to sum of square of 1 to n^2
So we will get two equation and we have two variables a(repeated) & b(missing)
Here we will get two equations with a & b. Now solving them we will get following result :
a = (c2/c1 + c1)/2 b = (c2/c1 - c1)/2
where
c1 = (sum of n^2 given numbers) - sum of first n^2 natiural numbers
c2 = (sum of square of n^2 given numbers) - sum of first n^2 natural numbers
*/
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
      long long sum=0,sqrSum=0,n=grid.size(),N=n*n;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum+=grid[i][j];
            sqrSum+=grid[i][j]*grid[i][j];
        }
      }
      long long c1 = sum - N * (N + 1)/2,  c2 = sqrSum - N*(N+1)*(2*N + 1)/6;
      return {(int)(c2/c1+c1)/2,(int)(c2/c1-c1)/2};
    }
};