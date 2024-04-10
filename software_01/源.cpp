#include <stdlib.h>
#include<stdio.h>
#include<iostream>
#include <time.h>
using namespace std;

int generateNumber(int max) {
    return rand() % max + 1;
}

char generateOperator(int grade) {
    if (grade == 1) {
        return (rand() % 2) ? '+' : '-';
    }
    else if (grade == 2) {
        return (rand() % 2) ? '+' : '-';
    }
    else if (grade == 3) {
        int op = rand() % 3;
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else return '*';
    }
    else {
        int op = rand() % 4;
        if (op == 0) return '+';
        else if (op == 1) return '-';
        else if (op == 2) return '*';
        else return '/';
    }
}

int generateResult(int num1, char op, int num2) {
    if (op == '+') {
        return num1 + num2;
    }
    else if (op == '-') {
        return num1 - num2;
    }
    else if (op == '*') {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

void generateExercises(int grade, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        int num1, num2;
        char op;
        if (grade == 1) {
            num1 = generateNumber(20);
            num2 = generateNumber(20 - num1);
            op = generateOperator(grade);
        }
        else if (grade == 2) {
            num1 = generateNumber(50);
            num2 = generateNumber(50 - num1);
            op = generateOperator(grade);
        }
        else if (grade == 3) {
            num1 = generateNumber(1000);
            num2 = generateNumber(50);
            op = generateOperator(grade);
        }
        else {
            num1 = generateNumber(100);
            num2 = generateNumber(100);
            char op1 = generateOperator(grade);
            char op2 = generateOperator(grade);
            int result1 = generateResult(num1, op1, num2);
            int result2 = generateResult(num2, op2, generateNumber(100));
            op = generateOperator(grade);
            num1 = result1;
            num2 = result2;
        }

        printf("第%d题: %d %c %d = ?\n", i + 1, num1, op, num2);
    }
}

int main() {
    int grade, num_questions;

    srand(time(NULL)); // 使用当前时间作为随机种子

    printf("请输入年级（1-6）：");
    scanf_s("%d", &grade);
    printf("请输入题目数量：");
    scanf_s("%d", &num_questions);

    generateExercises(grade, num_questions);

    return 0;
}