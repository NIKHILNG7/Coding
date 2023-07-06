class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        left, right = 0, 0
        current_sum, result = nums[0], 10**5 + 1
        while right < len(nums):
            if current_sum < target:
                if right == len(nums) - 1:
                    break
                right += 1
                current_sum += nums[right]
            else:
                result = min(result, right - left + 1)
                current_sum -= nums[left]
                left += 1
        if result > 10**5:
            return 0
        return result