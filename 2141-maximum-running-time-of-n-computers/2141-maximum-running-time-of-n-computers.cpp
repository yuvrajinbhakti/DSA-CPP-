class Solution {
public:
    long long maxRunTime(int joey, vector<int>& chandler) {
        vector<long long> monica;
        monica.reserve(chandler.size());
        for (int phoebe : chandler) monica.push_back((long long)phoebe);

        long long left = 0, right = 0;
        for (long long rachel : monica) right += rachel;
        right /= joey;  // upper bound for T

        while (left < right) {
            long long gunther = (left + right + 1) / 2; // mid T
            long long emma = 0;

            for (long long ross : monica) {
                emma += min(ross, gunther);
                if (emma >= gunther * joey) break;
            }

            if (emma >= gunther * joey) {
                left = gunther;      // feasible
            } else {
                right = gunther - 1; // not feasible
            }
        }

        return left;
    }
};