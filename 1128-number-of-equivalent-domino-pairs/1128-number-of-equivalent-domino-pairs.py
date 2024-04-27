class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        frq = defaultdict(int)

        for a, b in dominoes:
            pair = [b, a] if a > b else [a, b]
            
            frq[tuple(pair)] += 1

        return sum([v * (v - 1) // 2 for v in frq.values()])