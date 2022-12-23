#include <iostream>
using namespace std;

int rpn(char pol_f[1000]);

int c2i(char c);
int str2i(char str[1000]);

void push(int stack[1000], int *sp, int n);
int pop(int stack[1000], int *sp);

int main(void)
{
    char pol_f[1000];

    cin.getline(pol_f, 1000);  // 空白を含めて一行を読み込む

    cout << rpn(pol_f) << endl;

    return 0;
}               

int rpn(char pol_f[1000])
{
    int stack[1000];
    int sp = 0;
    int i;
    int first, second;

    for ( i = 0; pol_f[i] != '\0'; i++) {
        if ( '9' >= pol_f[i] && pol_f[i] >= '0' ) {
            push(stack,&sp,str2i(pol_f + i));
            while (pol_f[i + 1] >= '0' && pol_f[i + 1] <= '9') {
                i++;
            }
        } else {
            if (pol_f[i] == '+') {
                second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, first + second);
            } else if  (pol_f[i] == '-') {
                    second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, first - second);
            } else if  (pol_f[i] == '*') {
                 second = pop(stack, &sp);
                first = pop(stack, &sp);
                push(stack, &sp, first * second);
            }
        }
    }

    return pop(stack, &sp);
}

int c2i(char c)
{
    return c - '0';
}

int str2i(char str[1000])
{
    int i;
    int n = 0;
    for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
        n = n * 10 + c2i(str[i]);
    }
    return n;
}

void push(int stack[1000], int *sp, int n)
{
    stack[(*sp)++] = n;
}

int pop(int stack[1000], int *sp)
{
    return stack[--*sp];
}