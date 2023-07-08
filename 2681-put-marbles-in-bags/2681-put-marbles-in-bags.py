class Solution:
    def putMarbles(self, marbles: List[int], num_marbles: int) -> int:
        for i in range(len(marbles) -1):
            marbles[i] += marbles[i+1]
        marbles[-1] = 1<<31
        marbles.sort()
        return sum(marbles[-num_marbles:-1]) - sum(marbles[:num_marbles-1])