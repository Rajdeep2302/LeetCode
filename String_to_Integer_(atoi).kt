import kotlin.math.abs

class Solution {
    fun myAtoi(s: String): Int {
        var i = 0
        val n = s.length
        while (i < n && s[i] == ' ') {
            i++
        }
        
        if (i == n) {
            return 0
        }
        var sign = 1
        if (s[i] == '-') {
            sign = -1
            i++
        } else if (s[i] == '+') {
            i++
        }

        var result: Long = 0 
        val INT_MAX = 2147483647
        val INT_MIN = -2147483648

        while (i < n && s[i].isDigit()) {
            val digit = s[i] - '0' 
            
            if (sign == 1) {
                if (result > INT_MAX / 10 || (result == INT_MAX / 10L && digit > 7)) {
                    return INT_MAX
                }
            } else { 
                if (result > abs(INT_MIN / 10L) || (result == abs(INT_MIN / 10L) && digit > 8)) {
                    return INT_MIN
                }
            }

            result = result * 10 + digit
            i++
        }

        val finalResult = (result * sign).toInt()

        if (finalResult > INT_MAX) {
            return INT_MAX
        }
        if (finalResult < INT_MIN) {
            return INT_MIN
        }

        return finalResult
    }
}

fun main() {
    val sol = Solution()

    println("Input: \"42\", Output: ${sol.myAtoi("42")}") 
    println("Input: \"   -42\", Output: ${sol.myAtoi("   -42")}") 
    println("Input: \"4193 with words\", Output: ${sol.myAtoi("4193 with words")}") 
}