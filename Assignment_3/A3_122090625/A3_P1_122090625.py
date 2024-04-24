s = input()
a = 0
b = 0
for i in range(len(s)):
    if s[i] == 'A':
        a += 1
    if s[i] == 'B':
        b += 1

print(f"A:{a}")
print(f"B:{b}")
if (a == 0 and b == 0) or a == b:
    print('Draw!')
elif a > b:
    print('A wins!')
elif a < b:
    print('B wins!')