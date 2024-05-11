class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        ret = float("inf")
        
        pairs = sorted([(w / q, q) for w, q in zip(wage, quality)], key=lambda p : p[0])
        
        q = []
        
        total_quality = 0
        
        for rate, quality in pairs:
            heapq.heappush(q, -quality)
            
            total_quality += quality
            
            if len(q) > k:
                total_quality += heapq.heappop(q)
                
            if len(q) == k:
                ret = min(ret, rate * total_quality)
                
        return ret
        
        