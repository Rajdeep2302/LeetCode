/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length < 1) {
        return "";
    }

    let start = 0;
    let end = 0;

    function expandAroundCenter(left, right) {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    for (let i = 0; i < s.length; i++) {
        let len1 = expandAroundCenter(i, i);
        let len2 = expandAroundCenter(i, i + 1);
        let len = Math.max(len1, len2);

        if (len > end - start) {
            start = i - Math.floor((len - 1) / 2);
            end = i + Math.floor(len / 2);
        }
    }

    return s.substring(start, end + 1);
};

console.log("Input: \"babad\"");
console.log("Output: \"" + longestPalindrome("babad") + "\""); 

console.log("\nInput: \"cbbd\"");
console.log("Output: \"" + longestPalindrome("cbbd") + "\""); 

console.log("\nInput: \"a\"");
console.log("Output: \"" + longestPalindrome("a") + "\""); 

console.log("\nInput: \"ac\"");
console.log("Output: \"" + longestPalindrome("ac") + "\""); 

console.log("\nInput: \"racecar\"");
console.log("Output: \"" + longestPalindrome("racecar") + "\""); 

console.log("\nInput: \"aaaaa\"");
console.log("Output: \"" + longestPalindrome("aaaaa") + "\""); 

console.log("\nInput: \"\"")
console.log("Output: \"" + longestPalindrome("") + "\"");
