// class Solution {
// public:
//     string sortVowels(string s) {
//         vector<char> vowels;
//         for (char c : s) {
//             if (isVowel(c)) {
//                 vowels.push_back(c);
//             }
//         }

//         sort(vowels.begin(), vowels.end());

//         int v_index = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (isVowel(s[i])) {
//                 s[i] = vowels[v_index++];
//             }
//         }

//         return s;
//     }

// private:
//     bool isVowel(char c) {
//         return string("AEIOUaeiou").find(c) != string::npos;
//     }
// };


class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s)
            if (isVowel(c))
                vowels.push_back(c);

        sort(vowels.begin(), vowels.end());

        int idx = 0;
        for (char& c : s)
            if (isVowel(c))
                c = vowels[idx++];

        return s;
    }

private:
    bool isVowel(char c) {
        switch (c) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
        }
    }
};