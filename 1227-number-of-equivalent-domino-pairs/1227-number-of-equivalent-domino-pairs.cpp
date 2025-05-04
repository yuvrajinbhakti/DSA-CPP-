/*
Understanding the Problem
We're given an array dominoes which consists of a pairs of dominoes and we need to find the number of pairs a, b and c, d such that a == c && b == d or a == d && b == c.
For example : Some valid pairs are [1, 2], [2, 1], [1, 2].
These are all valid as either they're the same as each other or the mirror of each other.
\U0001f4a1 Approach 1 → Using Two Pointers [TLE]
This is the brute force approach where we simply run two loops and check the condition provided in the problem statement.
Due to the constraints being upto 4 * 1e5, this approach gives Time Limit Exceeded as its verdict.
\U0001f552 Time Complexity → O(n 
2
 )
\U0001f4be Space Complexity → O(1)
\U0001f6e0️ Brute Force Implementation
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            int count = 0;
            for (int i = 0 ; i < dominoes.size() ; i++) {
                for (int j = i + 1 ; j < dominoes.size() ; j++) {
                    int a = dominoes[i][0], b = dominoes[i][1];
                    int c = dominoes[j][0], d = dominoes[j][1];
                    if ((a == c && b == d) || (a == d && b == c))
                    ++count;
                }
            }
            return count;
        }
    };
\U0001f680 Approach 2 → Using Pair Map
This approach is simple where we simply store all the pairs in the same format in a pair map and then count the frequencies at the end.
What does storing pairs in the same format mean?
We store all the pairs in increasing order of the values, that is, for the pair (a, b) if (a < b) then we store it as (b, a).
This is because it stores all the identical pairs at one place, which means all pairs containing (a, b) or (b, a) will be counted together.
\U0001f552 Time Complexity (C++) → O(n log n), as insertion takes log n time in a map
\U0001f552 Time Complexity (Python & Java) → O(n)
\U0001f4be Space Complexity → O(n)
\U0001f527 Pair Map Implementation
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            map<pair<int, int>, int> mpp;
            int count = 0;
            for(auto& d : dominoes){
                if(d[0] > d[1]) swap(d[0], d[1]);
                count += mpp[make_pair(d[0], d[1])]++;
            }
            return count;
        }
    };
\U0001f680 Approach 3 → Using Pair Hashmap [C++]
We define a custom structure of hashmap here and then use it for storing the numbers in the form of pairs, similar to how we did above.
\U0001f552 Time Complexity → O(n), insertions are O(1) in umap
\U0001f4be Space Complexity → O(n)
\U0001f4bb Pair Hashmap Implementation
class Solution {
    public:
        struct hash_pair {
            size_t operator()(const pair<int,int>& p) const {
                return p.first * 31 + p.second;
            }
        };
    
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<pair<int,int>, int, hash_pair> mpp;
    
            for (auto& d : dominoes) {
                if (d[0] > d[1]) swap(d[0], d[1]);
                mpp[{d[0], d[1]}]++;
            }
    
            int count = 0;
            for (auto& [d, freq] : mpp)
                count += freq * (freq - 1) / 2;
    
            return count;
        }
    };
*/

//brute force
// class Solution {
//     public:
//         int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//             int count = 0;
//             for (int i = 0 ; i < dominoes.size() ; i++) {
//                 for (int j = i + 1 ; j < dominoes.size() ; j++) {
//                     int a = dominoes[i][0], b = dominoes[i][1];
//                     int c = dominoes[j][0], d = dominoes[j][1];
//                     if ((a == c && b == d) || (a == d && b == c))
//                     ++count;
//                 }
//             }
//             return count;
//         }
//     };

//using map
// class Solution {
//     public:
//         int numEquivDominoPairs(vector<vector<int>>& dominoes) {
//             map<pair<int, int>, int> mpp;
//             int count = 0;
//             for(auto& d : dominoes){
//                 if(d[0] > d[1]) swap(d[0], d[1]);
//                 count += mpp[make_pair(d[0], d[1])]++;
//             }
//             return count;
//         }
//     };

//using pair hashmap
//  Time Complexity → O(n), insertions are O(1) in umap
// \U0001f4be Space Complexity → O(n)
class Solution {
    public:
        struct hash_pair {
            size_t operator()(const pair<int,int>& p) const {
                return p.first * 31 + p.second;
            }
        };
    
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<pair<int,int>, int, hash_pair> mpp;
    
            for (auto& d : dominoes) {
                if (d[0] > d[1]) swap(d[0], d[1]);
                mpp[{d[0], d[1]}]++;
            }
    
            int count = 0;
            for (auto& [d, freq] : mpp)
                count += freq * (freq - 1) / 2;
    
            return count;
        }
    };