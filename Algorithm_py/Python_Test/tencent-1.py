'''
a,aa,aaa,aaaa,...,b,ba,baa,baaa,...,yyyy编码问题
进位：base_i*(b-a)+1
'''

str = input()
x = 0
list = [25*(25*26+1)+1, 25*26+1, 26, 1]

def main():
    ans = 0
    for i in range(len(str)):
        n = ord(str[i]) - ord('a')
        ans += list[i] * n + 1
    print(ans-1)

main()