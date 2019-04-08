//
// Created by authetic on 2019/4/8.
//

/*
 * 模拟两个多项式相加过程
 * 无非是依次判断系数大小复制到结果队列中，
 * 啊，很简单的题目，结构设置的有点混乱，
 * 偷个懒不写了^_^!
 *
 * 下面添加的是小白专场里的多项式乘法运算
 */

#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
    int coef;
    int expon;
    PolyNode* link;
};

typedef PolyNode* Polynomial;

void Attach(int c, int e, Polynomial *pRear) {
    auto p = (Polynomial)malloc(sizeof(PolyNode));
    p->coef = c;
    p->expon = e;
    p->link = nullptr;
    (*pRear)->link = p;
    (*pRear) = p;
}

Polynomial ReadPoly() {
    int n;
    scanf("%d", &n);
    Polynomial p, rear, tmp;
    p = (Polynomial)malloc(sizeof(PolyNode));
    p->link = nullptr;
    rear = p;
    while (n--) {
        int c, e;
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);
    }
    tmp = p, p = p->link;
    free(tmp);
    return p;
}

Polynomial Add(Polynomial p1, Polynomial p2) {
    Polynomial p, rear, t;
    p = (Polynomial)malloc(sizeof(PolyNode));
    p->link = nullptr;
    rear = p;
    while (p1 && p2) {
        if (p1->expon > p2->expon) {
            Attach(p1->coef, p1->expon, &rear);
            p1 = p1->link;
        } else if (p1->expon < p2->expon) {
            Attach(p2->coef, p2->expon, &rear);
            p2 = p2->link;
        } else {
            int c = p1->coef + p2->coef;
            if (c != 0) {
                Attach(c, p1->expon, &rear);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    while (p1) {
        Attach(p1->coef, p1->expon, &rear);
        p1 = p1->link;
    }
    while (p2) {
        Attach(p2->coef, p2->expon, &rear);
        p2 = p2->link;
    }
    t = p, p = p->link, free(t);
    return p;
}

Polynomial Multiply(Polynomial p1, Polynomial p2) {
    Polynomial t1 = p1, t2 = p2;
    Polynomial p, rear;
    p = (Polynomial)malloc(sizeof(PolyNode));
    p->link = nullptr, rear = p;
    while (t2) {
        Attach(t1->coef*t2->coef, t1->expon+t2->expon, &rear);
        t2 = t2->link;
    }

}

void PrintPoly(Polynomial p);

int main() {
    Polynomial p1, p2, pp, ps;

}