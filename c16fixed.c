#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 16

char *copy_input(const char *user_supplied_string) {
    int i, dst_index;
    size_t src_len = strlen(user_supplied_string);
    char *dst_buf = (char*) malloc((4 * src_len + 1) * sizeof(char));
    if (src_len > MAX_SIZE - 1) {
        printf("user string too long, die evil hacker!\n");
        exit(EXIT_FAILURE);
    }
    dst_index = 0;
    for (i = 0; i < src_len; i++) {
        if (user_supplied_string[i] == '&') {
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'a';
            dst_buf[dst_index++] = 'm';
            dst_buf[dst_index++] = 'p';
            dst_buf[dst_index++] = ';';
        } else if (user_supplied_string[i] == '<') {
            dst_buf[dst_index++] = '&';
            dst_buf[dst_index++] = 'l';
            dst_buf[dst_index++] = 't';
            dst_buf[dst_index++] = ';';
        } else {
            dst_buf[dst_index++] = user_supplied_string[i];
        }
    }
    dst_buf[dst_index] = '\0';
    return dst_buf;
}

int main() {
    char uss[MAX_SIZE];
    if (read(STDIN_FILENO, uss, MAX_SIZE - 1) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    char *dst_buff = copy_input(uss);
    printf("%s\n", dst_buff);
    free(dst_buff);
    return 0;
}
