#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdarg.h>

enum FLAGS {
        INV,
        ADD,
        SUB,
        MULT,
        DIV
};

int main(int argc, char *argv[]) {
        int num_count = 0;
        enum FLAGS type;
        for (int i = 1; i < argc; ++i) {
                if ('-' == argv[i][0]) {
                        switch (argv[i][1]) {
                        case 'a':
                                type = ADD;
                                break;
                        case 's':
                                type = SUB;
                                break;
                        case 'm':
                                type = MULT;
                                break;
                        case 'd':
                                type = DIV;
                                break;
                        default:
                                printf("ERROR: invalid flag at symbol '%s'\n", argv[i]);
                                return 0;
                        }
                } else {
                        num_count++;
                }
        }
        
        int nums[num_count];
        for (int i = 0; i < num_count; ++i) {
                nums[i] = atoi(argv[i + 2]);
                if (0 == nums[i]) {
                        printf("ERROR: invalid argument at symbol '%s'\n", argv[i]);
                        return 0;
                }
        }

        int total = nums[0];

        for (int i = 1; i < num_count; ++i) {
                switch (type) {
                case ADD:
                        total += nums[i];
                        break;
                case SUB:
                        total -= nums[i];
                        break;
                case MULT:
                        total *= nums[i];
                        break;
                case DIV:
                        total /= nums[i];
                        break;
                default:
                        break;
                }
        }

        printf("type is: '%d'\n", type);
        printf("total is: '%d'\n", total);

        return 0;
}
