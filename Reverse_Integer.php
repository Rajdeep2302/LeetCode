<?php

class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $sign = 1;
        if ($x < 0) {
            $sign = -1;
            $x = abs($x);
        }

        $reversedNum = 0;
        while ($x > 0) {
            $digit = $x % 10;
            $reversedNum = $reversedNum * 10 + $digit;
            $x = (int)($x / 10);
        }

        $result = $reversedNum * $sign;

        $INT_MAX = 2147483647;
        $INT_MIN = -2147483648;

        if ($result > $INT_MAX || $result < $INT_MIN) {
            return 0;
        }

        return $result;
    }
}

// Test cases
$sol = new Solution();

echo "Input: 123, Output: " . $sol->reverse(123) . "\n";
echo "Input: -123, Output: " . $sol->reverse(-123) . "\n"; 
echo "Input: 120, Output: " . $sol->reverse(120) . "\n"; 
echo "Input: 0, Output: " . $sol->reverse(0) . "\n"; 
echo "Input: 1534236469, Output: " . $sol->reverse(1534236469) . "\n"; 
echo "Input: -2147483648, Output: " . $sol->reverse(-2147483648) . "\n"; 

?>
