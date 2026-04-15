class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        thash = dict()
        for c in t:
            thash[c] = thash.get(c, 0) + 1

        shash = dict()
        shortest = ""
        curr = ""
        for c in s:
            # if not word move right pointer
            shash[c] = shash.get(c, 0) + 1
            curr += c

            # if substring found, move left pointer
            while len(curr) > 0:
                equal = True
                for c, n in thash.items():
                    if c not in shash or shash[c] < n:
                        equal = False
                if not equal:
                    break

                if len(curr) < len(shortest) or shortest == "":
                    shortest = curr

                shash[curr[0]] -= 1
                curr = curr[1:]

            # keep going until right is at the end and left moves past making substr with chars
        
        return shortest