//
// Created by authetic on 2018/9/8.
/*
 * 简单的链表剔除
 * Note: 真是服了，先是用set+vector做，不知道哪里错了，只对了一个，
 * 后来检查的时候突然内存爆炸，后台不知道运行什么未知进程，内存直接90+，
 * 以为要蓝屏了，心态爆炸，然后疯狂出错，简单题硬是再一次的搞了一个多小时，
 * 还肚子痛，屋漏偏逢连夜雨！！！不得不说自己弱到爆炸
 * 做这种静态链表题一般都是这种方式，order记录有效结点，再排一下序，这样可以
 * 简便很多。
 */
//

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

bool isExist[10010] = {false};

struct Node {
    int addr,data,next;
    int order;
    Node() {
      order = 2*maxn;
    }
}node[maxn];

bool cmp(Node a, Node b) {
  return a.order < b.order;
}

int main() {
   int head,n;
   scanf("%d %d", &head, &n);
   int addr,data,next;
   for (int i=0; i<n; i++) {
     scanf("%d %d %d", &addr, &data, &next);
     node[addr].addr = addr;
     node[addr].data = data;
     node[addr].next = next;
   }
   int p = head;
   int count=0, removeCount=0;
   while (p!=-1) {
     if (!isExist[abs(node[p].data)]) {
       isExist[abs(node[p].data)] = true;
       node[p].order = count++;
     } else {
       node[p].order = maxn+removeCount++;
     }
     p = node[p].next;
   }
   sort(node, node+maxn, cmp);
   int total = count+removeCount;
   for (int i=0; i<total; i++) {
     if (i!=count-1 && i!=total-1) {
       printf("%05d %d %05d\n", node[i].addr, node[i].data, node[i+1].addr);
     } else {
       printf("%05d %d -1\n", node[i].addr, node[i].data);
     }
   }
   return 0;
}