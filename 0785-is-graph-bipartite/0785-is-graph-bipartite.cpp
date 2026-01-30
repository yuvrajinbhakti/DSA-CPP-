//1 way can if even no of cycle or odd no of cycle


// class Solution {
// public:
//     bool validColouring(vector<vector<int>>& gr, vector<int>& colour, int node, int col){
//         if(colour[node] != 0)
//             return (colour[node] == col);

//         colour[node] = col;
//         for(int ne : gr[node]){
//             if(!validColouring(gr, colour, ne, -col))
//                 return false;
//         }

//         return true;
//     }

//     bool isBipartite(vector<vector<int>>& gr) {
//         int n = gr.size();
//         vector<int> colour(n, 0);

//         for(int node = 0; node < n; node++){
//             if(colour[node]==0 && !validColouring(gr, colour, node, 1))
//                 return false;
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool isBipartite(vector<vector<int>>& gr) {
        int n = gr.size();
        vector<int> colour(n, 0);

        for(int node = 0; node < n; node++){
            if(colour[node] != 0) continue;

            queue<int> q;
            q.push(node);
            colour[node] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int ne : gr[cur]){
                    if(colour[ne] == 0){
                        colour[ne] = -colour[cur];
                        q.push(ne);
                    }else if(colour[ne] != -colour[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};