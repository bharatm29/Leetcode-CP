def isValidOrder(c, d):
    if c == '(' and d == ')':
        return True
    elif c == '(' and d == ')':
        return True
    elif c == '(' and d == ')':
        return True

    return False


def validParenthesis(s):
    stack = []

    for c in s:
        if c == '(' or c == '[' or c == '{':
            stack.append(c)
        else:
            if not isValidOrder(stack[-1], c):
                return False
            stack.pop()


s = "(){}[]"
if validParenthesis(s):
    print("TRUE")
else:
    print("FALSE")
