class Node:
    def __init__(self):
        self.is_word = False
        self.children = collections.defaultdict(Node)

class Trie:

    def __init__(self):
        self.root = Node()
        

    def insert(self, word: str) -> None:

        cur_node = self.root
        
        for c in word:
            cur_node = cur_node.children[c]
            
        cur_node.is_word = True
        

    def search(self, word: str) -> bool:
        cur_node = self.root
        
        for c in word:
            if c not in cur_node.children:
                return False
            else:
                cur_node = cur_node.children[c]
            
        if cur_node.is_word == False:
            return False
        else:
            return True
        

    def startsWith(self, prefix: str) -> bool:
        cur_node = self.root
        
        for c in prefix:
            if c not in cur_node.children:
                return False
            else:
                cur_node = cur_node.children[c]
        
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
