#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charMap; 
        int maxLength = 0;
        int left = 0;      

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            if (charMap.count(currentChar) && charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1;
            }

            charMap[currentChar] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    std::string s1 = "abcabcbb";
    std::cout << "Input: \"" << s1 << "\"" << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(s1) << std::endl;

    std::string s2 = "bbbbb";
    std::cout << "\nInput: \"" << s2 << "\"" << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(s2) << std::endl;

    std::string s3 = "pwwkew";
    std::cout << "\nInput: \"" << s3 << "\"" << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(s3) << std::endl;

    std::string s4 = "";
    std::cout << "\nInput: \"" << s4 << "\"" << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(s4) << std::endl;

    std::string s5 = "au";
    std::cout << "\nInput: \"" << s5 << "\"" << std::endl;
    std::cout << "Output: " << sol.lengthOfLongestSubstring(s5) << std::endl;

    return 0;
}