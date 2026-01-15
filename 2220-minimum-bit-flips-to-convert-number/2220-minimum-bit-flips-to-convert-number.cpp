// //brute force Time Complexity: O(max bits),Space Complexity: O(1)
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         int count = 0;
//         while (start > 0 || goal > 0) {
//             // Increment count if the current bits differ
//             if ((start & 1) != (goal & 1)) {
//                 count++;
//             }
//             // Shift both numbers to the right to check the next bits
//             start >>= 1;
//             goal >>= 1;
//         }
//         return count;
//     }
// };


// //recrusive solution Time complexity: O(max bits),Space complexity: O(max bits)
// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         // Base case: both numbers have been fully processed
//         if (start == 0 && goal == 0) return 0;

//         // Flip for the current least significant bit
//         int flip = (start & 1) != (goal & 1);

//         // Recurse for the next bits by right-shifting both numbers
//         return flip + minBitFlips(start >> 1, goal >> 1);
//     }
// };

// XOR Rules
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Count the number of 1s in xorResult (differing bits)
        while (xorResult) {
            count += xorResult & 1;  // Increment if the last bit is 1
            xorResult >>= 1;         // Shift right to process the next bit
        }
        return count;
    }
};

