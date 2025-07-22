from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {} 
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return [] 
    
sol = Solution()
nums1 = [2, 7, 11, 15]
target1 = 9
print(f"Input: nums = {nums1}, target = {target1}")
print(f"Output: {sol.twoSum(nums1, target1)}")