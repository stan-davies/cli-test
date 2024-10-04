#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdarg.h>

enum colour {
        RED_ON_BLACK,
        WHITE_ON_BLACK
};

void set_col(HANDLE console, enum colour col);

void log_err(HANDLE console, char *argc, ...);


void set_col(HANDLE console, enum colour col) {
        int colour;
        switch (col) {
        case RED_ON_BLACK: 
                colour = FOREGROUND_RED;
                break;
        case WHITE_ON_BLACK:
                colour = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                break;
        }
        SetConsoleTextAttribute(console, colour);
}

void log_err(HANDLE console, char *message, ...) {
        set_col(console, RED_ON_BLACK);

        va_list argptr;
        va_start(argptr, message);
        vprintf(message, argptr);
        va_end(argptr);

        set_col(console, WHITE_ON_BLACK);
        printf("\n");
}

// argc is the number of arguments you recieve
// argv[0] is the program name
// all others are as given
// hello is interpreted as hello
// "hello" is interpreted as hello
// 'hello' is interpreted as 'hello'
// arguments are delimited by spaces, although spaces are ignored if part of a block enclosed in double quotes
int main(int argc, char *argv[]) {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        
        int sum = 0;
        int add = 0;
        for (int i = 1; i < argc; ++i) {
                add = atoi(argv[i]);
                if (0 == add) {
                        log_err(console, "ERROR: invalid symbol at '%s'", argv[i]);
                        return 0;
                }
                sum += add;
        }

        printf("the sum is %d\n", sum);

        return 0;

        // strcmp returns 0 if a==b, otherwise a>b or whatever, so we check for false
        // if (!strcmp(argv[1], "hello")) {
        //         printf("same\n");
        // } else {
        //         printf("diff\n");
        // }
}