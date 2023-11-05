n = int(input())
d = {}
print("Initial array:")

for i in range(10):
  d[str(i)] = []

mx = 0
for i in range(n):
    s = input()
    mx = len(s)
    
    if i == n - 1:
        print(s)
    else:
        print(s, end=", ")
    d[s[-1]] += [s]

print("**********")
newd = {}
for i in range(mx):
  for j in range(10):
    newd[str(j)] = []
  print("Phase", i + 1)

  for j in d:
    for p in d[j]:
      newd[str(p[-i - 1])] += [p]

  for i in newd:
    d[i] = newd[i]

  for j in range(10):
    j = str(j)
    print(f"Bucket {j}: ", end="")

    if len(d[j]) == 0:
      print("empty")
    else:
      for p in range(len(d[j])):
        if p == len(d[j]) - 1:
          print(d[j][p])
        else:
          print(d[j][p], ', ', end="", sep="")

  print("**********")

print('Sorted array:')
res = ''
for i in d:
    for j in d[i]:
        res += j + ', '
print(res[:-2])