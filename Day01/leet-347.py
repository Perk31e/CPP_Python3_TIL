class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for value in nums:
            if value in count:
                count[value] += 1
            else:
                count[value] = 1
        sorted_keys = sorted(count, key=count.get, reverse=True)
        return sorted_keys[:k]