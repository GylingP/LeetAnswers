char* intToRoman(int num) {
    char character[] = "MDCLXVI";
    int value[7] = {1000, 500, 100, 50, 10, 5, 1};
    char* res = (char*)malloc(sizeof(char) * 17);
    char* cursor = res;
    for (int i = 0; i < 7; i++) {
        if (num / value[i] <= 3) {
            for (int j = 0; j < num / value[i]; j++) {
                *cursor = character[i];
                cursor++;
            }
            num = num % value[i];
            continue;
        }
        if (cursor != res && *(cursor - 1) == character[i - 1]) {
            cursor--;
            *cursor = character[i];
            cursor++;
            *cursor = character[i - 2];
            cursor++;
        } else {
            *cursor = character[i];
            cursor++;
            *cursor = character[i - 1];
            cursor++;
        }
        num = num % value[i];
    }
    *cursor = '\0';
    return res;
}