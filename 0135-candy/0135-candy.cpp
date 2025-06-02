// Used greedy aproach:

// every student should get atleast one so initially give 1 candy to every student
// Now traverse left to right, whenever we get a higher rating, it should get more candy from its neighbour( left neighbour in the curr case) so give just one more candy than its left neighbour
// Now another case left when its right neighbour has higher rating, traverse from right, and if we get a higher rating, give it max(curr, 1+candy of its right). max ensures that for local maxima candies shuld be high than both neighbours;

class Solution {
public:
   int candy(vector<int>& r) {
        int n = r.size();
        vector<int> c(n, 1);
        for (int i = 1; i < n; i++)
            if (r[i] > r[i - 1]) c[i] = c[i - 1] + 1;
        for (int i = n - 2; ~i; i--)
            if (r[i] > r[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        int res = 0;
        for (auto t: c) res += t;
        return res;
    }

};