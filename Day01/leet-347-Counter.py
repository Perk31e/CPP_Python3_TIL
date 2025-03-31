from collections import Counter
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # nums 배열의 각 요소 빈도수를 계산하여 Counter 객체로 저장
        cnt_arr = Counter(nums)
        # 빈도수 기준 상위 k개의 (요소, 빈도수) 튜플 리스트를 반환하고, 요소만 추출
        return [item[0] for item in cnt_arr.most_common(k)]