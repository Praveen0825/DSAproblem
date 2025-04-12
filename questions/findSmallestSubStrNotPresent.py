'''
Given a array of bytes (c++ string or char array or unit_8 array).

Please find a shortest byte sequence that does not present in the input array.

assume that "byte" contains only "a" to "f"
input: "abcdefacbeddefd"

"a" is present
"b" is present
..
"f" is present
"aa" is not present
"ab" is present
"ac" is present

you can return "aa" or "ad" or "ae"... "ff"
but not "ab" "ac" "bc"

testcases
input - aabcdf
output - e
Check for single byte shortest byte sequence a,b,c, .... f

input - abcdefacbeddefd
output - aa
check for aa, ab, ac, .... ff
'''
from collections import deque

class TrieNode:
    def __init__(self, val):
        self.val = val
        self.child = {}
        isWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode(None)

    def addWord(self, word):
        root = self.root
        for c in word :
            if c not in root.child:
                root.child[c] = TrieNode(c)
            root = root.child[c]
        root.isWord = True

    def find_shortest_seq_not_present(s):
        trie = Trie()
        for i in range(len(s)):
            trie.addWord(s[i:])

        root = trie.root
        q = deque()
        q.append((root, ""))
        while(q) :
            root, string = q.popleft()
            temp = "abcdef"
            for c in temp:
                if c not in root.child:
                    return string + c
                else :
                    q.append(root.child[c], string + c)

        return ""











    