import sys

n = int(input())
ans = [ 0, 0, 0 ]

while n != 0:
    if n>=300:
        n -= 300
        ans[0]+=1
    elif n>=60:
        n -= 60
        ans[1]+=1
    elif n>=10:
        n -= 10
        ans[2]+=1
    else:
        print(-1)
        sys.exit(0)

for _ in ans:
    print(_, end=" ")