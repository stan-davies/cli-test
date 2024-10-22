#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hello() {
        printf("you have given option hello, hiya!!\n");
}

int goodbye() {
        printf("wow it is as if you don't even like me =(\n");
}

int main(int argc, char **argv) {
        for (int i = 0; i < argc; ++i) {
                if (0 == strcmp(argv[i], "hello")) {
                        hello();
                } else if (0 == strcmp(argv[i], "goodbye")) {
                        goodbye();
                }
        }

        return 0;
}