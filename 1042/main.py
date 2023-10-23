# 1042 - Sort Simples

A, B, C = list(map(int, input().split()))

AS = A
BS  = B
CS = C

if (AS > BS):
    AS, BS = BS, AS
if (BS > CS):
    BS, CS = CS, BS
if (AS > BS):
    AS, BS = BS, AS

print(f"{AS}\n{BS}\n{CS}\n")
print(f"{A}\n{B}\n{C}")
