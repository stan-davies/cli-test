#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define TRUE  1
#define FALSE 0

enum OPERATIONS {
        INV,
        ADD,
        SUB,
        MULT,
        DIV
};

int to_op(char *c) {
        switch (*c) {
        case 'a':
                return ADD;
        case 's':
                return SUB;
        case 'm':
                return MULT;
        case 'd':
                return DIV;
        default:
                return INV;
        }
}

// string is null terminated
int check_num(char *c) {
        int i = 0;
        char curr_c = c[i];

        // until null terminator is found
        while (0 != curr_c) {
                if (curr_c > 57 || curr_c < 48) {
                        return FALSE;
                }
                i++;
                curr_c = c[i];
        }

        return TRUE;
}

int main(int argc, char **argv) {
        enum OPERATIONS type;
        int opt;
        // each character is an option, a : indicates that an argument should follow this option
        // :: would indicate that an argument COULD follow this optional (i.e. it is optional)
        // obviously options do not have to be given, otherwise they would not be options
        // any other option being given yields '<program>: invalid option -- <opt>', and it will then go into default
        while ((opt = getopt(argc, argv, "o:")) != -1) {
                switch (opt) {
                case 'o':
                        type = to_op(optarg);
                        break;
                default:
                        printf("ERROR: unexpected option at symbol '%s'\n", opt);
                        break;
                }
        }

        if (INV == type) {
                printf("ERROR: invalid operation chosen\n");
                return 0;
        }




        int num_count = 0;

        for (int i = 1; i < argc; ++i) {
                if (FALSE == check_num(argv[i])) {
                        continue;
                }

                num_count++;
        }

        int *nums = (int *)malloc(num_count * sizeof(int));

        int n_i = 0;
        for (int a_i = 1; a_i < argc; ++a_i) {
                if (FALSE == check_num(argv[a_i])) {
                        continue;
                }

                nums[n_i] = atoi(argv[a_i]);

                if (0 == nums[n_i]) {
                        printf("ERROR: invalid argument at symbol '%s'\n", argv[a_i]);
                }
                n_i++;
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
                        printf("ERROR: invalid operation\n");
                        return 0;
                }
        }

        printf("total is: %d\n", total);

        return 0;
}
