class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        sorted_score_idx = sorted(list(range(len(score))), key=lambda x : -score[x])
        
        print(sorted_score_idx[0])
        
        ret = [0] * len(score)
        
        for i in range(len(score)):
            if i == 0:
                ret[sorted_score_idx[i]] = "Gold Medal"
            elif i == 1:
                ret[sorted_score_idx[i]] = "Silver Medal"
            elif i == 2:
                ret[sorted_score_idx[i]] = "Bronze Medal"
            else:
                ret[sorted_score_idx[i]] = str(i + 1)
        
        return ret