class Solution:
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        def can_finish(k: int) -> bool:
            return sum((pile + k - 1) // k for pile in piles) <= h
        
        left, right = 1, max(piles)
        while left < right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1
        return left   