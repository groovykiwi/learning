#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    printf("Enter the calculation to do: ");
    scanf("%lf %c %lf", &num1,&op,&num2);

    switch (op) {
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        default:
            result = 0;

    }
    printf("%lf %c %lf = %lf\n", num1 , op, num2, result);
    return 0;
}
