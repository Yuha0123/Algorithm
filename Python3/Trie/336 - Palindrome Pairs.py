class Node:
    def __init__(self):
        self.is_word = -1
        self.children = collections.defaultdict(Node)
        self.is_palindrome = []
        
class Trie:
    def __init__(self):
        self.root = Node()
    
    def check_palindrome(self, word):
        return word == word[::-1]

    def insert(self, word: str, idx: int) -> None:

        cur_node = self.root
        
        for i in range(len(word)):
            if self.check_palindrome(word[i:]):
                cur_node.is_palindrome.append(idx)
            cur_node = cur_node.children[word[i]]
            
            
        cur_node.is_word = idx
        

    def search(self, word: str, idx: int):
        cur_node = self.root
        result = []
        
        for i in range(len(word)):
            if cur_node.is_word >=0:
                if self.check_palindrome(word[i:]):
                    result.append([idx, cur_node.is_word])
            
            if word[i] not in cur_node.children:
                return result
            else:
                cur_node = cur_node.children[word[i]]
            
        
        if cur_node.is_word >=0 and cur_node.is_word != idx: 
            result.append([idx, cur_node.is_word])
        
        if len(cur_node.is_palindrome) > 0:
            for pair_idx in cur_node.is_palindrome:
                result.append([idx, pair_idx])
        
        return result


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        
        reverse = []
        
        for word in words:
            reverse.append(word[::-1])
        
        trie = Trie()
        for i in range(len(reverse)):
            trie.insert(reverse[i], i)
            
        answer = []
        
        for i in range(len(words)):
            result = trie.search(words[i], i)
            answer.extend(result)
            
        
        return answer
        
