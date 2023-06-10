
        

import math
class Solution:
    def maxValue(self, num: int, ind: int, maxSum: int) -> int:
        maxSum -= num              # remove the contributions from all the 1 in each element.
		                         # We will add 1 back to the final height later
        if ind < num // 2:       # make the index closer to the right boundary
            ind = num - ind - 1
        n_left = ind           # number of element to the left of the index
        n_right = num - 1 - ind  # number of element to the right of the index
        tri_left = (n_left * (n_left + 1)) // 2     # the triangle area for the left side if not hitting the boundary
        tri_right = (n_right * (n_right + 1)) // 2  # the triangle area for the right side if not hitting the boundary
		# case 1: perfect pyramid
        if maxSum <= (tri_right * 2 + n_right + 1):
            return int(math.sqrt(maxSum)) + 1
		# case 2: right side hits the boundary
        if maxSum <= (tri_left + tri_right + (n_left - n_right) * n_right + n_left + 1):
            b = 3 + 2 * n_right
            return int((-b + math.sqrt(b * b - 8 * (tri_right + 1 - n_right * n_right - maxSum))) / 2) + 1 + 1
		# case 3: both sides hit boundaries
        maxSum -= (tri_left + tri_right + (n_left - n_right) * n_right + n_left + 1)
        return n_left + 1 + 1 + (maxSum // num)