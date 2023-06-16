from math import comb
from typing import List

class Solution:
    def numOfWays(self, numbers: List[int]) -> int:
        def calculateWays(nums):
            if len(nums) <= 2:
                return 1   
            leftNumbers = [v for v in nums if v < nums[0]]
            rightNumbers = [v for v in nums if v > nums[0]]
            return comb(len(leftNumbers) + len(rightNumbers), len(rightNumbers)) * calculateWays(leftNumbers) * calculateWays(rightNumbers)
        
        return (calculateWays(numbers) - 1) % (10**9 + 7)