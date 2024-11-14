int getIndex(int i, int j, int r) {
    if (r == 1)
        return j;
    if (i == 0)
        return j * (2 * r - 2);
    if (i == r - 1)
        return (r - 1) + j * (2 * r - 2);
    if (j % 2)
        return (j + 1) / 2 * (2 * r - 2) - i;
    else
        return (j / 2) * (2 * r - 2) + i;
}

char* convert(char* s, int numRows) {
    int len = strlen(s);
    char* res = (char*)malloc(sizeof(char) * (len + 1));
    int cursor = 0;
    for (int i = 0; i < numRows; i++) {
        int j = 0;
        while (1) {
            int index = getIndex(i, j, numRows);
            if (index >= len)
                break;
            res[cursor] = s[index];
            j++;
            cursor++;
        }
    }
    res[cursor] = '\0';
    return res;
}