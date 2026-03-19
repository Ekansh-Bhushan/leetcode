class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> map;
        
        // Count the frequency of each character
        for (char c : s) {
            map[c]++;
        }
        
        // Find the index of the first unique character
        for (int i = 0; i < s.length(); i++) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        
        return -1; // Return -1 if no unique character is found
    }
};