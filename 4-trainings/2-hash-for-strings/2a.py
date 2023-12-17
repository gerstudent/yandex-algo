s = input()
n = int(input())

ln = len(s)
h = [0] * (ln + 1)
x = [0] * (ln + 1)
x[0] = 1

p = 10 ** 9 + 7
magic = 257
s = '' + s

for i in range(1, ln + 1):
    h[i] = (h[i - 1] * magic + ord(s[i - 1])) % p
    x[i] = (x[i - 1] * magic) % p

def isEqual(from1, from2, slen):
    return (
        (h[from1 + slen] + h[from2] * x[slen]) % p
        ==
        (h[from2 + slen] + h[from1] * x[slen]) % p
    )

res = []
for i in range(n):
    nums = [int(x) for x in input().split()]
    if isEqual(nums[1], nums[2], nums[0]):
        res.append("yes")
    else:
        res.append("no")
print(*res, sep='\n')