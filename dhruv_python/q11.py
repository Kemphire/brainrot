dict = {}

for i in range(1,6):
 dict[i] = i ** 3

print(dict)


dict = {key:key ** 3 for key in range(1,6)}
print(dict)
