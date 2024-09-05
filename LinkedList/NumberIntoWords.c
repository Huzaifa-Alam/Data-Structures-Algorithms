#include <stdio.h>

int main() {
    int num;
    printf("Enter a number (0-99): ");
    scanf("%d", &num);

    // Arrays to hold word equivalents
    char *single_digits[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    char *teen_numbers[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    char *tens_multiple[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    // Convert number to words
    if (num < 10) {
        printf("%s\n", single_digits[num]);
    } else if (num >= 10 && num < 20) {
        printf("%s\n", teen_numbers[num - 10]);
    } else if (num >= 20 && num < 100) {
        printf("%s", tens_multiple[num / 10]);
        if (num % 10 != 0) { // 7 % 10 = 7
            printf("-%s", single_digits[num % 10]);
        }
        printf("\n");
    } else {
        printf("Number out of range.\n");
    }

    return 0;
}
