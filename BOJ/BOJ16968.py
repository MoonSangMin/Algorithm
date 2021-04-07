form = input()

a = len(form)
if form[0]=='d':
    ans=10
else:
    ans=26

for i in range(1, a):
    if form[i]=='c':
        if form[i-1]=='c':
            ans*=25
        else:
            ans*=26
    elif form[i]=='d':
        if form[i-1]=='d':
            ans*=9
        else:
            ans*=10

print(ans)