#1029 - Fibonacci, Quantas Chamadas? 
fib = [0, 1]
calls = [1, 1]
for i in range(2, 40):
    calls.append(calls[i-1] + calls[i-2] + 1)
    fib.append(fib[i-1] + fib[i-2])
    
rep = int(input())

for i in range(0, rep):
    n = int(input())
    print(f"fib({n}) = {calls[n]-1} calls = {fib[n]}")