a, b = map(int, input().split())

def main():
    if b <= 0 or b > 1024:
        print(-1)
    elif b == a:
        print(1)
    else:
        print(0)

main()