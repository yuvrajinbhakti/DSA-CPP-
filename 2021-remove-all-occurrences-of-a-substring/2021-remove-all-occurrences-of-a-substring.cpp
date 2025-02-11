class Solution {
public:
    // string removeOccurrences(string s, string part) {
    //     string x = s;
	// int n = s.size(), m = part.size(), i, j;
	// for (i = 0, j = 0; i < n; i++) {
	// 	x[j++] = s[i];
	// 	if (j >= m && x.substr(j - m, m) == part)
	// 		j -= m;
	// }
	// return x.substr(0, j);
    // }
    string removeOccurrences(string s, string part) {
     while(s.length()!=0 && s.find(part)<s.length()){
         s.erase(s.find(part),part.length());
     }   
        return s;
}
};