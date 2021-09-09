def reverse(p):
    result = ""
    
    for char in p:
        if char == "(":
            result += ")"
        else:
            result += "("
    return result


def solution(p):
    if p == "":
        return p
    
    n = len(p)
    pos = 1
    stack = [p[0]]
    
    while len(stack) != 0 and pos < n:
        if stack[-1] != p[pos]:
            stack.pop()
        else:
            stack.append(p[pos])
        pos += 1
    
    u = p[0:pos]
    v = p[pos:]
    
    if u[0] == "(":
        return u + solution(v)

    
    v = solution(v)
    
    u = u[1: -1]
    u = reverse(u)
    
    answer = "(" + v + ")" + u
    
    return answer
