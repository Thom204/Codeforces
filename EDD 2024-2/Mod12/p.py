from collections import deque

class TrieNode:

    def __init__(self):
        self.children = {}  
        self.count = 0  

class Trie:
    def __init__(self):
        self.root = TrieNode()  

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.count += 1  

    def delete(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return  
            node = node.children[char]
            node.count -= 1
    
    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word
    
    def raiz(self,k,h):
        node = self.root
        q= deque()
        depth =0

        q.append(node)
        while len(q) >0 and depth<h:
            for j in range(len(q)):
                node = q.popleft()
                for child in node.children.keys():
                    q.append(node.children[child])

            depth+=1


        for nodo in q:
            if nodo.count >= int(k):
                return True
        return False

P = int(input())
a = Trie()
empty = True
for i in range(P):
    N = input().split()
    n = N[0]
    if n == "1":
        a.insert(N[1])
    elif n == "2":
        a.delete(N[1])
    else:
        x = a.raiz(N[1],int(N[2]))
        empty = False
        if x == True:
            print("SI")
        else:
            print("NO")   
if empty == True:
    print("-")