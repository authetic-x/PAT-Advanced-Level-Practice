//
// Created by authetic on 2018/11/22.
/*
 * 按时间排队，找出谁最先开门，谁最后关门
 */
//

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Person {
    char num_id[20];
    int sign_in, sign_out;
};

int M;

bool cmp_sign_in(Person a, Person b) {
    return a.sign_in < b.sign_in;
}

bool cmp_sign_out(Person a, Person b) {
    return a.sign_out > b.sign_out;
}

int main() {
    scanf("%d", &M);

    Person person[M];
    int hh, mm, ss, num=0;
    char s[20];
    for (int i = 0; i < M; i ++ ) {
        scanf("%s", s);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int sign_in = hh * 3600 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int sign_out = hh * 3600 + mm * 60 + ss;
        if (sign_in < sign_out) {
            strcpy(person[num].num_id, s);
            person[num].sign_in = sign_in;
            person[num].sign_out = sign_out;
            num++;
        }
    }
    sort(person, person + num, cmp_sign_in);
    printf("%s ", person[0].num_id);
    sort(person, person + num, cmp_sign_out);
    printf("%s", person[0].num_id);
    return 0;
}