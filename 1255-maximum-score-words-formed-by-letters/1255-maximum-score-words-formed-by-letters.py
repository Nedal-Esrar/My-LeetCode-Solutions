class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        letter_cnt = Counter(letters)
        
        def can_form_word(word):
            word_cnt = Counter(word)
            
            for c in word_cnt:
                if word_cnt[c] > letter_cnt[c]:
                    return False
                
            return True

        def get_score(word):
            ret = 0
            
            for c in word:
                ret += score[ord(c) - 97]
                
            return ret
        
        def backtrack(i):
            if i == len(words):
                return 0
            
            ret = backtrack(i + 1) # skip the current word
            
            if can_form_word(words[i]): # Include if the word can be formed
                for c in words[i]:
                    letter_cnt[c] -= 1
                    
                ret = max(ret, get_score(words[i]) + backtrack(i + 1))
                
                for c in words[i]:
                    letter_cnt[c] += 1
                
            return ret
        
        return backtrack(0)
                