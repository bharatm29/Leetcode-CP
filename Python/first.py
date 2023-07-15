s = ""

input(s)


def isPalindrome(s):
    i = 0
    j = len(s) - 1

    while i < j:
        if s.charAt(i) != s.charAt(j):
            return False
        else:
            i = 1 + i
            j = j - 1

    return True


if isPalindrome(s):
    print("TRUE")
else:
    print("FALSE")
