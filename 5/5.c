char* longestPalindrome(char* s) {
    char* fs = s; // flag_start
    int max = 0;
    char* cursor = s;
    for (int step = 0; *cursor; step++) {
        int i;
        if (step % 2) {
            for (i = 1; (cursor - i + 1) >= s && *(cursor + i); i++) {
                if (*(cursor - i + 1) == *(cursor + i))
                    continue;
                else
                    break;
            }
            i--;
            if (i * 2 > max) { // considering that no res exists
                fs = cursor - i + 1;
                max = i * 2;
            }
        } else {
            // prevent index out
            for (i = 0; (cursor - i) >= s && *(cursor + i); i++) {
                if (!i || *(cursor - i) == *(cursor + i))
                    continue;
                else
                    break;
            }
            i--;                   // undo the last increase
            if (i * 2 + 1 > max) { // considering that no res exists
                fs = cursor - i;
                max = i * 2 + 1;
            }
        }
        if (step % 2)
            cursor++;
    }
    char* res = (char*)malloc(sizeof(char) * (max + 1)); // considering '\0'
    strncpy(res, fs, max);
    res[max] = '\0';
    return res;
}