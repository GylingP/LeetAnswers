char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        strs[0][0] == '\0';
        return strs[0];
    }
    for (int i = 1; i < strsSize; i++) {
        if (strs[0][0] == '\0')
            return strs[0];
        char* str = strs[i];
        char* cursor = strs[0];
        while (*cursor && *str && *cursor == *str) {
            *cursor = *str;
            cursor++;
            str++;
        }
        cursor[0] = '\0';
    }
    return strs[0];
}