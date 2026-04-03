from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Count frequencies
        freq = Counter(nums)
        # Return top k elements using built-in method
        return [num for num, _ in freq.most_common(k)]   