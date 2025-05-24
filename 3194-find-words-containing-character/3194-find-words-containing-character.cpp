class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> output;
        for(int i=0; i < words.size(); i++){
            string word = words[i];
            if(words[i].find(x) != std::string::npos) {
                output.push_back(i);
            }
        }
        return output;
    }
};