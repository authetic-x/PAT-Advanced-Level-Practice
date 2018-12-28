//
// Created by authetic on 2018/12/28.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, cnt = 0;
    char a[50], b[50];
    scanf("%d", &n);
    double temp, sum = 0;
    for (int i = 0; i < n; i ++ ) {
        int flag = 0;
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        for (int j = 0; j < strlen(a); j ++ ) {
            if (a[j] != b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
        } else {
            cnt ++;
            sum += temp;
        }
    }
    if (cnt == 0) {
        printf("The average of 0 number is Undefined");
        return 0;
    }
    if (cnt == 1) {
        printf("The average of 1 number is %.2f\n", sum);
        return 0;
    }
    printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    return 0;
}