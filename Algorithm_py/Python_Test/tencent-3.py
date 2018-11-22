a = int(input())

def is_zhishu(a):
    if a == 2 or a == 3:
        return True
    for i in range(2, int((a ** 0.5))+1):
        if (a % i) == 0:
            return False
    return True

def main():
    ans = 0
    for i in range(2, int(a / 2)+1):
        if is_zhishu(i) and is_zhishu(a-i):
            ans += 1
    print(ans)

main()