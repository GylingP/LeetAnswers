int romanToInt(char* s) {
    char roman[8] = "IVXLCDM";
    int value[7] = {1, 5, 10, 50, 100, 500, 1000};
    int res = 0;
    while (*s) {
        int unsigned_value=0;
        int i;
        for (i = 0; i < 7; i++) {
            if (*s == roman[i]) {
                unsigned_value = value[i];
                break;
            }
        }
        if ((s[0]=='I'||s[0]=='X'||s[0]=='C')&&(s[1]==roman[i+1]||s[1]==roman[i+2]))
            res -= unsigned_value;
        else
            res += unsigned_value;
        s++;
    }
    return res;
}